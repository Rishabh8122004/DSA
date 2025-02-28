class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        vector<int> v;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C" && !v.empty()) {
                v.erase(v.end());
            } else if (operations[i] == "+") {
                v.push_back(v[v.size() - 1] + v[v.size() - 2]);
            } else if (operations[i] == "D") {
                v.push_back(2 * v[v.size() - 1]);
            } else {
                int x = 0,j =0;
                if(operations[i][0] == '-')j++;
                for (j; j < operations[i].size(); j++){

                    x = x * 10 + (operations[i][j] - '0');
                }
                if (operations[i][0] == '-') {
                    x = -x;
                }
                v.push_back(x);
            }
        }
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }
        return sum;
    }
};