from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        def sweepArray(StartIdx:tuple[int,int], EndIdx:tuple[int,int], straight:bool, horizontal:bool):
            result = []
            if horizontal:
                if straight:
                    for i in range(StartIdx[1], EndIdx[1]+1):
                        result.append(matrix[StartIdx[0]][i])
                else:
                    for i in range(StartIdx[1], EndIdx[1] - 1, -1):
                        result.append(matrix[StartIdx[0]][i])
            else: #vertical
                if straight:
                    for i in range(StartIdx[0], EndIdx[0]+1):
                        result.append(matrix[i][StartIdx[1]])
                else:
                    for i in range(StartIdx[0], EndIdx[0] - 1, -1):
                        result.append(matrix[i][StartIdx[1]])
            result.pop(0)
            return result

        result = []
        RemainLength_V = len(matrix)
        RemainLength_H = len(matrix[0])

        
        #edge case : first row 
        result.extend(matrix[0])

        #loop starts from first col
        CurIdx_V = 0
        CurIdx_H = len(matrix[0]) - 1
        EndIdx_V = 0
        EndIdx_H = 0
        Loop = 2 # 1=4

        while(RemainLength_H != 0 and RemainLength_V != 0):
            if Loop == 1: #straight horizontal
                EndIdx_H = CurIdx_H + RemainLength_H - 1
                EndIdx_V = CurIdx_V
            elif Loop == 2: #straight vertical
                EndIdx_H = CurIdx_H
                EndIdx_V = CurIdx_V + RemainLength_V - 1
            elif Loop == 3: #reverse horizontal
                EndIdx_H = CurIdx_H - RemainLength_H + 1
                EndIdx_V = CurIdx_V
            elif Loop == 4: #reverse vertical
                EndIdx_H = CurIdx_H
                EndIdx_V = CurIdx_V - RemainLength_V + 1
            if Loop % 2 == 1:
                RemainLength_H -= 1
            else:
                RemainLength_V -= 1
            
            result.extend(sweepArray((CurIdx_V, CurIdx_H), (EndIdx_V, EndIdx_H),Loop <= 2, Loop % 2 == 1))

            Loop += 1
            if Loop >= 5: Loop = 1

            CurIdx_H = EndIdx_H
            CurIdx_V = EndIdx_V
        
        return result


a = Solution()
input = [[1,2,3],[4,5,6],[7,8,9]]
print(a.spiralOrder(input))
