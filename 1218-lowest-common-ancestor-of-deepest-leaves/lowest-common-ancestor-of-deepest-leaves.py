from collections import Counter, defaultdict

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        depth_info = defaultdict(int)
        parent = defaultdict(int)

        def dfs(node, depth):
            depth_info[node.val] = depth

            if node.left:
                parent[node.left.val] = node.val
                dfs(node.left, depth + 1)
            if node.right:
                parent[node.right.val] = node.val
                dfs(node.right, depth + 1)

        def find(node, val):
            if node.val == val:
                return node
            
            if node.left:
                res = find(node.left, val)
                if res:
                    return res
            if node.right:
                res = find(node.right, val)
                if res:
                    return res
        
        dfs(root, 0)
        max_depth = max(depth_info.values())
        target = []

        for key, val in depth_info.items():
            if val == max_depth:
                target.append(key)
        s = set(target)
        

        while True:
            ns = set()

            if len(s) == 1:
                return find(root, list(s)[0])

            for num in s:
                ns.add(parent[num])

            s = ns