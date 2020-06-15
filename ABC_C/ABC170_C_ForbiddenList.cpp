#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnTarget, vector<int>& rvnForbid)
{
  int nForbidSiz;
  cin >> rnTarget >> nForbidSiz;
  rvnForbid.resize(nForbidSiz);

  for (int& rnForbid : rvnForbid)
    cin >> rnForbid;
}

int fnMinAbsNum(int nTarget, const vector<int>& cnrvnForbid)
{
  map<int, int> mpForbid;

  for (int nForbid : cnrvnForbid)
    mpForbid[ nForbid ]++;

  int nMore = nTarget;
  while (mpForbid[nMore] != 0)
    nMore++;

  int nLess = nTarget;
  while (mpForbid[nLess] != 0)
    nLess--;

  if (abs(nTarget - nMore) < abs(nTarget - nLess))
    return nMore;
  else
    return nLess;
}
  
int main()
{
  int nTarget;
  vector<int> vnForbid ;

  fnInput(nTarget, vnForbid);
  cout << fnMinAbsNum(nTarget, vnForbid) << endl;

  return 0;
}
