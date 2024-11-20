#include <bits/stdc++.h>
using namespace std;
int T, n, m, L, V, d[100001], v[100001], a[100001], p[100001];
struct interval {
    int l, r;
    bool operator<(const interval &x) const {
        return l < x.l;
    }
} t[100001];
int findl(int i, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ((p[mid] - d[i]) * a[i] * 2 > V * V - v[i] * v[i]) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int findr(int i, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ((p[mid] - d[i]) * a[i] * 2 <= V * V - v[i] * v[i]) r = mid - 1;
        else l = mid + 1;
    }
    return r;
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
        T f = 1;
        char ch = gc();
        while (!isdigit(ch)) {
            if (ch == '-') f = -1;
            ch = gc();
        }
        while (isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = gc();
        }
        x *= f;
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
    template<typename T, typename... Ts> void write(T x, Ts... xs) {
        write(x);
        pc(' ');
        write(xs...);
    }
} using namespace IO;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("detect.in", "r", stdin);
        freopen("detect.out", "w", stdout);
    #endif
    read(T);
    while (T--) {
        read(n), read(m), read(L), read(V);
        for (int i = 1; i <= n; i++) read(d[i]), read(v[i]), read(a[i]);
        for (int i = 1; i <= m; i++) read(p[i]);
        int cnt = 0, ans1 = 0, ans2 = 0;
        for (int i = 1; i <= n; i++) {
            int pos = lower_bound(p + 1, p + m + 1, d[i]) - p;
            if (pos > m) continue;
            if (v[i] > V && a[i] >= 0) {
                t[++cnt] = (interval){pos, m};
                ans1++;
            }
            else if (v[i] <= V && a[i] > 0) {
                int l = findl(i, pos, m);
                if (l <= m) {
                    t[++cnt] = (interval){l, m};
                    ans1++;
                }
            }
            else if (v[i] > V && a[i] < 0) {
                int r = findr(i, pos, m);
                if (pos <= r) {
                    t[++cnt] = (interval){pos, r};
                    ans1++;
                }
            }
        }
        if (cnt != 0) {
            ans2 = 1;
            sort(t + 1, t + cnt + 1);
            for (int i = 2, R = t[1].r; i <= cnt; i++) {
                if (t[i].l > R) {
                    R = t[i].r;
                    ans2++;
                }
                else R = min(R, t[i].r);
            }
        }
        write(ans1, m - ans2);
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}