#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

bool cmp( pii a, pii b){
      return a.first < b.first;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<pii> v;
  priority_queue<int> que;

  for(int i = 0; i < N; i++){
    int a,b;
    cin >> a >> b;
    v.push_back(make_pair(a,b));
  }

  // Aが小さい順にソートする
  sort(v.begin(), v.end(), cmp);

  cerr << v[0].first << "," << v[0].second << endl;

  int index = 0;
  int ans = 0;
  for(int i = 1; i <= M; i++){
    // Aiがi以下であれば、候補としてqueueにいれる 
    while(index < N && v[index].first <= i){
      que.push(v[index].second);
      index++;
    }
    // queueから報酬最大のものを選んで、i日目の仕事とする
    if(!que.empty()){
      ans += que.top();
      que.pop();
    }
  }

  cout << ans << endl;


}
