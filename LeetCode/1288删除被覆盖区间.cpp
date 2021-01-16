class Solution {
public:
    static bool cmp(vector<int>& o1, vector<int>& o2){
            if(o1[0] == o2[0]){
                return o1[1] > o2[1];
            }
            return o1[0] < o2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 按起点升序排序，重点降序排序
        
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i ++){
            vector<int> interval = intervals[i];
            //三种情况
            //1.
            //--------
            //  --------
            //2.
            //--------
            //          --------
            //3.
            //--------
            // ------
            //只有第三种情况算作区间覆盖
            //情况3，覆盖区间(需要先判定，防止后面的更新操作影响到判定)
            if(left <= interval[0] && right >= interval[1]){
                count ++;
            }
            // 情况1,扩大区间范围
            if(right >= interval[0] && right <= interval[1]){
                right = interval[1];
            }
            //情况2，更新区间
            if(right < interval[0]){
                left = interval[0];
                right = interval[1];
            }
            
        }
        return intervals.size() - count;

    }
};
