#include <bits/stdc++.h>
using namespace std;

void input(int& rnNum)
{
  cin >> rnNum;
}

void outPairKakko(int nNum, int nBit)
{
  for (int nEach = nNum - 1; nEach >= 0; --nEach)
    if (nBit & ( 1 << nEach ))
      cout << ")";
    else
      cout << "(";

  cout << endl;
}

void chkPairKakko(int nNum)
{
  for (int nBit = 0; nBit < ( 1 << nNum ); ++nBit)
  {
    int nLeftkkCnt = 0, nRigtkkCnt = 0;
    bool bPairkakko = true;

    for (int nEach = nNum - 1; nEach >= 0; --nEach)
    {
      if (nBit & ( 1 << nEach ))
         ++nRigtkkCnt;
      else
         ++nLeftkkCnt;

      if (nLeftkkCnt < nRigtkkCnt)
      {
        bPairkakko = false;
        break;
      }
    }
    if (bPairkakko && nLeftkkCnt == nRigtkkCnt)
       outPairKakko(nNum, nBit);
  }
}
  
int main()
{
  int nNum;
  input(nNum);
  chkPairKakko(nNum);

  return 0;
}
