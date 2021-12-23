# 937. Reorder Data in Log Files

做题前：

1. 



做题中：

1. ```python
   class Solution:
       def reorderLogFiles(self, logs: List[str]) -> List[str]:
           letters = []
           digits = []
           
           for l in logs:
               if l.split(" ")[1].isdigit():
                   digits.append(l)
               else:
                   letters.append(l)
           
           letters.sort(key = lambda x: (x.split(" ", 1)[1], x) )
           
           return letters + digits
   ```

2.  lambda 中，可以用 x: (condition1, condition2) 来列出多个条件。

3. sort 还有一个参数是 ```reverse```，如果想倒着排，可以加上 ```array.sort(reverse=True)```

4. sort 中，key 除了写成 lambda 的形式外，也可以是一个 function，比如：

   ```python
   def sortSecond(val):
       return val[1] 
   list1.sort(key=sortSecond)
   ```

5. 



做题后：

1. 

