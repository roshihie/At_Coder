#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnNumOfStaff)
{
  int nNumOfStaffSiz;
  cin >> nNumOfStaffSiz;
  rvnNumOfStaff.resize(nNumOfStaffSiz);

  for (int nx = 0; nx < rvnNumOfStaff.size() - 1; ++nx)
  {
    int nBoss;
    cin >> nBoss;
    ++rvnNumOfStaff[ --nBoss ];
  }
}
  
void calcNumOfStaff(const vector<int>& cnrvnNumOfStaff)
{
  for (int nNumOfStaff : cnrvnNumOfStaff)
    cout << nNumOfStaff << endl;
}
  
int main()
{
  vector<int> vnNumOfStaff;

  input(vnNumOfStaff);
  calcNumOfStaff(vnNumOfStaff);

  return 0;
}
