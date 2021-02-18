class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        queue = collections.deque()
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 2:
                    queue.append((i, j, 0))
        
        curM = 0
        while queue:
            (i, j, m) = queue.popleft()
            if grid[i][j] == 2 and m > 0:
                continue
            grid[i][j] = 2
            curM = max(m, curM)
            if i > 0 and grid[i - 1][j] == 1:
                queue.append((i - 1, j, m + 1))
            if i < len(grid) - 1 and grid[i + 1][j] == 1:
                queue.append((i + 1, j, m + 1))
            if j  < len(grid[i]) - 1 and grid[i][j + 1] == 1:
                queue.append((i, j + 1, m + 1))
            if j > 0  and grid[i][j - 1] == 1:
                queue.append((i, j - 1, m + 1))
        
        for row in grid:
            for cell in row:
                if cell == 1:
                    return -1
        return curM