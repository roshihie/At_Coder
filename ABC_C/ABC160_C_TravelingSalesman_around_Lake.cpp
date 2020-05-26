#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnLapDist, vector<int>& rvnOnePos)
{
  int nOneDistSiz;
  cin >> rnLapDist >> nOneDistSiz;
  rvnOnePos.resize(nOneDistSiz);

  for (int& nOneDist : rvnOnePos)
    cin >> nOneDist;
}
  
double fnMinMoveDist(int nLapDist, const vector<int>& cnrvnOnePos)
{
  int nMaxOneDist = 0;

  int i;
  for (i = 0; i < cnrvnOnePos.size() - 1; i++)
    nMaxOneDist = max(nMaxOneDist, abs(cnrvnOnePos[i + 1] - cnrvnOnePos[i]));

  nMaxOneDist = max(nMaxOneDist, abs(nLapDist -cnrvnOnePos[i]) + cnrvnOnePos[0]);
  return nLapDist - nMaxOneDist;
}
  
int main()
{
  int nLapDist;
  vector<int> vnOnePos;

  fnInput(nLapDist, vnOnePos);
  cout <<  fnMinMoveDist(nLapDist, vnOnePos) << endl;

  return 0;
}
