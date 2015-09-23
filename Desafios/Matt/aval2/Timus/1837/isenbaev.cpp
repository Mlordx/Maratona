/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P8 - 1837.Isenbaev's Number
*/

#include <bits/stdc++.h>

using namespace std;


int N;
map<string,int> number;
map<int,string> translator;
vector<int> adj[300];
vector<int> visited(300,0);
vector<int> dep(300,0);


int main(){

  cin >> N;
  int count = 0;

  for(int i = 0; i < N; i++){
      string bla1,bla2,bla3;
      cin >> bla1 >> bla2 >> bla3;
      auto it1 = number.find(bla1);
      auto it2 = number.find(bla2);
      auto it3 = number.find(bla3);

      if(it1 == number.end()){ translator.insert(make_pair(count,bla1)); number.insert(make_pair(bla1,count)); count++; }
      if(it2 == number.end()){ translator.insert(make_pair(count,bla2)); number.insert(make_pair(bla2,count)); count++; }
      if(it3 == number.end()){ translator.insert(make_pair(count,bla3)); number.insert(make_pair(bla3,count)); count++; }

      adj[number.find(bla1)->second].push_back(number.find(bla2)->second);
      adj[number.find(bla2)->second].push_back(number.find(bla1)->second);

      adj[number.find(bla1)->second].push_back(number.find(bla3)->second);
      adj[number.find(bla3)->second].push_back(number.find(bla1)->second);

      adj[number.find(bla2)->second].push_back(number.find(bla3)->second);
      adj[number.find(bla3)->second].push_back(number.find(bla2)->second);
  }

  queue< pair<int,int> > q;
  int d = 0;
  auto it = number.find("Isenbaev");
  if(it != number.end()) q.push(make_pair(it->second,d));
  
  while(!q.empty()){
    auto a = q.front();
    q.pop();
    visited[a.first] = 1;
    if(!dep[a.first]) dep[a.first] = a.second;

    for(auto b = adj[a.first].begin(); b != adj[a.first].end(); b++){
      if(!visited[*b]){
	q.push(make_pair(*b,a.second+1));

      }
    }
    
  }

  for(auto x = number.begin(); x != number.end(); x++)
    if(x->first != "Isenbaev"  && x->first != "" && dep[x->second] == 0) cout << x->first << " undefined\n";
    else if(x->first != "")  cout << x->first << " " << dep[x->second] << endl;
  
  return 0;
}
