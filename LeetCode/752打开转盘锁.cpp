class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        queue<string> q;
        set<string> visited;
        //set<string> de(deadends.begin(), deadends.end());
        // 将deadends加入visited
        for(int i = 0; i < deadends.size(); i ++ ){
            visited.insert(deadends[i]);
        }
        // 初始数字在deadends中直接 返回-1
        if(visited.count("0000") == 1) return -1;
        // 初始数字加入q
        q.push("0000");
        visited.insert("0000");
        int step = 1;
        while(! q.empty()){
            int sz = q.size();
            // 遍历当前层节点
            for(int i = 0; i < sz; i ++){
                string cur = q.front();
                q.pop();
                // 遍历每一个节点字符串的四个位置
                for(int j = 0; j < 4; j ++){
                    // 每个位置上操作或者下操作
                    string up_result = up_op(cur, j);
                    string dowm_result = down_op(cur, j);
                    // 操作结果如果是target，返回step
                    if(up_result == target || dowm_result == target) return step;
                    // 操作结果是否在 deadends中
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
