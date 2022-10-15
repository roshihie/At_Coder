#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvSeq, int& rSumAllElem)
{
  int sizSeq;
  cin >> sizSeq;
  rvSeq.resize(sizSeq);

  rSumAllElem = 0;

  for (int& rSeq : rvSeq)
  {
    cin >> rSeq;
    rSumAllElem += rSeq;
  }
}
  
llong calcSumSqreElemDiff(const vector<int>& crvSeq, int sumAllElem)
{
  llong sumSqreElemDiff = 0;

  for (int seq : crvSeq)
  {
    sumSqreElemDiff += (llong)seq * seq * (crvSeq.size() - 1);
    sumSqreElemDiff -= (llong)seq * (sumAllElem - seq);
  }

  return sumSqreElemDiff;
}

int main()
{
  vector<int> vSeq;
  int sumAllElem;

  input(vSeq, sumAllElem);
  cout << calcSumSqreElemDiff(vSeq, sumAllElem) << endl;

  return 0;
}
