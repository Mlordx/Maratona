/*
  Nome: Mateus Barros Rodrigues
  NUSP: 7991037
  MAC0327 - 2o Sem 2015
  3a Aval
  Problema PXX - 14B - Young Photographer
*/

#include <bits/stdc++.h>

using namespace std;

int n,x0;

int main(){

  cin >> n >> x0;

  int l = -1;
  int r = 1 << 29;
  
  for(int i = 0; i < n; i++){
    int a,b;
    cin >> a >> b;
    if(a > b){
      int aux = a;
      a = b;
      b = aux;
    }
    
    if(a > l) l = a;
    if(b < r) r = b;
  }

  if(l > r) cout << "-1\n";
  else if( x0 >= l && x0 <= r) cout << "0\n";
  else if(x0 < l) cout << l-x0 << endl;
  else if(x0 > r) cout << x0-r << endl;

  return 0;
}
