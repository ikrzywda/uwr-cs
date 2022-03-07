#lang racket

(define (my-if if then else)
    (and (or if else) then))