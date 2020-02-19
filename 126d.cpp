#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int main(){
  int N; cin >> N;
  long mat[N][N];
  vector<int> ans(N, -1);

  vector<vector<int> > v(N);
  queue<int> que;

  for(int i = 0; i < N - 1; i++){
    int a,b,c;
    cin >> a >> b >> c;
    // a < b
    mat[a-1][b-1] = c;
    mat[b-1][a-1] = c;

    v.at(a-1).push_back(b-1);
  }

  // -1: 更新してない, 0: 黒, 1:白
  que.push(0);
  ans[que.front()] = 0;

  bool flg = true; 
  while(!que.empty()){ 
    auto top = que.front();
    que.pop();

    for(auto a : v.at(top)){
      // 距離が奇数だったら、色を変える
      // 距離が偶数だったら、色が同じ
      cerr << "top: " << top << " a: " << a << " mat[top][a]: " << mat[top][a] << endl; 
      int tmpans = (ans[top] + mat[top][a]) % 2;
      cerr << "tmpans: " << tmpans << endl;

      // ans[a]が-1だったら、tmpans
      if(ans[a] == -1){
        ans[a] = tmpans;
      } else {
        // ans[a]が-1じゃなかったら、
        //   tmpansだったら、continue;
        //   tmpansじゃなかったら、終了;
        if(ans[a] == tmpans){

        } else {
          flg = false;
          break;
        }
      }
      cerr << "ans[a]: " << ans[a] << endl;
      que.push(a);
    }
    if(!flg) break;
  }

  if(flg){
    for(auto a: ans){
      cout << a << endl;
    }
  } else { 
    cout << "NO" << endl;
  }
}

