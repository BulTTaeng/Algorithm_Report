#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> card;
vector<int> sequence[2];
vector<int> score[2];

int n;

void nextcard(int num, int number) {
  
    int low = 0, high = sequence[number].size()-1, mid;
    int target = 1000000001;
    while (low <= high) {
        mid = (low + high) / 2;
        int now = sequence[number][mid];
        if (now >= num) {
            if (target > mid)
                target = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
   
    sequence[number][target] = num;
    score[number].push_back(sequence[number].size());
  
}
 
void cardlist(int number) {
  
    sequence[number].push_back(card[0]);
    score[number].push_back(1);
      for (int i = 1;i < n;i++) {
        if (sequence[number].back() < card[i]) {
            sequence[number].push_back(card[i]);
            score[number].push_back(sequence[number].size());
        }
        else {
            nextcard(card[i],number);
        }
      }
    
}


int main() {
  long input;
  int bscore = 0;
  cin >> n;

  for(int i =0; i<n; i++){
    scanf("%ld",&input);
    card.push_back(input);
  } 

  cardlist(0);
  reverse(card.begin(), card.end());
  
  cardlist(1);
  //reverse(score[1].begin(), score[1].end());

  for(int i =0; i<n ; i++){
    if(bscore < (score[0][i] + score[1][n-i-1]) ){
      bscore = (score[0][i] + score[1][n-i-1]) ;
    }
  }

  cout <<bscore -1 ;
  return 0;
}
