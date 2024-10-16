// 洛谷 P2142 高精度减法
// Submission: https://www.luogu.com.cn/record/182560086
// Time: 2024-10-16 20:35:58
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
char op, a[10087], b[10087], SUB[10088];
void reverse(char *s, int len) {
    for (char *l = s, *r = s + len - 1; l < r; l++, r--) {
        char t = *l;
        *l = *r;
        *r = t;
    }
}
void swap(char *x, char *y) {
    char t[10087];
    strcpy(t, x);
    strcpy(x, y);
    strcpy(y, t);
}
bool smaller(char *a, char *b, int la, int lb) {
    if (la != lb) return la < lb;
    return strcmp(a, b) < 0;
}
char *subtract(char *a, char *b) {
    strcpy(SUB, a);
    bool neg = false;
    if (smaller(SUB, b, strlen(SUB), strlen(b))) {
        neg = true;
        swap(SUB, b);
    }
    int la = strlen(SUB), lb = strlen(b);
    reverse(SUB, la);
    reverse(b, lb);
    for (int i = 0; b[i]; i++) {
        SUB[i] -= b[i] - '0';
        if (!isdigit(SUB[i])) {
            SUB[i] += 10;
            SUB[i+1]--;
        }
    }
    for (int i = lb; SUB[i] && !isdigit(SUB[i]); i++) {
        SUB[i] += 10;
        SUB[i+1]--;
    }
    reverse(SUB, la);
    int pos = 0;
    while (SUB[pos+1] && SUB[pos] == '0') pos++;
    strncpy(SUB, SUB + pos, la - pos);
    for (int i = la - pos; SUB[i]; i++) SUB[i] = '\0';
    if (neg) {
        char t[10088] = "";
        strncpy(t + 1, SUB, strlen(SUB));
        t[0] = '-';
        strcpy(SUB, t);
    }
    reverse(b, lb);
    return SUB;
}
int main() {
    scanf("%s%s", a, b);
    printf("%s", subtract(a, b));
    return 0;
}