#define _POSIX_C_SOURCE 199309L
#include "../stack.h"
#include <time.h>
#include <stdio.h>

static double now_sec() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec * 1e-9;
}

int main(void) {
    const int N = 1000000;
    Stack s;
    initStack(&s);

    double t1 = now_sec();
    for (int i = 0; i < N; ++i) push(&s, i);
    double t2 = now_sec();
    for (int i = 0; i < N; ++i) {
        int v;
        pop(&s, &v);
    }
    double t3 = now_sec();

    printf("push %d ops in %.6f s -> %.0f ops/s\n", N, t2 - t1, N / (t2 - t1));
    printf("pop  %d ops in %.6f s -> %.0f ops/s\n", N, t3 - t2, N / (t3 - t2));

    destroyStack(&s);
    return 0;
}
