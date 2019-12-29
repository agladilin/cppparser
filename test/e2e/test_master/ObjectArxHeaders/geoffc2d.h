//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2018 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////
#ifndef AC_GEOFFC2D_H
#  define AC_GEOFFC2D_H
#  include "gecurv2d.h"
#  pragma  pack (push, 8)
class GE_DLLEXPIMPORT AcGeOffsetCurve2d : public AcGeCurve2d
{
public:
  AcGeOffsetCurve2d(const AcGeCurve2d& baseCurve, double offsetDistance);
  AcGeOffsetCurve2d(const AcGeOffsetCurve2d& offsetCurve);
  const AcGeCurve2d* curve() const;
  double offsetDistance() const;
  Adesk::Boolean paramDirection() const;
  AcGeMatrix2d transformation() const;
  AcGeOffsetCurve2d& setCurve(const AcGeCurve2d& baseCurve);
  AcGeOffsetCurve2d& setOffsetDistance(double distance);
  AcGeOffsetCurve2d& operator =(const AcGeOffsetCurve2d& offsetCurve);
};
#  pragma  pack (pop)
#endif