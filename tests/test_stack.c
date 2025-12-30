#include "../stack.h"
#include <assert.h>
#include <stdio.h>

static void test_push_pop() {
    Stack s;
    initStack(&s);
    assert(isEmpty(&s));
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    assert(!isEmpty(&s));

    int v;
    assert(pop(&s, &v) && v == 3);
    assert(pop(&s, &v) && v == 2);
    assert(pop(&s, &v) && v == 1);
    assert(!pop(&s, &v));
    destroyStack(&s);
}

static void test_search_by_value_and_index() {
    Stack s;
    initStack(&s);
    push(&s, 100);
    push(&s, 200);
    push(&s, 300);

    Node* n = searchByValue(&s, 200);
    assert(n != NULL && n->data == 200);

    Node* n0 = searchByIndex(&s, 0);
    Node* n1 = searchByIndex(&s, 1);
    Node* n2 = searchByIndex(&s, 2);
    assert(n0 && n0->data == 300);
    assert(n1 && n1->data == 200);
    assert(n2 && n2->data == 100);

    assert(searchByIndex(&s, -1) == NULL);
    destroyStack(&s);
}

static void test_traverse_and_isEmpty() {
    Stack s;
    initStack(&s);
    push(&s, 7);
    assert(!isEmpty(&s));
    destroyStack(&s);
    assert(isEmpty(&s));
}

int main(void) {
    test_push_pop();
    test_search_by_value_and_index();
    test_traverse_and_isEmpty();
    printf("All tests passed\n");
    return 0;
}
