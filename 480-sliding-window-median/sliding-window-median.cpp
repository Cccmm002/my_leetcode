// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
// Examples: 
// [2,3,4] , the median is 3
// [2,3], the median is (2 + 3) / 2 = 2.5 
//
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Your job is to output the median array for each window in the original array.
//
// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
//
// Window position                Median
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7       -1
//  1  3 [-1  -3  5] 3  6  7       -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
//
//
// Therefore, return the median sliding window as [1,-1,-1,3,5,6].
//
// Note: 
// You may assume k is always valid, ie: k is always smaller than input array's size for non-empty array.


class Solution {
private:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> larger;
    unordered_map<int, int> moved;
    int balance = 0;   // positive: more smaller
    int _k;
    
    inline void clearTop() {
        while (smaller.size() > 0 && moved.find(smaller.top()) != moved.end() && moved[smaller.top()] > 0) {
            moved[smaller.top()]--;
            smaller.pop();
        }
        while (larger.size() > 0 && moved.find(larger.top()) != moved.end() && moved[larger.top()] > 0) {
            moved[larger.top()]--;
            larger.pop();
        }
    }
    
    void make_balanced() {
        while (balance > (_k&1)) {
            clearTop();
            int cur = smaller.top();
            smaller.pop();
            larger.push(cur);
            balance -= 2;
        }
        while (balance < (_k&1)) {
            clearTop();
            int cur = larger.top();
            larger.pop();
            smaller.push(cur);
            balance += 2;
        }
    }
    
    inline double getMid() {
        clearTop();
        if ((_k&1) == 1) return (double)(smaller.top());
        else return (((double)(smaller.top()) + (double)(larger.top()))/2.0);
    }
    
    void insert(int num) {
        if (num < getMid()) {
            smaller.push(num);
            balance++;
        }
        else {
            larger.push(num);
            balance--;
        }
        //make_balance();
    }
    
    void remove(int num) {
        if (moved.find(num) == moved.end())
            moved[num] = 1;
        else
            moved[num] += 1;
        if (num <= smaller.top()) balance--;
        else if(num >= larger.top()) balance++;
        //make_balance();
    }
    
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) {
            vector<double> res(n);
            for (int i = 0; i < n; i++) res[i] = (double)nums[i];
            return res;
        }
        _k = k;
        for (int i = 0; i < k; i++) smaller.push(nums[i]);
        balance = k;
        make_balanced();
        vector<double> res(n - k + 1, 0);
        res[0] = getMid();
        for (int i = k; i < n; i++) {
            insert(nums[i]);
            remove(nums[i - k]);
            make_balanced();
            res[i - k + 1] = getMid();
        }
        return res;
    }
};
