#include <bits/stdc++.h>

using namespace std;
typedef vector<int> BigInt;


BigInt integer(string a){
  BigInt res;
  char x = '0';

  for(int i = a.length()-1; i >=0 ;i--)
    res.push_back(a[i] - x);

  return res;
}

BigInt sum(BigInt a,BigInt b){
  int l = max(a.size(),b.size());
  int carry = 0;
  BigInt resp;
  
  for(int i = 0; i < l; i++){
    if(i < a.size()) carry += a[i];
    if(i < b.size()) carry += b[i];
    resp.push_back(carry%10);
    carry /= 10;
  }
  if(carry) resp.push_back(carry);

  return resp;
}

int main(){
  BigInt res;
  string aux;

  while(1){
    cin >> aux;
    if(aux == "0") break;

    BigInt bla = integer(aux);
    res = sum(res,bla);    
  }

  for(int x = res.size()-1; x >= 0;x--) cout << res[x];
  cout << endl;
  
  return 0;
}
