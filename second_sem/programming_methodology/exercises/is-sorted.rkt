#lang racket

(define (is-sorted lst)
    (andmap > (append lst (list +inf.0)) (append (list -inf.0) lst))
)