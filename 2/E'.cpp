// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/525673/submission/284624069
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int N, t[200001];
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int c) {
    for (int i = x; i <= N; i += lowbit(i)) t[i] += c;
}
int query(int x) {
    int s = 0;
    for (int i = x; i; i -= lowbit(i)) s += t[i];
    return s;
}
int find(int x) {
    int l = 1, r = N;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (query(mid) >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
struct person {
    int pos, val, id;
    bool operator<(const person &x) const {
        return id < x.id;
    }
} p[200001];
namespace IO {
    char buf[1 << 21], *p1 = buf, *p2 = buf, obuf[1 << 21], *p3 = obuf;
    char gc() {
        if (p1 == p2) {
            p1 = buf;
            p2 = buf + fread(buf, 1, 1 << 21, stdin);
        }
        return p1 == p2 ? EOF : *p1++;
    }
    template<typename T> bool read(T &x) {
        x = 0;
        char ch = gc();
        if (ch == EOF) return false;
        while (!isdigit(ch)) ch = gc();
        while (isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 48);
            ch = gc();
        }
        return true;
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
    while (read(N)) {
        for (int i = 1; i <= N; i++) {
            read(p[i].pos), read(p[i].val);
            p[i].pos++;
        }
        memset(t, 0, sizeof(t));
        for (int i = 1; i <= N; i++) add(i, 1);
        for (int i = N; i; i--) {
            p[i].id = find(p[i].pos);
            add(p[i].id, -1);
        }
        sort(p + 1, p + N + 1);
        for (int i = 1; i <= N; i++) write(p[i].val), pc(' ');
        pc('\n');
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}