class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if len(piles) == h:
            return max(piles)

        minSpeed = 1
        maxSpeed = max(piles)
        retSpeed = maxSpeed

        while minSpeed <= maxSpeed:
            avgSpeed = (minSpeed + maxSpeed) // 2
            hoursTaken = self.eatable(piles, avgSpeed)
            if hoursTaken <= h:
                maxSpeed = avgSpeed - 1
                if avgSpeed < retSpeed:
                    retSpeed = avgSpeed
            else:
                minSpeed = avgSpeed + 1
        return retSpeed

    def eatable(self, piles, avgSpeed) -> long:
        totalHours = 0
        for i in piles:
            if i % avgSpeed == 0:
                totalHours = totalHours + (i // avgSpeed)
            else:
                totalHours = totalHours + (i // avgSpeed) + 1
        return int(totalHours)
