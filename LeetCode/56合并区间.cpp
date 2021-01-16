class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //�������������򣬰���������յ㽵��
        sort(intervals.begin(), intervals.end(), cmp);
        vector< vector<int> > res;
        vector<int> sig(2);
        int left = intervals[0][0];
        int right = intervals[0][1];

        for(int i = 1; i < intervals.size(); i ++){
            vector<int> interval = intervals[i];
            // ��������û���ص�����
            if(right < interval[0]){
                // ��֮ǰ�ϲ����������res
                sig[0] = left;
                sig[1] = right;
                res.push_back(sig);
                // ����left��right
                left = interval[0];
                right = interval[1];
            }
            // �����������ص��Ҳ�����
            else if(right >= interval[0] && right <= interval[1]){
                // ����right
                right = interval[1];
            }
        }
        // �����һ�ε�left��right����res
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
