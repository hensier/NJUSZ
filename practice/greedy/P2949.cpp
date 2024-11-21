#include <bits/stdc++.h>
using namespace std;
int N;
long long ans;
priority_queue<int, vector<int>, greater<int>> q;
struct job {
    int D, P;
    bool operator<(const job &x) const {
        return D < x.D;
    }
} j[100001];
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
    for (int i = 1; i <= N; i++) read(j[i].D), read(j[i].P);
    sort(j + 1, j + N + 1);
    for (int i = 1; i <= N; i++) {
        if (q.size() < j[i].D) q.push(j[i].P);
        else if (j[i].P > q.top()) {
            q.pop();
            q.push(j[i].P);
        }
    }
    while (q.size()) {
        ans += q.top();
        q.pop();
    }
    printf("%lld", ans);
    return 0;
}