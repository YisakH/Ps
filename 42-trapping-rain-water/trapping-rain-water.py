class Solution(object):
    def trap(self, height):
        right_max = [0 for _ in height]
        right_max[-1] = height[-1]
        left_max = [0 for _ in height]
        left_max[0] = height[0]
        N = len(height)

        for i in range(1, len(height)):
            left_max[i] = max(left_max[i-1], height[i])
            right_max[N - 1 - i] = max(right_max[N - i], height[N - 1 - i])
        
        answer = 0

        for i in range(1, N - 1):
            answer += max(min(left_max[i - 1], right_max[i + 1]) - height[i], 0)
        
        return answer

                