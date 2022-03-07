#lang racket/gui

(define win-height 800)
(define win-width 200)
(define rocket-width 30)
(define rocket-height 70)

(define rocket-pos-x (/ (- win-width rocket-width) 2))
(define (comptute-rocket-pos-y a t)
    (let ([offset (/ (* a t t) 2)])
        (+ (- win-height - rocket-height) offset)))
(define rocket-pos-y 0)

(define frame (new frame% [label "Rocket"] [width 500] [height 500]))
(define canvas (new canvas% [parent frame]
                    [paint-callback
                     (λ (c dc)
                       (send dc set-brush "blue" 'solid)
                       (send dc clear)
                       (send dc draw-rectangle rocket-pos-x rocket-pos-y rocket-width rocket-height))]))
(send frame show #t)

(define animation-time 0)

(define (loop)
  (send canvas on-paint)
  (set! animation-time (+ animation-time 0.02))
  (set! rocket-pos-y (comptute-rocket-pos-y 10 animation-time))
  (sleep/yield 0.02)
  (loop))

(loop)