# Custom Sort String

做题前：

1. 一道考察 bucket sort 的题，不算太难

2.  i-th char in alphabetical order = char - 'a' + 1;

   eg: 'a' = 'a' - 'a' = 0

   ​	  'b' = 'b' - 'a' = 1

做题中：

1. 因为题目只要求 s 中所有在 order 中的 char 按照 order 中的顺序来，其他的 char 的顺序不做要求，我们首先用 bucket 将 s 中每个 char 出现了多少次给记录。

   ```c++
       int bucket[26] = {0};
       for(char i : s)
       {
           bucket[i - 'a'] += 1;
       }
   ```

2. 然后我们将所有出现在 order 中的 char，按照 order 的顺序进行排列。

   ```c++
       string re = "";
       for(char i : order)
       {
           while(bucket[i - 'a'] != 0)
           {
               re += i;
               bucket[i - 'a']--;
           }
       }
   ```

3. 最后我们再将没有出现在 order 中，但是出现在 s 中的 char 添加到 re 的末尾，再返回 re 即可。

   ```c++
       for(char i = 'a'; i != 'z' + 1; i++)
       {
           while(bucket[i - 'a'] != 0)
           {
               re += i;
               bucket[i - 'a']--;
           }
       }
       
       return re;
   ```

做题后：

1. 复习一下 bucket sort。

