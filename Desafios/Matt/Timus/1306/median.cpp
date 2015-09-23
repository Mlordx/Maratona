#include<bits/stdc++.h>

using namespace std;

int N;

int main(){
  cin >> N;

  unsigned int nums[250000/2+3];
  unsigned int bla = 0;
  int i = 0;
  for(; i < N/2+1; i++){ cin >> bla; nums[i] = bla; }

  make_heap(nums,nums+N/2+1);
  
  for(;i < N; i++){
    cin >> nums[N/2+1];
    push_heap(nums,nums+N/2+2);
    pop_heap(nums,nums+N/2+2);
  }

  unsigned int a,b;
  if(N%2 == 0){
    a = nums[0];
    pop_heap(nums,nums+N/2+1);
  
    b = nums[0];
    double bla2 = 1.0*(a+b)/2;
  
    printf("%.1f\n",bla2);
  }else{
    double bla2 = 1.0*nums[0];
    printf("%.1f\n",bla2);
  }
  
  return 0;
}
