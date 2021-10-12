# 268. Missing Number

做题前：

1. Bucket Sort



做题中：

1.  ```python
    class Solution:
        def missingNumber(self, nums: List[int]) -> int:
            arr = [0 for i in range(len(nums) + 1)]
            for i in nums:
                arr[i] = 1
            for i in range(len(arr)):
                if arr[i] != 1:
                    return i
            return -1
    ```

2. Math：

   ```python
   class Solution:
       def missingNumber(self, nums: List[int]) -> int:
   		return len(nums) * (1 + len(nums)) / 2 - sum(nums)
   ```

   

做题后：

1. 

