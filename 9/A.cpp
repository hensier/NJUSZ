// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/567353/submission/292282968
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n, m;
string s;
set<string> S;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        bool flag = false;
        for (int j = 1; j <= m; j++) {
            cin >> s;
            if (s.find("bie") != string::npos && S.find(s) == S.end()) {
                flag = true;
                cout << s << endl;
                S.insert(s);
            }
        }
        if (!flag) cout << "Time to play Genshin Impact, Teacher Rice!" << endl;
    }
    return 0;
}