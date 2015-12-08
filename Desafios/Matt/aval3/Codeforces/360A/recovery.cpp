/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema P4 - 210A - Levko and Array Recovery
*/

#include <bits/stdc++.h>

using namespace std;

int N,M;

struct op{
  int t;
  int l;
  int r;
  int val;
};

int numbers[5001];
op ops[5001];


int main(){
  cin >> N >> M;

  for(int i = 0; i <= N; i++) numbers[i] = 1e9;

  for(int i = 1; i <= M; i++){
    int t;
    int l,r,val;
    cin >> t >> l >> r >> val;
    ops[i].t = t;
    ops[i].l = l;
    ops[i].r = r;
    ops[i].val = val;

    if(t == 1){
      for(int k = l; k <= r; k++) numbers[k] += val;
    }else{
      for(int k = l; k <= r; k++){
	numbers[k] = min(numbers[k],val);
      }
    }
  }
  for(int i = M; i>=1; i--){
    int L = ops[i].l;
    int R = ops[i].r;
    if(ops[i].t == 1){
      for(int j = L; j <= R; j++)
	numbers[j] -= ops[i].val;
    }else{
      bool check = false;

      for(int j = L; j <= R; j++){
	if(numbers[j] == ops[i].val){
	  check = true;
	  break;
	}
      }
      if(!check){ cout << "NO\n"; return 0;}
      
    }
  }

  cout << "YES\n";

  for(int i = 1; i <= N; i++) cout << numbers[i] << " ";
  cout << endl;

  return 0;
}
