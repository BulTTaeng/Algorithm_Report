#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Rpill[100001];
vector<int> cpill[10001];
bool check[10001];
int Ppair =0;
int ans=0;
int n,m;

int identify(int start, int end){
  int result;
  Ppair++;
	check[start]= true;
	//printf("%d %d %d %d \n", start, end, depth, ans);
  
  if(start == end && Ppair%2 == 1){
    //cout<<"fasd\n";
    return 1;
  }
  
  else if(start == end && Ppair%2 == 0){
    return 2;
  }

	for(int i=0; i < cpill[start].size(); i++){
		int next = cpill[start][i];
		
		if(check[next]==false){
			
			result = identify(next, end);
      if(result == 1){
        return 1;
      }
      else if(result == 2){
        return 2;
      }
      else{
        Ppair--; 
      }
      
		}
	}
  return 0;
}

int find(int u)
{
    if (u == Rpill[u])
        return u;
 
    return Rpill[u] = find(Rpill[u]);
}

int Cpair(int p1, int p2)
{
    int Rp1 = find(p1);
    int Rp2 = find(p2);
 
    if (Rp1 == Rp2){
      Ppair =0;
      for(int i=1; i<=n; i++){
        check[i] = false;
      }
      return identify(p2,p1);
    }
   
    Rpill[Rp1] = Rp2;
    return 0;
}

int main() {
  int conflict=0;
  int p1 , p2;
  scanf("%d",&n);
  scanf("%d",&m);

  for (int i = 1; i <= n; i++)
      Rpill[i] = i;
  
  int isconf =0;

  for(int i =0; i<m; i++){
    
    scanf("%d %d",&p1,&p2);
    if(conflict == 1){
      continue;
    }

    else{
      cpill[p1].push_back(p2);
      cpill[p2].push_back(p1);
      isconf = Cpair(p1,p2);

      if(isconf == 1 && ans == 0){
        ans = i+1;
        conflict =1;
      }
    
    }

  }
  cout << ans;

}
