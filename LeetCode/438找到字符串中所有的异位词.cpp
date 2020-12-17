class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 窗口长度与目标串长度一致，使用定长滑动窗口
        map<char, int> window, need;
        // 初始化need
        for(int i = 0; i < p.length(); ++i){
            ++ need[p[i]];
        }
        // 窗口指针
        int left = 0;
        int right = left + p.length() - 1;

        vector<int> result;
        if(right >= s.length()) return result;

        int valid = 0;
        // 初始化窗口
        for(int i = left; i <= right; ++ i){
            char c = s[i];
            if(need.count(c)){
                ++ window[c];
                if(window[c] == need[c]) ++ valid;
            }
        }
        while(right < s.length()){
            if(valid == need.size()) result.push_back(left);
            // 更新窗口
            char c1 = s[left];
            ++ left;
            ++ right;
            char c2 = s[right];
            if(need.count(c1)){
                if(window[c1] == need[c1]) -- valid;
                -- window[c1];
            }
            if(need.count(c2)){
                ++ window[c2];
                if(window[c2] == need[c2]) ++ valid;
            }
        }
        return result;

    }
};
