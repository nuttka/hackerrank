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

pair<int, int> solve() {
    int qtdPacs = 0;
    int peso = 0;
    int pesoMaxAux = 50;

    for (int i=1; i<=pac; i++) {
        for (int j=1; j<=50; j++) {
            if(pesos[i-1] >= j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j - pesos[i-1]] + qtds[i-1], dp[i-1][j]);
            }
        }
    }

    for (int i=pac; i>0; i--) {
        if (dp[i][pesoMaxAux] != dp[i-1][pesoMaxAux]) {
            qtdPacs++;
            peso += pesos[i];
            if (pesoMaxAux-pesos[i] >= 0) {
                pesoMaxAux -= pesos[i];
            }
        }
    }

    return make_pair(peso, qtdPacs);
}


int main() {
    _;

    int n;
    cin >> n;

    while (n--) {
        memset(qtds, 0, sizeof(qtds));
        memset(pesos, 0, sizeof(pesos));
        memset(dp, 0, sizeof(dp));
        cin >> pac;

        for (int i=0; i<pac; i++) {
            cin >> qtds[i] >> pesos[i];
        }

        pair<int,int> result = solve();

        cout << dp[pac][50] << " brinquedos" << endl;
        cout << "Peso: " << result.first << " kg" << endl;
        cout << "sobra(m) " << pac-result.second << " pacote(s)" << endl;

    }



    return 0;
}