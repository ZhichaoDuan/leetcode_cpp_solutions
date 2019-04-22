class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.size()==0||board[0].size()==0) return false;
    vector<vector<bool> > v(board.size(), vector<bool>(board[0].size(), false));
    for (size_t i = 0; i < board.size(); i++) {
      for (size_t j = 0; j < board[0].size(); j++) {
        if (helper(board, v, word, 0, j, i)) {
          return true;
        }
      }
    }
    return false;
  }

  bool helper(vector<vector<char>>& board, vector<vector<bool>>& used, string word, int idx, int col, int row) {
    if (idx==word.length()) {
      return true;
    }
    if (row<0||row>=board.size()||col<0||col>=board[0].size()) {
      return false;
    }
    if (used[row][col]||board[row][col]!=word[idx]) {
      return false;
    }
    used[row][col]=true;
    bool exist=helper(board,used,word,idx+1,col+1,row);
    if(exist) return true;
    exist=helper(board,used,word,idx+1,col-1,row);
    if(exist) return true;
    exist=helper(board,used,word,idx+1,col,row+1);
    if(exist) return true;
    exist=helper(board,used,word,idx+1,col,row-1);
    if(exist) return true;
    used[row][col]=false;
    return false;
  }
};
