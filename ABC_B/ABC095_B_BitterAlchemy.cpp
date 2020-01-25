#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnAmont, vector<int>& rvnDonAmt)
{
  int nDonSiz;
  cin >> nDonSiz >> rnAmont;

  rvnDonAmt.resize(nDonSiz);
  for (int& rnDonAmt : rvnDonAmt)
    cin >> rnDonAmt;
}

int fnDonCount(int nAmont, const vector<int>& cnrvnDonAmt)
{
  auto itMinAmt = min_element(begin(cnrvnDonAmt), end(cnrvnDonAmt));

  for (int nDonAmt : cnrvnDonAmt)
    nAmont -= nDonAmt;

  int nDonCnt = cnrvnDonAmt.size();
  nDonCnt += nAmont / *itMinAmt;

  return nDonCnt;
}

int main()
{
  int nAmont;
  vector<int> vnDonAmt;

  fnInput(nAmont, vnDonAmt);
  cout << fnDonCount(nAmont, vnDonAmt) << endl;

  return 0;
}
