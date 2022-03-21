#lang racket


(define empty-set #f)

(define (singleton a)
  (lambda (x)
    (if (equal? a x)
      `(,a)
      empty-set
  )))

(define (in2 s)
  (lambda (el)
  (ormap (lambda (curr) (eq? curr el)) s)))

(define (in a s)
  (ormap (lambda (curr) (eq? curr a)) s))

(define (union s t)
  (lambda (el)
    (or (in el s) (in el t))
  )
)

(define (intersection s t)
  (lambda (el)
    (and (in el s) (in el t))
  )
)