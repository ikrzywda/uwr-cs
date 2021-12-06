#include "queue.h"

void print_arr(int len, double *arr) {
    for (int i = 0; i < len; ++i) {
        printf("%.2f ", arr[i]);
    }
    putchar('\n');
}

BQueue *bq_new(unsigned size) {
    BQueue *bq = malloc(sizeof(BQueue));
    bq->size = size;
    bq->contents = calloc(size, sizeof(double));
    bq->b = bq->contents - 1;
    bq->e = (bq->contents + size);
    bq->head_popped = 0;
    bq->tail_popped = 0;
    return bq;
}

void bq_clear(BQueue *bq) {
    for (int i = 0; i < bq->size; ++i) {
        bq->contents[i] = 0; 
    }
}

void bq_print(BQueue *bq) {
    printf("size: %d\ncontents:\n", bq->size);
    print_arr(bq->size, bq->contents);
}

int bq_fill_blanks(BQueue *bq, double el) {
    if (bq->head_popped) {
        bq->contents[bq->size-1] = el;
        bq->head_popped = 0;
        return 1;
    } else if (bq->tail_popped) {
        bq->contents[0] = el;
        bq->tail_popped = 0;
        return 1;
    }
    return 0;
}

int bq_head_push(BQueue *bq, double el) {
    if (bq_fill_blanks(bq, el)) return 1;
    if (bq->e - bq->b >= 0) {
        *(--bq->e) = el;
        return 1;
    }
    return 0;
}

void bq_head_pop(BQueue *bq, double *el) {
    if (bq->head_popped) {
        *el = bq->contents[bq->size-1];
        for (int i = bq->size - 2; i < (bq->contents - bq->e); ++i) {
            bq->contents[i] = bq->contents[i-1];
        }
        *(bq->b--) = 0;
    } else {
        *el = bq->contents[0];
        bq->contents[0] = 0;
        bq->tail_popped = 1;
    }
}

int bq_tail_push(BQueue *bq, double el) {
    if (bq_fill_blanks(bq, el)) return 1;
    if (bq->e - bq->b >= 0) {
        *(++bq->b) = el;
        return 1;
    }
    return 0;
}

void bq_tail_pop(BQueue *bq, double *el) {
    if (bq->tail_popped) {
        *el = bq->contents[1];
        for (int i = 1; i < (bq->b - bq->contents); ++i) {
            bq->contents[i] = bq->contents[i+1];
        }
        *(bq->b--) = 0;
    } else {
        *el = bq->contents[0];
        bq->contents[0] = 0;
        bq->tail_popped = 1;
    }
}

double bq_get_head(BQueue *bq, int direction) {
    if (direction) {
        return bq->contents[bq->size - 1];
    } else {
        return bq->contents[0];
    }
}

double bq_get_tail(BQueue *bq, int direction) {
    if (direction) {
        return *bq->e;
    } else {
        return *bq->b;
    }
}

int bq_is_empty(BQueue *bq) {return 0;}
