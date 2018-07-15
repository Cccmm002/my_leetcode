// Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
//
// You may assume each number in the sequence is unique.
//
// Consider the following binary search tree: 
//
//
//      5
//     / \
//    2   6
//   / \
//  1   3
//
// Example 1:
//
//
// Input: [5,2,6,1,3]
// Output: false
//
// Example 2:
//
//
// Input: [5,2,1,3,6]
// Output: true
//
// Follow up:
// Could you do it using only constant space complexity?
//


class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int n = preorder.size();
        int low = INT_MIN;
        for (int i = 0; i < n; i++) {
            int cur = preorder[i];
            if (cur < low) return false;
            while (!s.empty() && s.top() < cur) {
                low = s.top();
                s.pop();
            }
            s.push(cur);
        }
        return true;
    }
};
