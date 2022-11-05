#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvSeq, int& rSumElem)
{
  int sizSeq;
  cin >> sizSeq;
  rvSeq.resize(sizSeq);

  rSumElem = 0;

  for (int& rSeq : rvSeq)
  {
    cin >> rSeq;
    rSumElem += rSeq;
  }
}
  
llong calcSumSqreElemDiff(const vector<int>& crvSeq, int sumElem)
{
  llong sumSqreElemDiff = 0;

  for (int seq : crvSeq)
  {
    sumSqreElemDiff += (llong)seq * seq * (crvSeq.size() - 1);
    sumSqreElemDiff -= (llong)seq * (sumElem - seq);
  }
  return sumSqreElemDiff;
}

int main()
{
  vector<int> vSeq;
  int sumElem;

  input(vSeq, sumElem);
  cout << calcSumSqreElemDiff(vSeq, sumElem) << endl;

  return 0;
}
