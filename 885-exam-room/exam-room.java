// In an exam room, there are N seats in a single row, numbered 0, 1, 2, ..., N-1.
//
// When a student enters the room, they must sit in the seat that maximizes the distance to the closest person.  If there are multiple such seats, they sit in the seat with the lowest number.  (Also, if no one is in the room, then the student sits at seat number 0.)
//
// Return a class ExamRoom(int N) that exposes two functions: ExamRoom.seat() returning an int representing what seat the student sat in, and ExamRoom.leave(int p) representing that the student in seat number p now leaves the room.  It is guaranteed that any calls to ExamRoom.leave(p) have a student sitting in seat p.
//
//  
//
// Example 1:
//
//
// Input: ["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
// Output: [null,0,9,4,2,null,5]
// Explanation:
// ExamRoom(10) -> null
// seat() -> 0, no one is in the room, then the student sits at seat number 0.
// seat() -> 9, the student sits at the last seat number 9.
// seat() -> 4, the student sits at the last seat number 4.
// seat() -> 2, the student sits at the last seat number 2.
// leave(4) -> null
// seat() -> 5, the student​​​​​​​ sits at the last seat number 5.
//
//
// ​​​​​​​
//
// Note:
//
//
// 	1 <= N <= 10^9
// 	ExamRoom.seat() and ExamRoom.leave() will be called at most 10^4 times across all test cases.
// 	Calls to ExamRoom.leave(p) are guaranteed to have a student currently sitting in seat number p.
//


class ExamRoom {
    private TreeSet<Integer> tree;
    private int total_seat;

    public ExamRoom(int N) {
        tree = new TreeSet<Integer>();
        total_seat = N;
    }
    
    public int seat() {
        if (tree.size() == 0) {
            tree.add(0);
            return 0;
        }
        Iterator<Integer> iter = tree.iterator();
        int cur_dis, cur_seat = 0;
        if (tree.first() != 0) {
            cur_dis = tree.first();
        }
        else {
            cur_dis = 0;
        }
        int prev = iter.next();
        while (iter.hasNext()) {
            int c = iter.next();
            int m = (c + prev)/2;
            int gap = m - prev;
            if (cur_dis < gap) {
                cur_dis = gap;
                cur_seat = m;
            }
            prev = c;
        }
        if (prev != total_seat - 1) {
            int gap = total_seat - prev - 1;
            if (cur_dis < gap) {
                cur_dis = gap;
                cur_seat = total_seat - 1;
            }
        }
        tree.add(cur_seat);
        return cur_seat;
    }
    
    public void leave(int p) {
        if (tree.contains(p))
            tree.remove(p);
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
