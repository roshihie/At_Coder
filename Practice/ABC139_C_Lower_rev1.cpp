#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeq.resize(nSeqSiz);

  for (int& rnSeq : rvnSeq)
    cin >> rnSeq;
}
  
int fnLowerCnt(const vector<int>& cnrvnSeq)
{
  int nMaxLowerCnt = 0;
  int nBgn = 0;

  while (nBgn < cnrvnSeq.size() - 1)
  {
    int nLowerCnt = 0;
    int nFoward;

    for (nFoward = nBgn; nFoward < cnrvnSeq.size() - 1; nFoward++)
       if (cnrvnSeq[nFoward] >= cnrvnSeq[nFoward + 1])
          nLowerCnt++;
       else
          break;

    nMaxLowerCnt = max(nMaxLowerCnt, nLowerCnt);
    nBgn = nFoward + 1;
  }
  return nMaxLowerCnt;
}
  
int main()
{
  vector<int> vnSeq;

  fnInput(vnSeq);
  cout << fnLowerCnt(vnSeq) << endl;

  return 0;
}
