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
      m2[p.first] += p.second;
    }
  }
  return m2;
}


int main(){

  long long N; 
  cin >> N;
  // N = 1000;

  map<int, int> pf;
  for(int i = 2; i <= N; i++){
    pf = map_merge(pf, prime_factor(i));
  }

  long long ans = 1;
  long long mod = 1000000000 + 7;
  for(auto p : pf){
    cerr << p.first << " " << p.second << endl;
    ans = ans * (long long)(p.second + 1);
    ans = ans % mod;
  }

  cout << ans << endl;

}


