class Solution {
public:
    string minWindow(string s, string t) {
        // 统计窗口字符和目标字符,窗口只需要统计目标字符出现次数
        map<char, int> window, need;
        for(int i = 0; i < t.length(); i ++ ){
            need[t[i]] ++ ;
        }
        // 滑动窗口双指针
        int left = 0, right = 0;
        // valid=window.size()时窗口满足目标条件，默认最短串长inf
        int valid = 0, len = float('inf'), t_left = 0;
        // 滑动到源串右端时结束
        while(right < s.length()){
            // 扩大窗口
            char c = s[right];
            right ++;
            // 更新窗口
            if(need.count(c)){
                window[c] ++;
                if(window[c] == need[c]) valid ++;
            }
            // 当满足条件时收缩窗口
            while(valid == need.size()){
                // 更新目前最小字符串长度
                if(right - left < len){
                    len = right - left;
                    t_left = left;
                }
                // 收缩窗口
                c = s[left];
                left ++;
                // 更新窗口
                if(need.count(c)){
                    if(window[c] == need[c]) valid --;
                    window[c] --;
                }
            }
        }
        return len == float('inf')?"":s.substr(t_left, len);

    }
};
