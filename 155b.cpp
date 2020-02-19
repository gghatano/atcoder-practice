#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  bool chk = true;

  for(int i = 0; i < N; i++){
    int tmp;
    cin >> tmp;
    bool tmpchk = true;

    if(tmp % 2 == 0){
      if(tmp % 3 == 0 || tmp % 5 == 0){
        tmpchk = true;
      } else {
        tmpchk = false;
      }
    } else { 
      tmpchk = true;
    }
    chk = tmpchk && chk;
  }

  if(chk){
    cout << "APPROVED" << endl;
  } else { 
    cout << "DENIED" << endl;
  }

}
