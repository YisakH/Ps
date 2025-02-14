from collections import deque

class ProductOfNumbers(object):

    def __init__(self):
        self.st = [1]

    def add(self, num):
        if num == 0:
            self.st = [1]
        else:
            self.st.append(self.st[-1] * num)

    def getProduct(self, k):
        if len(self.st) - 1 - k < 0:
            return 0
        return self.st[-1] / self.st[len(self.st) - 1 - k]
        


# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)