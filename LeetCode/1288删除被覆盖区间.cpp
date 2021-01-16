class Solution {
public:
    static bool cmp(vector<int>& o1, vector<int>& o2){
            if(o1[0] == o2[0]){
                return o1[1] > o2[1];
            }
            return o1[0] < o2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // ��������������ص㽵������
        
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i ++){
            vector<int> interval = intervals[i];
            //�������
            //1.
            //--------
            //  --------
            //2.
            //--------
            //          --------
            //3.
            //--------
            // ------
            //ֻ�е���������������串��
            //���3����������(��Ҫ���ж�����ֹ����ĸ��²���Ӱ�쵽�ж�)
            if(left <= interval[0] && right >= interval[1]){
                count ++;
            }
            // ���1,�������䷶Χ
            if(right >= interval[0] && right <= interval[1]){
                right = interval[1];
            }
            //���2����������
            if(right < interval[0]){
                left = interval[0];
                right = interval[1];
            }
            
        }
        return intervals.size() - count;

    }
};
