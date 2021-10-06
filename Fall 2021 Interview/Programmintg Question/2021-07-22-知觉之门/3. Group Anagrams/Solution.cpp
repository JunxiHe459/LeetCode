class Solution {
public:

    // 方法1：用 sort 的值来作为 key
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> re;
        uordered_map<string, vector<string>> m;

        for(string s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());

            m[temp].push_back(s);
        }

        for(auto itr : m)
        {
            re.push_back(itr->second);
        }

        return re;
    }

    // 方法2: 用一个 int 数组来表示这个字符串
    // 用 counting sort 取代上面第12行的 sort
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

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> re;
        uordered_map<string, vector<string>> m;
        
        
        for(string s : strs)
        {
            m[counting_sort(s)] += s;
        }

        for(auto itr : m)
        {
            re.push_back(itr->second);
        }
        
        return re;
    }
};