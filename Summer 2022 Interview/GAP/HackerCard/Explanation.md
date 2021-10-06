# Hacker Card

给定一个数组 [2, 3, 4]，和一个限额 6

问从 1 开始买，最多能买多少个。买的东西不能和已有的重复

例如 [2, 3, 4] -> 6 则可购买 [1, 5] 或者 [6] -> 数量比 [1, 5] 少一个，所以不用这个

做题前：

1. Greedy Algorithm

做题中：

1. Naive Code:

   ```python
   def HackerCard(arr, d):
   	result = []
       start = 1
       while (d - start >= 0):
           if start not in arr:
               d -= start
               result.append(start)
               start += 1
       return result
   ```

   会发现超时了，原因是因为一次都会去判断 ```if start not in arr``` 实在是太慢了

2. 改进：在一开始就计算出哪些元素是可以购买的，记为 availabe

   ```python
   def HackerCard(arr, d):
   	m = max(arr)
       available = [i for i in range(1, m + 1)]
       # 将不能购买的设为 0
       for i in arr:
           available[i - 1] = 0
       
       for i in available:
           if i == 0:
               continue
           if d - i < 0:
               break
           d -= i
           result.append(i)
   ```

3. 改进后的 code 还是不完整的，因为可能出现把所有 available 的东西买完，d 还有余额的情况，所以需要修改为：

   ```python
   def HackerCard(arr, d):
   	m = max(arr)
       available = [i for i in range(1, m + 1)]
       # 将不能购买的设为 0
       for i in arr:
           available[i - 1] = 0
       
       for i in available:
           if i == 0:
               continue
           if d - i < 0:
               break
           d -= i
           result.append(i)
           
       start = m + 1
       while (d - start >= 0):s
       	if start not in arr:
               d -= start
               result.append(start)
               start += 1
       return result
   ```

   



做题后：

1. 

