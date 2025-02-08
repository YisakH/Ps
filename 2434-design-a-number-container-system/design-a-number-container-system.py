import heapq
from collections import defaultdict

class NumberContainers(object):
    def __init__(self):
        self.idxToVal = defaultdict(int)
        self.valToIdx = defaultdict(list) # value[val] = key
    
    def change(self, index, number):
        heapq.heappush(self.valToIdx[number], index)
        self.idxToVal[index] = number

    def find(self, number):
        minIdx = self.valToIdx[number][0] if self.valToIdx[number] else None

        while minIdx and self.idxToVal[minIdx] != number:
            heapq.heappop(self.valToIdx[number])
            minIdx = self.valToIdx[number][0] if self.valToIdx[number] else None
        
        return minIdx if minIdx else -1