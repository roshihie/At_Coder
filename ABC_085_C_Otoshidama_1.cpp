#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnTrgSu, int& rnTrgKin)
{
  cin >> rnTrgSu >> rnTrgKin;
}

int fnRcsSch(int nTrgSu, int nTrgKin)
{
  vector<int> vnMoney{10000, 5000, 1000};

  int nCalKin;
  int i, j;
  for (i = 0; i <= nTrgSu; i++)
  {
    for (j = 0; j <= (nTrgSu - i); j++)
    {
      nCalKin = nTrgKin;

      nCalKin -= vnMoney[0] * i;
      nCalKin -= vnMoney[1] * j;
      nCalKin -= vnMoney[2] * (nTrgSu - i - j);
      if (!nCalKin)
        break;
    }
    if (!nCalKin)
      break;
  }
  if (!nCalKin)
    cout << i << " " << j << " " << (nTrgSu - i - j) << endl;
  else
    cout << -1 << " " << -1 << " " << -1 << endl;
}

/*
int fnExhSch(int nTrgSu, int nTrgKin)
{
  vector<int> vnNumMoney(3);

  fnRcsSch(0, nTrgSu, nTrgKin, vnNumMoney);
  cout << vnNumMoney[0] << " " << vnNumMoney[1] << " " << vnNumMoney[2] << endl;
}
*/

int main()
{
  int nTrgSu, nTrgKin;
  
  fnInput(nTrgSu, nTrgKin);
  fnRcsSch(nTrgSu, nTrgKin);

  return 0;
}
 
