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
  
int calcLower(const vector<int>& cnrvnSeq)
{
  int nMaxSeqCnt = 0;
  int nFwd = 0;

  while (nFwd < cnrvnSeq.size() )
  {
    int nSeqCnt = 0;

    while ( nFwd < cnrvnSeq.size() - 1   &&
            cnrvnSeq[nFwd] >= cnrvnSeq[nFwd + 1] )
    {
      ++nSeqCnt;
      ++nFwd;
    }
    nMaxSeqCnt = max(nMaxSeqCnt, nSeqCnt);
    ++nFwd;
  }
  return nMaxSeqCnt;
}
  
int main()
{
  vector<int> vnSeq;

  input(vnSeq);
  cout << calcLower(vnSeq) << endl;

  return 0;
}
