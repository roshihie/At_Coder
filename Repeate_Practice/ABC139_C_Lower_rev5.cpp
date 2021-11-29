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
  int nMaxMoveCnt = 0;
  int nFwd = 0;

  while (nFwd < cnrvnSeq.size() )
  {
    int nMoveCnt = 0;

    while ( nFwd < cnrvnSeq.size() - 1  &&
            cnrvnSeq[nFwd] >= cnrvnSeq[nFwd + 1] )
    {
      ++nMoveCnt;
      ++nFwd;
    }
    nMaxMoveCnt = max(nMaxMoveCnt, nMoveCnt);
    ++nFwd;
  }
  return nMaxMoveCnt;
}
  
int main()
{
  vector<int> vnSeq;

  input(vnSeq);
  cout << calcLower(vnSeq) << endl;

  return 0;
}
