#include <bits/stdc++.h>

using namespace std;

double L,R;
#define PI 3.1415926535

int main(){
  cin >> L >> R;

  double A = L/2;
  if(R <= A){ printf("%.3lf\n",PI*R*R); return 0; }
  else if(R >= A*sqrt(2)){ printf("%.3lf\n",L*L); return 0; }
  
  double alpha = acos(A/R);
  double overlap = (PI - 4*alpha)*R*R + 4*A*R*sin(alpha);

  printf("%.3lf\n",overlap);
  return 0;
}
