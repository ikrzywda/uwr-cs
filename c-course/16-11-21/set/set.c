/*
 *  Igor Krzywda
 *  Lista 4, zadanie 1
 */
#include "set.h"

void read_set(Set s) {
    int n, i = 1, d;
    scanf("%d %d", &n, &s[i]);
    while (i < n) {
        scanf("%d", &d);
        if (d > s[i]) {
            s[++i] = d;
        } else {
            printf("Set values are not rising. Omitting %d\n", d);
            --n;
        }
    }
    s[0] = n;
}

void print_set(Set s) {
    int n = s[0];
    printf("SIZE: %d\n{", s[0]);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", s[i]);
    }
    printf("}\n");
}

void set_union(const Set s, const Set t, Set out) {
    int ls = 1, lt = 1;
    int i = 0, diff;
    while (ls <= s[0] && lt <= t[0]) {
        diff = s[ls] - t[lt];
        if (diff == 0) {
            out[++i] = s[ls];
            ++ls; ++lt;
        } else if (diff > 0) {
            out[++i] = t[lt++];
        } else {
            out[++i] = s[ls++];
        }
    }
    if (ls > s[0]) {
        for (; lt <= t[0]; out[++i] = t[lt++]);
    } else if (lt > t[0]) {
        for (; ls <= s[0]; out[++i] = s[ls++]);
    }
    out[0] = i;
}


void set_sym_diff(const Set s, const Set t, Set out) {
    int ls = 1, lt = 1;
    int i = 0, diff;
    while (ls <= s[0] && lt <= t[0]) {
        diff = s[ls] - t[lt];
        if (diff == 0) {
            ++ls; ++lt;
        } else if (diff > 0) {
            out[++i] = t[lt++];
        } else {
            out[++i] = s[ls++];
        }
    }
    if (ls > s[0]) {
        for (; lt <= t[0]; out[++i] = t[lt++]);
    } else if (lt > t[0]) {
        for (; ls <= s[0]; out[++i] = s[ls++]);
    }
    out[0] = i;
}

void clear_set(Set s) {
    s[0] = 0;
}

int search_set(Set s, int min, int max, int el) {
    int i;
    if (min <= max) {
        i = (min + max) / 2;
        if (s[i] == el) {
            return i;
        } else if (s[i] < el) {
            return search_set(s, i + 1, max, el);
        } else {
            return search_set(s, min, i - 1, el); 
        }
    } 
    return -1;
}

void add_to_set(int el, Set s) {
    int i = 0, t;
    if (search_set(s, 1, s[0], el) > 0 || s[0] == MAX_SET_SIZE) {
        return;
    }
    if (el > s[s[0]]) {
        s[++s[0]] = el;
        return;
    } else if (el < s[1]) {
        i = 1;  
    } else {
        for (i = s[0]; i > 1 && (s[i] < el || s[i-1] > el); --i);
    }
    for (int j = s[0] + 1; j > i; --j) {
        t = s[j-1];
        s[j-1] = s[j];
        s[j] = t;
    }
    s[i] = el;
    ++s[0];
}

void remove_from_set(int el, Set s) {
    int i, t;
    if ((i = search_set(s, 1, s[0], el)) < 0 || s[0] == MAX_SET_SIZE) {
        return;
    }
    for (int j = i; j < s[0]; ++j) {
        t = s[j+1];
        s[j+1] = s[j];
        s[j] = t;
    }
    --s[0];
}
