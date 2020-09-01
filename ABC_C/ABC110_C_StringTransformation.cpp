#include <bits/stdc++.h>
using namespace std;

void fnInput(string& rsSrc, string& rsTrg)
{
  cin >> rsSrc >> rsTrg;
}

string fnConvChk(string sSrc, string sTrg)
{
  vector<int> vnSrc(26, -1), vnTrg(26, -1);

  for (int i = 0; i < sSrc.size(); ++i)
  {
    int nSrc = sSrc[i] - 'a';
    int nTrg = sTrg[i] - 'a';

    if (vnSrc[nSrc] == -1 && vnTrg[nTrg] == -1)
    {
      vnSrc[nSrc] = nTrg;
      vnTrg[nTrg] = nSrc;
    }
    else
      if (vnSrc[nSrc] != nTrg || vnTrg[nTrg] != nSrc)
        return "No";
  }

  return "Yes";
}
  
int main()
{
  string sSrc, sTrg;
  
  fnInput(sSrc, sTrg);
  cout << fnConvChk(sSrc, sTrg) << endl;

  return 0;
}
