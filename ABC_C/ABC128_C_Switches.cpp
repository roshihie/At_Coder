#include <bits/stdc++.h>
using namespace std;

void input(int& rnSwitchSiz, 
           vector<vector<int>>& rvvnLightSw, vector<int>& rvnReslt)
{
  int  nLightSiz;
  cin >> rnSwitchSiz >> nLightSiz;
  rvvnLightSw.resize(nLightSiz);

  for (int nx = 0; nx < rvvnLightSw.size(); ++nx)
  {
    int nLightSwSiz;
    cin >> nLightSwSiz;
    rvvnLightSw[nx].resize(nLightSwSiz);

    for (int ny = 0; ny < rvvnLightSw[nx].size(); ++ny)
      cin >> rvvnLightSw[nx][ny];
  }

  rvnReslt.resize(nLightSiz);
  for (int& rnReslt : rvnReslt)
    cin >> rnReslt;
}

bool canLightSwitch(const vector<vector<int>>& cnrvvnLightSw,
                    const vector<int>& cnrvnSwitch,
                    const vector<int>& cnrvnReslt)
{
  for (int nx = 0; nx < cnrvvnLightSw.size(); ++nx)
  {
    int nLightUpCnt = 0;

    for (int ny = 0; ny < cnrvvnLightSw[nx].size(); ++ny)
      nLightUpCnt += cnrvnSwitch[ cnrvvnLightSw[nx][ny] - 1 ];

    if (nLightUpCnt % 2 != cnrvnReslt[nx])
      return false;
  }
  return true;
}

int calcNumOfCases(int nSwitchSiz,
                   const vector<vector<int>>& cnrvvnLightSw, 
                   const vector<int>& cnrvnReslt)
{
  int nNumOfCases = 0;
  vector<int> vnSwitch(nSwitchSiz);

  for (int nCtl = 0; nCtl < ( 1 << nSwitchSiz ); ++nCtl)
  {
    for (int nEach = 0; nEach < nSwitchSiz; ++nEach)
      if (nCtl & ( 1 << nEach ))
        vnSwitch[nEach] = 1;
      else
        vnSwitch[nEach] = 0;

    if (canLightSwitch(cnrvvnLightSw, vnSwitch, cnrvnReslt))
      ++nNumOfCases;
  }
  return nNumOfCases;
}
  
int main()
{
  int nSwitchSiz;
  vector<vector<int>> vvnLightSw;
  vector<int> vnReslt;

  input(nSwitchSiz, vvnLightSw, vnReslt);
  cout << calcNumOfCases(nSwitchSiz, vvnLightSw, vnReslt) << endl;

  return 0;
}
