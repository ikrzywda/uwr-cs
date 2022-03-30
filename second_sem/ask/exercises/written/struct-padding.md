## Padding of structs

1. each field has to start at an address that is a multiple of its size
2. padding is done before any given field
3. the size of the whole struct has to be a multiple of the size of its biggest field

### Takeaway:

Arranging fields in a way such that the least amount of padding is needed may yield
smaller struct sizes:

```
struct A {              // offsets:
    int8_t a;           // 0
    char padding_1[7];  // 
    void *b;            // 8
    int8_t c;           // 9
    char padding_2;     
    int16_t d;          // 10
    char padding[4];
};
```

Struct A is 24 bytes

```
struct C {              // offsets:
    int8_t a;
    int8_t c; 
    int16_t d;
    char padding[4];
    void *b;
};
```
whereas Struct C is 16 bytes

## volatile keyword:

Signals to the compiler that a variable may be changed by other means than the code itself
f.e. IO hardware that has access to the memory of the program --- signaling that a variable will
be externally mutated


## static keyword:

* local variable: the variable will preserve its value across funciton calls (f.e. strtok)
* global variable: restricts the variable to the file it has been declared in
* function: restricts the use of a function to the file it has been declared in

## restrict keyword:

Promise that a section of memory will only be accessed through a pointer declared with 'restrict' keyword.
It allows for optimising away additional loadings of memory pointed to by a pointer.

## C code to TAC

```s += b[j+1] + b[--j];```
```
    sc := s
    i1 := j + 1
    i1 := 8 * i1
    b1 := b[i1]
    i2 := j - 1
    i2 := 8 * i2
    b2 := b[i2]
    sc := b1 + b2
```

```a[i++] -= *b * (c[j*2] + 1);```
```
    ia := i + 1
    ia := 8 * ia
    a := a + ia
    a := &a
    ic := j * 16
    c := j[ic]
    c := c + 1
    db := *b
    pr := db * c
    *a := pr
```

``` vs->d = us[1].a + us[j].c;```
```
    vsd := vs + 18
    us1 := us + 24
    us2 := us + 40
    *vsd := *us1 + *us2
```