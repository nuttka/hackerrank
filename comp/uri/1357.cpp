#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 123

using namespace std;


string n1[] = {{"*."}, {".."}, {".."}};
string n2[] = {{"*."}, {"*."}, {".."}};
string n3[] = {{"**"}, {".."}, {".."}};
string n4[] = {{"**"}, {".*"}, {".."}};
string n5[] = {{"*."}, {".*"}, {".."}};
string n6[] = {{"**"}, {"*."}, {".."}};
string n7[] = {{"**"}, {"**"}, {".."}};
string n8[] = {{"*."}, {"**"}, {".."}};
string n9[] = {{".*"}, {"*."}, {".."}};
string n0[] = {{".*"}, {"**"}, {".."}};


int main() {
    _;
    while(true) {
        int D;
        cin >> D;
        if (D == 0) return 0;
        char com = ' ';
        cin >> com;

        if(com == 'S') {
            string val;
            cin >> val;
            
            for (int j=0; j<3; j++) {
                for (int i=0; i<D; i++) {
                    if (val[i] == '0') {
                        if (i==D-1) cout << n0[j];
                        else cout << n0[j] << " ";
                        // cout << n0[j] << " ";
                    }
                    if (val[i] == '1') {
                        if (i==D-1) cout << n1[j];
                        else cout << n1[j] << " ";
                        // cout << n1[j] << " ";
                    }
                    if (val[i] == '2') {
                        if (i==D-1) cout << n2[j];
                        else cout << n2[j] << " ";
                        // cout << n2[j] << " ";
                    }
                    if (val[i] == '3') {
                        if (i==D-1) cout << n3[j];
                        else cout << n3[j] << " ";
                        // cout << n3[j] << " ";
                    }
                    if (val[i] == '4') {
                        if (i==D-1) cout << n4[j];
                        else cout << n4[j] << " ";
                        // cout << n4[j] << " ";
                    }
                    if (val[i] == '5') {
                        if (i==D-1) cout << n5[j];
                        else cout << n5[j] << " ";
                        // cout << n5[j] << " ";
                    }
                    if (val[i] == '6') {
                        if (i==D-1) cout << n6[j];
                        else cout << n6[j] << " ";
                        // cout << n6[j] << " ";
                    }
                    if (val[i] == '7') {
                        if (i==D-1) cout << n7[j];
                        else cout << n7[j] << " ";
                        // cout << n7[j] << " ";
                    }
                    if (val[i] == '8') {
                        if (i==D-1) cout << n8[j];
                        else cout << n8[j] << " ";
                        // cout << n8[j] << " ";
                    }
                    if (val[i] == '9') {
                        if (i==D-1) cout << n9[j];
                        else cout << n9[j] << " ";
                        // cout << n9[j] << " ";
                    }
                }
                cout << endl;
            }
        } else if (com == 'B') {
            string arr1[MAX], arr2[MAX], arr3[MAX];

            for (int k=0; k<D; k++) {
                cin >> arr1[k];
            }
            for (int k=0; k<D; k++) {
                cin >> arr2[k];
            }
            for (int k=0; k<D; k++) {
                cin >> arr3[k];
            }

            for (int i=0; i<D; i++) {
                if (arr1[i] == "*.") {
                    if (arr2[i] == "..") {
                        cout << 1;
                    } else if (arr2[i] == ".*") {
                        cout << 5;
                    } else if (arr2[i] == "*.") {
                        cout << 2;
                    } else if (arr2[i] == "**") {
                        cout << 8;
                    }
                } else if (arr1[i] == "**") {
                    if (arr2[i] == "..") {
                        cout << 3;
                    } else if (arr2[i] == ".*") {
                        cout << 4;
                    } else if (arr2[i] == "*.") {
                        cout << 6;
                    } else if (arr2[i] == "**") {
                        cout << 7;
                    }
                } else if (arr1[i] == ".*") {
                    if (arr2[i] == "*.") {
                        cout << 9;
                    } else if (arr2[i] == "**") {
                        cout << 0;
                    }
                }
            }
            cout << endl;
        }
    }
    


    return 0;
}