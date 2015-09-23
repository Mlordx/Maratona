#include<bits/stdc++.h>

using namespace std;

int N,M;

int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> M;
    int resp = 0;
    for(int j = 0; j < M; j++){
      int a= 0, b= 0,c=0;
      cin >> a >> b >> c;
      resp += a*c;
    }
    cout << resp << endl;

  }

}
