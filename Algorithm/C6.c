#include <stdio.h>
#include <stdlib.h>

int DP_A[50001] = {0,};
int DP_D[50001] = {0,};
long card[50001];

int main() {
  int n , input , bscore = 0, big_A = 0, index =0;
  scanf("%d",&n);

  for(int i =0; i<n; i++){
    scanf("%ld", &card[i]);
  } 
  DP_A[0] = 1;
  DP_D[n-1] = 1;
  for (int i = 1; i < n; i++ )  
  { 
      DP_A[i] = 1; 
      for (int j = 0; j < i; j++ )   
          if ( card[i] > card[j] && DP_A[i] < DP_A[j] + 1){
              DP_A[i] = DP_A[j] + 1;
              if(big_A < DP_A[i]){
                big_A = DP_A[i];
                index = i;
              }  
          }
  }
  
  for(int i = n-2; i>=0; i--){
    DP_D[i] = 1;
    for(int j = i+1; j< n ; j++){
      if(card[i] > card[j] && DP_D[i] < DP_D[j] +1 ){
        DP_D[i] = DP_D[j] +1;  
      }

    }
    
    if(bscore < (DP_A[i] + DP_D[i]) ) 
      bscore = (DP_A[i] + DP_D[i]);
  } 

 
  printf("%d",bscore-1);

  return 0;
}
