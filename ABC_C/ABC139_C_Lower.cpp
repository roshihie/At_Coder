#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeq.resize(nSeqSiz);

  for(int& rnSeq : rvnSeq)
    cin >> rnSeq;
}
  
int fnLowerCnt(const vector<int>& cnrvnSeq)
{
  int nLowElemCnt = 0;
  int nMinLowElem = cnrvnSeq[0] + 1;

  for (int i = 0; i < cnrvnSeq.size(); i++)
    if (cnrvnSeq[i] < nMinLowElem)
    {
      nLowElemCnt++;
      nMinLowElem = cnrvnSeq[i];
    }

  return nLowElemCnt;
}
  
int main()
{
  vector<int> vnSeq;

  fnInput(vnSeq);
  cout << fnLowerCnt(vnSeq) << endl;

  return 0;
}
