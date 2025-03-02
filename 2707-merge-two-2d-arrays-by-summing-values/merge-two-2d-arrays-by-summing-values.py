class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        id1 = 0
        id2 = 0

        answer = []

        while id1 < len(nums1) and id2 < len(nums2):
            if nums1[id1][0] < nums2[id2][0]:
                answer.append(nums1[id1])
                id1 += 1
            elif nums1[id1][0] > nums2[id2][0]:
                answer.append(nums2[id2])
                id2 += 1
            else:
                answer.append([nums1[id1][0], nums1[id1][1] + nums2[id2][1]])
                id1 += 1
                id2 += 1
        
        while id1 < len(nums1):
            answer.append(nums1[id1])
            id1 += 1
        
        while id2 < len(nums2):
            answer.append(nums2[id2])
            id2 += 1

        return answer