#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnMonstr, vector<int>& rvnBrave)
{
  int nMonstrSiz;
  cin >> nMonstrSiz;
  rvnMonstr.resize(nMonstrSiz + 1);
  rvnBrave.resize(nMonstrSiz);

  for (int& rnMonstr : rvnMonstr)
    cin >> rnMonstr;

  for (int& rnBrave : rvnBrave)
    cin >> rnBrave;
}
  
int64_t fnStrikMonstr(vector<int>& rvnMonstr, vector<int>& rvnBrave)
{
  int64_t nSumStrikMon = 0;

  for (int nBgn = 0; nBgn < rvnBrave.size(); nBgn++)
    for (int nFoward = nBgn; nFoward < nBgn + 2; nFoward++)
    {
      int nStrikMonstr = min(rvnBrave[nBgn], rvnMonstr[nFoward]);
      rvnMonstr[nFoward] -= nStrikMonstr;
      rvnBrave[nBgn] -= nStrikMonstr;
      nSumStrikMon += nStrikMonstr;
    }

  return nSumStrikMon;
}
  
int main()
{
  vector<int> vnMonstr, vnBrave;

  fnInput(vnMonstr, vnBrave);
  cout << fnStrikMonstr(vnMonstr, vnBrave) << endl;

  return 0;
}
