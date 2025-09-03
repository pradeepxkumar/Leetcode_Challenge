class Solution {
public:
    // Directions for rook, bishop, queen
    vector<vector<int>> getDirs(string p) {
        if (p == "rook")   return {{1,0},{-1,0},{0,1},{0,-1}};
        if (p == "bishop") return {{1,1},{1,-1},{-1,1},{-1,-1}};
        return {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}; // queen
    }

    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        int n = pieces.size();
        vector<vector<vector<pair<int,int>>>> moves(n);

        // Generate all possible move paths for each piece
        for (int i = 0; i < n; i++) {
            int x = positions[i][0]-1, y = positions[i][1]-1;
            moves[i].push_back({{x,y}}); // stay still

            for (auto &d : getDirs(pieces[i])) {
                vector<pair<int,int>> path;
                int nx = x, ny = y;
                while (nx+d[0] >= 0 && nx+d[0] < 8 && ny+d[1] >= 0 && ny+d[1] < 8) {
                    nx += d[0]; ny += d[1];
                    path.push_back({nx,ny});
                    vector<pair<int,int>> tmp = {{x,y}};
                    tmp.insert(tmp.end(), path.begin(), path.end());
                    moves[i].push_back(tmp);
                }
            }
        }

        set<vector<pair<int,int>>> result;
        vector<int> choice(n);

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                int maxLen = 0;
                for (int k=0;k<n;k++) maxLen = max(maxLen,(int)moves[k][choice[k]].size());

                vector<pair<int,int>> snapshot;
                for (int step=0; step<maxLen; step++) {
                    set<pair<int,int>> seen;
                    for (int k=0;k<n;k++) {
                        auto &path = moves[k][choice[k]];
                        auto pos = path[min(step,(int)path.size()-1)];
                        if (seen.count(pos)) return; // collision
                        seen.insert(pos);
                        if (step == maxLen-1) snapshot.push_back(pos);
                    }
                }
                result.insert(snapshot);
                return;
            }
            for (int j=0;j<moves[i].size();j++) {
                choice[i] = j;
                dfs(i+1);
            }
        };

        dfs(0);
        return result.size();
    }
};
