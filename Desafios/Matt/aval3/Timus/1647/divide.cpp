/*
Nome: Mateus Barros Rodrigues
NUSP: 7991037
MAC0327 - 2o Sem 2015
3a Aval
Problema P2 - 1647. Divide an island
*/

#include <bits/stdc++.h>

#define ERROR 1e-10

using namespace std;

#define Point pair<double,double>


Point a,b,c;
Point S,T;

double dist(Point A, Point B){
  return sqrt((A.first- B.first)*(A.first-B.first) + (A.second-B.second)*(A.second - B.second));
}

void find(Point A, Point B, Point C){
  double ab = dist(A,B);
  double ac = dist(A,C);
  double bc = dist(B,C);

  double p = ab + ac + bc;

  double delta = (p/2)*(p/2) - 2*ab*ac;

  double x1 = (p/2 + sqrt(delta))/2;
  double x2 = (p/2 - sqrt(delta))/2;


  double c1 = x1-ab;
  double c2 = x1-ac;
  double c3 = x2-ab;
  double c4 = x2-ac;
  
  if(x2>0){
    if(((c1>ERROR)&&(c2>ERROR)) || ((c3>ERROR)&&(c4>ERROR))) return;
    if((c1>ERROR) || (c4>ERROR)) swap(x1,x2);
    
    Point BA;
    BA.first = B.first - A.first;
    BA.second = B.second - A.second;
    
    S.first = A.first + (x1/ab)*BA.first;
    S.second = A.second + (x1/ab)*BA.second;

    Point CA;
    CA.first = C.first - A.first;
    CA.second = C.second - A.second;
    

    T.first = A.first + (x2/ac)*CA.first;
    T.second = A.second + (x2/ac)*CA.second;
	
  }
  
}

int main(){

  cin >> a.first >> a.second;
  cin >> b.first >> b.second;
  cin >> c.first >> c.second;

  find(a,b,c);
  find(b,c,a);
  find(c,b,a);

  printf("YES\n%.15lf %.15lf\n%.15lf %.15lf\n",S.first,S.second,T.first,T.second);

  
  return 0;
}
