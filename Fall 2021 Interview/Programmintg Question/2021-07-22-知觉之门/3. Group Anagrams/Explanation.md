# Group Anagrams

做题前：

1. 怎么 hash 一个 string 的 anagrams 到一个 unique value 呢？
2. sort(anagrams) = string，将一个 string 的任意 anagram 进行排序，只会得到唯一解。



做题中：

1. 可以直接用自带的 Sort (O(n * log(n))

2. 也可以用 counting sort (O(n)) ---> 因为只有26个字母

   ```c++
       string counting_sort(string s)
       {
           int alpha[26] = {0};
           string re;
           for(char c : s)
           {
               alpha[c - 'a'] += 1;
           }
           for(int i = 0; i < 26; i++)
           {
               re += string(alpha[i], i + 'a');
           }
           return re;
       }
   ```

   



做题后：

1. 

