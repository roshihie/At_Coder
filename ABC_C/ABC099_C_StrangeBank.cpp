#include <bits/stdc++.h>
using namespace std;

void input(int& rnCash)
{
  cin >> rnCash;
}

int calcOpeCnt(int nCash)
{
  const vector<int> cnvnBase = { 59049, 46656, 7776, 6561, 1296, 729,
                                   216,    81,   36,    9,    6,   1 };
  int nOpeCnt = 0;

  for (int nBase : cnvnBase)
  {
    int nTimes = nCash / nBase;
    nCash -= nBase * nTimes;

    nOpeCnt += nTimes;
  }
  return nOpeCnt;
}

int main()
{
  int nCash; 
  input(nCash);
  cout << calcOpeCnt(nCash) << endl;

  return 0;
}
