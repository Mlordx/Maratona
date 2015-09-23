#include<bits/stdc++.h>

using namespace std;

int W,D,a,b,c,d;
double total;
string moves;

inline double dist(int a , int b, int c, int d){
  return sqrt(1.0*(a-c)*(a-c) + 1.0*(b-d)*(b-d));
}

int main(){
  cin >> W >> D >> a >> b >> c >> d >> moves;

  for(int i = 0; i < moves.length(); i++){
    if( moves[i] == 'L') a *= -1;
    if( moves[i] == 'R') a = 2*W - a;
    if( moves[i] == 'F') b *= -1;
    if( moves[i] == 'B') b = 2*D - b;
  }
  
  total = dist(a,b,c,d);
  printf("%.4lf\n",total);
}
