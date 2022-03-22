#lang racket

(define (product lst)
    (if (null? lst) 0
        (foldl * 1 lst)))
