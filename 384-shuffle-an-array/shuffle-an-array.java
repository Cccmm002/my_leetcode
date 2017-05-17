// Shuffle a set of numbers without duplicates.
//
//
// Example:
//
// // Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);
//
// // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
// solution.shuffle();
//
// // Resets the array back to its original configuration [1,2,3].
// solution.reset();
//
// // Returns the random shuffling of array [1,2,3].
// solution.shuffle();


public class Solution {
    Random rd;
    int[] n;

    public Solution(int[] nums) {
        n=nums;
        rd=new Random();
    }
    
    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        return n;
    }
    
    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        int[] res=new int[n.length];
        System.arraycopy(n,0,res,0,n.length);
        for(int i=n.length-1;i>0;i--) {
            int r=rd.nextInt(i+1);
            int t=res[i];
            res[i]=res[r];
            res[r]=t;
        }
        return res;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int[] param_1 = obj.reset();
 * int[] param_2 = obj.shuffle();
 */
