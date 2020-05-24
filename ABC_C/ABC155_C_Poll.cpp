#include <bits/stdc++.h>
using namespace std;

void fnInput(map<string, int>& rmpPoll)
{
  int nPollSiz;
  cin >> nPollSiz;

  for (int i = 0; i <= nPollSiz; i++)
  {
    string sPoll;
    cin >> sPoll;
    rmpPoll[sPoll]++;
  }
}
  
void fnMaxPollCnt(const map<string, int>& cnrmpPoll)
{
  int nMaxCnt = 0;

  for (pair<string, int> PPoll : cnrmpPoll)
    nMaxCnt = max(nMaxCnt, PPoll.second);

  for (pair<string, int> PPoll : cnrmpPoll)
  {
    if (PPoll.second == nMaxCnt)
      cout << PPoll.first << endl;
  }
}
  
int main()
{
  map<string, int> mpPoll;

  fnInput(mpPoll);
  fnMaxPollCnt(mpPoll);

  return 0;
}
