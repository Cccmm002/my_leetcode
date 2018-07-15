// We have jobs: difficulty[i] is the difficulty of the ith job, and profit[i] is the profit of the ith job. 
//
// Now we have some workers. worker[i] is the ability of the ith worker, which means that this worker can only complete a job with difficulty at most worker[i]. 
//
// Every worker can be assigned at most one job, but one job can be completed multiple times.
//
// For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.
//
// What is the most profit we can make?
//
// Example 1:
//
//
// Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
// Output: 100 
// Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get profit of [20,20,30,30] seperately.
//
// Notes:
//
//
// 	1 <= difficulty.length = profit.length <= 10000
// 	1 <= worker.length <= 10000
// 	difficulty[i], profit[i], worker[i]  are in range [1, 10^5]
//


typedef struct Job {
    int diff, profit;
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<Job> v;
        int n = profit.size();
        for (int i=0;i<n;i++) {
            Job j = {difficulty[i], profit[i]};
            v.push_back(j);
        }
        sort(v.begin(), v.end(), [](const Job &a, const Job &b) -> bool {
            return a.diff < b.diff;
        });
        map<int, int> mp;
        int curmax = 0;
        for (int i=0;i<n;i++) {
            Job j = v[i];
            curmax = max(curmax, j.profit);
            mp[j.diff] = curmax;
        }
        int res = 0;
        int w = worker.size();
        for (int i=0;i<w;i++) {
            auto it = mp.upper_bound(worker[i]);
            if (it == mp.begin()) continue;
            it--;
            res += it->second;
        }
        return res;
    }
};
