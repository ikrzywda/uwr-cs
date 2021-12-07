#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

void print_arr(int len, double *arr);

typedef struct bqueue {
    unsigned size;
    double *contents;
    double *b, *e;
    int head_popped;
    int tail_popped;
} BQueue;


BQueue *bq_new(unsigned size);
void bq_clear(BQueue *bq);
void bq_print(BQueue *bq);
int bq_fill_blanks(BQueue *q, double el);
int bq_head_push(BQueue *bq, double el);
void bq_head_pop(BQueue *bq, double *ret);
int bq_tail_push(BQueue *bq, double el);
void bq_tail_pop(BQueue *bq, double *ret);
double bq_get_head(BQueue *bq, int direction);
double bq_get_tail(BQueue *bq, int direction);
int bq_is_empty(BQueue *bq);

#endif
