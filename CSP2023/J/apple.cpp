#include <bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("apple.in", "r", stdin);
        freopen("apple.out", "w", stdout);
    #endif
    scanf("%d", &n);
    while (n > 0) {
        ans1++;
        if (ans2 == 0 && n % 3 == 1) ans2 = ans1;
        n -= ceil(n / 3.0);
    }
    printf("%d %d", ans1, ans2);
    return 0;
}