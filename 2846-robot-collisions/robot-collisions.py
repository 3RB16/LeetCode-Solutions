class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        n = len(positions)
        robots = [(positions[i], i) for i in range(n)]
        robots.sort()

        right_dir = []
        for i in range(n):
            position, robot_index = robots[i]

            if directions[robot_index] == 'R':
                right_dir.append(i)
                continue

            while right_dir and healths[robot_index] > 0:
                prev_position, prev_robot_index = robots[right_dir[-1]]

                if healths[prev_robot_index] < healths[robot_index]:
                    healths[prev_robot_index] = 0
                    healths[robot_index] -= 1
                    right_dir.pop()
                elif healths[prev_robot_index] > healths[robot_index]:
                    healths[robot_index] = 0
                    healths[prev_robot_index] -= 1
                else:
                    healths[prev_robot_index] = healths[robot_index] = 0
                    right_dir.pop()

        survived_robots_healths = [health for health in healths if health > 0]
        return survived_robots_healths
