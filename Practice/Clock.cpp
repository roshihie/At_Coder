#include <bits/stdc++.h>
using namespace std;
 
// 24時間表記の時計構造体 Clock を定義する
struct StClock
{
  int m_nHour;
  int m_nMinute;
  int m_nSecond;

  StClock(int nHour, int nMinute, int nSecond) :
    m_nHour(nHour), m_nMinute(nMinute), m_nSecond(nSecond)
  { }

  string to_str()
  {
    stringstream ss;
    ss << setw(2) << setfill('0') << m_nHour << ":";
    ss << setw(2) << setfill('0') << m_nMinute << ":";
    ss << setw(2) << setfill('0') << m_nSecond;

    return ss.str();
  }

  void shift(int nDiffSecond)
  {
    int nToSecond = 60 * 60 * m_nHour + 60 * m_nMinute + m_nSecond + nDiffSecond;

    if (nToSecond < 0)
      nToSecond += 86400;              // 60 * 60 * 24 

    m_nSecond = nToSecond % 60;

    int nToMinute = nToSecond / 60;
    m_nMinute = nToMinute % 60;

    m_nHour =  nToMinute / 60;
    if (m_nHour >= 24)                 // 0 <= m_nHour <= 23
      m_nHour -= 24;
  }
};
 
// -------------------
// ここから先は変更しない
// -------------------
 
int main()
{
  // 入力を受け取る
  int nHour, nMinute, nSecond;
  cin >> nHour >> nMinute >> nSecond;
  int nDiffSecond;
  cin >> nDiffSecond;
 
  // Clock構造体のオブジェクトを宣言
  StClock oClock(nHour, nMinute, nSecond);
 
  // 時刻を出力
  cout << oClock.to_str() << endl;
 
  // 時計を進める(戻す)
  oClock.shift(nDiffSecond);
 
  // 変更後の時刻を出力
  cout << oClock.to_str() << endl;
}
