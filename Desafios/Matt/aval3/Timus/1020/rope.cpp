#include <bits/stdc++.h>

using namespace std;

int N;
double R;
#define x first
#define y second
#define MY_PI 3.14159265358

vector< pair<double,double> > coords;

double dist(pair<double,double>& a, pair<double,double>& b){
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main(){
  cin >> N >> R;

  for(int i = 0; i < N; i++){
    double a,b;
    cin >> a >> b;
    coords.push_back(make_pair(a,b));
  }

  double total = 0;
  for(int i = 0; i < N; i++){
    int j = i+1;
    j %= N;
    total += dist(coords[i],coords[j]);
  }

  double total2 = 0;

  total2 = 2.0*R*MY_PI;
  printf("%.2f\n",total + total2);
  
  return 0;
}
