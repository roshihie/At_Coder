#include <bits/stdc++.h>
using namespace std;

void input(vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeq.resize(nSeqSiz);

  for (int& rnSeq : rvnSeq)
    cin >> rnSeq;
}
  
int calcLowElement(const vector<int>& cnrvnSeq)
{
  int nLowElementCnt = 0;
  int nMinLowNum = cnrvnSeq[0] + 1;

  for (int nx = 0; nx < cnrvnSeq.size(); ++nx)
    if (cnrvnSeq[nx] < nMinLowNum)
    {
      ++nLowElementCnt;
      nMinLowNum = cnrvnSeq[nx];
    }

  return nLowElementCnt;
}
  
int main()
{
  vector<int> vnSeq;

  input(vnSeq);
  cout << calcLowElement(vnSeq) << endl;

  return 0;
}
