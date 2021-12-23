# 1268. Search Suggestions System

做题前：

1. 



做题中：

1. 很慢的一种做法 O(n^2)。
   
   主要是慢在 search 的时候，需要把所有 product 都遍历一次
   
   ```python
   class Solution:
       def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
           products.sort()
           result = []
           for i in range(len(searchWord)):
               result.append(self.search(products, searchWord[:i + 1]))
           return result
       
       def search(self, products: List[str], s: str) -> List[str]:
           words = []
           for w in products:
               if len(w) >= len(s) and w[0:len(s)] == s:
                   words.append(w)
           return words[:3]
   ```
   
2. 不遍历 products，而是用 binary search 去找

   ```python
   class Solution:
       def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
           products.sort()
           result = []
           for i in range(len(searchWord)):
               result.append(self.search(products, searchWord[:i + 1]))
           return result
       
       def search(self, products: List[str], s: str) -> List[str]:
           words = []
           idx = self.binary_search(products, s)
           while len(words) < 3 and idx < len(products) and products[idx].startswith(s):
               words.append(products[idx])
               idx += 1
           return words
               
       def binary_search(self, array, target): # bisect.bisect_left implementation
           lo = 0
           hi = len(array)
   
           while lo < hi:
               mid = (lo + hi) //2
               if array[mid] < target: lo = mid + 1
               else: hi = mid
           return lo
       
   ```
   
   

做题后：

1. 

