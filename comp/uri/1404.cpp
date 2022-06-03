#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 123

using namespace std;

int n, m, b[30][30], v[30][30];
int ci, cj;




int solve(int i, int j) {
    
    int cc = 0;
    if (i+2<n && j+2<m && (b[i+2][j+2] == 0 || (i+2 == ci && j+2 == cj)) && b[i+1][j+1] == 2 && v[i+1][j+1] == 0) {
        v[i+1][j+1] = 1;
        cc = max(solve(i+2, j+2)+1, cc);
        v[i+1][j+1] = 0;
    }
    if (i+2<n && j-2>=0 && (b[i+2][j-2] == 0 || (i+2 == ci && j-2 == cj)) && b[i+1][j-1] == 2 && v[i+1][j-1] == 0) {
        v[i+1][j-1] = 1;
        cc = max(solve(i+2, j-2)+1, cc);
        v[i+1][j-1] = 0;
    }
    if (j+2<m && i-2>=0 && (b[i-2][j+2] == 0 || (i-2 == ci && j+2 == cj)) && b[i-1][j+1] == 2 && v[i-1][j+1] == 0) {
        v[i-1][j+1] = 1;
        cc = max(solve(i-2, j+2)+1, cc);
        v[i-1][j+1] = 0;
    }
    if (i-2>=0 && j-2>=0 && (b[i-2][j-2] == 0 || (i-2 == ci && j-2 == cj)) && b[i-1][j-1] == 2 && v[i-1][j-1] == 0) {
        v[i-1][j-1] = 1;
        cc = max(solve(i-2, j-2)+1, cc);
        v[i-1][j-1] = 0;
    }
    
    return cc;
}






int main() {
    _;

    while (cin >> n) {
        cin >> m;
        if (n == 0 && m ==0) break;
        memset(b, 0, sizeof(b));
        memset(v, 0, sizeof(v));
        for (int i=0; i<n; i++) {
			for (int j=(i%2); j<m; j+=2){
				cin >> b[i][j];
			}
		}


        int cc = 0;
        for (int i=0; i<n; i++) {
			for (int j=(i%2); j<m; j+=2){
				if (b[i][j] == 1) {
                    ci = i;
                    cj = j;
                    cc = max(solve(i, j), cc);
                }
			}
		}

        cout << cc << endl;

    }
 
    return 0;
}