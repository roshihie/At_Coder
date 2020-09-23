#include <bits/stdc++.h>
using namespace std;

void input(int& rnNum, int& rnTrg, vector<int>& rvnCandls)
{
  cin >> rnNum >> rnTrg;
  rvnCandls.resize(rnNum);

  for (int& rnCandls : rvnCandls)
    cin >> rnCandls;
}

int calcMinPutonTime(int nNum, int nTrg, const vector<int>& cnrvnCandls)
{
  int nMinPutonTime = INT_MAX;
  int nLeft = 0;
  int nRigt = nLeft + nTrg - 1;

  while ( nLeft < nNum &&
          nRigt < nNum    )
  {
    int nPutonTime =  min( abs(cnrvnCandls[nLeft]), abs(cnrvnCandls[nRigt]) )
                    + cnrvnCandls[nRigt] - cnrvnCandls[nLeft];
    nMinPutonTime = min(nMinPutonTime, nPutonTime);

    ++nLeft;
    ++nRigt;
  }
  return nMinPutonTime;
}
 
int main()
{
  int nNum, nTrg;
  vector<int> vnCandls;

  input(nNum, nTrg, vnCandls);
  cout << calcMinPutonTime(nNum, nTrg, vnCandls) << endl;

  return 0;
}
