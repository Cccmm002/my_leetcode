// Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
//
//
//
// According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N &minus; h papers have no more than h citations each."
//
//
//
// For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.
//
//
//
// Note: If there are several possible values for h, the maximum one is taken as the h-index.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


public class Solution {
    public int hIndex(int[] citations) {
        ArrayList<Integer> arr=new ArrayList<>();
        for(int i=0;i<citations.length;i++)
            arr.add(citations[i]);
        Collections.sort(arr, Collections.reverseOrder());
        int res=0;
        for(int i=0;i<arr.size();i++) {
            if(arr.get(i)>=i+1)
                res=i+1;
        }
        return res;
    }
}