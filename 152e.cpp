#include <bits/stdc++.h>
using namespace std;

map<int, int> prime_factor(int N){
  map<int, int> ret;

  for(int i = 2; i*i <= N; i++){
    while( N % i == 0){
      ret[i]++;
      N = N / i;
    }
  }
  if(N!=1){
    ret[N] = 1;
  }
  return ret;
}

map<int, int> map_merge(map<int,int>m1, map<int, int>m2){
  for(auto p : m1){
    if(m2.count(p.first) == 0){
      m2[p.first] = p.second;
    } else {
      m2[p.first] = max(m2[p.first], p.second);
    }
  }
  m2.erase(1);
  return m2;
}

map<int, int> map_diff(map<int,int>m1, map<int, int>m2){
  for(auto p : m2){
     m1[p.first] = m1[p.first] - p.second;
  }
  return m1;
}

int main(){
  int N;
  cin >> N;
  vector<map<int,int> > v(N);

  map<int,int> gcm;
  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    auto pf = prime_factor(tmp);
    v.at(i) = pf;

    for(auto p : pf){
      if(gcm.count(p.first) == 0){
        gcm[p.first] = p.second;
      } else {
        gcm[p.first] = max(gcm[p.first], p.second);
      }
    }
  }

  long long ans = 0;
  long long mod = 1000000000 + 7;

  for(int i = 0; i < N; i++){
    // pf:最小公倍数 から, v.at(i)の要素を引く
    //
    long long tmp = 1;
    auto pf_tmp = map_diff(gcm, v.at(i));
    for(auto p : pf_tmp){
      tmp = tmp * (long long) ( pow(p.first, p.second) % mod );

  }

  cout << ans << endl;

}


