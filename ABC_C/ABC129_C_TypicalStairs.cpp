#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(int& rnStair, vector<int>& rvnFine)
{
  int nFineSiz;
  cin >> rnStair >> nFineSiz;
  rvnFine.resize(rnStair + 1, true);

  for (int i = 0; i < nFineSiz; i++)
  {
    int nFine;
    cin >> nFine;
    rvnFine[ nFine ] = false;
  }
}

llong fnNumOfWays(int nStair, const vector<int>& cnrvnFine)
{
  const llong cnnMod = 1000000007;
  vector<llong> vnDPWays(nStair + 1);
  vnDPWays[0] = 1;

  for (int i = 1; i < vnDPWays.size(); i++)
    if (cnrvnFine[i])
    {
      vnDPWays[i] += vnDPWays[i - 1];
      if (i > 1)
        vnDPWays[i] += vnDPWays[i - 2];

      vnDPWays[i] %= cnnMod;
    }

  return vnDPWays[vnDPWays.size() - 1];
}
  
int main()
{
  int nStair;
  vector<int> vnFine;

  fnInput(nStair, vnFine);
  cout << fnNumOfWays(nStair, vnFine) << endl;

  return 0;
}
