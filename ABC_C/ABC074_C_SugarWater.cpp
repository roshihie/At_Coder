#include <bits/stdc++.h>
using namespace std;

struct StCond                  // 材料質量・限界量
{
  StCond() : m_nWaterA(0), m_nWaterB(0),
             m_nSugerC(0), m_nSugerD(0),
             m_nConcE(0),  m_nLimitF(0) { }

  int m_nWaterA, m_nWaterB;
  int m_nSugerC, m_nSugerD;
  int m_nConcE;
  int m_nLimitF;
};

struct StAmt                   // 使用量
{
  StAmt() : m_nAmtA(0), m_nAmtB(0), m_nAmtC(0), m_nAmtD(0) { }

  int m_nAmtA, m_nAmtB, m_nAmtC, m_nAmtD;
};

struct StReslt                  // 出力結果
{
  StReslt() : m_nAllMass(0), m_nSugerMass(0) { }

  int m_nAllMass, m_nSugerMass;
};

void input(StCond& roCond)
{
  cin >> roCond.m_nWaterA >> roCond.m_nWaterB >> roCond.m_nSugerC >> roCond.m_nSugerD;
  cin >> roCond.m_nConcE  >> roCond.m_nLimitF;
}

int accumulateAmt(string sProc, const StCond& cnroCond, const StAmt& cnroAmt)
{ 
  if      (sProc == "A")
    return  (cnroCond.m_nWaterA * cnroAmt.m_nAmtA) * 100;
  if      (sProc == "A+B")
    return  (cnroCond.m_nWaterA * cnroAmt.m_nAmtA + cnroCond.m_nWaterB * cnroAmt.m_nAmtB) * 100;
  else if (sProc == "A+B+C")
    return  (cnroCond.m_nWaterA * cnroAmt.m_nAmtA + cnroCond.m_nWaterB * cnroAmt.m_nAmtB) * 100 
          + (cnroCond.m_nSugerC * cnroAmt.m_nAmtC);
  else if (sProc == "A+B+C+D")
    return  (cnroCond.m_nWaterA * cnroAmt.m_nAmtA + cnroCond.m_nWaterB * cnroAmt.m_nAmtB) * 100 
          + (cnroCond.m_nSugerC * cnroAmt.m_nAmtC + cnroCond.m_nSugerD * cnroAmt.m_nAmtD);
  else           // "C+D" 
    return  (cnroCond.m_nSugerC * cnroAmt.m_nAmtC + cnroCond.m_nSugerD * cnroAmt.m_nAmtD);
}

double calcConc(const StCond& cnroCond, const StAmt& cnroAmt)
{
  static double stnLimtConc = 0.0;
  double nNowConc = 0.0;

  if (!stnLimtConc)
    stnLimtConc = cnroCond.m_nConcE / (100.0 + cnroCond.m_nConcE);

  if ( accumulateAmt("A+B+C+D", cnroCond, cnroAmt) )
  {
    nNowConc =  (double)accumulateAmt("C+D", cnroCond, cnroAmt)
               /        accumulateAmt("A+B+C+D", cnroCond, cnroAmt);
    if (stnLimtConc < nNowConc)
      return -1.0;
    else
      return nNowConc;
  }
  else
    return -1.0;
}

void totalSearchConc(const StCond& cnroCond, StReslt& roReslt)
{
  StAmt oAmt;
  double nMaxConc = -1.0;
  
  for ( oAmt.m_nAmtA = 0; 
        accumulateAmt("A", cnroCond, oAmt) <= cnroCond.m_nLimitF; oAmt.m_nAmtA++ )
  {
    for ( oAmt.m_nAmtB = 0; 
          accumulateAmt("A+B", cnroCond, oAmt) <= cnroCond.m_nLimitF; oAmt.m_nAmtB++ )
    {
      for ( oAmt.m_nAmtC = 0; 
            accumulateAmt("A+B+C", cnroCond, oAmt) <= cnroCond.m_nLimitF; oAmt.m_nAmtC++ )
      {
        for ( oAmt.m_nAmtD = 0;
              accumulateAmt("A+B+C+D", cnroCond, oAmt) <= cnroCond.m_nLimitF; oAmt.m_nAmtD++ )
        {
          double nNowConc = calcConc(cnroCond, oAmt);
          if (nMaxConc < nNowConc)
          {
            nMaxConc = nNowConc;
            roReslt.m_nAllMass = accumulateAmt("A+B+C+D", cnroCond, oAmt);
            roReslt.m_nSugerMass = accumulateAmt("C+D", cnroCond, oAmt);
          }
        }
      }
    }
  }
}

int main()
{
  StCond oCond;
  StReslt oReslt;

  input(oCond);
  totalSearchConc(oCond, oReslt);
  cout << oReslt.m_nAllMass << " " << oReslt.m_nSugerMass << endl;

  return 0;
}
