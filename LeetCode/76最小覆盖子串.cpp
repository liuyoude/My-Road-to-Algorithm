class Solution {
public:
    string minWindow(string s, string t) {
        // ͳ�ƴ����ַ���Ŀ���ַ�,����ֻ��Ҫͳ��Ŀ���ַ����ִ���
        map<char, int> window, need;
        for(int i = 0; i < t.length(); i ++ ){
            need[t[i]] ++ ;
        }
        // ��������˫ָ��
        int left = 0, right = 0;
        // valid=window.size()ʱ��������Ŀ��������Ĭ����̴���inf
        int valid = 0, len = float('inf'), t_left = 0;
        // ������Դ���Ҷ�ʱ����
        while(right < s.length()){
            // ���󴰿�
            char c = s[right];
            right ++;
            // ���´���
            if(need.count(c)){
                window[c] ++;
                if(window[c] == need[c]) valid ++;
            }
            // ����������ʱ��������
            while(valid == need.size()){
                // ����Ŀǰ��С�ַ�������
                if(right - left < len){
                    len = right - left;
                    t_left = left;
                }
                // ��������
                c = s[left];
                left ++;
                // ���´���
                if(need.count(c)){
                    if(window[c] == need[c]) valid --;
                    window[c] --;
                }
            }
        }
        return len == float('inf')?"":s.substr(t_left, len);

    }
};
