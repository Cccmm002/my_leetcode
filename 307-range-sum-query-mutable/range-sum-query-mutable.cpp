// Given an integer array nums, find the sum of the elements between indices i and j (i &le; j), inclusive.
//
// The update(i, val) function modifies nums by updating the element at index i to val.
//
// Example:
//
// Given nums = [1, 3, 5]
//
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
//
//
//
// Note:
//
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.


class NumArray {
private:
    typedef struct Node {
        int start;
        int end;
        int val;
        Node *left;
        Node *right;
        
        Node(int b, int e, int m) : start(b), end(e), val(m), left(NULL), right(NULL) {}
        
        int query(int i, int j) {
            if (j < start || i > end) return 0;
            if (i <= start && j >= end) return val;
            return left->query(i, j) + right->query(i, j);
        }
    }*pNode;
    
    pNode init(int b, int e, vector<int> &nums) {
        int val = b == e ? nums[b] : INT_MAX;
        pNode n = new Node(b, e, val);
        if (b != e) {
            int mid = (b + e)/2;
            n->left = init(b, mid, nums);
            n->right = init(mid + 1, e, nums);
            n->val = n->left->val + n->right->val;
        }
        return n;
    }
    
    pNode root = NULL;
    
    int _update(int i, int val, pNode cur) {
        if (cur->start == cur->end && cur->start == i) {
            int diff = val - cur->val;
            cur->val = val;
            return diff;
        }
        int mid = (cur->start + cur->end)/2;
        int diff = (i <= mid) ? _update(i, val, cur->left) : _update(i, val, cur->right);
        cur->val += diff;
        return diff;
    }
    
public:
    NumArray(vector<int> nums) {
        int len = nums.size();
        if (len > 0)
            root = init(0, len - 1, nums);
    }
    
    void update(int i, int val) {
        _update(i, val, root);
    }
    
    int sumRange(int i, int j) {
        return root->query(i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
