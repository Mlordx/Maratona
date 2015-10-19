#include <bits/stdc++.h>

using namespace std;

pair<int,int> cities[301];
int N;

using coord = pair<int,int>;

inline double dist(coord a, coord b){
  return sqrt((a.first - b.first)*(a.first - b.first) + (a.second-b.second)*(a.second-b.second));
}

int cmp(pair<coord,coord>& a, pair<coord,coord>& b){
  return dist(a.first,a.second) > dist(b.first,b.second);
}

int left(coord a, coord b, coord c){
  return (b.first - a.first)*(c.second -  a.second) - (b.second - a.second)*(c.first-a.first);
}


int check[301][301];

int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    int a,b;
    cin >> a >> b;
    cities[i] = make_pair(a,b);
  }

  int total = 0;

  vector<pair<coord,coord> > distances;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i==j)continue;
      if(!check[i][j]){
	distances.push_back(make_pair(cities[i],cities[j]));
	check[i][j] = 1;
	check[j][i] = 1;
      }
    }  
  }

  sort(distances.begin(),distances.end(),cmp);

  for(int i = 0; i < (int)distances.size(); i++){
    cout << dist(distances[i].first,distances[i].second) << " ";
    total += dist(distances[i].first,distances[i].second);
  }
  cout << endl;

  cout << round(total + 1e-8) << endl;
  
  return 0;
}
