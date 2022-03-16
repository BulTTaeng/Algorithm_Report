#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> word;
vector<string> ans[1001];
bool comp(string s1, string s2){
	return s1 < s2;	
}

int main() {
  string input;
  char last;
  scanf("%d",&n);
  getchar();

  for(int i =0; i<n; i++){
    getline(cin,input);
    word.push_back(input);
    //cout<<word[i]<<endl;
  }

  sort(word.begin(), word.end(),comp);
 
  int success =0;
 
  int i=0;
  for(i =0; i<n; i++){
    last = word[i][word[i].size()-1];
    ans[i].push_back(word[i]);

    vector<string> check;
    check.resize(word.size());
    copy(word.begin(),word.end(),check.begin());
    check.erase(check.begin() +i);
    for(int j =0 ; j<check.size(); j++){

      if(check[j][0] ==last){
        last = check[j][check[j].size()-1];
        ans[i].push_back(check[j]);
        //auto itr = check.begin()+j;
        //cout<< *itr <<endl;
        check.erase(check.begin()+j);

        if(check.empty()){
          success= 1;
          break;
        }

        j=-1;
        continue;
      }

    }//j
    if(success == 1){
      break;
    }
  }//i

  
  if(ans[i].size() != n){
    cout << "0";
  }
  else{
    for(int k =0; k<n;k++){
      cout <<ans[i][k] <<endl; 
    }
  }

  return 0;

  
}
