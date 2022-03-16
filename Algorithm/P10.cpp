#include<iostream>

using namespace std; 

int N,B;
long sum =0;
int weight[452];
  
int graph[452][452];  
int edgeN[452];
int clusterG[452];

bool  is_cluster(int until) 
{ 
    for (int i = 1; i < until; i++) { 
        for (int j = i + 1; j < until; j++){ 
  
            if (graph[clusterG[i]][clusterG[j]] == 0){
              sum =0; 
              return false;
            }  
        }
      sum+= weight[clusterG[i]];  
    } 
   
   return true; 
} 
  

long clusterW(int start, int end) 
{ 
  long max_weight = 0; 
  
  for (int i = start + 1; i <= N; i++) { 
    clusterG[end] = i;
        
    if (is_cluster(end + 1)) { 
      max_weight = max(max_weight, sum); 
      sum=0;
      max_weight = max(max_weight, clusterW(i, end + 1)); 
    }

  }
  
  return max_weight; 
} 
  

int main() 
{   
  int t1,t2,ans;
  scanf("%d %d",&N,&B);

  for(int i =1; i<=N ; i++){
    scanf("%d",&weight[i]);
  }

  for(int i =1; i<=B ; i++){
    scanf("%d %d", &t1,&t2);
    graph[t1][t2] =1;
    graph[t2][t1] = 1;
    edgeN[t1]++;
    edgeN[t2]++;
  }

  ans = clusterW(0, 1); 
  cout << ans;  
  
  return 0; 
} 
