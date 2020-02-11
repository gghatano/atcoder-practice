#include <bits/stdc++.h>
using namespace std;

int main(){
  long N,K;
  cin >> N >> K;
  vector<long> x(N);

  for(int i = 0; i < N; i++){
    cin >> x.at(i);
    x.at(i) = (x.at(i) + 1);
  }


  long m = 0;
  long tmp = 0;

  for(int i = 0; i < K; i++){
    tmp += x.at(i);
  }

  m = tmp;
  for(int i = 1; i < N - K + 1; i++){
    tmp = tmp - x[i-1] + x[i+K-1];
    if(tmp > m){
      m = tmp;
    }
  }

  cout << (long double)(m) / 2.0 << endl;

}

