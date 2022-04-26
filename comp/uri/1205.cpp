#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 1234
#define INF 0x3f3f3f
using namespace std;


int n, m, k, p[MAX][MAX], na, a[2345], start, fim;
long double prob;
int visited[MAX], val[MAX], minn;



int djk() {
    for (int i=1; i<n; i++) {
        int next, min = INF;
        for (int j=1; j<=n; j++) {
            if (visited[j] == 0 && val[j] < min) {
                min = val[j];
                next = j;
            }
            visited[next] = 1;
        }
        for (int j=1; j<=n; j++) {
            if (visited[j] == 0 && p[next][j] != 0 && (val[next] + a[j] < val[j])) {
                val[j] = val[next] + a[j];
            }
        }
    }

    return val[fim];
}   

// int djk() {
//     vector<int> val(MAX, INF);
//     val[start] = a[start];
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

//     q.push({val[start], start});

//     while(!q.empty()) {
//         int tt = q.top().second;
//         q.pop();

//         for (int i=0; i<n; i++) {
//             if (p[tt][i] == 1 && val[tt] + a[i] < val[i]) {
//                 val[i] = val[tt] + a[i];
//                 q.push({val[i], i});
//             }
//         }
//     }
//     return val[fim];
// }


long double calc() {
    if (minn>k) return 0.000;
    return pow(prob, minn);
}



int main() {
    _;

    while (cin >> n >> m >> k >> prob) {
        // cin >> n >> m >> k >> prob;
        memset(p, 0, sizeof(p));
        memset(a, 0, sizeof(a));
        memset(visited, 0, sizeof(visited));
        memset(val, INF, sizeof(val));
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            p[a][b] = 1;
            p[b][a] = 1;
        }
        cin >> na;
        for (int i=0; i<na; i++) {
            int aa;
            cin >> aa;
            a[aa]++;
        }
        cin >> start >> fim;

        val[start] = a[start];
        minn = djk();
        long double pf = calc();

        cout << fixed;
        cout << setprecision(3);
        cout << pf << endl;
    }

    return 0;
}