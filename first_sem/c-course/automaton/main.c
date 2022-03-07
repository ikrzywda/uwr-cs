#include <stdio.h>
#include <stdlib.h>

typedef struct automaton {
    int accst_count;
    int *accst;
    int lett_count;
    int instr_len;
    int **instr;
} Automaton;

void read_to_arr(int *arr, int len) {
    while (len > 0) {
        scanf("%d", arr++);
        --len;
    }
}

Automaton *init(int instr_len, int accst_count, int lett_count) {
    Automaton *a = malloc(sizeof(Automaton));
    a->lett_count = lett_count;
    a->instr_len = instr_len;
    a->accst_count = accst_count;
    a->accst = malloc(accst_count * sizeof(int));
    a->instr = malloc(lett_count * sizeof(int*));
    read_to_arr(a->accst, accst_count);
    for (int i = 0; i < lett_count; ++i) {
        a->instr[i] = malloc(instr_len * sizeof(int));
        read_to_arr(a->instr[i], instr_len);
    }
    return a;
}

int get_result(Automaton *a, char c, int state) {
    return a->instr[c-'a'][state]; 
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int check_state(Automaton *a, int state) {
    for (int i = 0; i < a->accst_count; ++i) {
        if (a->accst[i] == state) return 1;
    }
    return 0;
}

void print_arr(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

void print_automaton(Automaton *a) {
    printf("ACCEPTED STATES:\n");
    print_arr(a->accst, a->accst_count);
    printf("INSTRUCTIONS:\n");
    for (int i = 0; i < a->lett_count; ++i) {
        printf("%c: ", i + 'a');
        print_arr(a->instr[i], a->instr_len);
    }
}

int main() {
    int n,m,a;
    scanf("%d %d %d", &n, &m, &a);
    Automaton *aut = init(n, m, a);
    int test_count, state;
    char c;
    scanf("%d", &test_count);
    while (test_count > 0) {
        scanf("%d", &state); 
        while ((c = getchar()) != '\n') {
            if (c >= 'a' && c <= 'z') {
                state = get_result(aut, c, state);
            }
        }
        printf("%d %s\n", state, (check_state(aut, state)) ? "ACCEPT" : "REJECT");
        test_count--;
    }
}
