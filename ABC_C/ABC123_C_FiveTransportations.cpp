#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnMaxNum, vector<llong>& rvnCapcty)
{
  cin >> rnMaxNum;
  
  for (llong& rnCapcty : rvnCapcty)
    cin >> rnCapcty;
}

llong calcTransptCnt(llong nMaxNum, vector<llong>& rvnCapcty)
{
  for (int nx = 0; nx < rvnCapcty.size() - 1; ++nx)  // 交通機関の容量を直前の大きさに合わせる
    if (rvnCapcty[nx] < rvnCapcty[nx + 1])
      rvnCapcty[nx + 1] = rvnCapcty[nx];
  
  vector<llong> vnTime(6);                           // 各都市への移動時間

  for (int nx = 0; nx < vnTime.size() - 1; ++nx)     // 移動時間を計算
  {
    vnTime[nx + 1] = (nMaxNum + (rvnCapcty[nx] - 1)) / rvnCapcty[nx]; 
    vnTime[nx + 1] += nx;
  }
  llong nTotalTime = 0;

  for (int nx = 0; nx < vnTime.size() - 1; ++nx)     // トータル時間を計算
    nTotalTime += vnTime[nx + 1] - vnTime[nx];       // 各都市間へ同時に移動しているため
                                                     // 移動時間の差分を加算
  return nTotalTime;
}
 
int main()
{
  llong nMaxNum;
  vector<llong> vnCapcty(5);

  input(nMaxNum, vnCapcty);
  cout << calcTransptCnt(nMaxNum, vnCapcty) << endl;

  return 0;
}
