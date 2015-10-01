#include<bits/stdc++.h>
#define NMAX 2000
using namespace std;


int N,M;

typedef struct edge{
  int a,b,c;
}Edge;

vector<int> adj[NMAX];
vector<int> adj2[NMAX];
vector<int> discovery(NMAX,0);
vector<int> finish(NMAX,0);
int id[NMAX], tam[NMAX];
vector<pair<int,int> > not_used;
vector<Edge> in_tree;
int t = 0;

/*
  Sendo e = xy, e !E T, f = uv, f E T.

  f é coberta pelo ciclo fundamental de e caso:

  d[x] <= d[u] e f[x] >= f[u]
  e
  d[v] <= d[y] e f[v] >= f[y]

*/

void UFInit(int n){
  for(int i = 0; i < n; i++){ id[i] = i; tam[i] = 1;}
}

int UFFind(int a){
  if (id[a]!=a)
    id[a] = UFFind(id[a]);
  return id[a];
}

void UFUnion(int a, int b){
  int Paia = UFFind(a), Paib = UFFind(b);
  
  if(tam[Paia] < tam[Paib]){
    id[Paia] = Paib;
    tam[Paib] += tam[Paia];
  }
  else{
    id[Paib] = Paia;
    tam[Paia] += tam[Paib];
  }
}





void dfs_r(int u){
  discovery[u] = t++;

  for(auto a = adj2[u].begin(); a != adj2[u].end(); a++){
    auto v = *(a);
    if(!discovery[v]) dfs_r(v);
  }

  finish[u] = t++;
}

void dfs(){
  dfs_r(0);
}

int main(){
  cin >> N >> M;
  UFInit(N);

  for(int j = 0; j < M; j++){
    int a = 0, b = 0;
    cin >> a >> b;
    adj[a-1].push_back(b-1);
  }
  
  for(int i = 0; i < N; i++){
    for(auto k = adj[i].begin(); k != adj[i].end(); k++){
      auto j = *(k);
      
      if(UFFind(i) != UFFind(j)){
	
	UFUnion(i,j);
	
	Edge aux;
	aux.a = i;
	aux.b = j;
	aux.c = 0;
	
	in_tree.push_back(aux);
	adj2[i].push_back(j);
	
      }else not_used.push_back(make_pair(i,j));
      
    }
  }

  dfs();

  vector<int> sets(not_used.size());
  vector<int> is_bridge(in_tree.size(),1);

  int count = 0;

  for(int i = 0; i < not_used.size(); i++){
    int y = not_used[i].first;
    int x = not_used[i].second;
    for(auto j = in_tree.begin(); j != in_tree.end(); j++){
      auto aux = *(j);
      int v = aux.a;
      int u = aux.b;
      if(discovery[x] <= discovery[u] && finish[x] >= finish[u] && discovery[v] <= discovery[y] && finish[v] >= finish[y]){
	is_bridge[count++] = 0;
	sets[i]++;
      }
    }
  }
  for(int i = 0; i < not_used.size(); i++) sets[i]++;
  
  int bridges = 0;

  for(int i = 0; i < in_tree.size(); i++) if(is_bridge[i]) bridges++;

  int total = 0;

  if(bridges >= 2) total += (bridges*(bridges-1))/2;

  for(int i = 0; i < sets.size(); i++){
    if(sets[i] >= 2) total += (sets[i]*(sets[i]-1))/2;
  }

  cout << total << endl;

  return 0;
}
