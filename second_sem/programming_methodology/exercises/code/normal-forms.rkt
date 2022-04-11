#lang plait

(define-type (NNF 'v)
             (nnf-lit [polarity : Boolean] [var : 'v])
             (nnf-conj [l : (NNF 'v)] [r : (NNF 'v)])
             (nnf-disj [l : (NNF 'v)] [r : (NNF 'v)]))

(define (negate-nnf nnf)
  (cond
    [(nnf-lit? nnf) (nnf-lit (not (nnf-lit-polarity nnf)) (nnf-lit-var nnf))]
    [(nnf-conj? nnf) (nnf-disj (negate-nnf (nnf-conj-l nnf)) (negate-nnf (nnf-conj-r nnf)))]
    [(nnf-disj? nnf) (nnf-conj (negate-nnf (nnf-disj-l nnf)) (negate-nnf (nnf-disj-r nnf)))]))

(define (eval-nnf nnf)
  (cond
    [(nnf-lit? nnf) (nnf-lit-polarity nnf)]
    [(nnf-conj? nnf) (and (eval-nnf (nnf-conj-l nnf)) (eval-nnf (nnf-conj-r nnf)))]
    [(nnf-disj? nnf) (or (eval-nnf (nnf-disj-l nnf)) (eval-nnf (nnf-disj-r nnf)))]))

(define-type (Formula 'v)
             (var [var : 'v])
             (neg [f : (Formula 'v)])
             (conj [l : (Formula 'v)] [r : (Formula 'v)])
             (disj [l : (Formula 'v)] [r : (Formula 'v)]))

(define (to-nnf expr)
  (cond
    [(var? expr) (nnf-lit #t (var-var expr))]
    [(neg? expr) (negate-nnf (to-nnf (neg-f expr)))]
    [(conj? expr) (nnf-conj (to-nnf (conj-l expr)) (to-nnf (conj-r expr)))]
    [(disj? expr) (nnf-disj (to-nnf (disj-l expr)) (to-nnf (disj-r expr)))]))

(define (remove-duplicates lst)
  (foldr (lambda (x y) (cons x (filter (lambda (z) (not (equal? x z))) y))) empty lst))

(define (accumulate-vars t)
  (cond
    [(var? t) (cons (var-var t) empty)]
    [(neg? t) (accumulate-vars (neg-f t))]
    [(conj? t) (append (accumulate-vars (conj-l t)) (accumulate-vars (conj-r t)))]
    [(disj? t) (append (accumulate-vars (disj-l t)) (accumulate-vars (disj-r t)))]))

(define (free-vars t)
  (remove-duplicates (accumulate-vars t)))

(define (eval-var hash-table prop)
  (if (var? prop) (some-v (hash-ref hash-table (var-var prop))) #f))

(define (eval-expr vals expr)
  (cond
    [(var? expr) (eval-var vals expr)]
    [(neg? expr) (not (eval-var vals (neg-f expr)))]
    [(conj? expr) (and (eval-expr vals (conj-l expr)) (eval-expr vals (conj-r expr)))]
    [(disj? expr) (or (eval-expr vals (disj-l expr)) (eval-expr vals (disj-r expr)))]))

(define (init-values variables truth-values)
  (map2 (λ (sym val) (pair sym val)) variables truth-values))

; source: https://stackoverflow.com/questions/63024568/permutation-of-list-of-lists-of-booleans-in-racket
(define (bool-val-perms n)
  (if (= 1 n)
      '((#t) (#f))
      (append (map (λ (p) (cons #t p)) (bool-val-perms (sub1 n)))
              (map (λ (p) (cons #f p)) (bool-val-perms (sub1 n))))))

(define (make-truth-table expr truth-values)
  (map (λ (x) (pair x (eval-expr (make-hash (init-values (free-vars expr) x)) expr))) truth-values))

(define (eval-form expr)
  (let ([vars (free-vars expr)])
    (let ([truth-values (bool-val-perms (length vars))]) (make-truth-table expr truth-values))))
