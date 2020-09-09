#include <bits/stdc++.h>
using namespace std;

void input(vector<string>& rvsColor, int& rnRemain)
{
  int nySiz, nxSiz;
  cin >> nySiz >> nxSiz >> rnRemain;
  rvsColor.resize(nySiz);

  for (string& rsColor : rvsColor)
    cin >> rsColor;
}

int calcNumOfCase(const vector<string>& cnrvsColor, int nRemain)
{
  int nNumOfCase = 0;

  for (int nyCtl = 0; nyCtl < ( 1 << cnrvsColor.size() ); nyCtl++)
    for (int nxCtl = 0; nxCtl < ( 1 << cnrvsColor[0].size() ); nxCtl++)
    {
      int nCntTrg = 0;

      for (int nyEach = 0; nyEach < cnrvsColor.size(); nyEach++)
      {
        if (nyCtl & ( 1 << nyEach )) continue;

        for (int nxEach = 0; nxEach < cnrvsColor[nyEach].size(); nxEach++)
        {
          if (nxCtl & ( 1 << nxEach )) continue;
          if (cnrvsColor[nyEach][nxEach] == '#') nCntTrg++;
        }
      }
      if (nCntTrg == nRemain) nNumOfCase++;
    }

  return nNumOfCase;
}
 
int main()
{
  vector<string> vsColor;
  int nRemain;

  input(vsColor, nRemain);
  cout << calcNumOfCase(vsColor, nRemain) << endl;

  return 0;
}
