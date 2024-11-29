// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/535298/submission/286865058
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int t;
string a, b;
int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int maxl = 0;
        for (int i = 0; b[i]; i++) {
            int len = 0;
            for (int j = 0; a[j] && b[i+len]; j++) {
                if (a[j] == b[i+len]) {
                    len++;
                }
            }
            maxl = max(maxl, len);
        }
        cout << a.size() + b.size() - maxl << endl;
    }
    return 0;
}