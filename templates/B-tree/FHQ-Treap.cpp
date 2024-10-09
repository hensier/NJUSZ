// 洛谷 P3369 【模板】普通平衡树
// Submission: https://www.luogu.com.cn/record/181094637
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n, cnt, root;
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
void del(int k) {
    int x, y, z;
    split(root, x, z, k);
    split(x, x, y, k - 1);
    y = merge(t[y].ls, t[y].rs);
    root = merge(merge(x, y), z);
}
int query_rank(int k) {
    int x, y;
    split(root, x, y, k - 1);
    int r = t[x].siz + 1;
    merge(x, y);
    return r;
}
int query_kth(int p, int k) {
    if (k == t[t[p].ls].siz + 1) return t[p].val;
    if (k <= t[t[p].ls].siz) return query_kth(t[p].ls, k);
    else return query_kth(t[p].rs, k - t[t[p].ls].siz - 1);
}
int pre(int k) {
    int x, y;
    split(root, x, y, k - 1);
    int p = query_kth(x, t[x].siz);
    merge(x, y);
    return p;
}
int nxt(int k) {
    int x, y;
    split(root, x, y, k);
    int n = query_kth(y, 1);
    merge(x, y);
    return n;
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
        if (x < 0) {
            pc('-');
            x = -x;
        }
        if (x > 9) write(x / 10);
        pc(x % 10 + 48);
    }
} using namespace IO;
int main() {
    read(n);
    for (int i = 1, opt, x; i <= n; i++) {
        read(opt), read(x);
        switch (opt) {
            case 1: {
                insert(x);
                break;
            }
            case 2: {
                del(x);
                break;
            }
            case 3: {
                write(query_rank(x));
                pc('\n');
                break;
            }
            case 4: {
                write(query_kth(root, x));
                pc('\n');
                break;
            }
            case 5: {
                write(pre(x));
                pc('\n');
                break;
            }
            case 6: {
                write(nxt(x));
                pc('\n');
                break;
            }
        }
    }
    fwrite(obuf, p3 - obuf, 1, stdout);
    return 0;
}