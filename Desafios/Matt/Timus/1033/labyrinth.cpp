#include <bits/stdc++.h>

#define PAREDE 1
#define VAZIO 0
#define VISITED 2

using namespace std;

int N;

int main(){
  cin >> N;
  string row;
  vector< vector<int> > lab;
  vector< vector<int> > resp;
  
  
  lab.resize(35);
  for(int i = 0; i < 35; i++) lab[i].resize(35);

  resp.resize(35);
  for(int i = 0; i < 35; i++) resp[i].resize(35);

  for(int i = 0; i < 35; i++)
    for(int j = 0; j< 35; j++)
      lab[i][j] = -1;

  for(int i = 2; i <= N; i++){ lab[0][i] = VISITED; resp[0][i] = 1;}
  for(int i = 1; i < N; i++){ lab[i][N+1] = VISITED; resp[i][N+1] = 1;}
  for(int i = 1; i <= N; i++){ lab[i][0] = VISITED; resp[i][0] = 1;}
  for(int i = 1; i < N; i++){ lab[N+1][i]= VISITED; resp[N+1][i] = 1;}
  
  lab[0][1] = VISITED; resp[0][1] = VAZIO;
  lab[1][0] = VISITED; resp[1][0] = VAZIO;
  lab[N+1][N] = VISITED; resp[N+1][N] = VAZIO;
  lab[N][N+1] = VISITED; resp[N][N+1] = VAZIO;
  
  
  for(int i = 1; i <= N; i++){
    cin >> row;
    for(int j = 0; j < N; j++){
      if(row[j] == '.') lab[i][j+1] = VAZIO;
      else{ lab[i][j+1] = PAREDE; resp[i][j+1] = PAREDE; }
    }
  }

 
  queue< pair<int,int> > q;
  q.push(make_pair(1,1));
  lab[1][1] = VISITED;

  int sum1 = 0;

  while(!q.empty()){
    pair<int,int> a = q.front();
    q.pop();

    int A = a.first;
    int B = a.second;

    sum1 += resp[A+1][B] + resp[A][B+1] + resp[A-1][B] + resp[A][B-1];
    if(lab[A][B] != VISITED && lab[A][B] == VAZIO){       lab[A][B] = VISITED; q.push(make_pair(A,B)); }
    if(lab[A+1][B] != VISITED && lab[A+1][B] == VAZIO){ lab[A+1][B] = VISITED; q.push(make_pair(A+1,B)); }
    if(lab[A][B+1] != VISITED && lab[A][B+1] == VAZIO){ lab[A][B+1] = VISITED; q.push(make_pair(A,B+1)); }
    if(lab[A-1][B] != VISITED && lab[A-1][B] == VAZIO){ lab[A-1][B] = VISITED; q.push(make_pair(A-1,B)); }
    if(lab[A][B-1] != VISITED && lab[A][B-1] == VAZIO){ lab[A][B-1] = VISITED; q.push(make_pair(A,B-1)); }

  }

  int sum2 = 0;

  if(lab[N][N] != VISITED){
    queue< pair<int,int> > q2;  
    q2.push(make_pair(N,N));
    lab[N][N] = VISITED;
  

    while(!q2.empty()){
      pair<int,int> a = q2.front();
      q2.pop();

      int A = a.first;
      int B = a.second;

      sum2 += resp[A+1][B] + resp[A][B+1] + resp[A-1][B] + resp[A][B-1];
      if(lab[A][B] != VISITED && lab[A][B] == VAZIO){       lab[A][B] = VISITED; q2.push(make_pair(A,B)); }
      if(lab[A+1][B] != VISITED && lab[A+1][B] == VAZIO){ lab[A+1][B] = VISITED; q2.push(make_pair(A+1,B)); }
      if(lab[A][B+1] != VISITED && lab[A][B+1] == VAZIO){ lab[A][B+1] = VISITED; q2.push(make_pair(A,B+1)); }
      if(lab[A-1][B] != VISITED && lab[A-1][B] == VAZIO){ lab[A-1][B] = VISITED; q2.push(make_pair(A-1,B)); }
      if(lab[A][B-1] != VISITED && lab[A][B-1] == VAZIO){ lab[A][B-1] = VISITED; q2.push(make_pair(A,B-1)); }

    }
  }

  printf("%d\n",(sum1+sum2)*9);
  
  return 0;
}
