#lang racket

(define (matrix a b c d))

;  a b
;  c d

(define (matrix-mult m n)
    (let ([k (matrix 0 0 0 0)])
        (set! k-a (+ (* m-a n-a) (* m-c n-c)))
        (set! k-b (+ (* m-a n-b) (* m-c n-d)))
        (set! k-a (+ (* m-a n-a) (* m-b n-d)))
        (set! k-a (+ (* m-a n-a) (* m-b n-d)))
    )
)