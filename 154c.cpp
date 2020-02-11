#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long> x(n);
  for(int i = 0; i < n; i++){
    cin >> x.at(i);
  }

  sort(x.begin(), x.end());
  string ans = "YES";
  for(int i = 0; i < n-1; i++){
    if(x[i] == x[i+1]){
      ans = "NO";
      break;
    }
  }
  cout << ans << endl;

}

