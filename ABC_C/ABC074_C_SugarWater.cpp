#include <bits/stdc++.h>
using namespace std;

struct StCond                  // 材料質量・限界量
{
  int m_nWaterA;
  int m_nWaterB;
  int m_nSugerC;
  int m_nSugerD;
  int m_nConcE;
  int m_nLimitF;
};

struct StAmt                   // 使用量
{
  StAmt() : m_nAmtA(0), m_nAmtB(0), m_nAmtC(0), m_nAmtD(0) { }

  int m_nAmtA, m_nAmtB, m_nAmtC, m_nAmtD;
};

struct StRslt                  // 出力結果
{
  StRslt() : m_nAllMass(0), m_nSugerMass(0) { }

  int m_nAllMass, m_nSugerMass;
};

void fnInput(StCond& roCond)
{
  cin >> roCond.m_nWaterA >> roCond.m_nWaterB >> roCond.m_nSugerC >> roCond.m_nSugerD;
  cin >> roCond.m_nConcE  >> roCond.m_nLimitF;
}

void fnAmtClear(string sProc, const StCond& cnroCond, StAmt& roAmt)
{ 
  if      (sProc == "A")
    { roAmt.m_nAmtA = 0; roAmt.m_nAmtB = 0; roAmt.m_nAmtC = 0; roAmt.m_nAmtD = 0; }
  else if (sProc == "B")
    { roAmt.m_nAmtB = 0; roAmt.m_nAmtC = 0; roAmt.m_nAmtD = 0; }
  else if (sProc == "C")
    { roAmt.m_nAmtC = 0; roAmt.m_nAmtD = 0; }
  else if (sProc == "D")
    { roAmt.m_nAmtD = 0; }
}

int fnAmtSumup(string sProc, const StCond& cnroCond, const StAmt& cnroAmt)
{ 
  if (sProc == "ALL")
    return  (cnroCond.m_nWaterA * cnroAmt.m_nAmtA + cnroCond.m_nWaterB * cnroAmt.m_nAmtB) * 100
          + (cnroCond.m_nSugerC * cnroAmt.m_nAmtC + cnroCond.m_nSugerD * cnroAmt.m_nAmtD);
  else                       // sProc == "SUG"         
    return  (cnroCond.m_nSugerC * cnroAmt.m_nAmtC + cnroCond.m_nSugerD * cnroAmt.m_nAmtD);
}

double fnConcCalc(const StCond& cnroCond, const StAmt& cnroAmt)
{
  static double stnLimtConc = 0.0;

  if (!stnLimtConc)
    stnLimtConc = (double)cnroCond.m_nConcE / (100.0 + (double)cnroCond.m_nConcE);

  double nNowConc =  (double)fnAmtSumup("SUG", cnroCond, cnroAmt)
                   / (double)fnAmtSumup("ALL", cnroCond, cnroAmt);

  if (stnLimtConc < nNowConc)  return 0.0;
  else                         return nNowConc;
}

void fnConcCheck(const StCond& cnroCond, StRslt& roRslt)
{
  StAmt oAmt;
  double nMaxConc = -1.0;

  fnAmtClear("A", cnroCond, oAmt);
  while (true)
  {
    fnAmtClear("B", cnroCond, oAmt);
    if (fnAmtSumup("ALL", cnroCond, oAmt) > cnroCond.m_nLimitF)  break;

    if (!oAmt.m_nAmtA)  oAmt.m_nAmtB = 1;
    while (true)
    {
      fnAmtClear("C", cnroCond, oAmt);
      if (fnAmtSumup("ALL", cnroCond, oAmt) > cnroCond.m_nLimitF)  break;

      while (true)
      {
        fnAmtClear("D", cnroCond, oAmt);
        if (fnAmtSumup("ALL", cnroCond, oAmt) > cnroCond.m_nLimitF)  break;

        while (true)
        {
          if (fnAmtSumup("ALL", cnroCond, oAmt) > cnroCond.m_nLimitF)  break;

          double nNowConc = fnConcCalc(cnroCond, oAmt);
          if (nMaxConc < nNowConc)
          {
            nMaxConc = nNowConc;
            roRslt.m_nAllMass = fnAmtSumup("ALL", cnroCond, oAmt);
            roRslt.m_nSugerMass = fnAmtSumup("SUG", cnroCond, oAmt);
          }
          oAmt.m_nAmtD++;
        }
        oAmt.m_nAmtC++;
      }
      oAmt.m_nAmtB++;
    }
    oAmt.m_nAmtA++;
  }
}

int main()
{
  StCond oCond;
  StRslt oRslt;

  fnInput(oCond);
  fnConcCheck(oCond, oRslt);
  cout << oRslt.m_nAllMass << " " << oRslt.m_nSugerMass << endl;

  return 0;
}
