#include<bits/stdc++.h>
using namespace std;


long sumdist(int m, vector<int> v){
  double ans = 0;
  for(int i = 0; i < v.size(); i++){
    ans += (v.at(i) - m ) * (v.at(i) - m );
  }

  return(ans);

}

int main(){
  int N;
  cin >> N;
  vector<int> v(N);

  int mean = 0;
  for(int i = 0; i < N; i++){
    cin >> v.at(i);
    mean += v.at(i);
  }
  mean = mean / N;

  long ans;
  ans = min(sumdist(mean, v), sumdist(mean-1, v));
  ans = min(ans, sumdist(mean+1, v));

  cout << ans << endl;


  

}
