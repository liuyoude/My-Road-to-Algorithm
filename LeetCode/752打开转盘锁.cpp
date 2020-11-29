class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        queue<string> q;
        set<string> visited;
        //set<string> de(deadends.begin(), deadends.end());
        // ��deadends����visited
        for(int i = 0; i < deadends.size(); i ++ ){
            visited.insert(deadends[i]);
        }
        // ��ʼ������deadends��ֱ�� ����-1
        if(visited.count("0000") == 1) return -1;
        // ��ʼ���ּ���q
        q.push("0000");
        visited.insert("0000");
        int step = 1;
        while(! q.empty()){
            int sz = q.size();
            // ������ǰ��ڵ�
            for(int i = 0; i < sz; i ++){
                string cur = q.front();
                q.pop();
                // ����ÿһ���ڵ��ַ������ĸ�λ��
                for(int j = 0; j < 4; j ++){
                    // ÿ��λ���ϲ��������²���
                    string up_result = up_op(cur, j);
                    string dowm_result = down_op(cur, j);
                    // ������������target������step
                    if(up_result == target || dowm_result == target) return step;
                    // ��������Ƿ��� deadends��
                    if(visited.count(up_result) == 0){
                        q.push(up_result);
                        visited.insert(up_result);
                    }
                    if(visited.count(dowm_result) == 0){
                        q.push(dowm_result);
                        visited.insert(dowm_result);
                    }
                }
            }
            step ++;
        }
        return -1;
    }
    string up_op(string cur, int j){
        if(cur[j] == '9') cur[j] = '0';
        else cur[j] += 1;
        return cur;
    }
    string down_op(string cur, int j){
        if(cur[j] == '0') cur[j] = '9';
        else cur[j] -= 1;
        return cur;
    }
};
