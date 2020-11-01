#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvnMonstr, vector<int>& rvnBrave)
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
  
llong calcStrikMonstr(vector<int>& rvnMonstr, vector<int>& rvnBrave)
{
  llong nStrikMonstr = 0;

  for (int nBgn = 0; nBgn < rvnBrave.size(); ++nBgn)
    for (int nFwd = nBgn; nFwd < nBgn + 2; ++nFwd)
    {
      int nCurStrik = min(rvnBrave[nBgn], rvnMonstr[nFwd]);

      rvnMonstr[nFwd] -= nCurStrik;
      rvnBrave[nBgn]  -= nCurStrik;
      nStrikMonstr += nCurStrik;
    }

  return nStrikMonstr;
}
  
int main()
{
  vector<int> vnMonstr, vnBrave;

  input(vnMonstr, vnBrave);
  cout << calcStrikMonstr(vnMonstr, vnBrave) << endl;

  return 0;
}
