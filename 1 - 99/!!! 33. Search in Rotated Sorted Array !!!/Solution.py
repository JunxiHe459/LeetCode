class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = (left + right) >> 1
            # 情况一：mid 和 target 都在一边
            if (nums[mid] < nums[0] and target < nums[0]) or (nums[mid] >= nums[0] and target >= nums[0]):
                if nums[mid] > target:
                    right = mid
                elif nums[mid] < target:
                    left = mid + 1
                else:
                    return mid
            # 情况二：mid 在左，target 在右
            elif nums[mid] > nums[0] and target < nums[0]:
                left = mid + 1
            # 情况三：mid 在右，target 在左
            else:
                right = mid
        return -1