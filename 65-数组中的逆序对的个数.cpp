#define N 110
int t[N];
int res = 0;

int merge(int* nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + r >> 1;
    merge(nums, l, m);
    merge(nums, m+1, r);
    int i = l, j = m+1, k = 0;
    while (i <= m && j <= r) {
        if (nums[i] <= nums[j]) {
            t[k++] = nums[i++];
        } else {
            res += (m-i+1);
            t[k++] = nums[j++];
        }
    }
    while (i <= m) {
        t[k++] = nums[i++];
    }
    while (j <= r) {
        t[k++] = nums[j++]; 
    }
    for (int i = l, k = 0; i <= r; i++, k++) {
        nums[i] = t[k];
    }
    
}

int inversePairs(int* nums, int numsSize) {
    merge(nums, 0, numsSize-1);
    return res;
}