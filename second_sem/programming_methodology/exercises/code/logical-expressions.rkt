#lang plait

(define-type Prop
             (var [v : String])
             (conj [l : Prop] [r : Prop])
             (disj [l : Prop] [r : Prop])
             (neg [f : Prop]))

(define s (conj (var "x") (var "x")))

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

;; TESTS

(define test-vals (make-hash (list (pair "x" #f) (pair "y" #t))))

(define test-expr-neg (neg (var "x")))

(define test-expr-conj-t (conj (var "x") (var "y")))
(define test-expr-disj-t (disj (var "x") (var "y")))

(eval-prop test-vals test-expr-neg)

(eval-prop test-vals test-expr-conj-t)
(eval-prop test-vals test-expr-disj-t)
