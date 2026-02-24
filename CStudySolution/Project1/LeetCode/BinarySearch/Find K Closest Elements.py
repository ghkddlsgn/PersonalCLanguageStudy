class Solution:
    def findClosestElements(self, arr: list[int], k: int, x: int) -> list[int]:
        arr.sort(key=lambda a: self.custom_dist(a,x))
        return arr[:k]
    
    def custom_dist(self, a:int, x:int) -> float:
        dist = a - x
        if dist < 0:
            dist += 0.1
        return abs(dist)