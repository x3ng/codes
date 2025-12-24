#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int sum = 0;
    for (int p=0; p<appleSize; p++) {
        sum += apple[p];
    }
    qsort(capacity, capacitySize, sizeof(int), compare);
    int ans = 0;
    for (int p=0; p<capacity; p++) {
        sum -= capacity[p];
        ans += 1;
        if (sum <= 0) {
            return ans;
        }
    }
    return -1;
}
