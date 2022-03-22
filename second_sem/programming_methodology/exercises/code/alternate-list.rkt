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
  (define (f v l)
    (cond
      [(null? (l)) llist-null]
      [else (llist-append (list->llist (fun v (car (l)))) (foldr-llist v (list->llist (rest (l)))))]
    )
  )
  (f 3 list)
)
