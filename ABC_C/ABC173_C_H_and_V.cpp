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

int calcNumOfCases(const vector<string>& cnrvsColor, int nRemain)
{
  int nNumOfCases = 0;

  for (int nyBit = 0; nyBit < ( 1 << cnrvsColor.size() ); ++nyBit)
    for (int nxBit = 0; nxBit < ( 1 << cnrvsColor[0].size() ); ++nxBit)
    {
      int nCntTrg = 0;

      for (int nyEach = 0; nyEach < cnrvsColor.size(); ++nyEach)
      {
        if (nyBit & ( 1 << nyEach )) continue;

        for (int nxEach = 0; nxEach < cnrvsColor[nyEach].size(); ++nxEach)
        {
          if (nxBit & ( 1 << nxEach )) continue;
          if (cnrvsColor[nyEach][nxEach] == '#') ++nCntTrg;
        }
      }
      if (nCntTrg == nRemain) ++nNumOfCases;
    }

  return nNumOfCases;
}
 
int main()
{
  vector<string> vsColor;
  int nRemain;

  input(vsColor, nRemain);
  cout << calcNumOfCases(vsColor, nRemain) << endl;

  return 0;
}
