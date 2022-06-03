#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234

using namespace std;

int n, an[MAX], dp[MAX][MAX], dir, esq;


void verify() {
    for(int i=0; i<2*n; i++) {
        for(int j=0; i+j<2*n; j++) {
            if (i%2 == 0) {
                dp[j][i+j] = min(dp[j+1][i+j], dp[j][i+j-1]);
            } else {
                dp[j][i+j] = max(dp[j+1][i+j] + an[j], dp[j][i+j-1] + an[i+j]);
            }

        }
    }
}





int main() {
    _;

    while (cin >> n) {
        // esq = 0;
        // dir = 2*n - 1;
        if (n == 0) return 0;
        memset(an, 0, sizeof(an));
        memset(dp, 0, sizeof(dp));

        for(int i=0; i<2*n; i++) {
            cin >> an[i];
            an[i] = an[i]%2 == 0 ? 1 : 0;
        }

        // for(int i=0; i<2*n; i++) {
        //     cout << an[i] << ", ";
        // }

        

        verify();
        cout << dp[0][2*n-1] << endl;
    }
    
    

    return 0;
}