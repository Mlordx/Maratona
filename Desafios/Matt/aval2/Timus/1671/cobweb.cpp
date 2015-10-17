/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P14 - 1671.Anansi's Cobweb
*/

#include <bits/stdc++.h>

using namespace std;


int N,M,Q;
vector< pair<int,int> > edges;
#define MAXV 100001

int id[MAXV], tam[MAXV],rnk[MAXV];

void UFInit(int n){
  for(int i = 0; i < n; i++){ id[i] = i; tam[i] = 1;}
}

int UFFind(int a){
  if (id[id[a]]!=id[a])
    id[a] = UFFind(id[a]);
  return id[a];
}

void UFUnion(int a, int b){
  int Paia = UFFind(a), Paib = UFFind(b);
  if(Paia == Paib) return;

  if(tam[Paia] < tam[Paib]) swap(Paia,Paib);
  tam[Paia] += tam[Paib];
  id[Paib] = Paia;
}


int main(){
  cin >> N >> M;
  UFInit(N);

  for(int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    edges.push_back(make_pair(a,b));
  }

  cin >> Q;
  
  vector<int> edg(MAXV);
  vector<int> removedEdges(MAXV);

  for(int i = Q-1; i >= 0; i--){
    int a;
    cin >> a;
    removedEdges[i] = a-1;
    edg[a-1] = 1;
  }
  
  int cmp = N;
  vector<int> resp;
  for(int i = 0; i < M; i++){
    if(!edg[i]){
      if(UFFind(edges[i].first) != UFFind(edges[i].second)) cmp--;
      UFUnion(edges[i].first,edges[i].second);
    }
  }
  resp.push_back(cmp);

  for(int x = 0; x < Q-1; x++){
    if(UFFind(edges[removedEdges[x]].first) != UFFind(edges[removedEdges[x]].second)) cmp--;    
    UFUnion(edges[removedEdges[x]].first,edges[removedEdges[x]].second);
    resp.push_back(cmp);
  }

  for(int i = (int)resp.size()-1; i >= 1; i--) cout << resp[i] << " ";
  cout << resp[0] << endl;

  return 0;
}
