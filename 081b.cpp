#include<bits/stdc++.h>
using namespace std;

long div2count(long n){
  long count = 0;
  while(n % 2 == 0){
    count++;
    n = n / 2;
  }
  return count;
}

int main(){
  int N;
  cin >> N;

  long ans = 100000000000000;
  for(int i = 0; i < N; i++){
    long tmp;
    cin >> tmp;
    long count = div2count(tmp);
    cerr << count << endl;
    if(count < ans){
      ans = count;
    }

    if(ans == 0) { 
      break;
    }
  }

  cout << ans << endl;

}
