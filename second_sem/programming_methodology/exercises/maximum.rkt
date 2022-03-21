#lang racket

(define (maximum lst)
    (foldl (lambda (max elem)
        (if (<= max elem) elem max)
    )
    -inf.0
    lst
    )
)
