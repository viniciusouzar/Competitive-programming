#include <bits/stdc++.h>

int gcd(int a, int b) {
    if(a == 0) return b;
    else return gcd(b%a, a);
}

int mmc(int a, int b) {
    return a * ( b / gcd(a, b));
}

int main() {

    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", mmc(x,y));
    return 0;
}