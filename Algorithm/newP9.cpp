#include <iostream>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int n;
long t , p ,v;
long loc_speed[100001][2];

typedef struct location{
  int id;
  long dis;
}L;

struct comp{
  bool operator()(L &a, L &b){
    return a.dis < b.dis; 
  }
};

priority_queue <L, vector<L>, comp> gap;

void gap_push(int id, long dis){  
  L tmp;
  tmp.id = id;
  tmp.dis = dis;
  gap.push(tmp);
}


vector<long> loc_after_t;

int main() {
  long catchup_sec =0;
  long up, down;
  long catchup_id;
  int group=1;

  scanf("%d %ld",&n,&t);

  for(int i =0; i<n; i++){
    scanf("%ld %ld",&loc_speed[i][0],&loc_speed[i][1]);

    if(i != 0 && loc_after_t[i-1] == loc_after_t[i]){
        loc_speed[i][0] = loc_speed[i+1][0];
        loc_speed[i][1] = loc_speed[i+1][1];
    }

    loc_after_t.push_back(loc_speed[i][0] + loc_speed[i][1] * t);
  }

  for(int i =0; i<loc_after_t.size()-1; i++){
    if(loc_after_t[i] < loc_after_t[i+1]){
        continue;
    }
    else if(loc_after_t[i] == loc_after_t[i+1]){
      loc_speed[i][0] = loc_speed[i+1][0];
      loc_speed[i][1] = loc_speed[i+1][1];
      continue;
    }
    else{
       gap_push(i,(loc_after_t[i] - loc_after_t[i+1]));
    }
   
  }
  
  
  while(true){

    if(gap.empty()){
      break;
    }

    catchup_id = gap.top().id;
    gap.pop();
    
    up = abs(loc_speed[catchup_id][0] - loc_speed[catchup_id+1][0]);
    down = abs(loc_speed[catchup_id][1] - loc_speed[catchup_id+1][1]);
    
    if(up == 0 || down == 0){
      continue;
    }

    catchup_sec = up/down;

    if(up % down != 0){
      catchup_sec++;
    }
    
    if(catchup_sec > t){
      break;
    }

    loc_speed[catchup_id][0] = loc_speed[catchup_id+1][0];
    loc_speed[catchup_id][1] = loc_speed[catchup_id+1][1];
    loc_after_t[catchup_id] = loc_after_t[catchup_id+1];

    if(loc_after_t[catchup_id-1]  > loc_after_t[catchup_id]){
      gap_push(catchup_id-1,(loc_after_t[catchup_id-1] - loc_after_t[catchup_id]));
    }

  }

  for(int i =1; i< loc_after_t.size(); i++){
    if(loc_after_t[i] != loc_after_t[i-1]){
      group++;
    }
  }
  
  cout <<group;

}
