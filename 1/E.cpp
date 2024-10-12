#include <bits/stdc++.h>
using namespace std;
int n, maxa, cnt, a[1001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxa = max(maxa, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxa) {
            cnt++;
        }
    }
    printf(cnt % 2 ? "Alice" : "Bob");
    return 0;
}