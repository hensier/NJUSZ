#include <bits/stdc++.h>
using namespace std;
int N, ans;
priority_queue<int, vector<int>, greater<int>> q;
struct cow {
    int g, d;
    bool operator<(const cow &x) const {
        return d < x.d;
    }
} c[100001];
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
    read(N);
    for (int i = 1; i <= N; i++) read(c[i].g), read(c[i].d);
    sort(c + 1, c + N + 1);
    for (int i = 1; i <= N; i++) {
        if (q.size() < c[i].d) q.push(c[i].g);
        else if (c[i].g > q.top()) {
            q.pop();
            q.push(c[i].g);
        }
    }
    while (q.size()) {
        ans += q.top();
        q.pop();
    }
    printf("%d", ans);
    return 0;
}