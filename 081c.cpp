#include<bits/stdc++.h>
using namespace std;

int main(){
  long N,K;
  cin >> N >> K;
  map<long, long> v;
  for(int i =0; i < N; i++){
    long tmp;
    cin >> tmp;
    auto itr = v.find(tmp);
    if(itr == v.end()){
      v[tmp] = 1;
    } else { 
      v[tmp] += 1;
    }
  }
    
  priority_queue<long> q;
  for(auto x : v){
    q.push(x.second);
  }
  
  long count = 0;
  long ans = 0;
  while(!q.empty()){
    count += 1;
    ans += q.top();
    if(count == K) break;
    q.pop();
  }
  cout << N - ans << endl;
    
  
}
