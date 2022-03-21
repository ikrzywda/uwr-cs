#lang racket

(define (negatives n)
  (build-list n (lambda (x)
    (- (* x -1) 1))
))

(define (reciprocals n)
  (build-list n (lambda (x)
    (/ 1 (+ x 1))
  ))
)

(define (evens n)
  (build-list n (lambda (x)
    (* 2 x)
  ))
)

(define (identity n)
  (build-list n (lambda (x)
    (build-list n (lambda (z)
      (if (equal? z x) 1 0)
    ))
  ))
)