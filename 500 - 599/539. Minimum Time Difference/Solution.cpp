class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int min = INT_MAX;
        sort(timePoints.begin(), timePoints.end());
        for(int i = 0; i < timePoints.size() - 1; i++)
        {
            int x = timeDiff(timePoints[i], timePoints[i+1]);
            if(x < min)
            {
                min = x;
            }
        }
        int end = timeDiff(timePoints[0], timePoints[timePoints.size() - 1]);
        return min < end ? min : end;
    }
    
    int timeDiff(string time1, string time2)
    {
        int t1 = stoi(time1.substr(0,2));
        int t2 = stoi(time1.substr(3,2));
        int t3 = stoi(time2.substr(0,2));
        int t4 = stoi(time2.substr(3,2));
        // printf("%d\n", t1);
        // printf("%d\n", t2);
        // printf("%d\n", t3);
        // printf("%d\n", t4);
        
        int t  = abs(t3 - t1) * 60 + t4 - t2;
        // printf("%d\n", t);
        return min(24*60 - t, t);
        
    }
};