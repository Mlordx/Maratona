/*
  Nome: Mateus Barros Rodrigues
  NUSP: 7991037
  MAC0327 - 2o Sem 2015
  3a Aval
  Problema PXX - 14C - Four Segments
*/

#include <bits/stdc++.h>

using namespace std;

set<pair<int,int > > points;

typedef struct sgt{
  pair<int,int> u;
  pair<int,int> v;
}Segment;

vector<Segment> segments;


int main(){
  int x1,y1,x2,y2;

  for(int i = 0; i < 4; i++){
    cin >> x1 >> y1 >> x2 >> y2;
    points.insert(make_pair(x1,y1));
    points.insert(make_pair(x2,y2));
    Segment bla;
    bla.u = make_pair(x1,y1);
    bla.v = make_pair(x2,y2);
    segments.push_back(bla);
  }

  if( points.size() != 4 ){ cout << "NO\n"; return 0; }


  int xmin = INT_MAX;
  int xmax = INT_MIN;
  int ymin = INT_MAX;
  int ymax = INT_MIN;
  for(auto i = points.begin(); i != points.end(); i++){
    auto j = (*i);
    if(j.first > xmax) xmax = j.first;
    if(j.first < xmin) xmin = j.first;
    if(j.second > ymax) ymax = j.second;
    if(j.second < ymin) ymin = j.second;
  }

  if(xmin == xmax || ymin == ymax){ cout << "NO\n"; return 0; }
  
  int check = 0;
  pair<int,int> s1 = make_pair(xmin,ymin);
  pair<int,int> s2 = make_pair(xmin,ymax);
  pair<int,int> s3 = make_pair(xmax,ymin);
  pair<int,int> s4 = make_pair(xmax,ymax);

  /*
  cout << "---\n";
  cout << s1.first << "~" << s1.second << endl;
  cout << s2.first << "~" << s2.second << endl;
  cout << s3.first << "~" << s3.second << endl;
  cout << s4.first << "~" << s4.second << endl;
  cout << "---\n";
  */

  bool c1,c2,c3,c4;
  c1 = false;
  c2 = false;
  c3 = false;
  c4 = false;

  for(int i = 0; i < 4; i++){
    auto A = segments[i].u;
    auto B = segments[i].v;
    if( A == s1 && B == s2) c1 = true;
    else if( A == s2 && B == s1) c1 = true;
    
    else if( A == s1 && B == s3) c2 = true;
    else if( A == s3 && B == s1) c2 = true;
    
    else if( A == s2 && B == s4) c3 = true;
    else if( A == s4 && B == s2) c3 = true;

    else if( A == s4 && B == s3) c4 = true;
    else if( A == s3 && B == s4) c4 = true;
  }

  if(c1&&c2&&c3&&c4) cout << "YES\n";
  else cout << "NO\n";
  
  return 0;
}

