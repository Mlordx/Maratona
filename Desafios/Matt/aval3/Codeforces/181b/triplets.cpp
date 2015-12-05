/*
  Nome: Mateus Barros Rodrigues
  NUSP: 7991037
  MAC0327 - 2o Sem 2015
  3a Aval
  Problema PXX - 181B - Number of Triplets
*/

#include <bits/stdc++.h>

using namespace std;

bool points[2001][2001];
vector<pair<int,int> > coords;

int N;

int main(){

  cin >> N;

  for(int i = 0; i < N; i++){
    int a,b;
    cin >> a >> b;
    points[a+1000][b+1000] = true;
    coords.push_back(make_pair(a+1000,b+1000));
  }

  int M = (int)coords.size();

  int count = 0;

  bool already_counted[M][M];

  for(int i = 0; i < M; i++){
    for(int j = i; j < M; j++){
      if(i == j) continue;
      int A = (coords[i].first +  coords[j].first)/2;
      int B = (coords[i].second + coords[j].second)/2;
      double A2 = (coords[i].first +  coords[j].first)/2.0;
      double B2 = (coords[i].second + coords[j].second)/2.0;
      if(A2 > A || B2 > B) continue;
      if( points[A][B] == true) count++;
    }
  }

  cout << count << endl;

  return 0;
}
