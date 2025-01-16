# nums1 = [a, b, c, d, ...]
# nums2 = [e, f, g, h, ...]

# nums1 ^ nums2 = a^e ^ a^ f


class Solution(object):
    def xorAllNums(self, nums1, nums2):
        answer1, answer2 = 0, 0
        if len(nums2) % 2:
            for a in nums1:
                answer1 ^= a

        if len(nums1) % 2:
            for b in nums2:
                answer2 ^= b

        return answer1 ^ answer2
        