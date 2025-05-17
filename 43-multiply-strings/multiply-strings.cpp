class Solution {
public:
    string add(string n1, string b) {
    if (b.size() > n1.size()) swap(n1, b); // ensure n1 is longer

    int i = n1.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0) ? (n1[i] - '0') : 0;
        int y = (j >= 0) ? (b[j] - '0') : 0;
        int sum = x + y + carry;
        char digit = (sum % 10) + '0';

        if (i >= 0) n1[i] = digit;
        else n1 = digit + n1;

        carry = sum / 10;
        i--;
        j--;
    }
    return n1;
    }
    string multiply(string n1, string n2) {
        if (n1 == "0" || n2 == "0") return "0";
        if (n1.size() > n2.size()) swap(n1, n2);
        string ans = "0";
        string a = "";
        string p = n1;
        for (int i = n2.size() - 1; i >= 0; i--) {
            n1 = p;
            a = "";
            for (int j = n2.size() - 1; j > i; j--) a += "0";
            int x = n2[i] - '0';
            int carry = 0;
            for (int j = n1.size() - 1; j >= 0; j--) {
                int y = n1[j] - '0';
                int prod = x * y + carry;
                carry = prod / 10;
                a = char((prod % 10) + '0') + a;
            }
            if (carry > 0) {
                a = char(carry + '0') + a;
            }
            ans = add(ans, a);
        }
        return ans;
    }
};
