#include <bits/stdc++.h>

using namespace std;

int main(){
  long N,W;
  cin >> N >> W;
  vector<long>v(N);
  vector<long>w(N);

  // dp[i][j] : 商品iまで、重さjまでの価値最大値
  vector<vector<long> > dp(N, vector<long>(W+1, 0));


  for(int i = 0; i < N; i++){
    cin >> w.at(i) >> v.at(i);
  }

  for(int j = 0; j < W+1; j++){
    dp[0][j] = (j < w[0]) ? 0 : v[0];
  }

  for(int i = 1; i < N; i++){
    for(int j = 0; j < W+1; j++){
      if(j - w[i] >= 0){
        dp[i][j] = max(dp[i-1][j - w[i]] + v[i], dp[i-1][j]);
      } else {
        dp[i][j] = dp[i-1][j];
      }
    }
  }

  cout << dp[N-1][W] << endl;
}
