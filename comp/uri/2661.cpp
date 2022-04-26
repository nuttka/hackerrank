#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 10000

using namespace std;



int cc;
set<unsigned long long> sp;


bool verify (unsigned long long div) {
    if (div==1) return false;
    bool ret = false;
    for (unsigned long long i=2; i<=sqrt(div); i++) {
        if (div%(i*i) == 0) {
            return false;
        }
        if (div%i == 0) {
            ret = true;
        }
    }

    return ret;

}


int main() {
    _;
    unsigned long long value;
    cin >> value;
    cc = 0;
    
    for (unsigned long long i=1; i<=sqrt(value); i++) {
    // for (unsigned long long i=1; i<=value/2; i++) {
        if (value%i == 0) {
            if (verify(i)) {
                // cout << i << endl;
                cc++;
            }
            if (i != value/i) {
                if (verify(value/i)) {
                    cc++;
                    // cout << i << endl;    
                }
            }
        }
    }

    cout << cc << endl;

    return 0;
}