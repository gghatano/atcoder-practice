#include <bits/stdc++.h>
using namespace std;

int main(){
  long N; cin >> N;

  long ans;
  long tmp1 = 2, tmp2 = 1;


  for(int i = 2; i <= N; i++){
    ans = tmp1 + tmp2;
    tmp1 = tmp2;
    tmp2 = ans;

    //cerr << "i: " << i << ", ans: " << ans << endl;
  }

  if(N==1){
    cout << 1 << endl;
  } else {
    cout << ans << endl;
  }

}

