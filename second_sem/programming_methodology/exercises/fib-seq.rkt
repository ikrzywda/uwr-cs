#lang racket

(define (fib n)
    (cond 
        [(= n 1) 1]
        [(= n 0) 0]
        [else (+ (fib (- n 1)) (fib (- n 2)))]
    )
)

(define (fib-iter n)
    (let ([a 0] [b 1] [c 0])
        (for ([i (in-range n)])
            (set! c b)
            (set! b (+ a b))
            (set! a c)
        )
    b)
)