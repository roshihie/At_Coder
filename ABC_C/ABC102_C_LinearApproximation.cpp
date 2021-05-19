#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvnDiff)
{
  int nNumSiz;
  cin >> nNumSiz;
  rvnDiff.resize(nNumSiz);

  for (int nx = 0; nx < rvnDiff.size(); ++nx)
  {
    int nNum;
    cin >> nNum; 
    rvnDiff[nx] = nNum - (nx + 1);
  }
  sort(begin(rvnDiff), end(rvnDiff));
}

llong calcMinDiffSum(const vector<int>& cnrvnDiff)
{
  int nMidNum;
  int nMidx = cnrvnDiff.size() / 2;

  if ( cnrvnDiff.size() % 2 )
    nMidNum = cnrvnDiff[nMidx];
  else
    nMidNum = (cnrvnDiff[nMidx - 1] + cnrvnDiff[nMidx]) / 2;
    
  llong nMinDiffSum = 0;

  for (int nDiff : cnrvnDiff)
    nMinDiffSum += abs(nDiff - nMidNum);

  return nMinDiffSum;
}

int main()
{
  vector<int> vnDiff;

  input(vnDiff);
  cout << calcMinDiffSum(vnDiff) << endl;

  return 0;
}
