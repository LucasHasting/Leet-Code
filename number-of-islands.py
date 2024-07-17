class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        indicies = set()
        solution = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                joker = 0
                solution += int(self.helper(grid, (i,j), indicies, joker))
        return solution
    
    def helper(self, grid: List[List[str]], index: Tuple[int], indicies_cheked: Set[int], total: int) -> bool:
        if(index in indicies_cheked):
            return False
        
        if(grid[index[0]][index[1]] == "1"):
            if(not index in indicies_cheked):
                indicies_cheked.add(index)

            flag = 0
            #down
            if(index[0] < len(grid)-1):
                self.helper(grid, (index[0]+1,index[1]), indicies_cheked, total+1)
            else:
                flag += 1
            #up
            if(index[0] > 0):
                self.helper(grid, (index[0]-1,index[1]), indicies_cheked, total+1)
            else:
                flag += 1
            #left
            if(index[1] > 0):
                self.helper(grid, (index[0],index[1]-1), indicies_cheked, total+1)
            else:
                flag += 1
            #right
            if(index[1] < len(grid[0])-1):
                self.helper(grid, (index[0],index[1]+1), indicies_cheked, total+1)
            else:
                flag += 1
            if(total == 0): return True
            elif(flag == 4): return False
            else: return True

        return False
