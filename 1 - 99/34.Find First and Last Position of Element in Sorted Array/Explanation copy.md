# Find First and Last Position of Element in Sorted Array

做题前：

1. 要想 O(log n) 的复杂度，肯定得是 Bianry Search

   

做题中：

1. ```c++
           while(left <= right)
           {
               int mid = (left + right) / 2;
               
               if(nums[mid] < target)
               {
                   left = mid + 1;
               } 
               else 
               {
                   right = mid - 1;
               }
               if(nums[mid] == target) {index = mid;}
           }
   ```

一个挺标准的二分查找

做题后：

1. 遇到二分查找千万不要慌，慢慢想

