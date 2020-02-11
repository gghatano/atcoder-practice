#include <bits/stdc++.h>
using namespace std;

int main(){
  string A,B;
  cin >> A >> B;

  vector<int>x(2);
  cin >> x.at(0) >> x.at(1);

  string color;
  cin >> color;

  if(color == A){
    cout << x.at(0) -1 << " " << x.at(1) << endl;
  } else { 
    cout << x.at(0) << " " << x.at(1) -1 << endl;
  }

}

