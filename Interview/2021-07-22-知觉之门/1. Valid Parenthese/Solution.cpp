class Solution
{
    int getMin(string s)
    {
        vector<char> stack;
        int total = 0;
        for(char c : s)
        {
            if(c == '(')
            {
                stack.push_back(c);
                continue;
            }

            if(c == ')')
            {
                if(stack.empty())
                {
                    total += 1;
                    continue;
                }
                stack.pop_back();
            }
        }

        return total + stack.size();
    }
}