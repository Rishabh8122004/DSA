class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sand) {
        queue<int> q;
        for (int i = 0; i < s.size(); i++) {
            q.push(s[i]);
        }
        int n = q.size();
        bool flag = true;
        int i = 0;
        while (flag) {
            n = q.size();
            flag = false;
            while (!q.empty()) {
                if(n <= 0)break;
                if (q.front() == sand[i]) {
                    q.pop();
                    i++;
                    flag = true;
                } else {
                    q.push(q.front());
                    q.pop();
                }
                n--;
            }
        }
        return q.size();
    }
};