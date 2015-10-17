/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P21 - 1213.Cockroaches!
*/

#include <bits/stdc++.h>

using namespace std;

set<string> compartments;

int main(){
  string cmpt;

  cin >> cmpt;
  compartments.insert(cmpt);
  string c = "-";
  while(1){
    string token;
    cin >> cmpt;
    if(cmpt == "#") break;
    auto pos = cmpt.find(c);
    while((pos = cmpt.find(c)) != string::npos){
      token = cmpt.substr(0,pos);
      compartments.insert(token);
      cmpt.erase(0,pos+1);
    }
    compartments.insert(cmpt);
  }

  cout << compartments.size()-1 << endl;
  return 0;
}
