#include<bits/stdc++.h>
using namespace std;

int digit(long N, long K){
  int digit = 1;
  while(N >= K){
    N = N / K;
    digit++;
  }
  return(digit);
}


int main(){
  long N, K;
  cin >> N >> K;

  cout << digit(N, K) << endl;
}
