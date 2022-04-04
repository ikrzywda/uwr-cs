``` (define (apply f x) (f x)) ```

```(('a -> 'b) -> 'a -> b)``` - procedure f is wrapped inside apply

```(define (compose f g) (lambda (x)  (f (g x))))```

``` (('a -> 'b) ('c -> 'a) -> ('c -> 'b))``` - provided argument 'c, function
g returns 'a, which is used by f that returns 'b

```(define (flip f) (lambda (x y) (f y x)))```

``` (('a 'b -> 'c) 'b 'a -> 'c) ``` - f is a function that takes two arguments and
is immediately applied


```(define ( curry f ) ( lambda ( x ) ( lambda ( y ) ( f x y ) ) ) )```

``` ('a 'b -> 'c)) -> ('a -> ('b -> 'c))``` - f is a function that takes a function
and any type