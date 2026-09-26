#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    // Check whether person a knows person b
    bool knows(vector<vector<int>>& m, int a, int b, int n) {
        if (m[a][b] == 1) {
            return true;
        }
        else {
            return false;
        }
    }

    int celebrity(vector<vector<int>>& m, int n) {

        stack<int> s;

        // Step 1: Push all people into stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 2: Find potential celebrity
        while (s.size() > 1) {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            // If a knows b, then a cannot be celebrity
            if (knows(m, a, b, n)) {
                s.push(b);
            }
            // If a does not know b, then b cannot be celebrity
            else {
                s.push(a);
            }
        }

        // Single person left = potential celebrity
        int ans = s.top();

        // Step 3: Verify row
        // Celebrity should know nobody
        int zerocnt = 0;

        for (int i = 0; i < n; i++) {

            if (m[ans][i] == 0) {
                zerocnt++;
            }
        }

        // Celebrity's row should contain all 0
        if (zerocnt != n) {
            return -1;
        }

        // Step 4: Verify column
        // Everybody should know celebrity
        int onecnt = 0;

        for (int i = 0; i < n; i++) {

            if (m[i][ans] == 1) {
                onecnt++;
            }
        }

        // Except celebrity, everyone should know celebrity
        if (onecnt != n - 1) {
            return -1;
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> m = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };

    int n = m.size();

    Solution obj;

    int ans = obj.celebrity(m, n);

    if (ans == -1) {
        cout << "No Celebrity" << endl;
    }
    else {
        cout << "Celebrity is: " << ans << endl;
    }

    return 0;
}