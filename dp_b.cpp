#include <bits/stdc++.h>

using namespace std;

int main(){
  long N,K;
  cin >> N >> K;

  long MAX = 100000000000;
  vector<long> h(N);
  for(int i = 0; i < N; i++){
    cin >> h.at(i);
  }

  vector<long> dp(N, MAX);

  dp[0] = 0;

  for(int i = 0; i < N; i++){
    for(int j = 1; (j <= K) && (i+j < N) ; j++){
      dp[i+j] = min(dp[i] + abs(h.at(i) - h.at(i+j)), dp[i+j]);
    }
  }

  for(int i = 0; i < N; i++){
    cerr << dp[i] << endl;
  }

  cout << dp[N-1] << endl;
}
