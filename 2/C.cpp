// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/284047089
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
string n;
string add(string a, string b) {
    if (a.size() < b.size()) swap(a, b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; b[i]; i++) {
        a[i] += b[i] - '0';
        if (!isdigit(a[i])) {
            a[i] -= 10;
            if (a.size() == b.size() && i == b.size() - 1) a += '1';
            else a[i+1]++;
        }
    }
    for (int i = b.size(); a[i] && !isdigit(a[i]); i++) {
        a[i] -= 10;
        if (i == a.size() - 1) a += '1';
        else a[i+1]++;
    }
    reverse(a.begin(), a.end());
    return a;
}
string easy_mul(string a, char b) {
    reverse(a.begin(), a.end());
    int tmp = 0;
    for (int i = 0; a[i]; i++) {
        int x = (a[i] - '0') * (b - '0') + tmp;
        a[i] = x % 10 + '0';
        tmp = x / 10;
    }
    if (tmp) a += (tmp + '0');
    reverse(a.begin(), a.end());
    return a;
}
string mul(string a, string b) {
    string ans = "0", tmp;
    for (int i = b.size() - 1; i >= 0; i--) {
        ans = add(ans, easy_mul(a + tmp, b[i]));
        tmp += "0";
    }
    return ans;
}
string easy_div(string a, char b) {
    string ans;
    bool flag = false;
    for (int i = 0; a[i]; ) {
        int A = a[i] - '0', B = b - '0';
        if (A == 0) {
            ans += '0';
            i++;
        }
        else if (A >= B) {
            flag = false;
            ans += A / B + '0';
            if (A % B == 0) {
                flag = true;
                i++;
            }
            else a[i] = A % B + '0';
        }
        else {
            if (flag) ans += '0';
            flag = false;
            A = A * 10 + (a[i+1] - '0');
            ans += A / B + '0';
            if (A % B == 0) {
                flag = true;
                i += 2;
            }
            else a[++i] = A % B + '0';
        }
    }
    return ans;
}
int main() {
    cin >> n;
    cout << easy_div(mul(mul(n, add(n, "1")), add(mul(n, "2"), "1")), '6');
    return 0;
}