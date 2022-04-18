#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 10000

using namespace std;


int x[4];
int a,b,c;

int main() {
    _;
    
    cin >> x[0] >> x[1] >> x[2] >> x[3];

    int m = x[0];

    for (int i=0; i<4; i++) {
        m = max(m, x[i]);
    }

    for (int i=0; i<4; i++) {
        if(m!=x[i])
            cout << m-x[i] << " ";
    }

    return 0;
}