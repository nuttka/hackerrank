#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 3000

using namespace std;


int n, m, a;
int g[MAX][MAX];
int path[51];



int main() {
    _;

    while (true) {
        cin >> n >> m >> a;
        if (n == 0 && m == 0 && a == 0) break;

        memset(g, -1, sizeof(g));
        memset(path, 0, sizeof(path));

        for (int i=0; i<m; i++) {
            int o, d, s;
            cin >> o >> d >> s;

            g[o][d] = s;
            // g[d][o] = s;
        }

        path[1] = a;

        stack<int> s;
        int count = 0;
        s.push(1);
        
        while (path[n] < a) {
            stack<int> s2;
            s2.push(1);

            while (!s.empty()) {
                int aer = s.top();
                s.pop();
                for (int i=2; i<=n; i++) {
                    if (g[aer][i] != -1) {
                        // cout << aer << " " << i << endl;
                        // cout << "n = " << path[n] << endl;
                        path[i] += min(g[aer][i], path[aer]);

                        // cout << count << " -- " << endl;
                        // for (int o=1; o<=n; o++) {
                        //     cout << path[o] << ", ";
                        // }
                        // cout << endl;

                        if (aer != 1)
                            path[aer] -= min(g[aer][i], path[aer]);
                        if(i != n) 
                            s2.push(i);
                    }
                }
            }
            s = s2;
            count++;
        }

        cout << count << endl;

        

    }
    
    return 0;
}