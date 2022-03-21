#lang racket


(define (elem? x xs)
    (cond
        [(empty? xs) #f]
        [(= x (first xs)) #t]
    [else (elem? x (rest xs))]
    )
)