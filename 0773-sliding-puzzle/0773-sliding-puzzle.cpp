class Solution {
public:
    string boardToString(vector<vector<int>>& board) {
        string ans = "";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                ans += board[i][j] + '0';
            }
        }
        return ans;
    }

    void stringToBoard(string currState, vector<vector<int>>& board) {
        board[0][0] = currState[0] - '0';
        board[0][1] = currState[1] - '0';
        board[0][2] = currState[2] - '0';
        board[1][0] = currState[3] - '0';
        board[1][1] = currState[4] - '0';
        board[1][2] = currState[5] - '0';
    }

    vector<string> genNextStates(vector<vector<int>>& board) {
        int x = -1, y = -1;
        bool flag = false;

        vector<string> nextState;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    x = i, y = j;
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 and nx < 2 and ny >= 0 and ny < 3) {
                swap(board[x][y], board[nx][ny]);
                nextState.push_back(boardToString(board));
                swap(board[x][y], board[nx][ny]);
            }
        }
        return nextState;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string curr = boardToString(board);
        string tgt = "123450";

        queue<string> q;
        unordered_set<string> vis;
        vis.insert(curr);

        int moves = 0;
        if (curr == tgt) {
            return moves;
        }
        q.push(curr);
        while (!q.empty()) {
            moves++;
            int level = q.size();

            for (int i = 0; i < level; i++) {
                string currState = q.front();
                q.pop();
                stringToBoard(currState, board);
                vector<string> nextState = genNextStates(board);

                for (auto& it : nextState) {
                    if (it == tgt) {
                        return moves;
                    }

                    if (!vis.count(it)) {
                        vis.insert(it);
                        q.push(it);
                    }
                }
            }
        }
        return -1;
    }
};