# 1710. Maximum Units on a Truck

做题前：

1. Greedy Algorithm



做题中：

1. 先 sort 再从最大的开始找：`O(n * log(n))`

   ```python
   class Solution:
       def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
           boxTypes.sort(key=lambda x: x[1], reverse=True)
           total = 0
           curr = 0
           for i in boxTypes:
               if i[0] > truckSize:
                   return total + truckSize * i[1]
               total += i[1] * i[0]
               truckSize -= i[0]
           return total
   ```

2. `O(n)`

   ```python
   ```

   



做题后：

1. 

