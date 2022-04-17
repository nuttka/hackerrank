#include <bits/stdc++.h>
#define _                        \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);
#define endl '\n'
#define MAX 123
using namespace std;





int n, v, e, visited[MAX], vs[MAX][MAX], lenC;
char cam[MAX];



void dfs(int j, int v) {
   // cout << "aqui" << endl;
   // for (int i=0; i<lenC; i++) {
   //    cout << cam[i]+'a' << " ";
   // }
   // cout << endl;
   visited[j] = 1;
   cam[lenC] = j + 'a';
   lenC++;
   // cout << " cam = " << cam[lenC] << endl;

   for (int i=0; i<v; i++) {
      if (vs[j][i] == 1) {
         if (visited[i] == 0) {
            dfs(i, v);
         }
      }
   }
}

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int bbs(char *arr, int len) {
   for (int i=0; i<len; i++) {
      for (int j=0; j<len-i-1; j++) {
         if (arr[j] > arr[j+1]) {
            swap(&arr[j], &arr[j+1]);
         }
      
      }
   }
}

int main() {
   _;

   cin >> n;

   for(int i=1; i<=n; i++) {
      memset(visited, 0, sizeof(visited));
      memset(vs, 0, sizeof(vs));

      cin >> v >> e;

      for (int j=0; j<e; j++) {
         char a,b;
         cin >> a >> b;

         vs[a - 'a'][b - 'a'] = 1;
         vs[b - 'a'][a - 'a'] = 1;
      }


      // for (int j=0; j<v; j++) {
      //    for (int k=0; k<v; k++) {
      //       cout << vs[j][k] << " ";
      //    }
      //    cout << endl;
      // }




      cout << "Case #" << i << ":" << endl;

      int cc = 0;

      for (int j=0; j<v; j++) {
         lenC = 0;
         if (visited[j] == 0) {
            cc++;
            dfs(j, v);
            bbs(cam, lenC);
            for (int k=0; k<lenC; k++) {
               cout << cam[k] << ",";
            }

            cout << endl;
            memset(cam, 0, sizeof(cam));
         }
      }

      cout << cc << " connected components" << endl;
      cout << endl;
   }





   return 0;
}