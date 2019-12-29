//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2018 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////
#ifndef AC_GEKVEC_H
#  define AC_GEKVEC_H
#  include "gegbl.h"
#  include "gedblar.h"
#  pragma  pack (push, 8)
class AcGeInterval;
class AcGeKnotVector
{
public:
  GE_DLLDATAEXIMP static double globalKnotTolerance;
  GE_DLLEXPIMPORT AcGeKnotVector(double eps = globalKnotTolerance);
  GE_DLLEXPIMPORT AcGeKnotVector(int size, int growSize, double eps = globalKnotTolerance);
  GE_DLLEXPIMPORT AcGeKnotVector(int size, const double[], double eps = globalKnotTolerance);
  GE_DLLEXPIMPORT AcGeKnotVector(int plusMult, const AcGeKnotVector& src);
  GE_DLLEXPIMPORT AcGeKnotVector(const AcGeKnotVector& src);
  GE_DLLEXPIMPORT AcGeKnotVector(const AcGeDoubleArray& src, double eps = globalKnotTolerance);
  GE_DLLEXPIMPORT ~AcGeKnotVector();
  GE_DLLEXPIMPORT AcGeKnotVector& operator =(const AcGeKnotVector& src);
  GE_DLLEXPIMPORT AcGeKnotVector& operator =(const AcGeDoubleArray& src);
  GE_DLLEXPIMPORT double& operator [](int);
  GE_DLLEXPIMPORT const double operator [](int) const;
  GE_DLLEXPIMPORT Adesk::Boolean isEqualTo(const AcGeKnotVector& other) const;
  GE_DLLEXPIMPORT double startParam() const;
  GE_DLLEXPIMPORT double endParam() const;
  GE_DLLEXPIMPORT int multiplicityAt(int i) const;
  GE_DLLEXPIMPORT int multiplicityAt(double param) const;
  GE_DLLEXPIMPORT int numIntervals() const;
  GE_DLLEXPIMPORT int getInterval(int ord, double par, AcGeInterval& interval) const;
  GE_DLLEXPIMPORT void getDistinctKnots(AcGeDoubleArray& knots) const;
  GE_DLLEXPIMPORT Adesk::Boolean contains(double param) const;
  GE_DLLEXPIMPORT Adesk::Boolean isOn(double knot) const;
  GE_DLLEXPIMPORT AcGeKnotVector& reverse();
  GE_DLLEXPIMPORT AcGeKnotVector& removeAt(int);
  GE_DLLEXPIMPORT AcGeKnotVector& removeSubVector(int startIndex, int endIndex);
  GE_DLLEXPIMPORT AcGeKnotVector& insertAt(int indx, double u, int multiplicity = 1);
  GE_DLLEXPIMPORT AcGeKnotVector& insert(double u);
  GE_DLLEXPIMPORT int append(double val);
  GE_DLLEXPIMPORT AcGeKnotVector& append(AcGeKnotVector& tail, double knotRatio = 0.);
  GE_DLLEXPIMPORT int split(double par, AcGeKnotVector* pKnot1, int multLast, AcGeKnotVector* pKnot2, int multFirst) const;
  GE_DLLEXPIMPORT AcGeKnotVector& setRange(double lower, double upper);
  GE_DLLEXPIMPORT double tolerance() const;
  GE_DLLEXPIMPORT AcGeKnotVector& setTolerance(double tol);
  GE_DLLEXPIMPORT int length() const;
  GE_DLLEXPIMPORT Adesk::Boolean isEmpty() const;
  GE_DLLEXPIMPORT int logicalLength() const;
  GE_DLLEXPIMPORT AcGeKnotVector& setLogicalLength(int);
  GE_DLLEXPIMPORT int physicalLength() const;
  GE_DLLEXPIMPORT AcGeKnotVector& setPhysicalLength(int);
  GE_DLLEXPIMPORT int growLength() const;
  GE_DLLEXPIMPORT AcGeKnotVector& setGrowLength(int);
  GE_DLLEXPIMPORT const double* asArrayPtr() const;
  GE_DLLEXPIMPORT double* asArrayPtr();
  GE_DLLEXPIMPORT AcGeKnotVector& set(int size, const double[], double eps = globalKnotTolerance);
protected:
  AcGeDoubleArray mData;
  double mTolerance;
  Adesk::Boolean isValid(int) const;
};
inline double AcGeKnotVector::tolerance() const
{
  return mTolerance;
}
inline AcGeKnotVector& AcGeKnotVector::setTolerance(double eps)
{
  mTolerance = eps;
  return *this;
}
inline Adesk::Boolean AcGeKnotVector::isValid(int i) const
{
  return i >= 0 && i < mData.logicalLength();
}
inline double& AcGeKnotVector::operator [](int i)
{
  assert(isValid(i));
  return mData[i];
}
inline const double AcGeKnotVector::operator [](int i) const
{
  assert(isValid(i));
  return mData[i];
}
inline const double* AcGeKnotVector::asArrayPtr() const
{
  return mData.asArrayPtr();
}
inline double* AcGeKnotVector::asArrayPtr()
{
  return mData.asArrayPtr();
}
#  pragma  pack (pop)
#endif