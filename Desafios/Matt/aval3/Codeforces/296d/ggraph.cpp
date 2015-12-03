#include <bits/stdc++.h>

using namespace std;

#define INF 1 << 30

int N;

int adj[501][501];

int fw(int n){
  
  int min_dist[501][501];


  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      min_dist[i][j] = INF;

    for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      min_dist[i][j] = adj[i][j];


  for(int k = 1; k < N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
	if(min_dist[i][j] > min_dist[i][k] + min_dist[k][j])
	  min_dist[i][j] = min_dist[i][k] + min_dist[k][j];
      }
    }
  }

  int sum = 0;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      if(min_dist[i][j] != INF)
	sum += min_dist[i][j];
  
  for(int i = 1; i <= N; i++){
    adj[n][i] = 0;
    adj[i][n] = 0;
  }
  

  return sum;
}

int main(){

  cin >> N;

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      cin >> adj[i][j];

  int aux;

  for(int i = 1; i < N; i++){
    cin >> aux;
    cout << fw(aux) << " ";
  }

  cin >> aux;
  cout << fw(aux) << endl;


  return 0;
}
