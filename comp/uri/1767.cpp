#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 123

using namespace std;

int qtds[MAX];
int pesos[MAX];
int pac;

int dp[MAX][MAX];

int ks(int w, int ia) {
    if (ia > 50) 
        return 0;

    if (dp[ia][w] != -1)
        return dp[ia][w];


    if (pesos[ia] > w) {
        dp[ia][w] = ks(w, ia+1);
        return dp[ia][w];
    } else {
        dp[ia][w] = max(qtds[ia] + ks(w - pesos[ia], ia+1), ks(w, ia+1));
        return dp[ia][w];
    }


}


int main() {
    _;

    int n;
    cin >> n;

    while (n--) {
        memset(qtds, 0, sizeof(qtds));
        memset(pesos, 0, sizeof(pesos));
        memset(dp, -1, sizeof(dp));
        cin >> pac;

        for (int i=0; i<pac; i++) {
            cin >> qtds[i] >> pesos[i];
        }

        // pair<int,int> result = ks(50, 0);

        // cout << dp[pac][50] << " brinquedos" << endl;
        // cout << "Peso: " << result.first << " kg" << endl;
        // cout << "sobra(m) " << pac-result.second << " pacote(s)" << endl;

    }



    return 0;
}