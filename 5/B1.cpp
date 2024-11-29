// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/535298/submission/285143838
// Verdict: Time limit exceeded on test 4
#include <bits/stdc++.h>
using namespace std;
int t, n, q, m, cnt, f[1001], x[1001], y[1001];
long long ans;
struct subnetwork {
    int num, cost;
    set<int> s;
} sn[9];
struct edge {
    int u, v, w;
    bool operator<(const edge &x) const {
        return w < x.w;
    }
} e[499501];
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
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
        read(n), read(q);
        for (int i = 1; i <= q; i++) {
            read(sn[i].num), read(sn[i].cost);
            sn[i].s.clear();
            for (int j = 1, c; j <= sn[i].num; j++) {
                read(c);
                sn[i].s.insert(c);
            }
        }
        for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
        ans = LONG_LONG_MAX;
        for (int i = 0; i < (1 << q); i++) {
            long long cur = 0;
            for (int j = 1; j <= q; j++) {
                if (i >> (q - j) & 1) {
                    cur += sn[j].cost;
                }
            }
            m = 0;
            for (int j = 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    bool flag = false;
                    for (int l = 1; l <= q; l++) {
                        if ((i >> (q - l) & 1) && sn[l].s.find(j) != sn[l].s.end() && sn[l].s.find(k) != sn[l].s.end()) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) e[++m] = (edge){j, k, 0};
                    else e[++m] = (edge){j, k, (x[j] - x[k]) * (x[j] - x[k]) + (y[j] - y[k]) * (y[j] - y[k])};
                }
            }
            sort(e + 1, e + m + 1);
            cnt = 0;
            for (int j = 1; j <= n; j++) f[j] = j;
            for (int j = 1; j <= m; j++) {
                int x = find(e[j].u), y = find(e[j].v);
                if (x != y) {
                    f[x] = y;
                    cur += e[j].w;
                    if (++cnt == n - 1) {
                        ans = min(ans, cur);
                        break;
                    }
                }
            }
        }
        printf("%lld\n\n", ans);
    }
    return 0;
}