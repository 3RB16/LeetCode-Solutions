class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days = [0 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        def transferToDays(date):
            day = 0
            for i in range(0 , int(date[0 : 2])):
                day += days[i]
            return day + int(date[3 : 5])
        arriveAlice = transferToDays(arriveAlice)
        leaveAlice = transferToDays(leaveAlice)
        arriveBob = transferToDays(arriveBob)
        leaveBob = transferToDays(leaveBob)
        if leaveAlice < arriveBob or leaveBob < arriveAlice:
            return 0
        return min(leaveAlice , leaveBob) - max(arriveAlice , arriveBob) + 1