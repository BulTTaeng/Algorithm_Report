#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct score{
  int x;
  int y;
  int id;
}S;

S dmerge[8001];
S ymerge[8001];
S developersx[8001];
S developersy[8001];

int check[8001] = {0,};
int num=0;
int N;

void mergex(int start, int end)
{
    int mid = (start + end) / 2;
    int i = start, j = mid+1, k = start;
    while (i <= mid && j <= end) {
        if (developersx[i].x < developersx[j].x) {
          dmerge[k++] = developersx[i++];
        }

        else if(developersx[i].x == developersx[j].x){
          if(developersx[i].y < developersx[j].y){
            dmerge[k++] = developersx[i++];
          }
          else{
            dmerge[k++] = developersx[j++];
          }
        }
        else
            dmerge[k++] = developersx[j++];
    }
 
    while (i <= mid)
        dmerge[k++] = developersx[i++];
    while (j <= end)
        dmerge[k++] = developersx[j++];
 
    for (int i = start; i <= end; i++) {
        developersx[i] = dmerge[i];
    }
}

void mergey(int start, int end)
{
    int mid = (start + end) / 2;
    int i = start, j = mid+1, k = start;
    while (i <= mid && j <= end) {
        if (developersy[i].y <= developersy[j].y) 
            ymerge[k++] = developersy[i++];
        else
            ymerge[k++] = developersy[j++];
    }
 
    while (i <= mid)
        ymerge[k++] = developersy[i++];
    while (j <= end)
        ymerge[k++] = developersy[j++];
 
    for (int i = start; i <= end; i++) {
        developersy[i] = ymerge[i];
    }
}
 
void merge_sort(int start, int end, int std) 
{
  if(std == 0){
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(start, mid,std);
        merge_sort(mid + 1, end,std);
        mergex( start, end);
    }
  }
  else{
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(start, mid,std);
        merge_sort(mid + 1, end,std);
        mergey(start, end);
    }
  }
    
}

void S_push(int x, int y, int id){
  S temp;
  temp.x = x;
  temp.y = y;
  temp.id = id;
  developersx[id] = temp;
  developersy[id] = temp;
}

int main() {
  int x,y,stop=0;
  int ans = 0;
  scanf("%d",&N);
  for(int i =0; i<N; i++){
    scanf("%d %d",&x,&y);
    S_push(x,y,i);
  }
  
  merge_sort(0, N - 1,0);
  for(int i=0; i<N;i++){
    developersx[i].id = i;
    developersy[i]= developersx[i];
  }
  
  merge_sort(0, N - 1,1);
  
  
  for(int i=0; i<N; i++){
    
    if(developersx[i].id == developersy[i].id && stop == 0){
      ans++;
    }

    else if (developersx[i].id != developersy[i].id && stop ==0){
      ans++; 
      
      check[developersx[i].id] =1;
      
      check[developersy[i].id] =1;
      num=2;
      stop =1;      
    }

    else if(developersx[i].id != developersy[i].id && stop ==1){

      if(check[developersx[i].id] ==1){ 
        num--;
        
        check[developersx[i].id] =0;
      }
      else{
        check[developersx[i].id] =1;
        num++;
      }


      if (check[developersy[i].id] ==1){
        num--;
        check[developersy[i].id] =0;
      }
      else{
        
        check[developersy[i].id] =1;
        num++;
      }

      
      if(num==0){
        stop = 0;
        continue;
      }

      
      
    }
    
  }

  cout << ans;
}
