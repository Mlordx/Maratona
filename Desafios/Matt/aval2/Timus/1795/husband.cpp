/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P6 - 1795.Husband in a shop
*/


#include <bits/stdc++.h>

using namespace std;

struct customer{
  string prod;
  int qt;
  int old_qt;
  int ind;
  
  customer(string a, int b, int c, int d): prod(a), qt(b), old_qt(c), ind(d) {}
};

deque<customer> line;

map<string,int> products;

int n,m;

int main(){
  cin >> m;

  for(int i = 0; i < m; i++){
    string a,b;
    int c;

    cin >> c >> a >> b;
    products.insert(make_pair(b,c));
  }
  cin >> n;
  
  
  for(int i = 0; i < n; i++){
    string a,b;
    int c;
    cin >> c >> a >> b;
    customer bla = customer(b,c,0,i);
    line.push_back(bla);
  }

  if(n == 1){ cout << "1\n"; return 0; }


  int t = 0;

  while(!line.empty()){
    t++;
    auto front = line.front();
    auto p = products.find(front.prod);

    if(p == products.end()){
      line.pop_front();
      continue;
    }else{
      auto prod = *p;
      
      if(front.old_qt != 0){
	if(prod.second == front.old_qt){
	  products.erase(prod.first);
	  line.pop_front();
	  continue;
	}else{
	  line[0].old_qt = prod.second;
	  if(line.size() > 1 )swap(line[0],line[1]);
	  else break;
	  continue;
	}
      }else{
	if(front.qt <= prod.second){
	  auto aux = make_pair(prod.first,prod.second-front.qt);
	  products.erase(p);
	  if(aux.second != 0) products.insert(aux);
	  line.pop_front();
	}
      
	
	else{
	  line[0].old_qt = prod.second;
	  if(line.size() > 1 )swap(line[0],line[1]);
	  else break;
	}
      }
    }
  }

  cout << t << endl;

  return 0;
}
