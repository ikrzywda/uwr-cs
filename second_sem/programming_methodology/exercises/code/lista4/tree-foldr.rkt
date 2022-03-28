;; ex. 2

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
                                (node (leaf) 5 (leaf)))))

(define t2 (node (node (leaf) 1 (leaf))
                          2
                          (node (node (node (leaf) 7 (node (leaf) 8 (leaf))) 3 (leaf))
                                4
                                (node (leaf) 5 (node (leaf) 6 (leaf))))))

(check-true (tree? example-tree))

(define (tree-height x)
  (cond [(leaf? x) 0]
        [(node? x) (+ 1 (max (tree-height (node-l x))
                              (tree-height (node-r x))))]
        [else -1]))

; (define (my-foldr f x xs)
;   (if (null? xs)
;       x
;       (f (car xs) (my-foldr f x (cdr xs)))))

;zad 2
(define (fold-tree fun acc nd)
  (if (leaf? nd)
      acc
      (fun (fold-tree fun acc (node-r nd)) (node-elem nd) (fold-tree fun acc (node-l nd)))))

;(f (node-elem d) (f (fold-tree f x (node-l d)) (fold-tree f x (node-r d))))))

(define (tree-sum t)
  (fold-tree + 0 t))

(define (tree-flip t)
  (fold-tree node (leaf) t))


; (define (tree-height t)
;   (fold-tree (lambda (accr x accl)
;       (+ 1 (if (> accr accl)
;         accr
;         accl))) 0 t))

(define (tree-span t)
  (cons (fold-tree (lambda (a b c) (if (leaf?  c)
                                              b
                                              c)) (leaf) (node-l t))
        (fold-tree (lambda (a b c) (if (leaf?  a)
                                              b
                                              a)) (leaf) (node-r t))))

; to nie dziala
(define (flatten-tree t)
  (define out (fold-tree (lambda (a b c) (if (leaf?  c)
                                (cons b a)
                                (cons b (cons c a)))) null t))
  (flatten out)
)


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