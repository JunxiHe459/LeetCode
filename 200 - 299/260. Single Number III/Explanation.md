# 260. Single Number III

做题前：

1. 如果只有一个数是只出现了一次，那么把所有的数 XOR 一边就可以啦。

   **但是这个题是 2 个数只出现了一次，设为 a 和 b**

做题中：

1. 将数组中的数都 xor 一边，得到 a XOR b

   ```python
   # 0 XOR 任意数 = 还是那个数，所以这里设 diff = 0
   diff = 0
   for i in nums:
   	diff ^= i
   ```

2. 得到的结果就是 a XOR b，选出其中不为 0 的一位

   ```python
   # 这个做法是选出从右往左第一个不为 0 的 bit
   diff &= -(diff - 1)
   # 但这个题其实随便选一个不为 0 的一位就 ok 了
   ```

3.  这就证明了，这 a 和 b 在这个 bit 上，一个是 1，一个是 0

    ```python
    result = [0, 0]
    for i in nums:
    	if i & diff == 0:
            result[0] ^= i
        if i & diff == 1:
            result[1] ^= 1
    return result
    ```

    

做题后：

1. 

