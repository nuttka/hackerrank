#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 10000

using namespace std;



int main() {
    _;

    string aa,bb;

    cin >> aa >> bb;

    int count = 0;

    for (int i=0; i<=aa.size()-bb.size(); i++) {
        bool ok = true;
        for (int j=0; j<bb.size(); j++) {
            if (bb[j] == aa[i+j]) ok = false;
        }

        if (ok) {
            count++;
        }
    }

    cout << count << endl;


    return 0;
}