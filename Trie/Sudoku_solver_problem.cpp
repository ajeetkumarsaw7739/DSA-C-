 bool issafe(int row, int col, vector<vector<int>>& board, int val) {

        for(int i = 0; i < board.size(); i++) {

            // Row check
            if(board[row][i] == val) {
                return false;
            }

            // Column check
            if(board[i][col] == val) {
                return false;
            }

            // 3*3 matrix check
            if(board[3 * (row / 3) + i / 3]
                  [3 * (col / 3) + i % 3] == val) {
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<int>>& board) {

        int n = board.size();

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {

                // Cell empty
                if(board[row][col] == 0) {

                    for(int val = 1; val <= 9; val++) {

                        if(issafe(row, col, board, val)) {

                            // Place value
                            board[row][col] = val;

                            // Recursive call
                            bool aagesolutionpossible = solve(board);

                            if(aagesolutionpossible) {
                                return true;
                            }
                            else {
                                // Backtracking
                                board[row][col] = 0;
                            }
                        }
                    }

                    return false;
                }
            }
        }

        // Sudoku completely solved
        return true;
    }

    void solveSudoku(vector<vector<int>>& mat) {
        solve(mat);
    }