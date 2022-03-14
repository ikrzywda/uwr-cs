#lang racket


(define (suffixes xs)
    (let ([out '()])
        (for ([i (in-range (+ (length xs) 1))])
            (set! out (append out (list (list-tail xs i))))
        )
        out
    )
)