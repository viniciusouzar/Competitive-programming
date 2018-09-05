#include <bits/stdc++.h>
using namespace std;

int getSum(int BITree[], int index) {
    int sum = 0;
    index = index + 1;
    while(index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBit(int BITree[], int n, int index, int val) {
    index = index + 1;
    while(index <= n) {
        BITree[index] += val;
        index += index & (-index);    
    }
}


int main() {

    int n, idx;
    char c;
    scanf("%d", &n);

    int *bitT = new int[n+1];
    int v[n+1];

    for(int i=0; i <= n; ++i) bitT[i] = 0;

    for(int i=0; i < n; ++i) {
        scanf("%d", &v[i]);
        updateBit(bitT, n, i, v[i]);
    }

    while(cin >> c >> idx && !cin.eof ()) {
        --idx;
        if(c == 'a') {
            updateBit(bitT, n, idx, -v[idx]);
        }

        else printf("%d\n", getSum(bitT, idx-1));
    }
 
    return 0;
}