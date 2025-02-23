# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not postorder:
            return None
    
        root = TreeNode(preorder[0])

        if len(preorder) == 1:
            return root

        leftTreeLen = postorder.index(preorder[1]) + 1
        
        leftTreeRoot = self.constructFromPrePost(preorder[1:1+leftTreeLen], postorder[:leftTreeLen])
        rightTreeRoot = self.constructFromPrePost(preorder[1 + leftTreeLen:], postorder[leftTreeLen:-1])

        root.left = leftTreeRoot
        root.right = rightTreeRoot

        return root