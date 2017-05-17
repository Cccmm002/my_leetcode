// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
//
//
// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


public class Solution {
    private class Node{
        public int val,level;
        public Node(int v, int l){
            val=v;
            level=l;
        }
    }
    
    public int NumSquares(int n) {
        int count=(int)Math.Sqrt(n);
        if(count*count==n) return 1;
        List<int> raw=new List<int>();
        Queue<Node> q=new Queue<Node>();
        List<bool> visited=new List<bool>(n+1);
        for(int i=0;i<n;i++) visited.Add(false);
        for(int i=0;i<count;i++) {
            raw.Add((i+1)*(i+1));
            q.Enqueue(new Node(raw[i],1));
            visited[raw[i]]=true;
        }
        while(true){
            Node node=q.Dequeue();
            for(int i=0;i<count;i++){
                int newSum=node.val+raw[i];
                if(newSum==n)
                    return node.level+1;
                if(newSum<n){
                    if(!visited[newSum]){
                        q.Enqueue(new Node(newSum,node.level+1));
                        visited[newSum]=true;
                    }
                }
                else
                    break;
            }
        }
    }
}
