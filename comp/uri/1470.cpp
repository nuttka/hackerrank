#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 99  

using namespace std;


char ss;
int m;
vector<int> out;


vector<int> dobra(vector<int> arr, int p) {
    int size = arr.size();
    vector<int> no;

    // if (p == 0) {
    //     reverse(arr.begin(), arr.end());
    //     return arr;
    // } else 
    if (static_cast<float>(p) == static_cast<float>(size)/2) {
        // cout << "p==" << endl;
        for (int i=0; i<size/2; i++) {
            no.push_back(arr[i] + arr[size-1-i]);
        }
    } else if (static_cast<float>(p) > static_cast<float>(size)/2) {
        // cout << "p>" << endl;
        for (int i=0; i<size-(2*(size-p)); i++) {
            no.push_back(arr[i]);
        }
        for (int i=size-(2*(size-p)), j=0; i<MAX; i++) {
            if (i >= size-1-j) break;
            no.push_back(arr[i] + arr[size-1-j]);
            j++;
        }
    } else if (static_cast<float>(p) < static_cast<float>(size)/2) {
        // cout << "p<" << endl;
        for (int i=size-1; i>(2*p)-1 ; i--) {
            no.push_back(arr[i]);
        }
        for (int i=0; i<p; i++) {
            no.push_back(arr[i] + arr[2*p-i-1]);
        }
    }

    return no;
}

void verify (int n, vector<int> in) {
    if (ss == 'S') return;

    // if (n == m && equal(out.begin(), out.end(), in.begin())) {
    //     ss = 'S';
    //     return;
    // }

    if (n == m) {
        if (equal(out.begin(), out.end(), in.begin())) {
            ss = 'S';
            return;
        }
        reverse(in.begin(), in.end());
        if (equal(out.begin(), out.end(), in.begin())) {
            ss = 'S';
            return;
        }
    }

    if (n<=m) return;

    for (int i=1; i<in.size(); i++) {
        // cout << "como era:" << endl;
        // for (int k=0; k<in.size(); k++) {
        //     cout << in[k] << " ";
        // }
        // cout << endl;

        vector<int> d = dobra(in, i);

        // cout << "verify, p= " << i << endl;
        // for (int k=0; k<d.size(); k++) {
        //     cout << d[k] << " ";
        // }
        // cout << endl;

        verify(d.size(), d);
    }


}



int main() {
    _;
    int n;
    vector<int> in;
    
    while (cin >> n) {
        ss = 'N';
        in.clear();out.clear();
        // cin >> n;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            in.push_back(a);
        }
        cin >> m;
        for (int i=0; i<m; i++) {
            int a;
            cin >> a;
            out.push_back(a);
        }

        verify(n, in);
        
        cout << ss << endl;
    }
    return 0;
}