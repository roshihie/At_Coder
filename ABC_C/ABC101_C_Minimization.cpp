#include <bits/stdc++.h>
using namespace std;

void input(int& rnSelSiz, vector<int>& rvnSeq)
{
  int nSeqSiz;
  cin >> nSeqSiz >> rnSelSiz;
  rvnSeq.resize(nSeqSiz);

  for (int& rnSeq : rvnSeq)
    cin >> rnSeq;
}

int calcToMinElmCnt(int nSelSiz, const vector<int>& cnrvnSeq)
{
  int nToMinElmCnt = 1;
  nToMinElmCnt += ( (cnrvnSeq.size() - nSelSiz) + (nSelSiz - 2) ) / (nSelSiz - 1);

  return nToMinElmCnt;
}

int main()
{
  int nSelSiz;
  vector<int> vnSeq;
  
  input(nSelSiz, vnSeq);
  cout << calcToMinElmCnt(nSelSiz, vnSeq) << endl;

  return 0;
}
