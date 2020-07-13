# https://leetcode.com/problems/number-of-islands/
# Notes: I realized this only after doing this challege: instead of creating a
# `visited` array, I could have just changed the input array of 1's to 0's...
# Yikes! But still, solved it, lol.

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        soln = 0
        r_size = len(grid)
        
        if r_size == 0:
            return 0
        
        c_size = len(grid[0])
        visited = [ [ False for i in range(c_size) ] for j in range(r_size) ]
        ones_positions = []
        
        def getAdjacent(node):
            adjs = []
            if node[0]+1 >= 0 and node[0]+1 < r_size and not visited[node[0]+1][node[1]]:
                adjs.append([node[0]+1, node[1]])
            if node[0]-1 >= 0 and node[0]-1 < r_size and not visited[node[0]-1][node[1]]:
                adjs.append([node[0]-1, node[1]])
            if node[1]+1 >= 0 and node[1]+1 < c_size and not visited[node[0]][node[1]+1]:
                adjs.append([node[0], node[1]+1])
            if node[1]-1 >= 0 and node[1]-1 < c_size and not visited[node[0]][node[1]-1]:
                adjs.append([node[0], node[1]-1])
            
            return adjs
        
        for i, r in enumerate(grid):
            for j, c in enumerate(r):
                if c is "1":
                    ones_positions.append([i, j])
                
        for i, pos in enumerate(ones_positions):
            if visited[pos[0]][pos[1]]:
                continue
                
            queue = [pos]
            visited[pos[0]][pos[1]] = True
            while(len(queue) > 0):
                node = queue.pop()
                adjNodes = getAdjacent(node)
                for i, adjN in enumerate(adjNodes):
                    if grid[adjN[0]][adjN[1]] == "1":
                        visited[adjN[0]][adjN[1]] = True
                        queue.append(adjN)
            soln += 1
        
        return soln
