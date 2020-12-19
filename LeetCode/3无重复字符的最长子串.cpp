class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //if(s.length() == 0) return 0;
        // ���������ҳ�����ظ��Ӵ�
        map<char, int> window;
        int left = 0, right = 0;
        int max_len = 0, len = 0;
        while(right < s.length()){
            // ���󴰿�
            char c = s[right];
            right ++;
            // ���´���
            window[c] ++;
            len ++;
            if(window[c] == 1){
                if(max_len < len) max_len = len;
            }
            // �����ظ��ַ�ʱ��С����
            while(window[c] == 2){
                // ��������
                char c1 = s[left];
                left ++;
                // ���´���
                window[c1] --;
                len --;
            }
        }
        return max_len;
    }
};
