// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
//
//
//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
//
//
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
//
//
// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
//
// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
//
// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
//
// Example 1:
// "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Return true
// Example 2:
// "1,#"
// Return false
// Example 3:
// "9,#,#,1"
// Return false
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
private:
    struct stackPair{
        int node;
        bool left; //true: left; false: right
        stackPair(int n):node(n),left(true){}
    };
public:
    bool isValidSerialization(string preorder) {
        if(preorder=="") return false;
        vector<string> input;
        stringstream ss(preorder);
        string token;
        while(getline(ss, token, ','))
        input.push_back(token);
        
        stack<stackPair> st;
        for(int i=0;i<input.size();i++){
            string t=input[i];
            if(t!="#"){
                stackPair sp(stoi(t));
                st.push(sp);
                continue;
            }
            while(1){
                if(st.empty()){
                    if(i==input.size()-1)
                        return true;
                    else
                        return false;
                }
                stackPair curTop=st.top();
                st.pop();
                if(curTop.left){
                    curTop.left=false;
                    st.push(curTop);
                    break;
                }
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};
