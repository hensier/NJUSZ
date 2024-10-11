#include <bits/stdc++.h>
using namespace std;
int N, M, K, room[5001], vis[5001];
vector<pair<int, int>> portal[5001];
struct node {
    int x, val, cnt;
}; queue<node> q;
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
    read(N), read(M), read(K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1, x; j <= K; j++) {
            read(x);
            room[i] = (room[i] << 1) | x;
        }
    }
    for (int i = 1, x, y; i <= M; i++) {
        read(x), read(y);
        int val = 0;
        for (int j = 1, z; j <= K; j++) {
            read(z);
            val = (val << 1) | z;
        }
        portal[x].push_back({y, val});
    }
    q.push((node){1, 0, 0});
    while (q.size()) {
        node f = q.front();
        q.pop();
        f.val |= room[f.x];
        if (vis[f.x] && (vis[f.x] & f.val) == f.val) continue;
        vis[f.x] = f.val;
        if (f.x == N) {
            printf("%d", f.cnt);
            return 0;
        }
        for (pair<int, int> p: portal[f.x]) {
            if ((f.val & p.second) == p.second) {
                q.push((node){p.first, f.val, f.cnt + 1});
            }
        }
    }
    printf("No Solution");
    return 0;
}