#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,d,m;

int work[200002] = {0,};
vector<int> preminus;
vector<int> preloc;

bool done(int bull){
  int dueday =-1;
  int minus=0;
  int worktodo =0;
  int alarm=-1;
  int k =0;
  int workdone = 0;
  
  for(int i =1; i<=n+d; i++){

    worktodo += work[i];
    if(alarm != -1 && minus != 0){
      workdone += bull;
    }
    else{
      workdone = 0;
      alarm= -1;
    }

    while(workdone > 0 && k < preminus.size()){
     
      if(alarm>=0 && workdone >preloc[k]){
        if(dueday < preloc[k]){
          dueday = preloc[k];
        }
        workdone-=preminus[k];
      }
      k++;
      
      if(workdone <0){
        workdone = 0;
      }
    }
  
    if(dueday != -1 && i > dueday && minus != 0){
      return false;
    }

   

    if(minus == 0){ 
      if(worktodo != 0){ 
        if(worktodo == bull){
          minus =0;
          dueday = -1;
          worktodo = 0;
        }

        else if(worktodo > bull){ 
          minus += (worktodo - bull);
          worktodo = 0;
          dueday = (i+d);
          preminus.push_back(minus);
          preloc.push_back(i+d);
          if(alarm == -1){
            alarm++;
          }
          
        }

        else{
          worktodo =0;
          dueday =-1;
        }

      }

    } // end of minus ==0

    else{ 
      if(worktodo == 0){ 
        if(minus == bull){
          minus =0;
          dueday = -1;
          
        }

        else if(minus > bull){
          minus -= bull;
          
        }

        else { // ÀÜ¾÷ Ã³¸®³¡!!!
          minus =0;
          dueday =-1;
        }

      }

      else{ 

        if(minus == bull){
          minus =0;
          minus += worktodo;
          preminus.push_back(minus);
          preloc.push_back(i+d);
          alarm++;
          dueday = (i+d);
          worktodo = 0;
        }

        else if(minus > bull){
          minus -= bull;
          
          minus += worktodo;
          preminus.push_back(minus);
          preloc.push_back(i+d);
          alarm++;
          worktodo = 0;
        }

        else { 
          worktodo -= (bull - minus);
          if(worktodo <0) worktodo = 0;
          minus =0;
          minus += worktodo;
          preminus.push_back(minus);
          preloc.push_back(i+d);
          alarm++;
          if(minus == 0){
            dueday =-1;
          }
          else{
            dueday = (i+d);
          }
          worktodo = 0;
        }

      }
      

    }
    
  }// end of loop


  return true;
}

int binarySearch( int start, int end) {

    while (start <= end) {
        int bull = (start + end) / 2;
        preminus.clear();
        preloc.clear();
        if (done(bull)) {
            end = bull - 1;
        } else {
            start = bull + 1;
        }
    }

    return start;
}

int main() {
  int input,max=0,min=1;
  
  scanf("%d %d %d",&n,&d,&m);

  for(int i=0; i<m; i++){
    scanf("%d",&input);
    work[input]++;
    
    if(work[input] > max)
      max = work[input];
  }
  
  cout << binarySearch(min, max);
 
  return 0;
}
