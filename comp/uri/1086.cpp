#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 123456
#define INF 0x3f3f3f
using namespace std;


int m, n, l, k;





int verify(int larg, int alt, set<int> tabs, vector<int> used) {
    set<int>::reverse_iterator it = tabs.rbegin();
    int col = (larg*100)/l;
    int qntTabuas = 0;

    while(col > 0 && it != tabs.rend()) {
        int aux = *it;
        int rest = alt - aux;

        if (used[aux] <= 0 || rest < 0) {
            it++;
            continue;
        }
        if (rest == aux) {
            if (used[rest] <= 1) {
                it++;
                continue;
            }
        } else {
            if (rest != 0 && used[rest] <= 0) {
                it++;
                continue;
            }
        }

        used[aux]--;
        used[rest]--;

        if (rest) {
            qntTabuas += 2;
        } else {
            qntTabuas += 1;
        }

        col--;
    }

    return col > 0 ? INF : qntTabuas;
}





int main() {
    _;

    while (true) {
        cin >> m >> n;
        if (m==0 && n==0) break;
        cin >> l >> k;
        
        vector<int> used(MAX, 0);
        set<int> tabs;

        for (int i=0; i<k; i++) {
            int aa;
            cin >> aa;
            used[aa]++;
            tabs.insert(aa);
        }

        int ccTabuas = INF;
        // case m
        if ((m*100)%l == 0) {
            ccTabuas = min(ccTabuas, verify(m, n, tabs, used));
        }
        // case n
        if ((n*100)%l == 0) {
            ccTabuas = min(ccTabuas, verify(n, m, tabs, used));
        }


        if (ccTabuas == INF) {
            cout << "impossivel" << endl;
        } else {
            cout << ccTabuas << endl;
        }
        
    }




    return 0;
}
