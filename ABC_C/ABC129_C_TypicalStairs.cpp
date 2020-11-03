#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvnFine)
{
  int nStair;
  int nBrokenSiz;
  cin >> nStair >> nBrokenSiz;
  rvnFine.resize(nStair + 1, true);

  for (int i = 0; i < nBrokenSiz; i++)
  {
    int nBroken;
    cin >> nBroken;
    rvnFine[ nBroken ] = false;
  }
}

llong calcNumOfWays(const vector<int>& cnrvnFine)
{
  const int cnnMod = 1e9 + 7;
  vector<llong> vnDpWays(cnrvnFine.size());

  vnDpWays[0] = 1;

  for (int nx = 1; nx < vnDpWays.size(); ++nx)
    if ( cnrvnFine[nx] )
    {
      vnDpWays[nx] += vnDpWays[nx - 1];
      if (nx > 1)
        vnDpWays[nx] += vnDpWays[nx - 2];

      vnDpWays[nx] %= cnnMod;
    }

  return vnDpWays[ vnDpWays.size() - 1 ];
}
  
int main()
{
  vector<int> vnFine;

  input(vnFine);
  cout << calcNumOfWays(vnFine) << endl;

  return 0;
}
