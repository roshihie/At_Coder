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
  vector<int> vnRevSeq(cnrvnSeq);
  reverse(begin(vnRevSeq), end(vnRevSeq));

  int nMaxSeqCnt = 0;
  int nFoward = 0;
  while (nFoward < vnRevSeq.size())
  {
    int nSeqCnt = 0;

    for (int n = nFoward; n < vnRevSeq.size(); n++)
      if (vnRevSeq[n] <= vnRevSeq[n + 1])
        nSeqCnt++;
      else
      {
        nFoward = n + 1;
        break;
      }

    nMaxSeqCnt = max(nMaxSeqCnt, nSeqCnt);
  }
  return nMaxSeqCnt;
}
  
int main()
{
  vector<int> vnSeq;

  fnInput(vnSeq);
  cout << fnLowerCnt(vnSeq) << endl;

  return 0;
}
