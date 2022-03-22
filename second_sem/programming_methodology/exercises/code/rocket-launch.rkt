#lang racket/gui

(define win-height 800)
(define win-width 200)
(define rocket-width 30)
(define rocket-height 70)

(define rocket-pos-x (/ (- win-width rocket-width) 2))
(define (compute-rocket-pos-y a t)
    (- (- win-height rocket-height) (/ (* a t t) 2)))
(define rocket-pos-y 0)

(define time 0)

(define countdown 3)

(define frame (new frame% [label "Frame"] [width win-width] [height win-height]))
(define canvas (new canvas% [parent frame]
                    [paint-callback
                     (λ (c dc)
                       (send dc set-pen "red" 4 'solid)
                       (send dc clear)
                       (send dc draw-rectangle rocket-pos-x (compute-rocket-pos-y 10 time) rocket-width rocket-height)
                       (send dc set-text-foreground "red")
                       (send dc draw-text (number->string countdown) 0 0))]))
(send frame show #t)

(define time-delta 0)
(define sleep-time 1)


(define (rocket-launch)
    (send canvas on-paint)
    (set! countdown (if (> countdown 0) (- countdown 1) 0))
    (set! sleep-time (if (> countdown 0) 1 0.02))
    (set! time-delta (if (= countdown 0) 0.02 0))
    (set! time (+ time time-delta))
    (sleep/yield sleep-time)
)

(define (loop)
  (rocket-launch)
  (loop))

(loop)