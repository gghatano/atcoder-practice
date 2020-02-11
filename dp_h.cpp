#include <bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;

int main(){
  int H,W;
  cin >> H >> W;
  vector<string> m;

  for(int i = 0; i < H; i++){
    string x;
    cin >> x;
    m.push_back(x);
  }

  // 初期化
  long dp[H-1][W-1];

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;

  // 更新
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      if((i+1 < H) && (m[i+1][j] == '.')){
        dp[i+1][j] += dp[i][j];
        if(dp[i+1][j] >= MOD) dp[i+1][j] -= MOD;
      }
      if((j + 1 < W) && (m[i][j+1] == '.')){
        dp[i][j+1] += dp[i][j];
        if(dp[i][j+1] >= MOD) dp[i][j+1] -= MOD;
      }
    }
  }

  cout << dp[H-1][W-1] << endl;

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cerr << "i,j: " << i << "," << j << ": " << dp[i][j] << endl;
    }
  }
}
