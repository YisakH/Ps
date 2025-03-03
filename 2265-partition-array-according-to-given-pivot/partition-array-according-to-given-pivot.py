class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less, greater, pivot_l = [], [], []

        for i, num in enumerate(nums):
            if num < pivot:
                less.append(num)
            elif num > pivot:
                greater.append(num)
            else:
                pivot_l.append(num)

        return less + pivot_l + greater



        


