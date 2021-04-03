#include <bits/stdc++.h>
using namespace std;

void input(int& rnSwitchSiz, 
           vector<vector<int>>& rvvnLightSwt, vector<int>& rvnRslt)
{
  int nLightSiz;
  cin >> rnSwitchSiz >> nLightSiz;
  rvvnLightSwt.resize(nLightSiz);

  for (int ny = 0; ny < rvvnLightSwt.size(); ++ny)
  {
    int nLightSwtSiz;
    cin >> nLightSwtSiz;
    rvvnLightSwt[ny].resize(nLightSwtSiz);

    for (int nx = 0; nx < rvvnLightSwt[ny].size(); ++nx)
      cin >> rvvnLightSwt[ny][nx];
  }

  rvnRslt.resize(nLightSiz);
  for (int& rnRslt : rvnRslt)
    cin >> rnRslt;
}

bool canLinghtOn(const vector<vector<int>>& cnrvvnLightSwt,
                 const vector<int>& cnrvnSwitch,
                 const vector<int>& cnrvnRslt)
{
  for (int ny = 0; ny < cnrvvnLightSwt.size(); ++ny)
  {
    int nLightOnCnt = 0;

    for (int nx = 0; nx < cnrvvnLightSwt[ny].size(); ++nx)
      nLightOnCnt += cnrvnSwitch[ cnrvvnLightSwt[ny][nx] - 1 ];

    if (nLightOnCnt % 2 != cnrvnRslt[ny])
      return false;
  }
  return true;
}

int calcNumOfLightOn(int nSwitchSiz,
                     const vector<vector<int>>& cnrvvnLightSwt, 
                     const vector<int>& cnrvnRslt)
{
  int nNumOfLightOn = 0;
  vector<int> vnSwitch(nSwitchSiz);

  for (int nBit = 0; nBit < ( 1 << nSwitchSiz ); ++nBit)
  {
    for (int nEach = 0; nEach < nSwitchSiz; ++nEach)
      if (nBit & ( 1 << nEach ))
        vnSwitch[nEach] = 1;
      else
        vnSwitch[nEach] = 0;

    if (canLinghtOn(cnrvvnLightSwt, vnSwitch, cnrvnRslt))
      ++nNumOfLightOn;
  }
  return nNumOfLightOn;
}
  
int main()
{
  int nSwitchSiz;
  vector<vector<int>> vvnLightSwt;
  vector<int> vnRslt;

  input(nSwitchSiz, vvnLightSwt, vnRslt);
  cout << calcNumOfLightOn(nSwitchSiz, vvnLightSwt, vnRslt) << endl;

  return 0;
}
