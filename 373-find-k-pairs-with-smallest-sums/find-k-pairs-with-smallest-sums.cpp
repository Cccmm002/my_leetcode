//
// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k. 
//
//
// Define a pair (u,v) which consists of one element from the first array and one element from the second array.
//
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
//
//
// Example 1:
//
// Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
//
// Return: [1,2],[1,4],[1,6]
//
// The first 3 pairs are returned from the sequence:
// [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
//
//
//
// Example 2:
//
// Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
//
// Return: [1,1],[1,1]
//
// The first 2 pairs are returned from the sequence:
// [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//
//
//
// Example 3:
//
// Given nums1 = [1,2], nums2 = [3],  k = 3 
//
// Return: [1,3],[2,3]
//
// All possible pairs are returned from the sequence:
// [1,3],[2,3]
//
//
//
// Credits:Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases.


class Solution {
private:
    struct Data {
        int first;
        int second;
        int index;
        
        Data(int a, int b, int i) : first(a), second(b), index(i) {}
    };

    struct Comp {
        bool operator()(const Data& a, const Data& b) {
            return (a.first + a.second) > (b.first + b.second);
        }
    };
    
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Data, vector<Data>, Comp> pq;
        vector<pair<int, int>> res;
        int l1 = nums1.size();
        int l2 = nums2.size();
        if (l1 == 0 || l2 == 0) return res;
        int mini = k > l1 ? l1 : k;
        for (int i = 0; i < mini; i++) {
            Data d(nums1[i], nums2[0], 0);
            pq.push(d);
        }
        while (res.size() < k) {
            if (pq.size() <= 0) break;
            Data cur = pq.top();
            pq.pop();
            pair<int, int> curp(cur.first, cur.second);
            res.push_back(curp);
            int pos = cur.index;
            if (pos + 1 < l2) {
                Data nd(cur.first, nums2[pos + 1], pos + 1);
                pq.push(nd);
            }
        }
        return res;
    }
};
