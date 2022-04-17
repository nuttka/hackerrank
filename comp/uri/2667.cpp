#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 10000

using namespace std;



int main() {
    _;

    string val;
    cin >> val;
    int sum = 0;
    for (int i=0; i<val.size(); i++) {
        sum += int(val[i]);
    }

    cout << sum%3 << endl;


    return 0;
}