class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> re(n, 0);
        int left = 0;
        int right = n - 1;
        int i = 1;
        while(left < right)
        {
            re[left] = i;
            re[right] = -i;
            left ++;
            right --;
            i++;
        }
        return re;
    }
};