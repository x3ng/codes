int fourDivisorsSum(int num) {
    if (num < 6) {
        return 0;
    }
    int sqrt_num = (int)sqrt(num);
    if (num == sqrt_num * sqrt_num) {
        return 0;
    }
    int sum = num+1;
    for (int n=2; n<=sqrt_num; n++) {
        if (num%n == 0) {
            if (sum == num+1) {
                sum += num/n+n;
            } else {
                return 0;
            }
        }
    }
    return sum==num+1 ? 0 : sum;
}

int sumFourDivisors(int* nums, int numsSize) {
    int ans = 0;
    for (int p=0; p<numSize; p++) {
        ans += fourDivisorsSum(nums[p]);
    }
    return ans;
}
