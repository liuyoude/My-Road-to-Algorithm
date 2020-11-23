class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector< vector<string> > res;
        vector<string> current_board(n, string(n, '.'));
        solve(res, current_board, 0);
        return res;

    }
    void solve(vector< vector<string> >& res, vector<string>& current_board, int row){
        // n行遍历完结束
        if(row == current_board.size()){
            res.push_back(current_board);
            return;
        }
        // 第row行的n种分支
        for(int col = 0; col < current_board.size(); col ++ ){
            // 剪枝
            if(!isValid(current_board, row, col)) continue;
            // 做出选择
            current_board[row][col] = 'Q';
            // 递归遍历下一行
            solve(res, current_board, row+1);
            // 回朔，撤销选择
            current_board[row][col] = '.';
        }
    }
    // 全局遍历是否满足条件，比较暴力
    // bool isValid(vector<string>& current_board, int row, int col){
    //     for(int i = 0; i < current_board.size(); i ++ ){
    //         if(current_board[i][col] == 'Q') return false;
    //         for(int j = 0; j < current_board.size(); j ++){
    //             if(current_board[row][j] == 'Q') return false;
    //             if((abs(row-i) == abs(col-j)) && current_board[i][j] == 'Q') return false;
    //         }
    //     }
    //     return true;
    // }
    // 只考虑前row行即可
    bool isValid(vector<string>& current_board, int row, int col){
        // row + 1行还没有进行处理，只需要看前row行是否有皇后
        for(int i = 0; i < row; i ++ ){
            // 处理时每行只放一个，不用关注行上是否有其他皇后,只关注列上是否有其他皇后
            if(current_board[i][col] == 'Q') return false;
            for(int j = 0; j < current_board.size(); j ++ ){
                // 满足abs(row-j) == abs(col-i) 即满足对角条件
                if((abs(row-i) == abs(col-j)) && current_board[i][j] == 'Q') return false;
            }
        }     
        return true;
    }
};
