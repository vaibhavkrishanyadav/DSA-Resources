//Question 37.Sudoku Solver Leetcode
class Solution {
public:

bool isSafe(int r, int c, int k, vector<vector<char>>& board){
    for(int i=0; i<9; i++){
        if(board[r][i] ==  (k+'0')) return false;
     
        if(board[i][c] ==  (k+'0')) return false;
    }
   
    int row = r - r%3;
    int col = c - c%3;
    for(int i=row; i<row+3; i++){
        for(int j= col; j<col+3; j++){
            if(board[i][j] == (k+'0'))
                return false;
        }
    }
    return true;
}

bool sudoku(vector<vector<char>>& board){
    int i, j;
    int flag=0;
    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            if(board[i][j] == '.')
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(i == 9 && j == 9)
        return true;
   
    for(int k=1; k<=9; k++){
        if(isSafe(i, j, k, board)){
            board[i][j] = (k+'0');
            if(sudoku(board))
                return true;
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    sudoku(board);
}
};
