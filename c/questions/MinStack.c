#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int st[30000][2] = {{0, INT_MAX}};

typedef struct {
  int top;
} MinStack;

MinStack* minStackCreate() {
  MinStack* obj = malloc(sizeof(MinStack));
  obj->top = 0;
  return obj;
}

void minStackPush(MinStack* obj, int val) {
  obj->top++;
  st[obj->top][0] = val;
  st[obj->top][1] = MIN(val, st[obj->top-1][1]);
}

void minStackPop(MinStack* obj) {
  obj->top--;
}

int minStackTop(MinStack* obj) {
  return st[obj->top][0];
}

int minStackGetMin(MinStack* obj) {
  return st[obj->top][1];
}

void minStackFree(MinStack* obj) {
  free(obj);
}
