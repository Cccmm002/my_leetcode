// Alice has a hand of cards, given as an array of integers.
//
// Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.
//
// Return true if and only if she can.
//
//  
//
//
//
//
// Example 1:
//
//
// Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
//
// Example 2:
//
//
// Input: hand = [1,2,3,4,5], W = 4
// Output: false
// Explanation: Alice's hand can't be rearranged into groups of 4.
//
//  
//
// Note:
//
//
// 	1 <= hand.length <= 10000
// 	0 <= hand[i] <= 10^9
// 	1 <= W <= hand.length
//


class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        int count = hand.length;
        if (count % W != 0)
            return false;
        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
        for(int i = 0; i < count; i++) {
            int cur = hand[i];
            if (m.containsKey(cur)) {
                m.put(cur, m.get(cur) + 1);
            }
            else {
                m.put(cur, 1);
            }
        }
        ArrayList<Integer> keys = new ArrayList<Integer>(m.keySet());
        Collections.sort(keys);
        int p = 0, bucket = 0, lastStart = 0;
        while (lastStart < keys.size()) {
            int cur_key = keys.get(p);
            if (m.get(cur_key) <= 0) 
                return false;
            m.put(cur_key, m.get(cur_key) - 1);
            //if (m.get(cur_key) <= 0) {
            //    p += 1;
            //}
            bucket += 1;
            p += 1;
            if (bucket == W) {
                bucket = 0;
                while (lastStart < keys.size() && m.get(keys.get(lastStart)) <= 0) {
                    lastStart += 1;
                }
                if (lastStart >= keys.size())
                    break;
                p = lastStart;
            }
            else {
                if (!(m.containsKey(cur_key + 1) && m.get(cur_key + 1) >= 0))
                    return false;
            }
        }
        return true;
    }
}
