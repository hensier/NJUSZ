// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/556471/submission/285018979
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int N, cnt, root;
struct node {
    int ls, rs, val, rnd, siz;
} t[100001];
void push_up(int p) {
    t[p].siz = t[t[p].ls].siz + t[t[p].rs].siz + 1;
}
void split(int p, int &l, int &r, int k) {
    if (p == 0) {
        l = r = 0;
        return;
    }
    if (t[p].val <= k) {
        l = p;
        split(t[p].rs, t[p].rs, r, k);
    }
    else {
        r = p;
        split(t[p].ls, l, t[p].ls, k);
    }
    push_up(p);
}
int merge(int l, int r) {
    if (l == 0 || r == 0) return l | r;
    if (t[l].rnd < t[r].rnd) {
        t[l].rs = merge(t[l].rs, r);
        push_up(l);
        return l;
    }
    else {
        t[r].ls = merge(l, t[r].ls);
        push_up(r);
        return r;
    }
}
void insert(int k) {
    int x, y, c = ++cnt;
    t[c].val = k;
    t[c].rnd = rand();
    t[c].siz = 1;
    split(root, x, y, k);
    root = merge(merge(x, c), y);
}
int query_kth(int p, int k) {
    if (k == t[t[p].ls].siz + 1) return t[p].val;
    if (k <= t[t[p].ls].siz) return query_kth(t[p].ls, k);
    else return query_kth(t[p].rs, k - t[t[p].ls].siz - 1);
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
    read(N);
    for (int i = 1, a; i <= N; i++) {
        read(a);
        insert(a);
        if (i % 2 == 1) {
            write(query_kth(root, i / 2 + 1));
            pc('\n');
        }
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}