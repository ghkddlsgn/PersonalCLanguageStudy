class Solution:
    def findPeakElement(self, nums: list[int]) -> int:
        def isPeak(i:int) -> bool:
            left_check = nums[i - 1] < nums[i] if i - 1 >= 0 else True
            right_check = nums[i] > nums[i + 1] if i + 1 >= len(nums) - 1 else True
            return (left_check and right_check)

        def IsOtherChunk(l:int, r:int, shouldAcs:bool) -> bool:
            return nums[l] > nums[r] if shouldAcs else nums[l] < nums[r]
        
        l,r = 0, len(nums) - 1
        searchStart:int = 0
        searchEnd:int = len(nums) - 1
        ShouldACS = nums[l] < nums[r]
        step = (searchEnd - searchStart + 1) // 2

        while(step >= 1):
            if isPeak(l): return l
            if isPeak(r): return r
                
            chunk_num = 2
            step = (searchEnd - searchStart + 1) // 2
            for l in range(searchStart, searchEnd + 1, step):
                r = min(len(nums)-1, l + step)
                if IsOtherChunk(l, r, ShouldACS):
                    #exclude chunk
                    if searchStart == 0:
                        searchStart = searchStart + step + 1
                    else:
                        searchEnd = searchEnd - 1
                    chunk_num = 2
                    break
            else:
                chunk_num *= 2
        
        return searchStart

sol = Solution()
nums = [1, 2, 3, 1]
print("Input:", nums)
print("Peak element:", sol.findPeakElement(nums))

