#lang racket

(define (my-compose foo bar)
  (lambda (x) (foo (bar x)))
)