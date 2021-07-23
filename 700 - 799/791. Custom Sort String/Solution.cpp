class Solution {
public:
    string customSortString(string order, string s) {
        int bucket[26] = {0};
        for(char i : s)
        {
            bucket[i - 'a'] += 1;
        }
        
        string re = "";
        for(char i : order)
        {
            while(bucket[i - 'a'] != 0)
            {
                re += i;
                bucket[i - 'a']--;
            }
        }
        
        for(char i = 'a'; i != 'z' + 1; i++)
        {
            while(bucket[i - 'a'] != 0)
            {
                re += i;
                bucket[i - 'a']--;
            }
        }
        
        return re;
    }
};