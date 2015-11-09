#include <bits/stdc++.h>

using namespace std;

int X[10001];
int Y[10001];

int indMinY = -1;
int minY = 1 << 30;

inline int left(int i, int j, int k){
  return (X[j] - X[i])*(Y[k] - Y[i]) - (X[k] - X[i])*(Y[j] - Y[i]);
}


vector<int> translate(10001);

inline int isLeft(int i, int j, int k){ return left(i,j,k) < 0; }
inline int isRight(int i, int j, int k){ return left(i,j,k) > 0; }

bool cmp(const int i,const int j){
  return left(indMinY,j,i);
}


int N;

int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    translate[i] = i;
    cin >> X[i] >> Y[i];
    if(Y[i] < minY){
      minY = Y[i];
      indMinY = i;
    }
  }


  swap(translate[0],translate[indMinY]);
  //  swap(X[0],X[indMinY]);
  //swap(Y[0],Y[indMinY]);

  sort(translate.begin()+1,translate.end(),cmp);

  for(int i = 0; i < N; i++) cout << translate[i] << " ";
  cout << endl << endl;
  
  vector<int> H;

  H.push_back(0);
  H.push_back(1);
  H.push_back(2);

  int h = 2;

  for(int k = 3; k < N; k++){
    while(isLeft(H[h],H[h-1],k)) h--;
    H[++h] = k;
  }

  for(int i = 0; i <= h;i++) cout << X[H[i]] << "~" << Y[H[i]] << endl;
  
  return 0;
}
