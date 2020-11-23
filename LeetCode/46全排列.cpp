class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> choise_list;
        vector<int> path_list(nums.size(), 0);
        vector< vector<int> > track;
        solve(nums, choise_list, path_list, track);
        return track;
    }
    void solve(vector<int>& nums, vector<int>& choise_list, vector<int>& path_list, vector< vector<int> >& track){
        // 遍历到最底层结束
        if(choise_list.size() == nums.size()){
            track.push_back(choise_list);
            return;
        }
        for(int i = 0; i < nums.size(); i ++ ){
            // 剪枝
            if(path_list[i] == 1 ) continue;
            // 做选择
            path_list[i] = 1;
            choise_list.push_back(nums[i]);
            // 深搜
            solve(nums, choise_list, path_list, track);
            //  回朔，撤销选择
            path_list[i] = 0;
            choise_list.pop_back();
        }
    }

};
