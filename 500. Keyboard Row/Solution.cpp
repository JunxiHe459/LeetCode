class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> m;
        
        string first = "qwertyuiop";
        string second = "asdfghjkl";
        string third = "zxcvbnm";
        
        for(int i = 0; i < first.length(); i++)
        {
            m[first[i]] = 1;
            m[toupper(first[i])] = 1;
        }
        for(int i = 0; i < second.length(); i++)
        {
            m[second[i]] = 2;
            m[toupper(second[i])] = 2;
        }
        for(int i = 0; i < third.length(); i++)
        {
            m[third[i]] = 3;
            m[toupper(third[i])] = 3;
        }
        
        
        
        vector<string> re;
        
        for(int i = 0; i < words.size(); i++)
        {
            int flag = m[words[i][0]];
            for(int j = 1; j < words[i].length(); j++)
            {
                if(flag != m[words[i][j]])
                {
                    // cout << flag << endl;
                    // cout << m[words[i][j]] << endl;
                    flag = -1;
                    break;
                }
            }
            if(flag != -1)
            {
                re.push_back(words[i]);
            }
        }
        
        return re;
    }
};