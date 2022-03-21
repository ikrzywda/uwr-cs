#lang racket


(define empty-set #f)

(define (singleton a)
  (lambda (x)
    (if (equal? a x)
      `(,a)
      #f
  )))

(define (in s)
  (lambda (el)
  (ormap (lambda (curr) (eq? curr el)) s)))

(define (union s t)
  (cond [(null? s) t]
        [(in (car s) t)
          (union (rest s) t)]
        [else 
          (cons (car s) (union (rest s) t))])
)

(define (test t s)
(flatten `(,s ,t)))

(define (intersection s t)
  (filter-not (lambda (curr) (and (in curr s) (or (in curr t)))) (union s t))
)