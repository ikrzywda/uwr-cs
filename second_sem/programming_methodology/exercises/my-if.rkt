#lang racket

; not lazy
(define (my-if if then else)
    (and (or if else) then))