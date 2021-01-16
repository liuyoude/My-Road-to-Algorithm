class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //区间问题先排序，按起点升序，终点降序
        sort(intervals.begin(), intervals.end(), cmp);
        vector< vector<int> > res;
        vector<int> sig(2);
        int left = intervals[0][0];
        int right = intervals[0][1];

        for(int i = 1; i < intervals.size(); i ++){
            vector<int> interval = intervals[i];
            // 两个区间没有重叠部分
            if(right < interval[0]){
                // 将之前合并的区间加入res
                sig[0] = left;
                sig[1] = right;
                res.push_back(sig);
                // 更新left和right
                left = interval[0];
                right = interval[1];
            }
            // 两个区间有重叠且不包含
            else if(right >= interval[0] && right <= interval[1]){
                // 更新right
                right = interval[1];
            }
        }
        // 将最后一次的left和right加入res
        sig[0] = left;
        sig[1] = right;
        res.push_back(sig);
        return res;

    }

    static bool cmp(vector<int>& o1, vector<int>& o2){
        if(o1[0] == o2[0]){
            return o1[1] > o2[1];
        }
        return o1[0] < o2[0];
    }
};
