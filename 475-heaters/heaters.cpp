// Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.
//
// Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.
//
// So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.
//
// Note:
//
// Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
// Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
// As long as a house is in the heaters' warm radius range, it can be warmed.
// All the heaters follow your radius standard and the warm radius will the same.
//
//
//
// Example 1:
//
// Input: [1,2,3],[2]
// Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
//
//
//
// Example 2:
//
// Input: [1,2,3,4],[1,4]
// Output: 1
// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
//
//


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int f = houses.size();
        int r = heaters.size();
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int i = 0; i < f; i++) {
            int dis = 0;
            if (r == 1)
                dis = abs(houses[i] - heaters[0]);
            else {
                int a = 0, b = r - 1;
                while (a + 1 < b) {
                    int mid = a + (b - a)/2;
                    if (heaters[mid] == houses[i]) break;
                    else if (heaters[mid] < houses[i]) a = mid;
                    else b = mid;
                }
                if (a + 1 == b && heaters[a] != houses[i] && heaters[b] != houses[i])
                    dis = min(abs(houses[i] - heaters[a]), abs(heaters[b] - houses[i]));
            }
            res = max(res, dis);
        }
        return res;
    }
};
