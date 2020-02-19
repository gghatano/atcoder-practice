#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  map<string, int> m;

  for(int i = 0; i < N; i++){
    string tmp;
    cin >> tmp;
    auto itr = m.find(tmp);
    if(itr != m.end()){
      m[tmp] += 1;
    } else { 
      m[tmp] = 1;
    }
  }
  int maxnum = 0;
  for(auto x : m){
    if(x.second > maxnum){
      maxnum = x.second;
    }
  }
  cerr << maxnum << endl;

  vector<string> ans;
  for(auto x : m){
    if(x.second == maxnum){
      ans.push_back(x.first);
    }
  }
  sort(ans.begin(), ans.end());

  for(auto x : ans){
    cout << x << endl;
  }


}
