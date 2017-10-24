// A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 &le; Li, Ri &le; INT_MAX, 0 < Hi &le; INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//
// For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
//
// The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.
//
// For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
//
// Notes:
//
//  The number of buildings in any input list is guaranteed to be in the range [0, 10000].
//  The input list is already sorted in ascending order by the left x position Li. 
//  The output list must be sorted by the x position. 
//  There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
//
//
//
// Credits:Special thanks to @stellari for adding this problem, creating these two awesome images and all test cases.


class HashHeap {
private:
    vector<pair<int, int>> arr;    // (Height, ID)
    unordered_map<int, int> umh;   // (ID, Position in arr)

    inline void exchange(int a, int b) {
        pair<int, int> tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
        umh[arr[a].second] = a;
        umh[arr[b].second] = b;
    }

    void siftup(int index) {
        while (index > 0) {
            int p = (index - 1)/2;
            if (arr[p].first >= arr[index].first)
                break;
            exchange(p, index);
            index = p;
        }
    }

    void siftdown(int index) {
        int n = arr.size();
        while (index < n) {
            int left = index*2 + 1;
            int right = index*2 + 2;
            if (left >= n) break;
            int l = arr[left].first;
            int tex = left;
            if (right < n && arr[right].first > l) {
                l = arr[right].first;
                tex = right;
            }
            if (arr[index].first < l) {
                exchange(index, tex);
                index = tex;
            }
            else
                break;
        }
    }

public:
    HashHeap() {
        arr.clear();
        umh.clear();
    }

    bool empty() {
        return arr.empty();
    }

    int top() {
        if (empty()) return 0;
        else return arr[0].first;
    }

    void insert(int height, int building) {
        int n = arr.size();
        arr.push_back(make_pair(height, building));
        umh[building] = n;
        siftup(n);
    }

    int pop() {
        if (empty()) return 0;
        int res = arr[0].first;
        umh.erase(arr[0].second);
        exchange(0, arr.size() - 1);
        arr.pop_back();
        siftdown(0);
    }

    void remove(int building) {
        int n = arr.size();
        int index = umh[building];
        exchange(index, n - 1);
        arr.pop_back();
        int p = (index - 1)/2;
        if (index > 0 && arr[p].first < arr[index].first)
            siftup(index);
        else
            siftdown(index);
    }
};

struct Node {
    int position, building;
    bool begin;
    int height;

    Node(int p, int index, bool s, int h) : position(p), building(index), begin(s), height(h) {}
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int bn = buildings.size();
        if (bn == 0) return res;
        vector<Node> skyline;
        for (int i = 0; i < bn; i++) {
            Node ns(buildings[i][0], i, true, buildings[i][2]);
            Node ne(buildings[i][1], i, false, buildings[i][2]);
            skyline.push_back(ns);
            skyline.push_back(ne);
        }
        sort(skyline.begin(), skyline.end(), [](const Node &a, const Node &b) -> bool {
            if (a.position < b.position) return true;
            else if (a.position > b.position) return false;
            else if (a.begin && !b.begin) return true;
            else if (!a.begin && b.begin) return false;
            else if (a.begin) return a.height > b.height;
            else return a.height < b.height;
        });
        int n = skyline.size();
        pair<int, int> prev_pos = make_pair(skyline[0].position, skyline[0].height);
        int curh = skyline[0].height;
        HashHeap *heap = new HashHeap();
        heap->insert(skyline[0].height, skyline[0].building);
        for (int i = 1; i < n; i++) {
            if (skyline[i].begin) {
                heap->insert(skyline[i].height, skyline[i].building);
            }
            else {
                heap->remove(skyline[i].building);
            }
            if (curh != heap->top()) {
                res.push_back(prev_pos);
                prev_pos = make_pair(skyline[i].position, heap->top());
                curh = heap->top();
            }
        }
        res.push_back(prev_pos);
        delete heap;
        return res;
    }
};
