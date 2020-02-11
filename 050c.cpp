#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  vector<int> v(N);

  for(int i=0; i < N; i++){
    cin >> v.at(i) ;
    if(N % 2 == 0){
      v.at(i) = v.at(i) -1;
    }
  }

  if(N % 2 == 1){
    v.push_back(0);
  }

  sort(v.begin(), v.end());

  bool chk = true;
  for(int i = 0; i < v.size(); i+=2){
    cerr << "i: " << i << " v: " << v.at(i) << " " << v.at(i+1) << endl;

    if(v.at(i) != v.at(i+1) || v.at(i) != i){
      chk = false;
      //break;
    }
  }
  long long ans = 1;
  long long MOD = 1000000000 + 7;

  for(int i=0; i < N/2; i++){
    ans = ans * 2;
    ans %= MOD;
  }

  if(chk) cout << ans << endl;
  else cout << 0 << endl;

  
}

