from inspect import stack
class Solution:
    def findClosestElements(self, arr: list[int], k: int, x: int) -> list[int]:
        bucket:list[int] = []
        search_idx_list:list[int] = [x]
        elem_in_bucket:set[int] = set()

        while(len(bucket) < k):
            #find new pivot from search_target
            search_target = search_idx_list.pop(0)
            pivot = self.get_pivot_idx(arr, search_target)
            #find left and right edge
            left_edge = self.get_chunk_left_idx(arr, pivot)
            right_edge = self.get_chunk_right_idx(arr, pivot)
            #add element as much as possible
            bucket.append([arr[left_edge] * (right_edge - left_edge + 1)])
            #find next search target then add
            buffer_add:list[int] = []
            if left_edge - 1  >= 0:
                buffer_add.append(left_edge-1)

    def get_pivot_idx(self, arr:list[int], target:int):
    def get_chunk_left_idx(self, arr:list[int], pivot:int):
    def get_chunk_right_idx(self, arr:list[int], pivot:int):
    def get_dist(self, a:int, x:int) -> float:
        return abs(a-x + 0.1) if a < 0 else abs(a-x)



a = Solution()
print(a.findClosestElements([1,2,3,4,5], 4, 3))