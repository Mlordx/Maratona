#include <bits/stdc++.h>

using namespace std;

int N;

int adj[501][501];

vector<int> deleted(501);
vector<bool> valid(501);
vector<long long> answer(501);

void fw(){
  
  int min_dist[501][501];

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      min_dist[i][j] = adj[i][j];


  for(int k = 1; k <= N; k++){
    answer[k] = 0;
    int aux = deleted[k];
    valid[aux] = true;

    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
	min_dist[i][j] = min(min_dist[i][j],min_dist[i][aux] + min_dist[aux][j]);
	if(valid[i] && valid[j]) answer[k] += min_dist[i][j];
      }
    }
  }
  
 
  
}

int main(){

  cin >> N;

  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      cin >> adj[i][j];

  int aux;

  for(int i = N; i >= 1; i--){
    cin >> deleted[i];
    valid[i] = false;
  }

  fw();

  for(int i = N; i>=1; i--){
    cout << answer[i] << " ";
  }
  cout << endl;
  
  return 0;
}
