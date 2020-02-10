#include <bits/stdc++.h>
using namespace std;

void fnInput(vector<int>& rvnSeqP, vector<int>& rvnSeqQ)
{
  int nSeqSiz;
  cin >> nSeqSiz;
  rvnSeqP.resize(nSeqSiz);
  rvnSeqQ.resize(nSeqSiz);

  for (int& rnSeqP : rvnSeqP)
    cin >> rnSeqP;
  for (int& rnSeqQ : rvnSeqQ)
    cin >> rnSeqQ;
}
  
int fnCountOrderGet(const vector<int>& cnrvnSeqP, const vector<int>& cnrvnSeqQ)
{
  vector<int> vnSeqX(cnrvnSeqP.size());
  int nCntP, nCntQ, nCntX = 0;

  iota(begin(vnSeqX), end(vnSeqX), 1);
  do {
    nCntX++;
    if (cnrvnSeqP == vnSeqX) nCntP = nCntX;
    if (cnrvnSeqQ == vnSeqX) nCntQ = nCntX;
  }
  while ( next_permutation(begin(vnSeqX), end(vnSeqX)) );

  return abs(nCntP - nCntQ);
}
  
int main()
{
  vector<int> vnSeqP, vnSeqQ;

  fnInput(vnSeqP, vnSeqQ);
  cout << fnCountOrderGet(vnSeqP, vnSeqQ) << endl;

  return 0;
}
