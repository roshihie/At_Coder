#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnTrgSu, int& rnTrgKin)
{
  cin >> rnTrgSu >> rnTrgKin;
}

int fnRcsSch(int nPos, int nTrgSu, int nTrgKin, vector<int>& rvnNumMoney)
{
  vector<int> vnMoney{10000, 5000, 1000};

  if (nTrgKin < 0)  return -1;
  if (nPos == rvnNumMoney.size() - 1)
  {
    rvnNumMoney[nPos] = nTrgSu;
    if (nTrgKin - vnMoney[nPos] * nTrgSu == 0)
      return 1;
    else
      return 0;
  }

  for (int i = 0; i <= nTrgSu; i++)
  {
    rvnNumMoney[nPos] = i;
    int nRtn = fnRcsSch(nPos + 1, nTrgSu - i, nTrgKin - vnMoney[nPos] * i, rvnNumMoney);
    if      (nRtn == -1)  return 0;
    else if (nRtn)        return 1;
  }

  return 0;
}

int fnExhSch(int nTrgSu, int nTrgKin)
{
  vector<int> vnNumMoney(3);

  if (fnRcsSch(0, nTrgSu, nTrgKin, vnNumMoney))
    cout << vnNumMoney[0] << " " << vnNumMoney[1] << " " << vnNumMoney[2] << endl;
  else
    cout << -1 << " " << -1 << " " << -1 << endl;
}

int main()
{
  int nTrgSu, nTrgKin;
  
  fnInput(nTrgSu, nTrgKin);
  fnExhSch(nTrgSu, nTrgKin);

  return 0;
}
 
