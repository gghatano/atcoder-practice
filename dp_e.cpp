#include <bits/stdc++.h>

using namespace std;

int main(){
  long N, W;
  cin >> N >> W;
  long w[N], v[N];
  long vmax = N * 1001;
  long wmax = 10000000000;

  // dp[i][j] : iまでの商品で、価値jを達成する重さの最小値
  // dp[i+1][j]: min(dp[i][j], dp[i][j-v[i+1]] + w[i+1])
  // O(10^3 * N * N) = 10^7 マス
  //
  // long dp[N][vmax];
  vector<vector<long> > dp(N, vector<long>(vmax, wmax));


  for(int i = 0; i < N; i++){
    cin >> w[i] >> v[i];
    cerr << "w[i], v[i]" << w[i] << ", " << v[i] << endl;
  }
  for(int i = 0; i< N; i++){
    dp[i][0] = 0;
  }
  for(int j = 0; j< vmax; j++){
    if(j <= v[0]) dp[0][j] = w[0];
  }

  for(int i = 1; i < N; i++){
    for(int j = 0; j < vmax; j++){
      if(j - v[i] >= 0){
        dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
      } 

      if(j <=  v[i]){
        dp[i][j] = min(dp[i][j], w[i]);
      }

      dp[i][j] = min(dp[i][j], dp[i-1][j]);
    }
  }

  // N-1で、vmax以下の最大値で、W以下なものを探す

  long ans = 0;
  for(int i = 0; i < vmax; i++){
    cerr << "dp[N-1]["<<i<<"]: " << dp[N-1][i] << endl;
    if(dp[N-1][i] <= W){
      ans = i;
    }
  }

  cout << ans << endl;

}
