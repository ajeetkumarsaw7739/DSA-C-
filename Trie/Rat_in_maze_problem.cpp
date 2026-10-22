bool issafe(int newx, int newy, vector<vector<bool>>& vis,
                vector<vector<int>>& arr, int n) {

        if(newx >= 0 && newx < n &&
           newy >= 0 && newy < n &&
           vis[newx][newy] == 0 &&
           arr[newx][newy] == 1) {

            return true;
        }
        else {
            return false;
        }
    }

    void solve(int x, int y, vector<vector<int>>& arr, int n,
               vector<string>& ans, vector<vector<bool>>& vis,
               string path) {

        // Base case
        if(x == n-1 && y == n-1) {
            ans.push_back(path);
            return;
        }

        // 4 movements: DLRU
        vis[x][y] = 1;

        // Down
        if(issafe(x+1, y, vis, arr, n)) {
            solve(x+1, y, arr, n, ans, vis, path + "D");
        }

        // Left
        if(issafe(x, y-1, vis, arr, n)) {
            solve(x, y-1, arr, n, ans, vis, path + "L");
        }

        // Right
        if(issafe(x, y+1, vis, arr, n)) {
            solve(x, y+1, arr, n, ans, vis, path + "R");
        }

        // Up
        if(issafe(x-1, y, vis, arr, n)) {
            solve(x-1, y, arr, n, ans, vis, path + "U");
        }

        // Backtracking
        vis[x][y] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {

        int n = maze.size();
        vector<string> ans;

        vector<vector<bool>> visited(n, vector<bool>(n, 0));

        string path = "";

        if(n == 0 || maze[0][0] == 0) {
            return ans;
        }

        solve(0, 0, maze, n, ans, visited, path);

        return ans;
    }