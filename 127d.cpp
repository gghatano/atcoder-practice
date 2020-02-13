#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

bool cmp(pii x, pii y){
  return x.second > y.second;
}

int main(){
  long N, M;
  cin >> N >> M;
  vector<long> A;

  for(int i = 0; i < N; i++){
    long x;
    cin >> x;
    A.push_back(x);
  }

  vector<pii> v;
  for(int i = 0; i < M; i++){
    long x,y;
    cin >> x >> y;
    v.push_back(make_pair(x,y));
  }

  // 全部書き換わったとしたら、N個
  // vから大きい順にN個とって、Aに足して、ソートして、上からN個取る
  //
  sort(v.begin(), v.end(), cmp);
  // cerr << v[0].first << "," << v[0].second << endl;

  int counter = 0;
  for(int i = 0; i < M; i++){
    if(counter >= N) break;
    for(int j = 0; j < v[i].first && counter < N; j++){
      A.push_back(v[i].second);
      counter++;
    }
  }

  sort(A.begin(), A.end(), greater<int>());
  
  long ans = 0;
  for(int i = 0; i < N; i++){
    ans += A[i];
  }
  cout << ans << endl;




  
  


}
