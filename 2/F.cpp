#include <bits/stdc++.h>
using namespace std;
int N, M, cnt, head[17];
vector<int> v[2];
struct node {
    int nxt, to, w[2];
} e[121];
void add_edge(int A, int B, int C, int D) {
    e[++cnt] = (node){head[A], B, {C, D}};
    head[A] = cnt;
}
void dfs(int u, int tot, int type) {
    if (u == N) {
        v[type].push_back(tot);
        return;
    }
    for (int i = head[u]; i; i = e[i].nxt) dfs(e[i].to, tot + e[i].w[type], type);
}
int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1, A, B, C, D; i <= M; i++) {
        scanf("%d%d%d%d", &A, &B, &C, &D);
        add_edge(A, B, C, D);
    }
    for (int i = 0; i < 2; i++) dfs(1, 0, i);
    if (v[0].empty()) {
        printf("IMPOSSIBLE");
        return 0;
    }
    for (int i = 0; i < 2; i++) sort(v[i].begin(), v[i].end());
    for (int i = 0; i < v[0].size(); i++) {
        int pos = lower_bound(v[1].begin(), v[1].end(), v[0][i]) - v[1].begin();
        if (v[1][pos] == v[0][i]) {
            printf("%d", v[0][i]);
            return 0;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}