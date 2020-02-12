#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  cin >> N;


  int n = N.size()-1;

  for(int bit = 0; bit < (1<<n); bit++){

    int ans = N[0] - '0';
    string tmp;
    tmp = tmp + N[0];

    // 0 1 2
    for(int i = 0; i < n; i++){
      if(bit & (1<<i)){
        ans += N[i+1] - '0';
        tmp = tmp + "+" + N[i+1];
      } else {
        ans -= N[i+1] - '0';
        tmp = tmp + "-" + N[i+1];
      }
    }


    if(ans == 7){
      cout << tmp << "=7" << endl;
      break;
    }

  }

}

