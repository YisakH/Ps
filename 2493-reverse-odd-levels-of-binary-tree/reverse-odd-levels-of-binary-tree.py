from collections import defaultdict
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        st = [(root, 0)]
        answer = defaultdict(list)

        while st:
            (cur_node, cur_depth) = st.pop()
            if cur_node == None:
                continue

            if cur_depth % 2 == 1:
                answer[cur_depth].append(cur_node.val)
                
            st.append((cur_node.right, cur_depth + 1))
            st.append((cur_node.left, cur_depth + 1))

        st = [(root, 0)]

        while st:
            (cur_node, cur_depth) = st.pop()
            if cur_node == None:
                continue

            if cur_depth % 2 == 1:
                cur_node.val = answer[cur_depth].pop()
                
            st.append((cur_node.right, cur_depth + 1))
            st.append((cur_node.left, cur_depth + 1))

        return root