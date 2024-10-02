// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/523987/submission/284049005
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int t, n, cnt, a[200001];
map<int, int> mp;
vector<int> v[200001];
namespace IO {
    char buf[1 << 21], *p1 = buf, *p2 = buf, obuf[1 << 21], *p3 = obuf;
    char gc() {
        if (p1 == p2) {
            p1 = buf;
            p2 = buf + fread(buf, 1, 1 << 21, stdin);
        }
        return p1 == p2 ? EOF : *p1++;
    }
    template<typename T> void read(T &x) {
        x = 0;
        char ch = gc();
        while (!isdigit(ch)) ch = gc();
        while (isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = gc();
        }
    }
    void pc(char c) {
        if (p3 - obuf < (1 << 21)) *p3++ = c;
        else {
            fwrite(obuf, p3 - obuf, 1, stdout);
            p3 = obuf;
            *p3++ = c;
        }
    }
    template<typename T> void write(T x) {
        if (x > 9) write(x / 10);
        pc(x % 10 + 48);
    }
} using namespace IO;
int main() {
    read(t);
    while (t--) {
        read(n);
        cnt = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            if (mp.find(a[i] >> 2) == mp.end()) mp[a[i] >> 2] = ++cnt;
            v[mp[a[i] >> 2]].push_back(a[i]);
        }
        for (int i = 1; i <= cnt; i++) {
            v[i].push_back(0);
            sort(v[i].begin(), v[i].end());
        }
        for (int i = 1; i <= n; i++) {
            int id = mp[a[i] >> 2];
            write(v[id][++v[id][0]]);
            pc(' ');
        }
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}