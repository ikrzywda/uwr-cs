#lang racket

(require rackunit)

(define-struct leaf () #:transparent)
(define-struct node (l elem r) #:transparent)

(define (tree? x)
  (cond [(leaf? x) #t]
        [(node? x) (and (tree? (node-l x)) (tree? (node-r x)))]
        [else #f]))

(define example-tree (node (node (leaf) 1 (leaf))
                           2
                           (node (node (leaf) 3 (leaf))
                                 4
                                 (node (leaf) 5 (node (leaf) 6 (leaf))))))

(define t2 (node (node (leaf) 1 (leaf))
                           2
                           (node (node (node (leaf) 7 (node (leaf) 8 (leaf))) 3 (leaf))
                                 4
                                 (node (leaf) 5 (node (leaf) 6 (leaf))))))

(check-true (tree? example-tree))

;zad 2
(define (fold-tree f x d)
  (if (leaf? d)
      x
      (f (fold-tree f x (node-r d)) (node-elem d) (fold-tree f x (node-l d)))))

(define (tree-sum t)
  (fold-tree + 0 t))

(define (tree-flip t)
  (fold-tree node (leaf) t))


(define (tree-height t)
  (fold-tree (lambda (accr x accl)
      (+ 1 (if (> accr accl)
             accr
             accl))) 0 t))

(define (tree-span t)
  (cons (fold-tree (lambda (a b c) (if (leaf?  c)
                                              b
                                              c)) (leaf) (node-l t))
        (fold-tree (lambda (a b c) (if (leaf?  a)
                                              b
                                              a)) (leaf) (node-r t))))

(define (flatten t)
  (fold-tree (lambda (x y z) (append z (list y) x)) '() t))

;zad 3
(define (sorted? xs)
  (cond [(null? (cdr xs)) #t]
        [(<= (car xs) (car (cdr xs))) (sorted? (cdr xs))]
        [else #f])
  )

(define (bst? t)
  (sorted? (flatten t)))

;dodać let
(define (sum-paths t)
  (define (sum t acc)
    (if (leaf? t)
        (leaf)
        (node
         (sum (node-l t) (+ acc (node-elem t)))
         (+ acc (node-elem t))
         (sum (node-r t) (+ acc (node-elem t))))))
    (sum t 0))
  

(define (flatten2 t)
  (if (leaf? t)
      '()
      (append (flatten2 (node-l t)) (list (node-elem t))  (flatten2 (node-r t)))))

;zad 5
(define (insert-bstM x t)
  (cond [(leaf? t) (node (leaf) x (leaf))]
        [(node? t)
         (cond [(= x (node-elem t))
                (node
                 (node
                  (node-l t)
                  (node-elem t)
                  (leaf))
                 (node-elem t)
                 (node-r t))]
               [(< x (node-elem t))
                (node
                 (insert-bstM x (node-l t))
                 (node-elem t)
                 (node-r t))]
               [else
                (node
                 (node-l t)
                 (node-elem t)
                 (insert-bstM x (node-r t)))])]))

(define (travel xs t)
     (if (null? xs)
         t
         (travel (cdr xs) (insert-bstM (car xs) t))))

(define (treesort xs)
 (flatten
   (travel xs (leaf))))

;zad 6

(define (minValue t)
  (if (leaf? (node-l t))
      (node-elem t)
      (minValue (node-l t))))

;dodac let
(define (delete x t)
  (cond [(leaf? t) (leaf)]
        [(node? t)
         (cond [(= x (node-elem t))
                (cond [(and (leaf? (node-r t)) (leaf? (node-l t)) (leaf))]
                      [(and (not (leaf? (node-r t))) (leaf? (node-l t)) (node-r t))]
                      [(and (leaf? (node-r t)) (not (leaf? (node-l t))) (node-l t))]
                      [else (node
                             (node-l t)
                             (minValue (node-r t))
                             (delete (minValue (node-r t)) (node-r t))
                             )])]
               [(< x (node-elem t))
                (node
                 (delete x (node-l t))
                 (node-elem t)
                 (node-r t))]
               [else
                (node
                 (node-l t)
                 (node-elem t)
                 (delete x (node-r t)))])]))

; inna wersja tree height

(define (tree-height2 t)
  (if (leaf? t)
      0
      (let ([r (tree-height2 (node-r t))]
             [l (tree-height2 (node-l t))])
      (+ 1
         (if (> r l)
             r
             l)))))

; ((let [r (tree-height node-r)]
          ; [l (tree-height node-l)])