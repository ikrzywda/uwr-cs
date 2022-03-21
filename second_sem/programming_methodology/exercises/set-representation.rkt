#lang racket


(define empty-set #f)

(define (singleton a)
  (lambda (x)
    (if (equal? a x)
      `(,a)
      empty-set
  )))

(define (in s)
  (lambda (el)
  (ormap (lambda (curr) (eq? curr el)) s)))

(define (union s t)
  (define in-s (in s))
  (define in-t (in t))
  (lambda (el)
    (or (in-s el) (in-t el))
  )
)

(define (intersection s t)
  (define in-s (in s))
  (define in-t (in t))
  (lambda (el)
    (and (in-s el) (in-t el))
  )
)