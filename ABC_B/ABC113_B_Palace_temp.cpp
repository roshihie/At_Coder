#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnBasTmpr, int& rnTrgTmpr, vector<int>& rvnPosHeight)
{
  int nPosSiz;
  cin >> nPosSiz;
  cin >> rnBasTmpr >> rnTrgTmpr;

  rvnPosHeight.resize(nPosSiz);
  for (int& rnPosHeight : rvnPosHeight)
    cin >> rnPosHeight;
}

int fnTmprCheck(int nBasTmpr, int nTrgTmpr, const vector<int>& cnrvnPosHeight)
{
  double nMinDiff = (double)DBL_MAX;
  int nMinPos;

  for (int n = 0; n < cnrvnPosHeight.size(); n++)
  {
    auto nCalc1 = cnrvnPosHeight[n] * 0.006;
    auto nCalc2 = nBasTmpr - nCalc1;
    auto nPosDiff = abs(nCalc2 - nTrgTmpr);

    cout << "nCalc1 = (" << nCalc1 << ")" << endl;
    cout << "nCalc2 = (" << nCalc2 << ")" << endl;
    cout << "nPosDiff = (" << nPosDiff << ")" << endl;
    if (nPosDiff < nMinDiff)
    {
      nMinDiff = nPosDiff;
      nMinPos  = n;
    }
  }
  return nMinPos + 1;
}

int main()
{
  int nBasTmpr, nTrgTmpr;
  vector<int> vnPosHeight;

  fnInput(nBasTmpr, nTrgTmpr, vnPosHeight);
  cout << fnTmprCheck(nBasTmpr, nTrgTmpr, vnPosHeight) << endl;

  return 0;
}
