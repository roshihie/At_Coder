#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeq.resize(nSeqSiz);

  for (int& rnSeq : rvnSeq)
    cin >> rnSeq;
}
  
llong calcSumSqreElmDiff(const vector<int>& cnrvnSeq)
{
  llong nSumSqreElmDiff = 0;
  llong nSumSquares = 0;
  llong nSumElement = 0;

  for (int nSeq : cnrvnSeq)
  {
    nSumElement += nSeq;
    nSumSquares += nSeq * nSeq;
  }
  nSumSqreElmDiff += nSumSquares * (cnrvnSeq.size() - 1);

  for (int nSeq : cnrvnSeq)
  {
    nSumElement -= nSeq;
    nSumSqreElmDiff -= 2 * nSumElement * nSeq; 
  }
  return nSumSqreElmDiff;
}

int main()
{
  vector<int> vnSeq;

  input(vnSeq);
  cout << calcSumSqreElmDiff(vnSeq) << endl;

  return 0;
}
