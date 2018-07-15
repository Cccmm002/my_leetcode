// You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists. 
//
// We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.
//
// Example 1:
//
// Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
// Output: [20,24]
// Explanation: 
// List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
// List 2: [0, 9, 12, 20], 20 is in range [20,24].
// List 3: [5, 18, 22, 30], 22 is in range [20,24].
//
//
//
//
// Note:
//
// The given list may contain duplicates, so ascending order means >= here.
// 1 <= k <= 3500
//  -105 <= value of elements <= 105.
// For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
//
//
//


struct Element {
    int val;
    int arr_num;
    int pointer;
    
    Element(int v, int a, int p) : val(v), arr_num(a), pointer(p) {}
};

struct Comp{
    bool operator()(const Element& a, const Element& b){
        return a.val > b.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> res(2);
        int n = nums.size();
        if (n == 0) return res;
        vector<int> listLen(n);
        for (int i = 0; i < n; i++) listLen[i] = nums[i].size();
        priority_queue<Element, vector<Element>, Comp> pq;
        int cur_max = INT_MIN;
        int cur_min = INT_MAX;
        for (int i = 0; i < n; i++) {
            cur_max = max(nums[i][0], cur_max);
            cur_min = min(nums[i][0], cur_min);
            Element e(nums[i][0], i, 0);
            pq.push(e);
        }
        int range_min = cur_max - cur_min;
        res[0] = cur_min;
        res[1] = cur_max;
        while (!pq.empty()) {
            Element e = pq.top();
            cur_min = e.val;
            if (cur_max - cur_min < range_min) {
                range_min = cur_max - cur_min;
                res[0] = cur_min;
                res[1] = cur_max;
            }
            int next_pointer = e.pointer + 1;
            if (next_pointer >= listLen[e.arr_num]) break;
            Element next(nums[e.arr_num][next_pointer], e.arr_num, next_pointer);
            cur_max = max(cur_max, nums[e.arr_num][next_pointer]);
            pq.pop();
            pq.push(next);
        }
        return res;
    }
};
