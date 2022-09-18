class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        players.sort()
        trainers.sort()
        count = 0
        for trainer in trainers:
            if count < len(players) and players[count] <= trainer:
                count += 1
        return count