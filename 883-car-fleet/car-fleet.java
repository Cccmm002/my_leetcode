// N cars are going to the same destination along a one lane road.  The destination is target miles away.
//
// Each car i has a constant speed speed[i] (in miles per hour), and initial position position[i] miles towards the target along the road.
//
// A car can never pass another car ahead of it, but it can catch up to it, and drive bumper to bumper at the same speed.
//
// The distance between these two cars is ignored - they are assumed to have the same position.
//
// A car fleet is some non-empty set of cars driving at the same position and same speed.  Note that a single car is also a car fleet.
//
// If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
//
//
// How many car fleets will arrive at the destination?
//
//  
//
// Example 1:
//
//
// Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
// Output: 3
// Explanation:
// The cars starting at 10 and 8 become a fleet, meeting each other at 12.
// The car starting at 0 doesn't catch up to any other car, so it is a fleet by itself.
// The cars starting at 5 and 3 become a fleet, meeting each other at 6.
// Note that no other cars meet these fleets before the destination, so the answer is 3.
//
//
//
// Note:
//
//
// 	0 <= N <= 10 ^ 4
// 	0 < target <= 10 ^ 6
// 	0 < speed[i] <= 10 ^ 6
// 	0 <= position[i] < target
// 	All initial positions are different.
//


class Solution {
    private class Car {
        public double distance;
        public double speed;

        public Car(double d, double v) {
            distance = d;
            speed = v;
        }
    }
    
    public int carFleet(int target, int[] position, int[] speed) {
        int n = speed.length;
        if (n == 0)
            return 0;
        Car[] cars = new Car[n];
        for (int i = 0; i < n; i++) {
            cars[i] = new Car((double)(target - position[i]), (double)speed[i]);
        }
        Arrays.sort(cars, (Car a, Car b) -> {return Integer.signum((int)(a.distance - b.distance));});
        int res = n;
        Car front = new Car(cars[0].distance, cars[0].speed);
        for (int i = 1; i < n; i++) {
            if (cars[i].speed <= front.speed) {
                front = new Car(cars[i].distance, cars[i].speed);
                continue;
            }
            double time = (cars[i].distance - front.distance) / (cars[i].speed - front.speed);
            double meet = front.distance - time*front.speed;
            if (meet >= 0) {
                res--;
                //front.distance = meet;
            }
            else {
                front = new Car(cars[i].distance, cars[i].speed);
            }
        }
        return res;
    }
}
