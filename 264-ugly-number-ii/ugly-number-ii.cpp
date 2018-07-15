// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
//
// Example:
//
//
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
//
// Note:  
//
//
// 	1 is typically treated as an ugly number.
// 	n does not exceed 1690.
//
//


class mycomparison
{
  bool reverse;
  public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (!reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, mycomparison> pq;
        unordered_set<int> us;
        pq.push(1);
        int cur=0;
        int front;
        while(cur!=n){
            cur++;
            front=pq.top();
            pq.pop();
            if(us.find(front)!=us.end()){
                cur--;
                continue;
            }
            else
                us.insert(front);
            if(front<=INT_MAX/2)
                pq.push(front*2);
            if(front<=INT_MAX/3)
                pq.push(front*3);
            if(front<=INT_MAX/5)
                pq.push(front*5);
        }
        return front;
    }
};
