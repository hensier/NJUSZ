#include <bits/stdc++.h>
using namespace std;
map<char, int> suit = {
    {'D', 0}, {'C', 13}, {'H', 26}, {'S', 39}
}, 
rnk = {
    {'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
    {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}
};
int n, ans;
string s;
bool p[53];
int main() {
    #ifndef ONLINE_JUDGE
        freopen("poker.in", "r", stdin);
        freopen("poker.out", "w", stdout);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        p[suit[s[0]] + rnk[s[1]]] = true;
    }
    for (int i = 1; i <= 52; i++) ans += !p[i];
    cout << ans;
    return 0;
}