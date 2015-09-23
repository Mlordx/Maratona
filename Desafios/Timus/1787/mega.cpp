/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P5 - 1787.Turn for MEGA
*/


#include<bits/stdc++.h>

using namespace std;

int k,n;

int main(){
  cin >> k >> n;

  int cars = 0;
  for(int i = 0; i < n; i++){
    int bla = 0;
    cin >> bla;
    if((cars+bla) < k) cars = 0;
    else cars += bla-k;
    
  }
  cout << cars << endl;
  
  return 0;
}
