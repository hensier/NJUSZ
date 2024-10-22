// 洛谷 P1601 A+B Problem（高精）
// Submission: https://www.luogu.com.cn/record/184083195
// Time: 2024-10-22 20:48:49
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[501], b[501], ADD[501];
void swap(char *x, char *y) {
    char t[501];
    strcpy(t, x);
    strcpy(x, y);
    strcpy(y, t);
}
void reverse(char *s, int len) {
    for (char *l = s, *r = s + len - 1; l < r; l++, r--) {
        char t = *l;
        *l = *r;
        *r = t;
    }
}
void append(char *s, int ls, char c) {
    s[ls] = c;
    s[ls+1] = '\0';
}
char *add(char *a, char *b) {
    strcpy(ADD, a);
    if (strlen(ADD) < strlen(b)) swap(ADD, b);
    int la = strlen(ADD), lb = strlen(b);
    reverse(ADD, la);
    reverse(b, lb);
    for (int i = 0; b[i]; i++) {
        ADD[i] += b[i] - '0';
        if (!isdigit(ADD[i])) {
            ADD[i] -= 10;
            if (la == lb && i == lb - 1) append(ADD, la++, '1');
            else ADD[i+1]++;
        }
    }
    for (int i = lb; ADD[i] && !isdigit(ADD[i]); i++) {
        ADD[i] -= 10;
        if (i == la - 1) append(ADD, la++, '1');
        else ADD[i+1]++;
    }
    reverse(ADD, la);
    return ADD;
}
int main() {
    scanf("%s%s", a, b);
    printf("%s", add(a, b));
    return 0;
}