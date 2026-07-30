function removeElement(nums: number[], val: number): number {
    let r = 0;
    for (let p=0; p<nums.length; ++p) {
        if (nums[p] != val) {
            nums[r] = nums[p];
            r++;
        }
    }
    return r;
};
