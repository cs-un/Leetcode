import sys
import os
from typing import List

class Solution:
    def numIslands(self, grid):
        count = 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[i])):
                print(grid[i][j])
                if(grid[i][j] == '1'):
                    grid[i][j] = 0
                    self.unmark(grid, i, j)
                    count = count + 1
        return count
                    
    def unmark(self, grid, i, j):
        queue = [(i, j)]
        while(len(queue) > 0):
            x, y = queue[0]
            queue = queue[1:]
            if(y > 0):
                if(grid[x][y-1] == '1'):
                    queue.append((x, y-1))
                    grid[x][y-1] = 0
            if(y < len(grid[x]) - 1):
                if(grid[x][y+1] == '1'):
                    queue.append((x, y+1))
                    grid[x][y+1] = 0
            if(x > 0):
                if(grid[x-1][y] == '1'):
                    queue.append((x-1, y))
                    grid[x-1][y] = 0
            if(x < len(grid) - 1):
                if(grid[x+1][y] == '1'):
                    queue.append((x+1, y))
                    grid[x+1][y] = 0