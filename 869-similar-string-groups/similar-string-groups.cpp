// Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y.
//
// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".
//
// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.
//
// We are given a list A of strings.  Every string in A is an anagram of every other string in A.  How many groups are there?
//
// Example 1:
//
//
// Input: ["tars","rats","arts","star"]
// Output: 2
//
// Note:
//
//
// 	A.length <= 2000
// 	A[i].length <= 1000
// 	A.length * A[i].length <= 20000
// 	All words in A consist of lowercase letters only.
// 	All words in A have the same length and are anagrams of each other.
// 	The judging time limit has been increased for this question.
//
//


class UF {
private:
    int *group;
    int n;
    int count;
    
public:
    UF(int nn) {
        this->n = nn;
        this->count = nn;
        group = new int[n];
        for (int i = 0; i < n; i++)
            group[i] = i;
    }
    
    ~UF() {
        delete[] this->group;
    }
    
    int parent(int num) {
        int res = group[num];
        while (group[res] != res)
            res = group[res];
        group[num] = res;
        return res;
    }
    
    inline bool isSameGroup(int a, int b) {
        return this->parent(a) == this->parent(b);
    }
    
    void connect(int a, int b) {
        int pa = parent(a);
        int pb = parent(b);
        if (pa != pb) {
            group[pa] = pb;
            count -= 1;
        }
    }
    
    int getCount() {
        return this->count;
    }
};

class Solution {
private:
    bool similar(string a, string b) {
        int n = a.size();
        int diff = 0;
        int index[2];
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 2)
                    return false;
                else
                    index[diff - 1] = i;
            }
        }
        if (diff != 2)
            return false;
        else
            return (a[index[0]] == b[index[1]]) && (a[index[1]] == b[index[0]]);
    }
    
public:
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        UF uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!uf.isSameGroup(i, j)) {
                    if (similar(A[i], A[j])) {
                        uf.connect(i, j);
                    }
                }
            }
        }
        return uf.getCount();
    }
};
