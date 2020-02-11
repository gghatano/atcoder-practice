#include <bits/stdc++.h>
using namespace std;

typedef long double LL;


bool check(LL P, vector<LL> H, vector<LL> S){
  vector<LL> T(H.size());

  for(int i = 0; i < T.size(); i++){
    T.at(i) = (P - H.at(i)) / S.at(i);
    if(T.at(i) < 0) T.at(i) = -1;
  }
  sort(T.begin(), T.end());

  bool chk = true;
  for(int i = 0; i < T.size(); i++){
    if(T.at(i) < i){
      chk = false;
      break;
    }
  }

  return chk;
}

int main(){
  int N; cin >> N;

  vector<LL> H(N);
  vector<LL> S(N);
  for(int i=0; i < N; i++){
    cin >> H.at(i) >> S.at(i);
  }

  long right = 100000000000;
  long left = 0;

  while(right - left > 1){
    LL tmp = ( right + left ) / 2;
    if(check(tmp, H, S)){
      right = tmp;
    } else {
      left = tmp;
    }
    cerr << right - left << endl;
  }
  cout << right << endl;
}


