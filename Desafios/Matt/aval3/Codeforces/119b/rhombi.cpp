/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema PXX - 119B - Counting Rhombi
*/

#include <bits/stdc++.h>

using namespace std;

int w,h;

int main(){

  cin >> w >> h;

  long long sum = 0;
  for(int i = 2; i <= w; i+=2){
    for(int j = 2; j <= h; j+=2){
	sum += (w-i+1)*(h-j +1);
    }
  }

  cout << sum << endl;

  return 0;
}
