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
  (cond [(var? expr) (nnf-lit #t (var-var expr))]
        [(neg? expr) (negate-nnf (to-nnf (neg-f expr))) ]
        [(conj? expr) (nnf-conj (to-nnf (conj-l expr)) (to-nnf (conj-r expr))) ]
        [(disj? expr) (nnf-disj (to-nnf (disj-l expr)) (to-nnf (disj-r expr))) ]))


