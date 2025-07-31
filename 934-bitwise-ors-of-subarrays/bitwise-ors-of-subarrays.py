class Solution:
    def subarrayBitwiseORs(self, arr):
        result = set()
        prev = set()

        for num in arr:
            curr = {num}

            for p in prev:
                curr.add(p | num)

            result.update(curr)
            prev = curr

        return len(result)



