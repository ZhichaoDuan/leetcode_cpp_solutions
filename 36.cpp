class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    for (std::vector<char> v : board) {
      bool check[9]={false};
      for (char c: v) {
        if (c!='.') {
          if (check[c-'1']) return false;
          else check[c-'1']=true;
        }
      }
    }

    for (size_t r = 0; r < board.size(); r++) {
      bool check[9]={false};
      for (size_t i = 0; i < board[r].size(); i++) {
        if (board[i][r]!='.') {
          if (check[board[i][r]-'1']) return false;
          else check[board[i][r]-'1']=true;
        }
      }
    }

    for (size_t i = 0; i < 9; i++) {
      bool check[9]={false};
      for (size_t j = 0; j < 3; j++) {
        for (size_t k = 0; k < 3; k++) {
          char c = board[j+3*(i/3)][k+(i%3)*3];
          if (c!='.') {
            if (check[c-'1']) return false;
            else check[c-'1']=true;
          }
        }
      }
    }

    return true;
  }
};
