#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int n;

vector<vector<int>> v;

typedef struct Location{
  int x;
  int y;
  int id;
  Location(int x, int y, int id) : x{ x }, y{ y }, id{ id } {}
  bool operator < (const Location& loc) const {
 
        if (y == loc.y) return x < loc.x;
        else return y < loc.y;
 
  }
}L;

typedef struct check{
  int size;
  int id;
}C;

C c[50001];



bool cmp_x(const L& loc1, const L& loc2) {
 
    return (loc1.x < loc2.x);
 
}

struct compare{
    bool operator()(C a, C b){
        return a.size<b.size;
    }
};

priority_queue <C,vector<C>,compare> q;

vector <L> Loc;
int check[50001];


int main() {
  int x,y;
  scanf("%d",&n);

  for(int i =0; i<n; i++){
    scanf("%d %d",&x,&y);
    Loc.push_back({x,y,i});
  }

  sort(Loc.begin() , Loc.end(), cmp_x);
  for(int i =0; i<n; i++){
    Loc[i].id = i;
  }

  int start = 0;
 
    for (int i = 0; i < n; i++) {

        vector<int> vv;
        L l = Loc[i];
 
        
        auto lower = lower_bound(Loc.begin() , Loc.end(), L(l.x-5,1,0));
        auto upper = upper_bound(Loc.begin(), Loc.end(), L(l.x+5,500000,n));
        
        for (auto itr = lower; itr != upper; itr++) {
 
            int dst =pow(l.x - itr->x, 2) + pow(l.y - itr->y, 2);
           
            if(dst <= 25 && dst !=0){
              vv.push_back(itr->id);
            }
        }
  
        v.push_back(vv);
 
    }

    int max = n;

    for(int i =0; i<n; i++){
      c[i].size = v[i].size();
      c[i].id = Loc[i].id;
      q.push(c[i]);
    }
    
    int maxs=0;
    int maxid =0;
    C m;  
    C mm;

    for(int i =0 ; i<n; i++){
      while(true){
        m = q.top();
        q.pop();
        if(m.size <=0){
          break;
        }
        if(check[m.id] == 0){
          break;
        }
        else if(check[m.id] ==1){
          check[m.id] =0;
        }
      }
      
      maxs = m.size;
      maxid = m.id;
      
      if(maxs <= 0){
        break;
      }
      
      max--;

      for(int j =0; j<v[maxid].size(); j++){
        
        c[v[maxid][j]].size--;
        //if(c[v[maxid][j]].size > 0){
          mm.size = c[v[maxid][j]].size;
          mm.id = c[v[maxid][j]].id;
          check[mm.id] =1;
          q.push(mm);
        //}
      }

      
      c[maxid].size = 0;
      
      
    }

    
    cout << n-max;
    return 0;
}
