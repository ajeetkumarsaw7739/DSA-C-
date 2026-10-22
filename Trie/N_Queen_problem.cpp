void addsolution(vector<vector<int>>& ans, vector<vector<int>>& board,
                     int n) {

        vector<int> temp;

        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                if(board[i][j] == 1) {
                    temp.push_back(i + 1);
                    break;
                }
            }
        }
        ans.push_back(temp);
    }

    bool issafe(int row, int col, vector<vector<int>>& board, int n) {

        int x = row;
        int y = col;

        // Check for same row on left side
        while(y >= 0) {
            if(board[x][y] == 1) {
                return false;
            }
            y--;
        }

        x = row;
        y = col;

        // Check upper diagonal
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 1) {
                return false;
            }
            y--;
            x--;
        }

        x = row;
        y = col;

        // Check lower diagonal
        while(x < n && y >= 0) {
            if(board[x][y] == 1) {
                return false;
            }
            y--;
            x++;
        }

        return true;
    }

    void solve(int col, vector<vector<int>>& ans,
               vector<vector<int>> board, int n) {

        // Base case
        if(col == n) {
            addsolution(ans, board, n);
            return;
        }

        // Place queen in each row
        for(int row = 0; row < n; row++) {

            if(issafe(row, col, board, n)) {

                // Place queen
                board[row][col] = 1;

                solve(col + 1, ans, board, n);

                // Backtracking
                board[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {

        vector<vector<int>> board(n, vector<int>(n, 0));

        vector<vector<int>> ans;

        solve(0, ans, board, n);

        return ans;
    }