```
    ((lambda (x y) (+ x (* x y))) 1 2) -> (+ 1 (* 1 3)) -> 3
    ((lambda (x) x) (lambda (x) x )) -> (lambda (x) x)
    ((lambda (x) (x x)) (lambda (x) x)) -> ((lambda (x) x) (lambda (x) x)) -> (lambda (x) x)
    ((lambda (x) (x x)) (lambda (x) (x x))) -> ((lambda (x) (x x)) (lambda (x) (x x))) ... 
```