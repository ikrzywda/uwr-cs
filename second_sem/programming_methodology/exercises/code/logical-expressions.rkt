#lang plait

(define-type Prop
             (var [v : String])
             (conj [l : Prop] [r : Prop])
             (disj [l : Prop] [r : Prop])
             (neg [f : Prop]))

(define (remove-duplicates lst)
  (foldr (lambda (x y) (cons x (filter (lambda (z) (not (string=? x z))) y))) empty lst))

(define (free-vars t)
  (remove-duplicates (cond
                       [(var? t) (cons (var-v t) empty)]
                       [(neg? t) (free-vars (neg-f t))]
                       [(conj? t) (append (free-vars (conj-l t)) (free-vars (conj-r t)))]
                       [(disj? t) (append (free-vars (disj-l t)) (free-vars (disj-r t)))])))

(define (eval-var val-hash prop)
  :
  Boolean
  (if (var? prop) (some-v (hash-ref val-hash (var-v prop))) #f))

(define (eval-prop vals expr)
  :
  Boolean
  (cond
    [(var? expr) (eval-var vals expr)]
    [(neg? expr) (not (eval-var vals (neg-f expr)))]
    [(conj? expr) (and (eval-prop vals (conj-l expr)) (eval-prop vals (conj-r expr)))]
    [(disj? expr) (or (eval-prop vals (disj-l expr)) (eval-prop vals (disj-r expr)))]))

(define (init-values variables truth-values)
  (map2 (λ (sym val) (pair sym val)) variables truth-values))

(define (permutation-of-lists n)
  (if (= 1 n)
      '((#t) (#f))
      (append (map (λ (p) (cons #t p)) (permutation-of-lists (sub1 n)))
              (map (λ (p) (cons #f p)) (permutation-of-lists (sub1 n))))))

(define (check-tautology expr truth-values)
  (cond
    [(empty? truth-values) #t]
    [(eval-prop (make-hash (init-values (free-vars expr) (first truth-values))) expr)
     (check-tautology expr (rest truth-values))]
    [else #f]))

(define (tautology? expr)
  (let ([vars (free-vars expr)])
    (let ([truth-values (permutation-of-lists (length vars))]) (check-tautology expr truth-values))))

;; TESTS

(define test-vals (make-hash (list (pair "x" #f) (pair "y" #t))))

(define test-expr-neg (neg (var "x")))

(define test-expr-conj-t (conj (var "x") (var "y")))
(define test-expr-disj-t (disj (var "x") (var "y")))
(define tatuto (disj (var "x") (neg (var "x"))))

(eval-prop test-vals test-expr-neg)

(eval-prop test-vals test-expr-conj-t)
(eval-prop test-vals test-expr-disj-t)

(tautology? test-expr-conj-t)
(tautology? tatuto)
