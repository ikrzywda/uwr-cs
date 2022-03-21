#lang racket


(define empty-set '())

(define (singleton a)
  `(,a)
)

(define (in a s)
  (ormap (lambda (curr) (eq? curr a)) s)
)

(define (union s t)
  (cond [(null? s) t]
        [(in (car s) t)
          (union (rest s) t)]
        [else 
          (cons (car s) (union (rest s) t))])
)