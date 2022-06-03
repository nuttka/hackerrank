#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 999
#define INF 0x3f3f3f

using namespace std;


int r, c, k;
int cine[MAX][MAX];
int aux[MAX];




int solve() {
    int area = INF;

    for (int i=0; i<r; i++) {
        memset(aux, 0, sizeof(int)*c);

        for (int j=i; j<r; j++) {
            for (int l=0; l<c; l++)
                aux[l] += cine[j][l];

            int seats = 0, aux2 = 0;

            for (int l=0; l<c; l++) {
                seats += aux[l];

                while((aux2 < l) && (seats >= k + aux[aux2])) {
                    seats -= aux[aux2];
                    aux2++;
                }

                if (seats >= k)
                    area = min(area, (abs(aux2-l) + 1) * (abs(i-j) + 1));

            }

        }

    }

    return area;
}



int main() {
    _;
    
    while (cin >> r >> c >> k) {
        if (r == 0 && c == 0 && k == 0) 
            return 0;

        memset(cine, 0, sizeof(cine));
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                char c;
                cin >> c;
                if (c == '.') 
                    cine[i][j] = 1;
            }
        }

        int res = solve();

        cout << res << endl;
    }


    return 0;
}