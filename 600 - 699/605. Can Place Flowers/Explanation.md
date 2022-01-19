# 696. Count Binary Substrings

做题前：

1. 



做题中：

1. 很快的做法

   ```python
   class Solution:
       def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
           prev = 0
           count = 0
           
           for curr in flowerbed:
               # 如果前一个是 0
               if prev == 0:
                   # 且当前位置为 0，则我们栽下去 1 朵 flower，先不管下一个是不是 1
                   if curr == 0:
                       count += 1
                   # 不管 curr == 0 还是 == 1，prev 的位置最终都会有花，所以 prev = 1
                   prev = 1
               # 如果前一个位置有花
               else:
                   # 且当前位置也有花，证明我们不应该在 prev 的位置栽花，所以 count -= 1
                   if curr == 1:
                       count -= 1
                   prev = curr
           return count >= n
   ```

1. 很慢的做法

   ```python
   class Solution:
       def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
           # We need at least 3 slots to plant 2 non-adjacent flowers
           front = 1 
           count = 0
           
           for curr in flowerbed:
               if front == 1:
                   if curr == 0:
                       front = 2
                   else:
                       front = 0
               elif front == 2:
                   if curr == 0:
                       front = 1
                       count += 1
                   else:
                       front = 0
               else:
                   if curr == 0:
                       front = 1
           if front > 1:
               count += 1
           return count >= n
   ```

   



做题后：

1. 

