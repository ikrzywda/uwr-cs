#lang racket

(define (list->llist lst)
  (lambda ([l '()]) 
    (append lst l)))

(define (llist->list lst) (lst))

(define llist-null (list->llist '()))

(define (llist-singleton a) 
  (list->llist `(,a)))

(define (llist-append l1 l2)
  (list->llist (l1 (l2)))
)

(define (foldr-llist fun list)
  (define (foldr-llist-impl f v l)
    (llist-append (f (car (l)) (foldr-llist-impl (f (rest (l))))))
  )
  (foldr-llist-impl fun 0 list))
