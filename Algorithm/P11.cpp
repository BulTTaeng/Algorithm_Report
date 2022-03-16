#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> word;
vector<string> ans[1001];

int used[1001];
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
  int lastloc =0;
  int cc=0;
  for(int i=0; i<word.size(); i++){
    
    last = word[i][word[i].size()-1];
    lastloc = i;
  

    for(int j =0 ; j<word.size(); j++){
      if( i==j){
        continue;
      }
       if(word[j][0] ==last){
        //cout <<word[j] << " " <<i<<endl;
        last = word[j][word[j].size()-1];
        
        //cout <<last<<endl;
        
        word[lastloc] = word[lastloc] +"\n"+ word[j];
        //cout << word[j]<<endl;
        word.erase(word.begin()+j);
        if(lastloc > j){
          lastloc--;
        }
        //j=0;
        

        if(word.size() ==1){
          success= 1;
          break;
        }
      }

    }//j

    if(success ==1){
      break;
    }

    /*for(int k =0 ;k <word.size(); k++){
      cout << word[k] << " ";
    }
    cout<<endl;*/

  }//i

  if(success == 0){
    cout <<"0";
  }
  else{
    cout <<word[0];
  }

  return 0;

  
}
