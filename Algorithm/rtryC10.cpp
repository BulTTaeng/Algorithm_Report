#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <set>

using namespace std;

int n;

int black =0;
int red =0;


typedef struct Location{
  int x;
  int y;
  int id;
  int color;
  Location(int x, int y, int id) : x{ x }, y{ y }, id{ id } {}
  bool operator < (const Location& loc) const {
 
        if (y == loc.y) return x < loc.x;
        else return y < loc.y;
 
  }
}L;



bool cmp_x(const L& loc1, const L& loc2) {
 
    return (loc1.x < loc2.x);
 
}

vector <L> Loc;


vector<int>visit;

vector<vector<int>>g;

void BFS(int s)
  {
      int j =0;
        queue<int> q;
        visit[s] = 1;
        q.push(s);
        //cout << s <<"  ";
        red++;
        j++;
        while (!q.empty())
        {
          int node = q.front();
          q.pop();
          for(int i =0; i<g[node].size(); i++)
          {
              if(visit[g[node][i]] != 1)
              {
                visit[g[node][i]] = 1;
                //cout<<g[node][i]<<" ";
                q.push(g[node][i]);
                if(j%2 == 0){
                  red++;
                  j++;
                }
                else if (j%2 == 1){
                  black++;
                  j++;
                }
              }
          }
        }

    }


int main() {
  int x,y;
  scanf("%d",&n);
  g.resize(n);
  visit.resize(n+1);

  for(int i =0; i<n; i++){
    scanf("%d %d",&x,&y);
    Loc.push_back({x,y,i});
    
  }

  sort(Loc.begin() , Loc.end(), cmp_x);
  
  int start = 0;
  set<L> candi;
  candi.insert(Loc[0]);
  
    for (int i = 1; i < n; i++) {
       
        L l = Loc[i];
        if(l.id != Loc[start].id)
          candi.insert(l);

        while (start<i) {
 
            auto p = Loc[start];
            int x = l.x- p.x;
            //candi.insert(p);

            if (x > 5) {
              candi.erase(p);
              start++;
            }

            else{
              break;
            }
        }

       
        auto lower = candi.lower_bound(L(1,l.y-5,0));
        auto upper = candi.upper_bound(L(500000,l.y+5,n));
        
       
        for (auto itr = lower; itr != upper; itr++) {
            
            int dst =pow(l.x - itr->x, 2) + pow(l.y - itr->y, 2);
           
            if(dst <= 25 && itr->id != l.id){
              
              g[l.id].push_back(itr->id);
              g[itr->id].push_back(l.id);
              
            }
        }
     
    }//i
  
  for(int i =0; i<n; i++){
    if(visit[i] != 1)
      BFS(i);
  }
  

  if(black < red){
      cout << black;
    }
  else{
    cout << red;
  }

   
    return 0;
}
