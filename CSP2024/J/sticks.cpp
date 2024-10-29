#include <bits/stdc++.h>
using namespace std;
const int ans[] = {
    -1, 
    -1, 1, 7, 4, 2, 6, 8, 
    10, 18, 22, 20, 28, 68, 88,
    108, 188, 200, 208, 288, 688, 888
};
int T, n;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("sticks.in", "r", stdin);
        freopen("sticks.out", "w", stdout);
    #endif
    cin >> T;
    while (T--) {
        cin >> n;
        if (n <= 14) cout << ans[n] << endl;
        else {
            cout << ans[n%7+14];
            for (int i = 1; i <= n / 7 - 2; i++) cout << 8;
            cout << endl;
        }
    }
    return 0;
}