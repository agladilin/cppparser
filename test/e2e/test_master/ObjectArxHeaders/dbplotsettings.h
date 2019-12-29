//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2018 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//  dbPlotSettings.h
//
//////////////////////////////////////////////////////////////////////////////
#ifndef AD_DBPLOTSETTINGS_H
#  define AD_DBPLOTSETTINGS_H
#  include "dbmain.h"
#  include "dbdict.h"
#  include "AcDbCore2dDefs.h"
class IAcReadStream;
#  pragma  pack(push, 8)
class AcDbPlotSettings : public AcDbObject
{
  ACDB_DECLARE_MEMBERS(AcDbPlotSettings);
public:
  AcDbPlotSettings();
  AcDbPlotSettings(bool ModelType);
  virtual ~AcDbPlotSettings();
  using AcDbObject::copyFrom;
  Acad::ErrorStatus copyFrom(AcDbPlotSettings* fromPlotSettings);
  enum PlotPaperUnits
  {
    kInches,
    kMillimeters,
    kPixels
  };
  enum PlotRotation
  {
    k0degrees,
    k90degrees,
    k180degrees,
    k270degrees
  };
  enum PlotType
  {
    kDisplay,
    kExtents,
    kLimits,
    kView,
    kWindow,
    kLayout
  };
  enum StdScaleType
  {
    kScaleToFit,
    k1_128in_1ft,
    k1_64in_1ft,
    k1_32in_1ft,
    k1_16in_1ft,
    k3_32in_1ft,
    k1_8in_1ft,
    k3_16in_1ft,
    k1_4in_1ft,
    k3_8in_1ft,
    k1_2in_1ft,
    k3_4in_1ft,
    k1in_1ft,
    k3in_1ft,
    k6in_1ft,
    k1ft_1ft,
    k1_1,
    k1_2,
    k1_4,
    k1_5,
    k1_8,
    k1_10,
    k1_16,
    k1_20,
    k1_30,
    k1_40,
    k1_50,
    k1_100,
    k2_1,
    k4_1,
    k8_1,
    k10_1,
    k100_1,
    k1000_1,
    k1and1_2in_1ft
  };
  enum ShadePlotType
  {
    kAsDisplayed = 0,
    kWireframe = 1,
    kHidden = 2,
    kRendered = 3,
    kVisualStyle = 4,
    kRenderPreset = 5
  };
  enum ShadePlotResLevel
  {
    kDraft,
    kPreview,
    kNormal,
    kPresentation,
    kMaximum,
    kCustom
  };
  Acad::ErrorStatus addToPlotSettingsDict(AcDbDatabase* towhichDb);
  Acad::ErrorStatus getPlotSettingsName(const ACHAR*& plotSettingsName) const;
  Acad::ErrorStatus getPlotSettingsName(ACHAR*& plotSettingsName) const;
  Acad::ErrorStatus setPlotSettingsName(const ACHAR* plotSettingsName);
  Acad::ErrorStatus getPlotCfgName(const ACHAR*& plotCfgName) const;
  Acad::ErrorStatus getPlotPaperMargins(double& printableXmin, double& printableYmin, double& printableXmax, double& printableYmax) const;
  Acad::ErrorStatus getPlotPaperSize(double& paperWidth, double& paperHeight) const;
  ACDBCORE2D_PORT Acad::ErrorStatus getPlotPaperSize(AcGePoint2d& paperSize) const;
  Acad::ErrorStatus getCanonicalMediaName(const ACHAR*& mediaName) const;
  Acad::ErrorStatus getPlotOrigin(double& x, double& y) const;
  ACDBCORE2D_PORT Acad::ErrorStatus getPlotOrigin(AcGePoint2d& origin) const;
  AcDbPlotSettings::PlotPaperUnits plotPaperUnits() const;
  Adesk::Boolean plotViewportBorders() const;
  void setPlotViewportBorders(Adesk::Boolean plotViewportBorders);
  Adesk::Boolean plotTransparency() const;
  void setPlotTransparency(Adesk::Boolean plotTransparency);
  Adesk::Boolean plotPlotStyles() const;
  void setPlotPlotStyles(Adesk::Boolean plotPlotStyles);
  Adesk::Boolean showPlotStyles() const;
  void setShowPlotStyles(Adesk::Boolean showPlotStyles);
  AcDbPlotSettings::PlotRotation plotRotation() const;
  Adesk::Boolean plotCentered() const;
  Adesk::Boolean plotHidden() const;
  void setPlotHidden(Adesk::Boolean plotHidden);
  AcDbPlotSettings::ShadePlotType shadePlot() const;
  Acad::ErrorStatus setShadePlot(AcDbPlotSettings::ShadePlotType shadePlot);
  AcDbPlotSettings::ShadePlotResLevel shadePlotResLevel() const;
  Acad::ErrorStatus setShadePlotResLevel(AcDbPlotSettings::ShadePlotResLevel resLevel);
  Adesk::Int16 shadePlotCustomDPI() const;
  Acad::ErrorStatus setShadePlotCustomDPI(Adesk::Int16 val);
  AcDbPlotSettings::PlotType plotType() const;
  Acad::ErrorStatus getPlotWindowArea(double& xmin, double& ymin, double& xmax, double& ymax) const;
  Acad::ErrorStatus getPlotViewName(const ACHAR*& viewName) const;
  Adesk::Boolean useStandardScale() const;
  Acad::ErrorStatus getCustomPrintScale(double& numerator, double& denominator) const;
  Acad::ErrorStatus getCurrentStyleSheet(const ACHAR*& styleSheetName) const;
  ACDBCORE2D_PORT IAcReadStream* getStyleSheetReadStream();
  AcDbPlotSettings::StdScaleType stdScaleType() const;
  Acad::ErrorStatus getStdScale(double& scale) const;
  Adesk::Boolean scaleLineweights() const;
  void setScaleLineweights(Adesk::Boolean scaleLineweights);
  Adesk::Boolean printLineweights() const;
  void setPrintLineweights(Adesk::Boolean printLineweights);
  Adesk::Boolean drawViewportsFirst() const;
  void setDrawViewportsFirst(Adesk::Boolean drawViewportsFirst);
  Adesk::Boolean modelType() const;
  AcDbObjectId shadePlotId() const;
  Acad::ErrorStatus setShadePlot(AcDbPlotSettings::ShadePlotType type, AcDbObjectId shadePlotId);
  bool plotWireframe() const;
  bool plotAsRaster() const;
protected:
  virtual Acad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};
#  pragma  pack(pop)
#endif