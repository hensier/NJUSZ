// Submission: https://codeforces.com/group/fVoe9GOJPd/contest/567353/submission/292284841
// Verdict: Accepted
#include <bits/stdc++.h>
using namespace std;
int n;
double sum, a[100001];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
        sum += a[i];
    }
    printf("%.8lf", sum / (n + 1) * 2);
    for (int i = 2; i <= n; i++) printf(" %.8lf", sum / (n + 1));
    return 0;
}