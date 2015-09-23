/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P4 - 1607.Taxi
*/


#include <bits/stdc++.h>

using namespace std;

int a,b,c,d;

int main(){
  cin >> a >> b >> c >> d;

  int n;

  while(a <= c){
    a += b;
    if(a > c) a = c;
    c -= d;
  }

  cout << a << endl;

  return 0;
}
