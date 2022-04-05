#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'



#define MAX 10000



using namespace std;

int main() {
   _;

   int n;
   cin >> n;

   for(int i=1; i<=n; i++) {
      int v, e;
      cin >> v >> e;

      int vs[122][122] = {0};
      int rejeitados[26] = {0};

      for (int j=97; j<97+v; j++) {
         vs[j][j] = 1;
      } 

      for (int j=0; j<e; j++) {
         char a,b;
         cin >> a >> b;

         vs[a][b] = 1;
         vs[b][a] = 1;

         for (int k=97; k<97+v; k++) {
            if (vs[a][k] == 1 || vs[b][k] == 1) {
               vs[k][b] = 1;
               vs[b][k] = 1;
               vs[k][a] = 1;
               vs[a][k] = 1;
               for (int l=97; l<97+v; l++) {
                  vs[k][l] |= vs[b][l];
                  vs[k][l] |= vs[a][l];
                  vs[l][k] = vs[k][l];
               }
            }
         }
      }



      // for (int j=97; j<97+v; j++) {
      //    for (int k=97; k<97+v; k++) {
      //       cout << vs[j][k] << ", ";
      //    }
      //    cout << endl;
      // }
      // cout << endl;



      cout << "Case #" << i << ":" << endl;

      int cc = 0;

      for (int j=97; j<97+v; j++) {
         if (rejeitados[97+v-j] == 1) continue;
         for (int k=97; k<97+v; k++) {
            if (vs[j][k] == 1) {
               cout << char(k) << ",";
               rejeitados[97+v-k] = 1;
            }
         }
         if(j == 97+v) break;
         cout << endl;
         cc++;
      }

      cout << cc << " connected components" << endl;

      cout << endl;
      
   }





   return 0;
}