class Solution(object):
    def countServers(self, grid):
        col = [0 for _ in grid]
        row = [0 for _ in grid[0]]

        not_connected = 0
        pc = []

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    col[i] += 1
                    row[j] += 1
                    pc.append((i, j))
        
        for i, j in pc:
            if col[i] == 1 and row[j] == 1:
                not_connected += 1
        
        return len(pc) - not_connected



        