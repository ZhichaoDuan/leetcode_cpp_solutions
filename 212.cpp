#include "bits/stdc++.h"
using namespace std;

class TrieNode {
public:
    vector<TrieNode *> child;
    string str;
    TrieNode() : child(26, nullptr), str("") {};
    ~TrieNode() {
        for (auto c: child) delete c;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() : root(new TrieNode()) {};
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int num = c - 'a';
            if (!node->child[num]) node->child[num] = new TrieNode();
            node = node->child[num];
        }
        node->str = word;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        static const int M = board.size(), N = board[0].size();
        vector<vector<bool> > visited(M, vector<bool>(N, false));
        Trie trie;
        for (string word: words) {
            trie.insert(word);
        }
        vector<string> res;
        for (int r=0;r<M;r++) {
            for (int c=0;c<N;c++) {
                if (trie.root->child[board[r][c] - 'a']) {
                    DFS(board, trie.root->child[board[r][c]-'a'], r, c, visited, res);
                }
            }
        }
        return res;
    }

    void DFS(vector<vector<char>>& board, TrieNode* p, int r, int c, vector<vector<bool>>& visited, vector<string>& res) {
        const int M = board.size(), N = board[0].size();
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }
        visited[r][c] = true;
        for (auto d: dirs) {
            int nr = r + d.first;
            int nc = c + d.second;
            if (nr<0||nr>=M||nc<0||nc>=N||visited[nr][nc]||!p->child[board[nr][nc]-'a']) continue;
            DFS(board, p->child[board[nr][nc]-'a'], nr, nc, visited, res);
        }
        visited[r][c] = false;
    }
private:
    vector<pair<int, int> > dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
int main(int argc, char const *argv[])
{
    int col=3, row=4;
    char board[][col] = {
        {'o','a','a'},
        {'e', 't', 'a'},
        {'i', 'h', 'k'},
        {'i', 'f', 'l'},
    };
    vector<vector<char> > v;
    vector<string> words = {
        "oaaakl",
    };
    for (int i = 0; i < row; i++)
    {
        v.push_back(vector<char>());
        for (int j = 0; j < col; j++)
        {
            v[i].push_back(board[i][j]);
        }        
    }
    Solution sol;
    for (string s: sol.findWords(v, words)) {
        cout<<"result "<<s<<endl;
    }
    
    return 0;
}