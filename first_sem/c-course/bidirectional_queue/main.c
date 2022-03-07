#include "queue.h"

int main() {
    double a;
    BQueue *bq = bq_new(4);
    bq_tail_push(bq, 10);
    bq_tail_push(bq, 20);
    bq_tail_push(bq, 30);
    bq_tail_pop(bq, &a);
    bq_tail_pop(bq, &a);
    bq_print(bq);
    printf("%.2f %.2f\n", bq_get_head(bq, 1), bq_get_head(bq, 0));
    printf("%.2f %.2f\n", bq_get_tail(bq, 1), bq_get_tail(bq, 0));
}
