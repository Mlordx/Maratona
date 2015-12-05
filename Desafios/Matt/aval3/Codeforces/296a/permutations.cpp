/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema PXX - 179A - Greg and Graph
*/

#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[1001];

int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    int aux;
    cin >> aux;
    cnt[aux]++;
  }

  for(int i = 0; i < 1001; i++){
    if(cnt[i] > (N+1)/2){ cout << "NO\n"; return 0; }
  }

  cout << "YES\n";
  

  return 0;
}
