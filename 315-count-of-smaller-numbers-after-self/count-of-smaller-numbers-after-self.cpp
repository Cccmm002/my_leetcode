// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//
//


class Solution {
private:
    typedef struct Node {
        int val;
        int duplicate;
        int smaller;
        Node *left;
        Node *right;
        
        Node (int v) {
            val = v;
            duplicate = 1;
            smaller = 0;
            left = NULL;
            right = NULL;
        }
    }*pNode;
    
    int insert(pNode root, int val) {
        if (val < root->val) {
            root->smaller++;
            if (root->left == NULL) {
                pNode n = new Node(val);
                root->left = n;
                return 0;
            }
            else {
                return insert(root->left, val);
            }
        }
        else if (val == root->val) {
            root->duplicate++;
            return root->smaller;
        }
        else {
            if (root->right == NULL) {
                pNode n = new Node(val);
                root->right = n;
                return root->duplicate + root->smaller;
            }
            else {
                return insert(root->right, val) + root->duplicate + root->smaller;
            }
        }
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len);
        if (len == 0)
            return res;
        pNode root = new Node(nums[len-1]);
        res[len - 1] = 0;
        for (int i = len - 2; i >= 0; i--) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }
};

