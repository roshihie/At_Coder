#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnStair, vector<int>& rvnFine)
{
  int nFineSiz;
  cin >> rnStair >> nFineSiz;
  rvnFine.resize(rnStair + 1, true);

  for (int nx = 0; nx < nFineSiz; ++nx)
  {
    int nFine;
    cin >> nFine;
    rvnFine[ nFine ] = false;
  }
}

llong calcNumOfWays(int nStair, const vector<int>& cnrvnFine)
{
}
  
int main()
{
  int nStair;
  vector<int> vnFine;

  input(nStair, vnFine);
  cout << calcNumOfWays(nStair, vnFine) << endl;

  return 0;
}
