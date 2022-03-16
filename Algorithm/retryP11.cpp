#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, adj[26][26], in_d[26], out_d[26] , visit[26];
vector<string> edge[26][26]; 
vector<int> ans;

void reset() {
	ans.clear();
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			edge[i][j].clear();
			adj[i][j] = 0;
		}
		in_d[i] = out_d[i] = 0;
	}	
}

int divide_case() {
  
	int s = 0, e = 0; 
	for (int i = 0; i < 26; i++) {
		int t = out_d[i] - in_d[i];	
    //cout << t << " ";
    if (t == 0 ) continue;	
		else if (t == 1) s++;
		else if (t == -1)e++;
    else{
      return 0;
    }
	}

	if (s == 1 && e == 1) return 1;
	if (s == 0 && e == 0) return 2;
	return 0;
}

bool comp(string s1, string s2){
	return s1 > s2;	
}

void dfs(int u) {
	for(int v=0; v<26; v++)
		while (adj[u][v] > 0) {
      sort(edge[u][v].begin() , edge[u][v].end(), comp);
			adj[u][v]--;
			dfs(v);
		}
	ans.push_back(u);
}

int main() {

		reset();
    
    cin >> n;
		vector<string> words(n);
		for (int i = 0; i < n; i++) 
      cin >> words[i];
    //sort(words.begin() , words.end(), comp);
		for (int i = 0; i < words.size(); i++) {
			int a = words[i][0] - 'a';
			int b = words[i].back() - 'a';
			edge[a][b].push_back(words[i]);
			adj[a][b]++;
			out_d[a]++;
			in_d[b]++;
		}
    
    for(int i =0; i<26; i++){
      for(int j =0; j<26 ; j++){
        sort(edge[i][j].begin() , edge[i][j].end(), comp);
        //cout << adj[i][j] << " "; 
      }
      //cout <<endl;
    }



		int _case = divide_case();
		if (_case == 0) {
			cout << "0";
			return 0;
		}

		else if (_case == 1) { 
			for (int i = 0; i < 26; i++) 
				if (out_d[i] == in_d[i] + 1) {
					dfs(i);
					break; 
				}
		}

		else {
			for(int i=0; i<26; i++)
				if (out_d[i]) { 
					dfs(i);
					break; 
				}
		}

		if (ans.size() != n + 1) {
			cout << "0";
			return 0;
		}
    /*for(int i =0 ; i< ans.size(); i++){
      cout << ans[i] << " ";
    }*/
		reverse(ans.begin(), ans.end());
		for (int i = 1; i < ans.size(); i++) {
			int a = ans[i - 1]; 
      int b = ans[i];
			cout << edge[a][b].back() << "\n";
			edge[a][b].pop_back();
		}
	
}
