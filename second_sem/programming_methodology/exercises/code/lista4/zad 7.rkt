#lang racket

;zad 7
(define eq ; pusta kolejka
  (cons null (cons null null)))

(define (empty? q) ; czy kolejka jest pusta ?
 (null? (car q)))

(define (pb x q)
  (if (null? (car q))
  (cons (cons x (car q)) (cdr q))
  (cons (car q) (cons (cons x (car (cdr q))) null))))

(define (front q)
  (caar q))

(define (reverse xs)
  (foldl cons null xs))

(define (pop q)
  (if (null? (cdr (car q)))
      (cons (reverse (car (cdr q))) (cons null null))
      (cons (cdr (car q)) (cdr q))))

(define q1 (pb 2 (pb 1 (pb 1 eq))))




(define (push-back x q) ; dodaj element na koniec kolejki
 (append q (list x)))


