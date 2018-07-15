// In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 
//
// There is at least one empty seat, and at least one person sitting.
//
// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
//
// Return that maximum distance to closest person.
//
//
// Example 1:
//
//
// Input: [1,0,0,0,1,0,1]
// Output: 2
// Explanation: 
// If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.
//
//
// Example 2:
//
//
// Input: [1,0,0,0]
// Output: 3
// Explanation: 
// If Alex sits in the last seat, the closest person is 3 seats away.
// This is the maximum distance possible, so the answer is 3.
//
//
// Note:
//
//
// 	1 <= seats.length <= 20000
// 	seats contains only 0s or 1s, at least one 0, and at least one 1.
//
//
//
//


class Solution {
    // 0, 4, 6
    // 100001
    // 234567
    // 7-2=5/2=2
    public int maxDistToClosest(int[] seats) {
        int n = seats.length;
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1)
                list.add(i);
        }
        int list_size = list.size();
        int res = 0;
        if (list.get(0) != 0)
            res = Math.max(res, list.get(0));
        if (list.get(list_size - 1) != n - 1)
            res = Math.max(res, n - list.get(list_size - 1) - 1);
        for (int i = 1; i < list_size; i++) {
            int cur = (list.get(i) - list.get(i - 1))/2;
            res = Math.max(cur, res);
        }
        return res;
    }
}
