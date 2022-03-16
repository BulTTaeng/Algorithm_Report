#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int n;
long t , p ,v;
long loc_speed[100001][3];
//2 is for the panalty
vector<long> loc_after_t;

int main() {
  int group =1;
  long catchup_sec =0;
  long nloc=0;
  long speed =0;
  long up, down;
  scanf("%d %ld",&n,&t);

  for(int i =0; i<n; i++){
    scanf("%ld %ld",&loc_speed[i][0],&loc_speed[i][1]);
    loc_speed[i][2] = 0;
    loc_after_t.push_back(loc_speed[i][0] + loc_speed[i][1] * t);
  }


  for(int i=0; i<n-1; i++){
    
    if(loc_after_t[i] < loc_after_t[i+1] ){
      group++;
    }
    else if (loc_after_t[i] == loc_after_t[i+1]){
      continue;
    }

    else{//따라 잡았다!
    
      up = abs(loc_speed[i][0] - loc_speed[i+1][0]) + (loc_speed[i][2] * loc_speed[i][1]) ;
      down = abs(loc_speed[i][1] - loc_speed[i+1][1]);
      //cout <<up << "    " <<down << endl;
      catchup_sec = up/down;

      if(up % down != 0){
        catchup_sec++;
      }

      if(loc_speed[i][1] < loc_speed[i+1][1]){
        speed = loc_speed[i][1];
      }
      else{
        speed = loc_speed[i+1][1];
      }
      
      nloc = loc_speed[i][0] + (loc_speed[i][1]-loc_speed[i][2]) * catchup_sec;
      loc_speed[i+1][0] = nloc;
      loc_speed[i+1][1] = speed;
      loc_speed[i+1][2] = catchup_sec;
      //cout << nloc << "  " <<speed << "  " << catchup_sec << endl;
      nloc = nloc + speed * (t-catchup_sec);
      //loc_after_t.erase(loc_after_t.begin() +i);
      //loc_after_t.insert(loc_after_t.begin() + i+1, nloc);
      //loc_after_t.erase(loc_after_t.begin() +(i+1));
      loc_after_t[i+1] = nloc;
      catchup_sec =0;
      nloc=0;
      
    }

  }

  /*for(int i =0; i<loc_after_t.size(); i++){
    cout << loc_after_t[i] << "  ";
  }
  cout <<endl;
  for(int i =0; i<n; i++){
    cout << loc_speed[i][2] << "  ";
  }*/

  cout << group;
}
