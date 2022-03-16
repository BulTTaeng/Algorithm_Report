#include <iostream>
#include <vector>
using namespace std;


//long **hours;

vector<long> cable;
vector<long> half;

long Minhour(vector<long> vcable, int nN, long nresult) 
{ 
  if(nN == 1) return 0;
  long min =20002, minloc =0;
  
  for(int i =0; i<nN-1; i++){
    if(min >= vcable[i] + vcable[i+1]){
      min = vcable[i] + vcable[i+1];
      minloc = i;
    }
  }

  vcable.erase(vcable.begin() + minloc );
  vcable.insert(vcable.begin() + minloc, min);
  vcable.erase(vcable.begin() + minloc+1);
  /*for(int i =0; i<nN-1; i++){
    printf("%ld " , vcable[i]);
  }

  cout <<endl;*/
  nresult += min;
  
  nN--;
  nresult += Minhour(vcable, nN, 0);
  return nresult;
}

long Minhour2(vector<long> half, int N2, long result2){
  
  long two;
  for(int i =0; i<half.size()-1; i++){
    two = half[i] + half[i+1];
    result2 += two;
    half.erase(half.begin() + i);
    half.insert(half.begin() + i, two);
    half.erase(half.begin() + i+1);
  }
  /*for(int i =0; i<half.size(); i++){
    printf("%ld " , half[i]);
  }

  cout <<result2<<endl;*/
  N2 = half.size();
  result2 += Minhour(half , N2, 0);
  return result2;
}


int main() {
  long input;
  int N;
  int N2;
  long result =0;
  long result2 = 0;
  
  scanf("%d",&N);
  N2 = N;
  for(int i =0; i<N; i++){
    scanf("%ld",&input);
    cable.push_back(input);
    half.push_back(input);
  }
  
  result = Minhour(cable, N,result);
  //cout <<endl;
  result2 = Minhour2(half, N2, result2);
  if(result > result2){
    cout << result2;
  }
  else{
    cout<< result;
  }
  
  return 0;
}
