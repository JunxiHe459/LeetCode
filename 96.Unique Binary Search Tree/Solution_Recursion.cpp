class Solution
{
public:
    int numTrees(int n)
    {
        map<int, int> m;
        m[0] = 1;
        m[1] = 1;
        return count(n, m);
    }

    int count(int n, map<int, int> &m)
    {
        if (m[n] != 0)
        {
            return m[n];
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            sum += count(i - 1, m) * count(n - i, m);
        }
        m[n] = sum;
        return sum;
    }
};