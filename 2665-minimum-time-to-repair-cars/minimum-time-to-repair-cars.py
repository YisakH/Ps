from math import sqrt

class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        def getCars(time):
            total = 0
            
            for rank in ranks:
                total += int(sqrt(time/rank))

            return total
        
        l, r = 1, 10 ** 14

        while l <= r:
            time = (l + r) // 2

            curCars = getCars(time)
            if curCars >= cars:
                r = time - 1
            else:
                l = time + 1

        return l