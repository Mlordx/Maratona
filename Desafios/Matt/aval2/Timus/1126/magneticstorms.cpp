/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P24 - 1126.Magnetic Storms
*/


#include <bits/stdc++.h>

using namespace std;

int values[25001];
int M;

int main(){
  cin >> M;

  int aux;

  int N = 0;
  while((cin >> aux)&& aux != -1){
    values[N++] = -1*aux;
  }

  multiset<int> storm;
  for(int i = 0; i < N; i++){
    storm.insert(values[i]);
    if(i >= M-1){
      auto bla = *(storm.begin());
      cout << -1*bla  << endl;
      auto val = storm.find(values[i-M+1]);
      storm.erase(val);
    }
  }


  return 0;
}
