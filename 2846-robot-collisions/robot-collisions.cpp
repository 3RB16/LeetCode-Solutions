/**
There are n 1-indexed robots, each having a position on a line,
health, and movement direction.

You are given 0-indexed integer arrays positions, healths,
and a string directions (directions[i] is either 'L' for left or 'R' for right).
All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line,
and the health of the other robot decreases by one.

The surviving robot continues in the same direction it was going.
If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions,
in the same order that the robots were given,
i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived),
and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots
(in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.

    Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
    Output: [2,17,9,15,10]

    Explanation: No collision occurs in this example,
    since all robots are moving in the same direction.
    So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].





    Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
    Output: [14]

    Explanation: There are 2 collisions in this example.
    Firstly, robot 1 and robot 2 will collide, and since both have the same health,
    they will be removed from the line.
    Next, robot 3 and robot 4 will collide and since robot 4's health is smaller,
    it gets removed, and robot 3's health becomes 15 - 1 = 14.
    Only robot 3 remains, so we return [14].



**/

/**
    Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"

    robots = [[2,2] , [3,0], [5,1], [6,3]]

    stack = [0, 1]

    at index 2:
        use while here condition will be !stack.empty() and healths[robot] > 0

        stack.top() ==> {5, 10, L} ===> (heal => 0) => current healths = [0, 0, 15, 12]
        stack.pop()  == > stack = [0]

    at index 3:


**/

class Solution {
  public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = int(positions.size());

        vector<pair<int, int>> robots;
        for(int i = 0; i < n; i++) {
            robots.emplace_back(positions[i], i);
        }

        sort(begin(robots), end(robots));

        stack <int> right_dir;
        for(int i = 0; i < n; i++) {
            auto [position, robot_index] = robots[i];

            if(directions[robot_index] == 'R') {
                right_dir.push(i);
                continue;
            }

            while(!right_dir.empty() and healths[robot_index] > 0) {
                auto [prev_position, prev_robot_index] = robots[right_dir.top()];

                if(healths[prev_robot_index] < healths[robot_index]) {
                    healths[prev_robot_index] = 0;
                    healths[robot_index] -= 1;
                    right_dir.pop();
                } else if (healths[prev_robot_index] > healths[robot_index]) {
                    healths[robot_index] = 0;
                    healths[prev_robot_index] -= 1;
                } else {
                    healths[prev_robot_index] = healths[robot_index] = 0;
                    right_dir.pop();
                }
            }
        }

        vector <int> survived_robots_healths;
        for(const int health : healths) if(health > 0) {
            survived_robots_healths.push_back(health);
        }

        return survived_robots_healths;
    }
};