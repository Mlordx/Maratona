/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
2a Aval
Problema P13 - 1325.Dirt
*/


#include <bits/stdc++.h>

using namespace std;

char maze[501][501];
int visited[501][501];

int N,M;
pair<int,int> ent,ex;


struct tile{
  pair<int,int> pos;
  pair<int,int> dist;
  bool operator<(const tile& t) const{ return dist > t.dist; }
};

inline bool inBounds(pair<int,int> pos){
  return ( pos.first >= 0&& pos.first < N) && ( pos.second >= 0 && pos.second < M);
}

inline bool isVisited(pair<int,int> a){ return visited[a.first][a.second]; }

int main(){
  int a,b;
  cin >> N >> M;
  cin >> a >> b;
  ent = make_pair(a-1,b-1);
  cin >> a >> b;
  ex = make_pair(a-1,b-1);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      char c;
      cin >> c;
      maze[i][j] = c;
    }
  }
    
  int minBoots = 0;
  int minDist = 0;

  priority_queue<tile> q;
  tile A;
  A.pos = ent;
  A.dist = make_pair(0,1);
  q.push(A);

  while(!q.empty()){
    auto aux = q.top();
    q.pop();
    
    if(aux.pos == ex){
      minBoots = aux.dist.first;
      minDist = aux.dist.second;
      break;
    }

    if(isVisited(aux.pos)) continue;
    visited[aux.pos.first][aux.pos.second] = 1;

    for(int i = -1; i <= 1; i++){
      for(int j = -1; j <= 1; j++){
	int x = aux.pos.first+i;
	int y = aux.pos.second+j;
	if(!inBounds(make_pair(x,y)) || visited[x][y] || maze[x][y] == '0') continue;
	tile t;
	t.pos = make_pair(x,y);
	if(maze[aux.pos.first][aux.pos.second] != maze[x][y]){
	  t.dist = make_pair(aux.dist.first+1,aux.dist.second+1);
	}else t.dist = make_pair(aux.dist.first,aux.dist.second+1);
	q.push(t);
      }
    }
  }
  cout << minDist << " " << minBoots << endl;

  return 0;
}
