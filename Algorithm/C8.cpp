#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

typedef struct village{
  double smallx;
  double laregex;
  int num;
 
}village;

int n, d ,inx, iny, a, b, c, D, well=0;
double x1, x2;

struct complaregex{
  bool operator()(village &a, village &b){
    return a.laregex > b.laregex; 
  }
};

struct compsmallx{
  bool operator()(village &a, village &b){
    return a.smallx > b.smallx;
  }
};


priority_queue<village, vector<village>, complaregex> large_Abi;
priority_queue<village, vector<village>, compsmallx> small_Abi2;

void large_Abi_push(double smallx, double laregex, int num){  
  village tmp;
  tmp.smallx = smallx;
  tmp.laregex = laregex;
  tmp.num = num;
  large_Abi.push(tmp);
}

void Abi2_push(double smallx, double laregex, int num){  
  village tmp;
  tmp.smallx = smallx;
  tmp.laregex = laregex;
  tmp.num = num;
  small_Abi2.push(tmp);
}

int main() {
  

  scanf("%d %d",&n,&d);

  int * haveWell = (int*)malloc(sizeof (int) *n );

  int d2 = d*d;
  
  for(int i =0; i<n; i++){
    scanf("%d %d",&inx, &iny);
    a =1; b = -2*inx; c = inx*inx + iny*iny - d2;
    D = b*b -(4*a*c);

    if(D>0){
      x1 = (-b + (sqrt(D))) / (2*a);
      x2 = (-b - (sqrt(D))) / (2*a);
      large_Abi_push(x2,x1,i);
      Abi2_push(x2,x1,i);
    }

    else if(D ==0){
      x1 = (-b + (sqrt(D))) / (2*a);
      large_Abi_push(x1,x1,i);
      Abi2_push(x1,x1,i);
    }
    
  }

  
  while(!large_Abi.empty()){
      double bigx = large_Abi.top().laregex;
      int anum = large_Abi.top().num;

      
      if(haveWell[anum] == 0){
        
        while(!small_Abi2.empty()){
          if(bigx >= small_Abi2.top().smallx ){
            haveWell[small_Abi2.top().num] =1;
            small_Abi2.pop();
          }
          else{
            break;
          }
        }
       
        well++;
      }
      large_Abi.pop();
      
  }
  
  cout << well;

}
