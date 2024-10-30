#include <bits/stdc++.h>
using namespace std;
int n, d, v[100001], a[100001];
long double rem;
long long ans;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("road.in", "r", stdin);
        freopen("road.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &d);
    for (int i = 1; i < n; i++) scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1, mina = 100000; i <= n; i++) {
        mina = min(mina, a[i]);
        long double req = 1.0 * v[i] / d - rem;
        if (req > 0) {
            ans += ceil(req) * mina;
            rem = ceil(req) - req;
        }
        else rem -= 1.0 * v[i] / d;
    }
    printf("%lld", ans);
    return 0;
}