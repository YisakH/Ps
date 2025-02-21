from typing import Optional

class FindElements:
    def __init__(self, root: Optional[TreeNode]):
        self.values = set()
        self.recover_tree(root, 0)

    def recover_tree(self, node: Optional[TreeNode], value: int):
        """ 오염된 트리를 복구하고 값들을 저장 """
        if not node:
            return
        node.val = value  # 현재 노드 값 복원
        self.values.add(value)  # 복원된 값을 set에 저장
        self.recover_tree(node.left, 2 * value + 1)  # 왼쪽 자식 복구
        self.recover_tree(node.right, 2 * value + 2)  # 오른쪽 자식 복구

    def find(self, target: int) -> bool:
        """ target 값이 존재하는지 확인 """
        return target in self.values