#lang racket

(define (sq x) (* x x))

(define (square-biggest-args x y z)
    (let ([args-list (sort (list x y z) >)])
        (+ (sq (first args-list)) (sq (second args-list)))))