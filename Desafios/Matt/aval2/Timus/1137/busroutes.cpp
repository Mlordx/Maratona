#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> adj[1000];
int degree = 0;

int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    int M;
    cin >> M;
    int first;
    cin >> first;
    int last = first-1;
    for(int i = 0; i < M; i++){
      int a;
      cin >> a;
      adj[last].push_back(a-1);
      last = a-1;
    }
  }


  return 0;
}
