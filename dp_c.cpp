#include <bits/stdc++.h>

using namespace std;

int main(){
  long N;
  cin >> N;

  // 幸福度
  vector<vector<long> > hp(N, vector<long>(3,0));
  // 幸福度の総和の最大値
  vector<vector<long> > dp(N, vector<long>(3,0));

  for(int i = 0; i < N; i++){
    cin >> hp.at(i).at(0) >> hp.at(i).at(1) >> hp.at(i).at(2);
  }
  
  // 1日目
  for(int j = 0; j < 3; j++){
    dp.at(0).at(j) = hp.at(0).at(j);
  }

  for(int i = 0; i < N -1; i++){
    for(int j = 0; j <= 2; j++){
      for(int k = 0; k <=2; k++){
        if(k!=j) dp[i+1][j] = max(dp[i+1][j], dp[i][k] + hp[i+1][j]);
      }
    }
  }
  long ans = 0;
  for(int j = 0; j < 3; j++){
    ans = max(ans, dp[N-1][j]);
  }
  cout << ans << endl;


}
