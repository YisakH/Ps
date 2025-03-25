class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        x_list = [(sx, ex) for sx, _, ex, _ in rectangles]
        y_list = [(sy, ey) for _, sy, _, ey in rectangles]

        x_list.sort(key=lambda x:(x[0], x[1]))
        y_list.sort(key=lambda y:(y[0], y[1]))

        cnt = 0
        idx = 1
        for i, (sx, ex) in enumerate(x_list):
            if idx <= sx:
                cnt += 1
            idx = max(idx, ex)

            if cnt >= 2:
                return True
        

        cnt = 0
        idx = 1
        for i, (sy, ey) in enumerate(y_list):
            if idx <= sy:
                cnt += 1
            idx = max(idx, ey)

            if cnt >= 2:
                return True

        return False