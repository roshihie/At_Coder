#include <bits/stdc++.h>
using namespace std;

void input(string& rsNum)
{
  cin >> rsNum;
}

int canMultiples3(const string& cnrsNum)
{
  int nMinDgtRemv = cnrsNum.size();
                                   // 全ての桁を消すことはないため 1 から始める
  for (int nBit = 1; nBit < ( 1 << cnrsNum.size() ); ++nBit)
  {
    int nDgtSum  = 0;
    int nDgtRemv = 0;

    for (int nEach = 0; nEach < cnrsNum.size(); ++nEach)
      if ( nBit & ( 1 << nEach ) )
        nDgtSum += cnrsNum[nEach] - '0';
      else
        ++nDgtRemv;

    if (nDgtSum % 3 == 0)
      nMinDgtRemv = min(nMinDgtRemv, nDgtRemv);
  }
  if (nMinDgtRemv == cnsNum.size())
    return -1;
  else
    return nMinDgtRemv;
}

int main()
{
  string sNum;
  input(sNum);
  cout << canMultiples3(sNum) << endl;

  return 0;
}
