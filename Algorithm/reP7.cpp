#include <iostream>
#include <algorithm>

using namespace std;

long long dp[501][501];
long long sum[501];
long long input[501];
int N;

int main() {
  scanf("%d",&N);

  for(int i =1; i<=N; i++){
    scanf("%lld",&input[i]);
    sum[i] = sum[i-1] + input[i];
  }

  for(int i=1; i<N;i++){
    for(int j =1; j+i<=N;j++){
      int k = j+i;
      dp[j][k] = 50000001;
      for(int now = j; now<k; now++){
        dp[j][k] = min(dp[j][k] , dp[j][now] + dp[now+1][k] + sum[k] - sum[j-1]);
      }
    }
  }

  cout << dp[1][N];
}
