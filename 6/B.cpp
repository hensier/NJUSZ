// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/547994/submission/286696916
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
__int128_t powers[64];
int Q, op;
string s;
void init() {
    powers[5] = ((1 << 17) + 13) << 1;
    for (int i = 5; i < 64; i++) powers[i+1] = (powers[i] + ((1ULL << i) - 1)) << 1;
}
__int128_t get_name(unsigned long long x) {
    if (x <= 18) return 1 << (x - 1);
    if (x < 32) return (1 << 17) + x - 18;
    int id = log2(x);
    return powers[id] + x - (1ULL << id);
}
unsigned long long get_id(__int128_t x) {
    if (x <= (1 << 17)) return log2((long double)x) + 1;
    if (x < (1 << 17) + 14) return x - (1 << 17) + 18;
    int pos = upper_bound(powers + 5, powers + 64, x) - powers - 1;
    return (1ULL << pos) + x - powers[pos];
}
string encode(__int128_t x) {
    string s;
    while (x) {
        s += char((x & 1) + '0');
        x >>= 1;
    }
    reverse(s.begin(), s.end());
    return s;
}
__int128_t decode(string s) {
    __int128_t x = 0;
    for (int i = 0; s[i]; i++) x = (x << 1) | (s[i] - '0');
    return x;
}
int main() {
    init();
    cin >> Q;
    while (Q--) {
        cin >> op >> s;
        if (op == 1) cout << encode(get_name(stoull(s))) << endl;
        else cout << get_id(decode(s)) << endl;
    }
    return 0;
}