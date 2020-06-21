#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(int& rnStair, vector<int>& rvnBroken)
{
  int nBrokenSiz;
  cin >> rnStair >> nBrokenSiz;
  rvnBroken.resize(nBrokenSiz);

  for (int& rnBroken : rvnBroken)
    cin >> rnBroken;
}

void fnDPWaySet(int nStair, vector<llong>& rvnDPWays)
{
  rvnDPWays.resize(nStair + 1);
  rvnDPWays[0] = 1;

  for (int i = 1; i < rvnDPWays.size(); i++)
  {
    rvnDPWays[i] += rvnDPWays[i - 1];
    if (i > 1)
      rvnDPWays[i] += rvnDPWays[i - 2];

    rvnDPWays[i] %= 1000000007;
  }
}

bool fnUseFulStairSet(int nStair, vector<int>& rvnUseful, const vector<int>& cnrvnBroken)
{
  for (int i = 0; i < cnrvnBroken.size(); i++)
    if (i == 0)
      if (cnrvnBroken[i] == 1);
      else
        rvnUseful.push_back( cnrvnBroken[i] - 1 );
    else
      if (cnrvnBroken[i] - cnrvnBroken[i - 1] == 1)
        return false;
      else
        rvnUseful.push_back( (cnrvnBroken[i] - 1) - (cnrvnBroken[i - 1] + 1) );

  if (cnrvnBroken.size())
    rvnUseful.push_back( nStair - (cnrvnBroken[cnrvnBroken.size() - 1] + 1) );
  else
    rvnUseful.push_back( nStair );
  return true;
}

llong fnNumOfWays(int nStair, const vector<int>& cnrvnBroken)
{
  vector<llong> vnDPWays;
  fnDPWaySet(nStair, vnDPWays);

  vector<int> vnUseful;
  if (!fnUseFulStairSet(nStair, vnUseful, cnrvnBroken))
    return 0;

  llong nNumOfWays = 1;

  for (int nUseful : vnUseful)
  {
    nNumOfWays *= vnDPWays[ nUseful ];
    nNumOfWays %= 1000000007;
  }
  
  return nNumOfWays;
}
  
int main()
{
  int nStair;
  vector<int> vnBroken;

  fnInput(nStair, vnBroken);
  cout << fnNumOfWays(nStair, vnBroken) << endl;

  return 0;
}
