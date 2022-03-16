#include <iostream>
#include <vector>

using namespace std;
int N;
int root[8001];
int score[8001][3] ={0,};
int check[8001] = {0,};
vector<int> sig[8001];
int same[8001][8001] ={0,};

int find(int x) {
  if (root[x] == x) {
      return x;
  } else {
      
      return root[x] = find(root[x]);
  }
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    
    root[y] = x;
      //root[x] = y;
  
    
}

int main() {
  int pi,pj,group =0;
  int raise =0;
  int p,pp;
  scanf("%d",&N);
  //group=N;
  for(int i=0; i<N; i++){
    scanf("%d %d",&score[i][0],&score[i][1]);
    score[i][2] = i;
    root[i] = i;
    /*if(same[score[i][0]][score[i][1]] != 0){
      root[i] = same[score[i][0]][score[i][1]];
    }

    else{
      root[i] = i;
      same[score[i][0]][score[i][1]] = i;
    }*/
    
    
  }

  for(int i=0; i<N; i++){

    for(int j=i-1; j>=0;j--){
      /*if(score[i][0] == score[j][0] && score[i][1] ==score[j][1]){
        sig[i].push_back(j);
        //sig[j].push_back(i);
      }*/

      if(raise == 1){
        if(root[j] == p  ){
          root[j] = pj;
          //continue;
        }

      }

      if(score[i][0] > score[j][0] && score[i][1] <score[j][1]){
        p = root[j];
        //pp= root[i];
        merge(i,j);
        pj = find(j);
        raise =1;
        
        
      }

      else if(score[i][0] < score[j][0] && score[i][1] >score[j][1]){
        p = root[j];
        //pp=root[i];
        merge(i,j);
        pj = find(j);
        raise =1;
        if(pi == pj){
          
        }
        
      }


    }

    raise =0;

   
  }

  /*for(int i=0; i<N; i++){
    if(root[i] != i){
      if(!sig[i].empty()){
        for(int j=0; j<sig[i].size(); j++){
          merge(i,sig[i][j]);
        }
      }
    }
  }*/

  for(int i=0; i<N; i++){
    //cout << root[i] << " ";
    if(check[root[i]] == 0){
      group++;
      check[root[i]] = 1;
    }
    
  }
  //cout <<endl;
  cout << group;
}
