class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less, greater, pivot_l = [], [], []

        for i, num in enumerate(nums):
            if num < pivot:
                nums[i] = (0, num)
            elif num > pivot:
                nums[i] = (2, num)
            else:
                nums[i] = (1, num)

        nums.sort(key=lambda x:x[0])
        return [val for k, val in nums]



        


