// You are given an array of positive and negative integers. If a number n at an index is positive, then move forward n steps. Conversely, if it's negative (-n), move backward n steps. Assume the first element of the array is forward next to the last element, and the last element is backward next to the first element. Determine if there is a loop in this array. A loop starts and ends at a particular index with more than 1 element along the loop. The loop must be "forward" or "backward'.
//
// Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 -> 2 -> 3 -> 0.
//
// Example 2: Given the array [-1, 2], there is no loop.
//
// Note: The given array is guaranteed to contain no element "0".
//
// Can you do it in O(n) time complexity and O(1) space complexity?
//


class Solution {
private:
    inline int abs(int i) {
        return i>0?i:(0-i);
    }

    int getIndex(int index, int len) {
        if(index < 0)
            return getIndex(index + len, len);
        else if(index < len)
            return index;
        else
            return getIndex(index - len, len);
    }
    
public:
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        for(int cur = 0; cur < len; cur++) {
            bool sign = nums[cur] > 0;
            int p = cur;
            if(abs(nums[cur]) == len)
                continue;
            while (true) {
                int i1 = getIndex(p, len);
                p += nums[i1];
                int i2 = getIndex(p, len);
                if(i1 == i2)
                    break;
                int c = nums[i2];
                bool s = c > 0;
                if(s != sign)
                    break;
                if(i2 == cur)
                    return true;
            }
        }
        return false;
    }
};
