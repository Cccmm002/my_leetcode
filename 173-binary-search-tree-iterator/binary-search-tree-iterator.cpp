// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//
// Calling next() will return the next smallest number in the BST.
//
// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    struct stackPair {
        TreeNode *node;
        bool inLeft; //true: Left; false: Right
        stackPair(TreeNode *n, bool il) : node(n), inLeft(il) {}
    };

    stack<stackPair> s;
    TreeNode* current;
    
    void findSmallest() {
        while(current->left!=NULL) {
            stackPair sp(current,true);
            s.push(sp);
            current=current->left;
        }
    }
    
public:
    BSTIterator(TreeNode *root) {
        current=root;
        if(current!=NULL)
            findSmallest();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(current==NULL)
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        int res=current->val;
        if(current->right!=NULL){
            stackPair sp(current,false);
            s.push(sp);
            current=current->right;
            findSmallest();
            return res;
        }
        while(!s.empty()) {
            stackPair sp=s.top();
            s.pop();
            if(sp.inLeft){
                current=sp.node;
                return res;
            }
        }
        if(s.empty()) current=NULL;
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
