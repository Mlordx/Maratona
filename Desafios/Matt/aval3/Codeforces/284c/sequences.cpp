#include <bits/stdc++.h>

using namespace std;

int N;

long long sum;

vector<int> sequence;
vector<long long> added;

int main(){
  cin >> N;
  sequence.push_back(0);
  added.push_back(0);

  for(int i = 0; i < N; i++){
    int t,a,x;
    cin >> t;

    if(t == 1){
      cin >>  a >> x;
      added[a-1] += x;
      sum += x*a;
      printf("%.6f\n",(double)sum/sequence.size());
    }else if(t == 2){
      cin >> a;
      sequence.push_back(a);
      added.push_back(0);
      sum += a;
      printf("%.6f\n",(double)sum/sequence.size());

    }else{
      int last = sequence.size()-1;
      sum -= sequence[last] + added[last];
      added[last-1] += added[last];
      added.pop_back();
      sequence.pop_back();
      printf("%.6f\n",(double)sum/sequence.size());
    }

  }
  
  return 0;
}
