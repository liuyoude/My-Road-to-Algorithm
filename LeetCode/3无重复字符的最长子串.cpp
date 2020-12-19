class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //if(s.length() == 0) return 0;
        // 滑动窗口找出最长无重复子串
        map<char, int> window;
        int left = 0, right = 0;
        int max_len = 0, len = 0;
        while(right < s.length()){
            // 扩大窗口
            char c = s[right];
            right ++;
            // 更新窗口
            window[c] ++;
            len ++;
            if(window[c] == 1){
                if(max_len < len) max_len = len;
            }
            // 出现重复字符时缩小窗口
            while(window[c] == 2){
                // 收缩窗口
                char c1 = s[left];
                left ++;
                // 更新窗口
                window[c1] --;
                len --;
            }
        }
        return max_len;
    }
};
