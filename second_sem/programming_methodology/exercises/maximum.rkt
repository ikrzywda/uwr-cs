#lang racket

(define (maximum lst)
    (foldl (lambda (max lst)
        (if (<= max lst) lst max)
    )
    -inf.0
    lst
    )
)
