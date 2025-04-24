from typing import List

class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if len(mat) == 0 or len(mat[0]) == 0: return []

        maxidx_y = len(mat)-1
        maxidx_x = len(mat[0])-1
        maxlayer = maxidx_x + maxidx_y
        result = []

        def get_diagonal_upright(layer:int): #idx = index1
            if layer > maxidx_x:
                idx_min = layer - maxidx_x
                idx_max = maxidx_x
            else:
                idx_min = 0
                idx_max = layer

            for i in range(idx_min, idx_max + 1):
                result.append(mat[layer-i][i])

            return
        
        def get_diagonal_downleft(layer:int): #idx = index1
            if layer > maxidx_y:
                idx_min = layer - maxidx_y
                idx_max = maxidx_x
            else:
                idx_min = 0
                idx_max = layer

            for i in range(idx_min, idx_max + 1):
                result.append(mat[i][layer-i])
            
            return

        upright = True
        for i in range(maxlayer+1):
            if upright:
                get_diagonal_upright(i)
            else:
                get_diagonal_downleft(i)
            upright = not upright

        return result

sol = Solution()
a = [[2,3]]

print(sol.findDiagonalOrder(a))