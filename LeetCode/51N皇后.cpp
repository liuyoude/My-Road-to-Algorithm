class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector< vector<string> > res;
        vector<string> current_board(n, string(n, '.'));
        solve(res, current_board, 0);
        return res;

    }
    void solve(vector< vector<string> >& res, vector<string>& current_board, int row){
        // n�б��������
        if(row == current_board.size()){
            res.push_back(current_board);
            return;
        }
        // ��row�е�n�ַ�֧
        for(int col = 0; col < current_board.size(); col ++ ){
            // ��֦
            if(!isValid(current_board, row, col)) continue;
            // ����ѡ��
            current_board[row][col] = 'Q';
            // �ݹ������һ��
            solve(res, current_board, row+1);
            // ��˷������ѡ��
            current_board[row][col] = '.';
        }
    }
    // ȫ�ֱ����Ƿ������������Ƚϱ���
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
    // ֻ����ǰrow�м���
    bool isValid(vector<string>& current_board, int row, int col){
        // row + 1�л�û�н��д���ֻ��Ҫ��ǰrow���Ƿ��лʺ�
        for(int i = 0; i < row; i ++ ){
            // ����ʱÿ��ֻ��һ�������ù�ע�����Ƿ��������ʺ�,ֻ��ע�����Ƿ��������ʺ�
            if(current_board[i][col] == 'Q') return false;
            for(int j = 0; j < current_board.size(); j ++ ){
                // ����abs(row-j) == abs(col-i) ������Խ�����
                if((abs(row-i) == abs(col-j)) && current_board[i][j] == 'Q') return false;
            }
        }     
        return true;
    }
};
