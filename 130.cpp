class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (n==0) {
      return ;
    }
    int m = board[0].size();
    if (m==0) {
      return ;
    }
    vector<vector<int> > alive(n, vector<int>(m, 0));
    queue<pair<int, int> > Q;
    for (size_t i = 0; i < m; i++) {
      if (board[0][i]=='O') {
        alive[0][i]=1;
        Q.push(make_pair(0, i));
      }
      if (board[n-1][i]=='O'&&alive[n-1][i]==0) {
        alive[n-1][i]=1;
        Q.push(make_pair(n-1, i));
      }
    }
    for (size_t i = 0; i < n; i++) {
      if (board[i][0]=='O') {
        alive[i][0]=1;
        Q.push(make_pair(i, 0));
      }
      if (board[i][m-1]=='O'&&alive[i][m-1]==0) {
        alive[i][m-1]=1;
        Q.push(make_pair(i, m-1));
      }
    }
    while(!Q.empty()) {
      pair<int, int> p = Q.front();
      Q.pop();
      int x = p.first;
      int y = p.second;
      int dx[] = {-1,1,0,0};
      int dy[] = {0,0,-1,1};
      for (int i=0;i<4;i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx>=0&&ny>=0&&nx<n&&ny<m&&!alive[nx][ny]&&board[nx][ny]=='O') {
          alive[nx][ny]=1;
          Q.push(make_pair(nx,ny));
        }
      }
    }
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if (board[i][j]=='O'&&alive[i][j]==0) {
          board[i][j]='X';
        }
      }
    }
  }
};
