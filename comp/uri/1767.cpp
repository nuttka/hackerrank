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

int ks(int w, int i) {
    if (dp[i][w] != -1)
        return dp[i][w];

    if (i<=0 || w<=0) {
        dp[i][w] = 0;
        return dp[i][w];
    } else if (pesos[i-1] > w) {
        dp[i][w] = ks(w, i-1);
        return dp[i][w];
    } else {
        dp[i][w] = max(qtds[i-1] + ks(w-pesos[i-1], i-1), ks(w, i-1));
        return dp[i][w];
    }
}


pair<int,int> get_p_q(int w, int i) {
    int qtd = pac;
    int pes = 0;
    while (w>0 && i>0) {
        if (dp[i][w] != dp[i-1][w]) {
            pes += pesos[i-1];
            qtd--;
            w -= pesos[i-1];
        }
        i--;
    }
    return make_pair(pes, qtd);
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

        int result = ks(50, pac);
        pair<int, int> result2 = get_p_q(50, pac);

        cout << result << " brinquedos" << endl;
        cout << "Peso: " << result2.first << " kg" << endl;
        cout << "sobra(m) " << result2.second << " pacote(s)" << endl;

    }



    return 0;
}
