#include <stdlib.h>

int camp(const void* a, const void* b) {
    return *(int*)a < *(int*)b;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    qsort(happiness, happinessSize, sizeof(int), camp);
    long long ans = happiness[0];
    for (int p=1; p<k; p++) {
        if (happiness[p] > p) {
            ans += happiness[p] - p;
        } else {
            return ans;
        }
    }
    return ans;
}
