#include <bits/stdc++.h>
using namespace std;

struct StRect
{
  StRect() : m_High(0), m_Pos(0) { }

  int m_High;
  int m_Pos;
};

void input(vector<int>& rvSeq)
{
  int sizSeq;
  cin >> sizSeq;
  rvSeq.resize(sizSeq);

  for (int& rseq : rvSeq)
    cin >> rseq;

  rvSeq.push_back( 0 );
}

int calcMaxRect(const vector<int>& crvSeq)
{
  int maxRect = 0;
  stack<StRect> stArea;

  for (int nx = 0; nx < (int)crvSeq.size(); ++nx)
  {
    StRect oRect;
    oRect.m_High = crvSeq[nx];
    oRect.m_Pos  = nx;

    if ( stArea.empty() )
      stArea.push( oRect );
    else if ( stArea.top().m_High < oRect.m_High )
      stArea.push( oRect );
    else if ( stArea.top().m_High > oRect.m_High )
    {
      int trgPos = nx;

      while ( stArea.size()  &&
              stArea.top().m_High >= oRect.m_High )
      {
        StRect oPreRect = stArea.top(); stArea.pop();
        int square = oPreRect.m_High * ( nx - oPreRect.m_Pos );
        maxRect = max( maxRect, square );
        trgPos = oPreRect.m_Pos;
      }
      oRect.m_Pos = trgPos;
      stArea.push( oRect );
    }
  }
  return maxRect;
}
  
int main()
{
  vector<int> vSeq;

  input(vSeq);
  cout << calcMaxRect(vSeq) << endl;

  return 0;
}
