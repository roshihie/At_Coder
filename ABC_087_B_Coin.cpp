#include <bits/stdc++.h>
using namespace std;

struct StCoin
{
  StCoin() :
    m_nCoin(0), m_nNum(0)
  { }
  StCoin(int nCoin, int nNum) :
    m_nCoin(nCoin), m_nNum(nNum)
  { }

  int m_nCoin;
  int m_nNum;
};

void fnInput(vector<StCoin>& rvoCoin, int& rnTrgKin)
{
  int nNum500, nNum100, nNum50;
  cin >> nNum500 >> nNum100 >> nNum50;

  int i = 0;
  StCoin oCoin500(500, nNum500);
  rvoCoin[i++] = oCoin500;
  StCoin oCoin100(100, nNum100);
  rvoCoin[i++] = oCoin100;
  StCoin oCoin50(50, nNum50);
  rvoCoin[i] = oCoin50;

  cin >> rnTrgKin;
}

int fnRcsSch(int nPos, int nTrgKin, const vector<StCoin>& cnrvoCoin, int& rnSuccess)
{
  if (!nTrgKin)
  {
    rnSuccess++;
    return 1;
  }
  if (nTrgKin < 0)              return 1;
  if (nPos == cnrvoCoin.size()) return 0;

  for (int i = 0; i <= cnrvoCoin[nPos].m_nNum; i++)
    if (fnRcsSch(nPos + 1, nTrgKin - cnrvoCoin[nPos].m_nCoin * i, cnrvoCoin, rnSuccess))
      break;

  return 0;
}

void fnExhSch(int nTrgKin, const vector<StCoin>& cnrvoCoin)
{
  int nSuccess = 0;
  fnRcsSch(0, nTrgKin, cnrvoCoin, nSuccess);
  cout << nSuccess << endl;
}

int main()
{
  vector<StCoin> voCoin(3);
  int nTrgKin;

  fnInput(voCoin, nTrgKin);
  fnExhSch(nTrgKin, voCoin);

  return 0;
}
 
