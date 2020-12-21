#include <bits/stdc++.h>
using namespace std;

void input(map<string, int>& rmpPoll)
{
  int nPollSiz;
  cin >> nPollSiz;

  for (int nx = 0; nx < nPollSiz; ++nx)
  {
    string sPoll;
    cin >> sPoll;
    ++rmpPoll[sPoll];
  }
}
  
void calcMaxPoll(const map<string, int>& cnrmpPoll)
{
  int nMaxCnt = 0;

  for (auto PPoll : cnrmpPoll)
    nMaxCnt = max(nMaxCnt, PPoll.second);

  for (auto PPoll : cnrmpPoll)
    if (PPoll.second == nMaxCnt)
      cout << PPoll.first << endl;
}
  
int main()
{
  map<string, int> mpPoll;

  input(mpPoll);
  calcMaxPoll(mpPoll);

  return 0;
}
