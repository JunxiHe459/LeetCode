# Diagonal Traverse

做题前：

1. Bucket Sort

做题中：

1. ```python
      class Solution:
          def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
              arr = [0 for i in range(len(nums))]
              for i in nums:
                  arr[i - 1] += 1
              result = []
              for i in range(len(arr)):
                  if arr[i] == 0:
                      result += [i + 1]
              return result
      ```
      
2. 

做题后：

1.  

