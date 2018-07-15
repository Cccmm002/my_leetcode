// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Example 1:
//
//
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
//
//
// Example 2:
//
//
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.
//


int partition(int* nums, int begin, int end) {
    if (begin == end) return begin;
    int pivot = nums[end];
    int store = begin;   // The first element after number block smaller than pivot
    for (int i = begin; i < end; ++i) {
        if (nums[i] < pivot) {  //swap nums[i] and nums[store]
            int swap = nums[i];
            nums[i] = nums[store];
            nums[store] = swap;
            ++store;
        }
    }
    //swap nums[store] and nums[end]
    nums[end] = nums[store];
    nums[store] = pivot;
    return store;
}

int kth(int *nums, int begin, int end, int k) {
    if (begin == end) return nums[begin];
    int pivot = partition(nums, begin, end);
    if (pivot == k) return nums[k];
    else if (k < pivot) return kth(nums, begin, pivot - 1, k);
    else return kth(nums, pivot + 1, end, k);
}

int findKthLargest(int* nums, int numsSize, int k) {
    if (numsSize == 1) return nums[0];
    return kth(nums, 0, numsSize - 1, numsSize - k);
}
