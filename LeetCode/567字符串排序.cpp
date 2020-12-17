class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // ʹ�ö�����������
        map<char, int> need, window;
        for(int i = 0; i < s1.length(); i ++){
            need[s1[i]] ++;
        }
        int left = 0;
        int right = left + s1.length() - 1;
        int valid = 0;
        if(right >= s2.length()) return false;
        else{
            // ��ʼ������
             for(int i = left; i <= right; i ++){
                char c = s2[i];
                if(need.count(c)){
                    window[c] ++;
                    if(window[c] == need[c]) valid ++;
                }
            }
        }     
        while(right < s2.length()){
            // valid����need.size()ʱ��������       
            if(valid == need.size()) return true;
            // ���´���,ȥ��s2[left]������s2[++right] 
            char c1 = s2[left];
            left ++;
            right ++;
            char c2 = s2[right];
            if(need.count(c1)){
                if(window[c1] == need[c1]) valid --;
                window[c1] --;
            }
            if(need.count(c2)){
                window[c2] ++;
                if(window[c2] == need[c2]) valid ++;
                
            }
        }
        return false;
    }
};
