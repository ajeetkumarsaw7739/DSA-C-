class Solution {
  public:
    string firstNonRepeating(string &s) {

        map<char, int> cnt;
        string ans = "";

        queue<char> q;

        for(int i = 0; i < s.length(); i++) {

            char ch = s[i];

            // Count frequency of current character
            cnt[ch]++;

            //  current character ko queue me push karo
            q.push(ch);

            // Queue ke front par repeated characters ko remove karo
            while(!q.empty()) {

                if(cnt[q.front()] > 1) {
                    q.pop();
                }
                else {
                    break;
                }
            }

            // Agar queue empty hai, koi non-repeating character nahi hai
            if(q.empty()) {
                ans.push_back('#');
            }
            else {
                // Queue ka front = first non-repeating character
                ans.push_back(q.front());
            }
        }

        return ans;
    }
};