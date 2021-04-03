#include <bits/stdc++.h>
using namespace std;

void input(int& rnSwitchSiz, 
           vector<vector<int>>& rvvnLightSwt, vector<int>& rvnReslt)
{
  int  nLightSiz;
  cin >> rnSwitchSiz >> nLightSiz;
  rvvnLightSwt.resize(nLightSiz);

  for (int nx = 0; nx < rvvnLightSwt.size(); ++nx)
  {
    int nLightSwtSiz;
    cin >> nLightSwtSiz;
    rvvnLightSwt[nx].resize(nLightSwtSiz);

    for (int ny = 0; ny < rvvnLightSwt[nx].size(); ++ny)
      cin >> rvvnLightSwt[nx][ny];
  }

  rvnReslt.resize(nLightSiz);
  for (int& rnReslt : rvnReslt)
    cin >> rnReslt;
}

bool canLightSwitch(const vector<vector<int>>& cnrvvnLightSwt,
                    const vector<int>& cnrvnSwitch,
                    const vector<int>& cnrvnReslt)
{
  for (int nx = 0; nx < cnrvvnLightSwt.size(); ++nx)
  {
    int nLightUpCnt = 0;

    for (int ny = 0; ny < cnrvvnLightSwt[nx].size(); ++ny)
      nLightUpCnt += cnrvnSwitch[ cnrvvnLightSwt[nx][ny] - 1 ];

    if (nLightUpCnt % 2 != cnrvnReslt[nx])
      return false;
  }
  return true;
}

int calcNumOfCases(int nSwitchSiz,
                   const vector<vector<int>>& cnrvvnLightSwt, 
                   const vector<int>& cnrvnReslt)
{
  int nNumOfCases = 0;
  vector<int> vnSwitch(nSwitchSiz);

  for (int nBit = 0; nBit < ( 1 << nSwitchSiz ); ++nBit)
  {
    for (int nEach = 0; nEach < nSwitchSiz; ++nEach)
      if (nBit & ( 1 << nEach ))
        vnSwitch[nEach] = 1;
      else
        vnSwitch[nEach] = 0;

    if (canLightSwitch(cnrvvnLightSwt, vnSwitch, cnrvnReslt))
      ++nNumOfCases;
  }
  return nNumOfCases;
}
  
int main()
{
  int nSwitchSiz;
  vector<vector<int>> vvnLightSwt;
  vector<int> vnReslt;

  input(nSwitchSiz, vvnLightSwt, vnReslt);
  cout << calcNumOfCases(nSwitchSiz, vvnLightSwt, vnReslt) << endl;

  return 0;
}
