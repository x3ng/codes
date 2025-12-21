#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define INIT_CAPACITY 16
#define EXPAND_FACTOR 2

typedef struct {
  int* value;
  int capacity;
  int top;
} Stack;

Stack* StackCreate() {
  Stack* obj = (Stack*) malloc(sizeof(Stack));
  if (obj == NULL) {
    fprintf(stderr, "create failed");
    return NULL;
  }
  obj->value = (int*) malloc(sizeof(int) * INIT_CAPACITY);
  if (obj->value == NULL) {
    fprintf(stderr, "create failed");
    free(obj);
    return NULL;
  }
  obj->top = 0;
  obj->capacity = INIT_CAPACITY;
  return obj;
}

static int StackExpand(Stack* st) {
  if (st == NULL) {
    fprintf(stderr, "null pointer");
    return 0;
  }
  int new_cap = st->capacity * EXPAND_FACTOR;
  int* new_val = (int*) realloc(st->value, sizeof(int)*new_cap);
  if (new_val == NULL) {
    return 0;
  }
  st->value = new_val;
  st->capacity = new_cap;
  return 1;
}

void StackPush(Stack* st, int val) {
  if (st == NULL) {
    fprintf(stderr, "null pointer");
    return;
  }
  if (st->top == st->capacity) {
    if (!StackExpand(st)) {
      fprintf(stderr, "expand failed");
      return;
    }
  }
  st->value[st->top] = val;
  st->top++;
}

int StackPop(Stack* st) {
  if (st == NULL) {
    fprintf(stderr, "null pointer");
    return -1;
  }
  if (st->top == 0) {
    fprintf(stderr, "empty stack");
    return -1;
  }
  return st->value[st->top--];
}

int StackTop(Stack* st) {
  if (st == NULL) {
    fprintf(stderr, "null pointer");
    return -1;
  }
  if (st->top == 0) {
    fprintf(stderr, "empty stack");
    return -1;
  }
  return st->value[st->top-1];
}

void StackFree(Stack* st) {
  if (st == NULL) {
    return;
  }
  free(st->value);
  free(st);
}
