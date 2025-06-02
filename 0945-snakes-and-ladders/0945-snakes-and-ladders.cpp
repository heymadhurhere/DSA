class Solution {
public:
    int boardSize;
    int snakesAndLadders(vector<vector<int>>& board) {
        boardSize = board.size();
        queue<int> pos;
        pos.push(1);
        vector<bool> vis(boardSize * boardSize + 1, false);
        vis[1] = true;
        int cnt = 0;
        while (!pos.empty()) {
            int cell = pos.size();
            for (int i = 0; i < cell; i++) {
                int curr = pos.front();
                pos.pop();
                if (curr == boardSize * boardSize)
                    return cnt;
                // dixe roll
                for (int j = curr + 1;
                     j <= min(curr + 6, boardSize * boardSize); j++) {
                    int next = j;
                    auto newPos = convert(j);
                    int row = newPos.first;
                    int col = newPos.second;
                    if (board[row][col] != -1)
                        next = board[row][col];
                    if (!vis[next]) {
                        pos.push(next);
                        vis[next] = true;
                    }
                }
            }
            cnt++;
        }
        return -1;
    }

    pair<int, int> convert(int pos) {
        int row = (pos - 1) / boardSize;
        int col = (pos - 1) % boardSize;
        if (row % 2 == 1) {
            col = boardSize - col - 1;
        }
        row = boardSize - row - 1;
        return {row, col};
    }
};