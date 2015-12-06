#include <bits/stdc++.h>

using namespace std;

int n;

int perm[2000001];
int perm2[2000001];
int position[2000001];

int main(){
  cin >> n;

  for(int i = 1; i <= n; i++) cin >> perm[i];
  for(int i = 1; i <= n; i++) cin >> perm2[i];
  for(int i = 1; i <= n; i++) position[perm2[i]] = i;

  int aux = 0;
  for(int i = 1; i <= n; i++){
    if(aux <= position[perm[i]]) aux = position[perm[i]];
    else{
      cout << n - i + 1 << endl;
      return 0;
    }
  }
    

  
  cout << "0\n";
  
  return 0;
}
