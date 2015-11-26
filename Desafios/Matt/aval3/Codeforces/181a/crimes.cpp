#include <bits/stdc++.h>

using namespace std;

int N,M;

int Map[101][101];

vector<pair<int,int> > coords;

double calculaArea(pair<int,int> A, pair<int,int> B, pair<int,int> C){
  double area = ((A.first*B.second + A.second*C.first + B.first*C.second) - (B.second*C.first + A.first*C.second + A.second*B.first));
  if(area < 0) area *= -1;
  return area;
}

int main(){
  cin >> N >> M;

  for(int i = 0; i < N; i++){
    string aux;
    cin >> aux;
    for(int k = 0; k < aux.length(); k++)
      if(aux[k] == '*'){ coords.push_back(make_pair(i+1,k+1)); Map[i+1][k+1] = 1;}
  }
  /*  
  double area = calculaArea(coords[0],coords[1],coords[2]);
  printf("%f\n",area);
  int maxX = -1;
  int maxY = -1;

  pair<int,int> m;
  pair<int,int> n;
  
  for(int i = 0; i < 3;i++){
    if(coords[i].first > maxX){ maxX = coords[i].first; m = coords[i]; }
    if(coords[i].second > maxY){ maxY = coords[i].second; n = coords[i]; }
  }
  cout << n.first << "~" << n.second << " e " << m.first << "~" << m.second << endl;

  for(int i = 1; i <= maxX; i++){
    for(int j = 1; j <= maxY; j++){
      cout << i << "~" << j << " = " << calculaArea(make_pair(i,j),n,m) << endl;
      if( Map[i][j] != 1 && calculaArea(make_pair(i,j),n,m) == area ){
	cout << i << " " << j << endl;
	return 0;
      }
    }
  }
  */
  int x1,x2;
  x1 = coords[0].first;

  for(int i = 0; i < 3; i++){
    if(coords[i].first != x1){ x2 = coords[i].first; break;}
    if(coords[i].second != x1){ x2 = coords[i].second; break;}
  }


  int x1First, x1Second;
  int x2First, x2Second;

  for(int i = 0; i < 3; i++){
    int a = coords[i].first;
    int b = coords[i].second;


    if(a == x1) x1First++;
    else if(a == x2) x2First++;

    if(b == x1) x1Second++;
    else if(b == x2) x2Second++;
  }
  

  int a,b;
  if(x1First != 2) a = x1;
  else a = x2;


  if(x1Second != 2) b = x1;
  else  b = x2;

  cout << a << " " << b << endl;
  
  return 0;
}
