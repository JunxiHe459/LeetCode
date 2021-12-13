# 416. Partition Equal Subset Sum

做题前：

1. 递归是最简单的
1. DP



做题中：

1. Time O(n^2)

   ```python
   class Solution:
       def canPartition(self, nums: List[int]) -> bool:
           # If the sum of elements in nums is odd,
           # it is impossible to reach Partition Equal Subset Sum
           total = sum(nums)
           if total % 2:
               return False
           
           seen = {0: True}
           # 将所有可能得到的 subset 的 sum 记录下来，看 total // 2 能否得到
           for n in nums:
               
          		# 避免 Dictionary changed size during iteration error
               arr = []
               for k in keys = seen.keys():
                   arr.append(k + n)
               for i in arr:
                   seen[i] = True
                   
               # 因为只会有 2 个 subset，所以我们只需要找 total // 2 是否出现过就行
               if (total >> 1) in seen:
                   return True
           
           return False
   ```

2. 最简单的做法，但是 time limit 过不去

   time O(2^n) <- 就不是正常人能想出来算法

   ```go
   func canPartition(nums []int) bool {
       return recFind(&nums, 0, 0)
   }
   
   func recFind(nums *[]int, idx, total int) bool {
       if idx == len(*nums) {
           return total == 0
       }
       
       total_p := total + (*nums)[idx]
       total_n := total - (*nums)[idx]
       idx += 1
       
       return recFind(nums, idx, total_p) || recFind(nums, idx, total_n)
   }
   ```

3. 另一种递归的方式

   ```go
   func canPartition(nums []int) bool {
       total := 0
       for _, v := range(nums) {
           total += v
       }
       return total % 2 != 1 && recFind(nums, 0, total)
   }
   
   func recFind(nums []int, idx, total int) bool {
       if total == 0 {
           return true
       }
       if idx >= len(nums) || total < 0 {
           return false
       }
       temp := total - nums[idx] * 2
       idx += 1
       return recFind(nums, idx, temp) || recFind(nums, idx, total)
   }
   ```

1. 



做题后：

1. 

