#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  string ans = "No";

  if(a == b && b != c){
    ans = "Yes";
  }
  if(a == c && a != b){
    ans = "Yes";
  }
  if(b == c && a != b){
    ans = "Yes";
  }

  cout << ans << endl;
}
