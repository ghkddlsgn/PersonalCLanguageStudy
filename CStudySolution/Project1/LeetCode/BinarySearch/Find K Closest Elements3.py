class Solution:
    def findClosestElements(self, arr: list[int], k: int, x: int) -> list[int]:
        l, r = 0, len(arr) - k
        while(l <= r):
            m = (l + r) // 2
            cur_dist = self.get_edge_dist(arr, m, k, x)
            #check left
            if m - 1 >= 0 and self.get_edge_dist(arr, m - 1, k, x) < cur_dist:
                r = m - 1
            #else check right
            elif m + k < len(arr) and self.get_edge_dist(arr, m + 1, k, x) < cur_dist:
                l = m + 1
            else:
                return arr[m:m+k]
        
        print("logic err")
        return [-1]

    def get_edge_dist(self, arr:list[int], window_start_idx:int, window_size:int, x:int) -> float:
        left_edge_dist = arr[window_start_idx] - x
        right_edge_dist = arr[window_start_idx + window_size - 1] - x

        if arr[window_start_idx] < x:
            left_edge_dist = abs(left_edge_dist) - 0.1
        if arr[window_start_idx + window_size - 1] < x:
            right_edge_dist = abs(right_edge_dist) - 0.1
        
        return abs(left_edge_dist) + abs(right_edge_dist)

a = Solution()
# print(a.findClosestElements([1,1,1,10,10,10], 1, 9))
print(a.findClosestElements([1,2,2,2,5,5,5,8,9,9], 4, 0))
