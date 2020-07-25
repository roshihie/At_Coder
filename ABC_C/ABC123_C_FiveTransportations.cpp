#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(llong& rnMaxNum, vector<llong>& rvnCapcty)
{
  cin >> rnMaxNum;
  
  for (llong& rnCapcty : rvnCapcty)
    cin >> rnCapcty;
}

llong fnTransptCnt(llong nMaxNum, vector<llong>& rvnCapcty)
{
  for (int i = 0; i < rvnCapcty.size() - 1; i++)   // 交通機関の容量を直前の大きさに合わせる
    if (rvnCapcty[i] < rvnCapcty[i + 1])
      rvnCapcty[i + 1] = rvnCapcty[i];
  
  vector<llong> vnTime(6);                         // 各都市への移動時間

  for (int i = 0; i < vnTime.size() - 1; i++)      // 移動時間を計算
  {
    vnTime[i + 1] = (nMaxNum + (rvnCapcty[i] - 1)) / rvnCapcty[i]; 
    vnTime[i + 1] += i;
  }
  llong nTotalTime = 0;

  for (int i = 0; i < vnTime.size() - 1; i++)      // トータル時間を計算
    nTotalTime += vnTime[i + 1] - vnTime[i];       // 各都市間へ同時に移動しているため
                                                   // 移動時間の差分を加算
  return nTotalTime;
}
 
int main()
{
  llong nMaxNum;
  vector<llong> vnCapcty(5);

  fnInput(nMaxNum, vnCapcty);
  cout << fnTransptCnt(nMaxNum, vnCapcty) << endl;

  return 0;
}
