#include <bits/stdc++.h>
using namespace std;
int t, n, a[200001], cnt[3];
vector<int> v[3][200001];
map<pair<int,int>, int> mp[3];
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
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= cnt[i]; j++) v[i][j].clear();
            cnt[i] = 0;
            mp[i].clear();
        }
        for (int i = 2; i < n; i++) {
            if (mp[0].find({a[i], a[i+1]}) == mp[0].end()) mp[0][{a[i], a[i+1]}] = ++cnt[0];
            v[0][mp[0][{a[i], a[i+1]}]].push_back(a[i-1]);
        }
        for (int i = 2; i < n; i++) {
            if (mp[1].find({a[i-1], a[i+1]}) == mp[1].end()) mp[1][{a[i-1], a[i+1]}] = ++cnt[1];
            v[1][mp[1][{a[i-1], a[i+1]}]].push_back(a[i]);
        }
        for (int i = 2; i < n; i++) {
            if (mp[2].find({a[i-1], a[i]}) == mp[2].end()) mp[2][{a[i-1], a[i]}] = ++cnt[2];
            v[2][mp[2][{a[i-1], a[i]}]].push_back(a[i+1]);
        }
        long long ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= cnt[i]; j++) {
                sort(v[i][j].begin(), v[i][j].end());
                vector<int> u;
                int lst = 0;
                for (int k = 0; k < v[i][j].size(); k++) {
                    if (k && v[i][j][k] != v[i][j][k-1]) {
                        u.push_back(k - lst);
                        lst = k;
                    }
                }
                u.push_back(v[i][j].size() - lst);
                long long cur = 0;
                for (int k = 0; k < u.size(); k++) cur += 1LL * u[k] * (v[i][j].size() - u[k]);
                ans += cur / 2;
            }
        }
        write(ans);
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}