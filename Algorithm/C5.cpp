#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int main() {
  int n;
  long loc, rad;
  vector <double> x, y;
  double maxr = 0;

  
      double a, b , len, temp,max;

  
  scanf("%d",&n);
  vector<long> balloon[n];

  for(int i =0; i<n;i++){
    scanf("%ld %ld",&loc,&rad);
    balloon[i].push_back(loc);
    balloon[i].push_back(rad);
  }

  for(int i =0; i<n ; i++){

    if(i == 0){
      printf("%.3lf\n", (double)balloon[i][1]);
      x.push_back(balloon[i][0]);
      y.push_back(balloon[i][1]);
      
    }
    
    else{
      max = balloon[i][1] ;
      for(int j =i-1; j>=0; j--){
        temp = balloon[i][0] - x[j] ;
        a =  pow(temp ,2) ;
        b =  (4 * y[j]);
        len= a/b ;

        if(len <max){
          max = len;
        }

        if(y[j] > max) break;
    
      }

      printf("%.3lf\n", max);
      x.push_back(balloon[i][0]);
      y.push_back(max);
    }

  }
  

  return 0;
}
