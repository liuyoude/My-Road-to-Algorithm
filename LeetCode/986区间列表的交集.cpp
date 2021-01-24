class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector< vector<int> > res;
        vector<int> sig(2);
        int a_i = 0, b_i = 0;
        while(a_i < firstList.size() && b_i < secondList.size()){
            int a1 = firstList[a_i][0];
            int a2 = firstList[a_i][1];
            int b1 = secondList[b_i][0];
            int b2 = secondList[b_i][1];
            // 如果区间有交集
            // 1.
            // -------
            //   ---
            // 2.
            // -------
            //   -------
            // 3.
            //   ----
            // ---------
            // 4.
            //  ---------
            // -------
            //共性是都在区间[max(a1,b1),min(a2,b2)]中
            if(a2 >= b1 && a1 <= b2){
                sig[0] = max(a1, b1);
                sig[1] = min(a2, b2);
                res.push_back(sig);
            }
            // 递增指针
            if(b2 <= a2) b_i ++;
            else a_i ++;          
        }
        return res;
    }
};
