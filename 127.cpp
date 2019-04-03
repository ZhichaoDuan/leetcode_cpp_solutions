class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::map<std::string, std::vector<std::string>> graph;
        construct_graph(beginWord, wordList, graph);
        return BFS_graph(beginWord, endWord, graph);
    }
    
private:
    bool connect(const std::string &word1, const std::string &word2) {
        int cnt=0;
        for (int i=0; i<word1.length(); i++) {
            if (word1[i]!=word2[i])
                cnt++;
        }
        return cnt == 1;
    }
    
    void construct_graph(std::string &beginWord,
                         std::vector<std::string> &wordList,
                         std::map<std::string, std::vector<std::string>> &graph) {
        wordList.push_back(beginWord);
        for (int i=0;i <wordList.size(); i++ ){
            graph[wordList[i]] = std::vector<std::string>();
        }
        
        for (int i=0; i<wordList.size(); i++) {
            for (int j=i+1; j<wordList.size(); j++) {
                if (connect(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
    }
    
    int BFS_graph(std::string &beginWord, std::string &endWord, std::map<std::string, std::vector<std::string>> &graph) {
        std::queue<std::pair<std::string, int>> Q;
        std::set<std::string> visit;
        Q.push(std::make_pair(beginWord, 1));
        visit.insert(beginWord);
        while(!Q.empty()) {
            std::string node = Q.front().first;
            int step = Q.front().second;
            Q.pop();
            if (node == endWord) 
                return step;
            const std::vector<std::string> &neighbours = graph[node];
            for (int i=0; i<neighbours.size(); i++) {
                if (visit.find(neighbours[i]) == visit.end()) {
                    Q.push(std::make_pair(neighbours[i], step+1));
                    visit.insert(neighbours[i]);
                }
            }
        }
        return 0;
    }
};
