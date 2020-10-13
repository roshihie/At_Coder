#include <bits/stdc++.h>
using namespace std;

void input(int& rnLapDist, vector<int>& rvnOneDist)
{
  int nOneDistSiz;
  cin >> rnLapDist >> nOneDistSiz;
  rvnOneDist.resize(nOneDistSiz);

  for (int& nOneDist : rvnOneDist)
    cin >> nOneDist;
}
  
double calcMinMoveDist(int nLapDist, const vector<int>& cnrvnOneDist)
{
  int nMaxOneDist = 0;
  int nx = 0;

  while (nx < cnrvnOneDist.size() - 1)
  {
    nMaxOneDist = max(nMaxOneDist, cnrvnOneDist[nx + 1] - cnrvnOneDist[nx]);
    ++nx;
  }

  nMaxOneDist = max(nMaxOneDist, nLapDist - cnrvnOneDist[nx] + cnrvnOneDist[0]);
  return nLapDist - nMaxOneDist;
}
  
int main()
{
  int nLapDist;
  vector<int> vnOneDist;

  input(nLapDist, vnOneDist);
  cout <<  calcMinMoveDist(nLapDist, vnOneDist) << endl;

  return 0;
}
