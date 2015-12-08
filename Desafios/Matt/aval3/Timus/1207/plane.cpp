/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema P17 - 1207.Median on the plane
*/

#include <bits/stdc++.h>

using namespace std;


int N;

struct Point{
  long long first;
  long long second;
  int pos;
};

vector<Point> points;


long long left(Point A, Point B, Point C){
  return (B.first - A.first)*(C.second - A.second)-(B.second - A.second)*(C.first - A.first);
}

bool cmp(const Point& A, const Point& B){
  return left(points[0],A,B) < 0;
}

int main(){
  cin >> N;
  points.resize(N);

  for(int i = 0; i < N; i++){
    cin >> points[i].first >> points[i].second;
    points[i].pos = i;
  }
  
  sort(points.begin()+1,points.end(),cmp);

  cout << "1 " << points[N/2].pos+1 << endl;
  
  return 0;
}
