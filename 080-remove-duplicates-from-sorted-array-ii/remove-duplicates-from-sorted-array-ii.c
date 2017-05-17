// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
//
//
// For example,
// Given sorted array nums = [1,1,1,2,2,3],
//
//
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.


int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int placer = 1;
    int pointer = 1;
    int counter = 1;
    int current = nums[0];
    while (pointer < numsSize) {
        if (nums[pointer] == current)
            counter++;
        else {
            current = nums[pointer];
            counter = 1;
        }
        if (counter <= 2) {
            nums[placer] = nums[pointer];
            placer++;
        }
        pointer++;
    }
    return placer;
}
