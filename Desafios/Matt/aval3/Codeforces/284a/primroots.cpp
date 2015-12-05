/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema PXX - 174A - Cows and Primitive Roots
*/

#include <bits/stdc++.h>

using namespace std;

int p;

int main(){
  cin >> p;

  int resp = 0;
  for(int i = 1; i < p; i++){
    int count = 0; 
    int x = i;
    if((x-1)%p == 0) count--;
    for(int j = 2; j < p; j++){
      x = (x*i)%p;
      if((x-1)%p == 0){
	if(j == p-1) count++;
	else count--;
      }
    }
    if(count == 1) resp++;
  }
  if(p == 2){ cout << 1 << endl; return 0; }
  cout << resp << endl;
  
  return 0;
}
