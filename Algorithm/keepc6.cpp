#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long card[50001];
vector<int> sequence[2];
vector<int> score[2];

int n;

void binary_search(int num, int number) {
  if(number == 0){
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
    //cout << num << endl;
    sequence[number][target] = num;
    score[number].push_back(sequence[number].size());
  }
  else if (number == 1){
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
    cout << num <<"aaaaaa"<< endl;
    sequence[number][target] = num;
    score[number].push_back(sequence[number].size());
  }
  
}
 
void find_lis(int number) {
  if(number ==0){
    sequence[number].push_back(card[0]);
    score[number].push_back(1);
      for (int i = 1;i < n;i++) {
        if (sequence[number].back() < card[i]) {
            sequence[number].push_back(card[i]);
            score[number].push_back(sequence[number].size());
        }
        else {
            binary_search(card[i],number);
        }
      }
  }

    else if(number == 1){
      sequence[number].push_back(card[n-1]);
      score[number].push_back(1);
      for (int i = n-2;i >= 0;i--) {
        if (sequence[number].back() < card[i]) {
            sequence[number].push_back(card[i]);
            score[number].push_back(sequence[number].size());
        }
        else {
            binary_search(card[i],number);
        }
      }
    }    
}


int main() {
  int input , bscore = 0;
  cin >> n;

  for(int i =0; i<n; i++){
    scanf("%ld", &card[i]);
  } 

  find_lis(0);
  find_lis(1);
  cout << score[1].size() << endl;
  reverse(score[1].begin() , score[1].end());
  for(int i =0; i<sequence[0].size(); i++){
    cout << sequence[0][i] <<"  ";
  }
  cout << endl;
  for(int i =0; i<score[0].size(); i++){
    
    cout << score[0][i] <<"  ";
  }
  cout << endl;
  for(int i =0; i<sequence[1].size(); i++){
    cout << sequence[1][i] <<"  ";
  }
  cout << endl;
  for(int i =0; i<score[1].size(); i++){
      
    cout << score[1][i] <<"  ";
  }

  for(int i =0; i<n ; i++){
    if(bscore < (score[0][i] + score[1][i]) ){
      bscore = (score[0][i] + score[1][i]) ;
    }
  }
  cout << bscore -1 ;
  return 0;
}
