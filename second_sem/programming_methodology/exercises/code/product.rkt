#lang racket

(define (product lst)
    (if (null? lst) 0
        (foldl (lambda (acc curr)
            (* acc curr)
        )
        1
        lst
        )
    )
)
