#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnSwitchSiz, 
             vector<vector<int>>& rvvnLightSw, vector<int>& rvnReslt)
{
  int  nLightSiz;
  cin >> rnSwitchSiz >> nLightSiz;
  rvvnLightSw.resize(nLightSiz);

  for (int i = 0; i < rvvnLightSw.size(); i++)
  {
    int nLightSwSiz;
    cin >> nLightSwSiz;
    rvvnLightSw[i].resize(nLightSwSiz);

    for (int j = 0; j < rvvnLightSw[i].size(); j++)
      cin >> rvvnLightSw[i][j];
  }

  rvnReslt.resize(nLightSiz);
  for (int& rnReslt : rvnReslt)
    cin >> rnReslt;
}

bool fnLightSwChk(const vector<vector<int>>& cnrvvnLightSw,
                  const vector<int>& cnrvnSwitch,
                  const vector<int>& cnrvnReslt)
{
  for (int i = 0; i < cnrvvnLightSw.size(); i++)
  {
    int nLightUpCnt = 0;

    for (int j = 0; j < cnrvvnLightSw[i].size(); j++)
      nLightUpCnt += cnrvnSwitch[ cnrvvnLightSw[i][j] - 1 ];

    if (nLightUpCnt % 2 != cnrvnReslt[i])
      return false;
  }
  return true;
}

int fnNumOfCase(int nSwitchSiz,
                const vector<vector<int>>& cnrvvnLightSw, 
                const vector<int>& cnrvnReslt)
{
  int nNumOfCase = 0;
  vector<int> vnSwitch(nSwitchSiz);

  for (int n = 0; n < ( 1 << nSwitchSiz ); n++)
  {
    for (int i = 0; i < nSwitchSiz; i++)
      if (n & ( 1 << i ))
        vnSwitch[i] = 1;
      else
        vnSwitch[i] = 0;

    if (fnLightSwChk(cnrvvnLightSw, vnSwitch, cnrvnReslt))
      nNumOfCase++;
  }
  return nNumOfCase;
}
  
int main()
{
  int nSwitchSiz;
  vector<vector<int>> vvnLightSw;
  vector<int> vnReslt;

  fnInput(nSwitchSiz, vvnLightSw, vnReslt);
  cout << fnNumOfCase(nSwitchSiz, vvnLightSw, vnReslt) << endl;

  return 0;
}
