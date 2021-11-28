#include <bits/stdc++.h>
using namespace std;

void input(int& rnSwitchSiz, 
           vector<vector<int>>& rvvnLightSwt, vector<int>& rvnRslt)
{
  int nLightSiz;
  cin >> rnSwitchSiz >> nLightSiz;
  rvvnLightSwt.resize(nLightSiz);

  for (auto& rvnLightSwt : rvvnLightSwt)
  {
    int nLightSwtSiz;
    cin >> nLightSwtSiz;
    rvnLightSwt.resize(nLightSwtSiz);

    for (int& rnLightSwt : rvnLightSwt)
      cin >> rnLightSwt;
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
    int nCanLightOn = 0;

    for (const int& cnrnLightSwt : cnrvvnLightSwt[ny])
      nCanLightOn += cnrvnSwitch[ cnrnLightSwt - 1 ];

    if (nCanLightOn % 2 != cnrvnRslt[ny])
      return false;
  }
  return true;
}

int cntLightOn(int nSwitchSiz,
               const vector<vector<int>>& cnrvvnLightSwt, 
               const vector<int>& cnrvnRslt)
{
  int nCntLightOn = 0;
  vector<int> vnSwitch(nSwitchSiz);

  for (int nBit = 0; nBit < ( 1 << nSwitchSiz ); ++nBit)
  {
    for (int nEach = 0; nEach < nSwitchSiz; ++nEach)
      if (nBit & ( 1 << nEach ))
        vnSwitch[nEach] = 1;
      else
        vnSwitch[nEach] = 0;

    if ( canLinghtOn(cnrvvnLightSwt, vnSwitch, cnrvnRslt) )
      ++nCntLightOn;
  }
  return nCntLightOn;
}
  
int main()
{
  int nSwitchSiz;
  vector<vector<int>> vvnLightSwt;
  vector<int> vnRslt;

  input(nSwitchSiz, vvnLightSwt, vnRslt);
  cout << cntLightOn(nSwitchSiz, vvnLightSwt, vnRslt) << endl;

  return 0;
}
