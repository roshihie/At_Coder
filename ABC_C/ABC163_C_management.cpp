#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnBoss)
{
  int nBossSiz;
  cin >> nBossSiz;
  rvnBoss.resize(nBossSiz - 1);

  for (int& rnBoss : rvnBoss)
    cin >> rnBoss;
}
  
void fnStaffGet(const vector<int>& cnrvnBoss)
{
  vector<int> vnStaff(cnrvnBoss.size() + 1);

  for (int nBoss : cnrvnBoss)
    vnStaff[ nBoss - 1 ]++;

  for (int nStaff : vnStaff)
    cout << nStaff << endl;
}
  
int main()
{
  vector<int> vnBoss;

  fnInput(vnBoss);
  fnStaffGet(vnBoss);

  return 0;
}
