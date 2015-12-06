/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema PXX - 174B - Cows and Poker Game
*/


#include <bits/stdc++.h>

using namespace std;

int N;

int nA,nF,nI;

int main(){

  cin >> N;

  for(int i = 0; i < N; i++){
    char a;
    cin >> a;
    if(a == 'A') nA++;
    if(a == 'F') nF++;
    if(a == 'I') nI++;
  }

  if(nI == 0) cout << nA << endl;
  else if(nI == 1) cout << "1\n";
  else if(nI >= 2) cout << "0\n";
  
  
  return 0;
}
