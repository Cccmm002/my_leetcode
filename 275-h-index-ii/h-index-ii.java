// Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?


public class Solution {
    public int hIndex(int[] citations) {
        int len=citations.length;
        int res=0;
        for(int i=0;i<len;i++) {
            if(citations[len-i-1]>=i+1)
                res=i+1;
        }
        return res;
    }
}
