#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 500000000

using namespace std;





int n, c, t, e = 1, d = MAX, ff = 1, mm;




bool verify(vector<int> &pip) {
    int can = t*mm, comp = 1, cana = t*mm;

    for (int i=0; i<pip.size(); i++) {

        if (cana >= pip[i]) {
            cana -= pip[i];

        } else {

            if (comp == c) {
                return false;
            } else {
                comp++;
                cana = can;
                i--;
            }
        }
    }

    return true;
}

int main() {
    _;

    cin >> n >> c >> t;

    vector<int> pip(n, 0);

    for (int i=0; i<n; i++) {
        int aa;
        cin >> aa;
        pip[i] = aa;
    }

    while(e <= d) {
        mm = (e + d)/2;

        if (verify(pip)) {
            ff = mm;
            d = mm - 1;
        } else {
            e = mm + 1;
        }      
    }

    if (verify(pip)) {
        cout << ff << endl;
    } else {
        cout << e << endl;
    }

    return 0;
}