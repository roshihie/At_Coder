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

int calcMaxOpeCnt(const vector<int>& cnrvnSeq)
{
  int nMaxOpeCnt = 0;

  for (int nSeq : cnrvnSeq)
  {
    while (nSeq % 2 == 0)
    {
      ++nMaxOpeCnt;
      nSeq /= 2;
    }
  }
  return nMaxOpeCnt;
}

int main()
{
  vector<int> vnSeq;
  
  input(vnSeq);
  cout << calcMaxOpeCnt(vnSeq) << endl;

  return 0;
}
