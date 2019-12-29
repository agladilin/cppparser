#ifndef AD_DBFILER_H
#  define AD_DBFILER_H
//////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2018 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form.   
//
//////////////////////////////////////////////////////////////////////////////
#  include <stdarg.h>
#  include "AdAChar.h"
#  include "acdb.h"
#  include "rxobject.h"
#  include "rxboiler.h"
#  pragma  pack (push, 8)
class AcDbAuditInfo;
class AcDbDatabase;
class AcDbFilerController;
class AcDbHandle;
class AcDbHardOwnershipId;
class AcDbSoftOwnershipId;
class AcDbHardPointerId;
class AcDbSoftPointerId;
class AcDbIdRefQueue;
class AcDbObjectId;
class AcGePoint2d;
class AcGePoint3d;
class AcGeScale3d;
class AcGeVector2d;
class AcGeVector3d;
class AcString;
struct resbuf;
struct ads_binary;
class ADESK_NO_VTABLE AcDbDwgFiler : public AcRxObject
{
public:
  ACRX_DECLARE_MEMBERS(AcDbDwgFiler);
protected:
  ACDBCORE2D_PORT AcDbDwgFiler();
public:
  ACDBCORE2D_PORT virtual ~AcDbDwgFiler();
  virtual Acad::ErrorStatus filerStatus() const = 0;
  virtual AcDb::FilerType filerType() const = 0;
  virtual void setFilerStatus(Acad::ErrorStatus es) = 0;
  virtual void resetFilerStatus() = 0;
  virtual Acad::ErrorStatus dwgVersion(AcDb::AcDbDwgVersion& ver, AcDb::MaintenanceReleaseVersion& maintVer) const;
  ACDBCORE2D_PORT virtual Acad::ErrorStatus extendedDwgMaintenanceReleaseVersion(AcDb::MaintenanceReleaseVersion& maintVer) const;
  virtual Acad::ErrorStatus readHardOwnershipId(AcDbHardOwnershipId* pVal) = 0;
  virtual Acad::ErrorStatus writeHardOwnershipId(const AcDbHardOwnershipId& val) = 0;
  virtual Acad::ErrorStatus readSoftOwnershipId(AcDbSoftOwnershipId* pVal) = 0;
  virtual Acad::ErrorStatus writeSoftOwnershipId(const AcDbSoftOwnershipId& val) = 0;
  virtual Acad::ErrorStatus readHardPointerId(AcDbHardPointerId* pVal) = 0;
  virtual Acad::ErrorStatus writeHardPointerId(const AcDbHardPointerId& val) = 0;
  virtual Acad::ErrorStatus readSoftPointerId(AcDbSoftPointerId* pVal) = 0;
  virtual Acad::ErrorStatus writeSoftPointerId(const AcDbSoftPointerId& val) = 0;
  virtual Acad::ErrorStatus readInt8(Adesk::Int8* pVal) = 0;
  virtual Acad::ErrorStatus writeInt8(Adesk::Int8 val) = 0;
  virtual Acad::ErrorStatus readString(ACHAR** pVal) = 0;
  virtual Acad::ErrorStatus writeString(const ACHAR* pVal) = 0;
  virtual Acad::ErrorStatus readString(AcString& val) = 0;
  virtual Acad::ErrorStatus writeString(const AcString& pVal) = 0;
  virtual Acad::ErrorStatus readBChunk(ads_binary* pVal) = 0;
  virtual Acad::ErrorStatus writeBChunk(const ads_binary&) = 0;
  virtual Acad::ErrorStatus readAcDbHandle(AcDbHandle* pVal) = 0;
  virtual Acad::ErrorStatus writeAcDbHandle(const AcDbHandle& val) = 0;
  virtual Acad::ErrorStatus readInt64(Adesk::Int64* pVal) = 0;
  virtual Acad::ErrorStatus writeInt64(Adesk::Int64 val) = 0;
  virtual Acad::ErrorStatus readInt32(Adesk::Int32* pVal) = 0;
  virtual Acad::ErrorStatus writeInt32(Adesk::Int32 val) = 0;
  virtual Acad::ErrorStatus readInt16(Adesk::Int16* pVal) = 0;
  virtual Acad::ErrorStatus writeInt16(Adesk::Int16 val) = 0;
  virtual Acad::ErrorStatus readUInt64(Adesk::UInt64* pVal) = 0;
  virtual Acad::ErrorStatus writeUInt64(Adesk::UInt64 val) = 0;
  virtual Acad::ErrorStatus readUInt32(Adesk::UInt32* pVal) = 0;
  virtual Acad::ErrorStatus writeUInt32(Adesk::UInt32 val) = 0;
  virtual Acad::ErrorStatus readUInt16(Adesk::UInt16* pVal) = 0;
  virtual Acad::ErrorStatus writeUInt16(Adesk::UInt16 val) = 0;
  virtual Acad::ErrorStatus readUInt8(Adesk::UInt8* pVal) = 0;
  virtual Acad::ErrorStatus writeUInt8(Adesk::UInt8 val) = 0;
  virtual Acad::ErrorStatus readBoolean(Adesk::Boolean* pVal) = 0;
  virtual Acad::ErrorStatus writeBoolean(Adesk::Boolean val) = 0;
  virtual Acad::ErrorStatus readBool(bool* pVal) = 0;
  virtual Acad::ErrorStatus writeBool(bool val) = 0;
  virtual Acad::ErrorStatus readDouble(double* pVal) = 0;
  virtual Acad::ErrorStatus writeDouble(double val) = 0;
  virtual Acad::ErrorStatus readPoint2d(AcGePoint2d* pVal) = 0;
  virtual Acad::ErrorStatus writePoint2d(const AcGePoint2d& val) = 0;
  virtual Acad::ErrorStatus readPoint3d(AcGePoint3d* pVal) = 0;
  virtual Acad::ErrorStatus writePoint3d(const AcGePoint3d& val) = 0;
  virtual Acad::ErrorStatus readVector2d(AcGeVector2d* pVal) = 0;
  virtual Acad::ErrorStatus writeVector2d(const AcGeVector2d& val) = 0;
  virtual Acad::ErrorStatus readVector3d(AcGeVector3d* pVal) = 0;
  virtual Acad::ErrorStatus writeVector3d(const AcGeVector3d& val) = 0;
  virtual Acad::ErrorStatus readScale3d(AcGeScale3d* pVal) = 0;
  virtual Acad::ErrorStatus writeScale3d(const AcGeScale3d& val) = 0;
  virtual Acad::ErrorStatus readBytes(void* pDest, Adesk::UIntPtr nBytes) = 0;
  virtual Acad::ErrorStatus writeBytes(const void* pSrc, Adesk::UIntPtr nBytes) = 0;
  virtual Acad::ErrorStatus readAddress(void** pVal);
  virtual Acad::ErrorStatus writeAddress(const void* pVal);
  Acad::ErrorStatus readItem(AcDbHardOwnershipId* pId);
  Acad::ErrorStatus writeItem(const AcDbHardOwnershipId& id);
  Acad::ErrorStatus readItem(AcDbSoftOwnershipId* pId);
  Acad::ErrorStatus writeItem(const AcDbSoftOwnershipId& id);
  Acad::ErrorStatus readItem(AcDbHardPointerId* pId);
  Acad::ErrorStatus writeItem(const AcDbHardPointerId& id);
  Acad::ErrorStatus readItem(AcDbSoftPointerId* pId);
  Acad::ErrorStatus writeItem(const AcDbSoftPointerId& id);
  Acad::ErrorStatus readItem(ACHAR** pVal);
  Acad::ErrorStatus writeItem(const ACHAR* val);
  Acad::ErrorStatus writeItem(const AcString& val);
  Acad::ErrorStatus readItem(ads_binary* pVal);
  Acad::ErrorStatus writeItem(const ads_binary& val);
  Acad::ErrorStatus readItem(AcDbHandle* pVal);
  Acad::ErrorStatus writeItem(const AcDbHandle& val);
  Acad::ErrorStatus readItem(Adesk::Int32* pVal);
  Acad::ErrorStatus writeItem(Adesk::Int32 val);
  Acad::ErrorStatus readItem(Adesk::Int16* pVal);
  Acad::ErrorStatus writeItem(Adesk::Int16 val);
  Acad::ErrorStatus readItem(Adesk::Int8* pVal);
  Acad::ErrorStatus writeItem(Adesk::Int8 val);
  Acad::ErrorStatus readItem(Adesk::UInt32* pVal);
  Acad::ErrorStatus writeItem(Adesk::UInt32 val);
  Acad::ErrorStatus readItem(Adesk::UInt16* pVal);
  Acad::ErrorStatus writeItem(Adesk::UInt16 val);
  Acad::ErrorStatus readItem(Adesk::UInt8* pVal);
  Acad::ErrorStatus writeItem(Adesk::UInt8 val);
  Acad::ErrorStatus readItem(Adesk::Boolean* pVal);
  Acad::ErrorStatus writeItem(Adesk::Boolean val);
#  if  !defined(Adesk_Boolean_is_bool) 
  Acad::ErrorStatus readItem(bool* pVal);
  Acad::ErrorStatus writeItem(bool val);
#  endif
  Acad::ErrorStatus readItem(double* pVal);
  Acad::ErrorStatus writeItem(double val);
  Acad::ErrorStatus readItem(AcGePoint2d* pVal);
  Acad::ErrorStatus writeItem(const AcGePoint2d& val);
  Acad::ErrorStatus readItem(AcGePoint3d* pVal);
  Acad::ErrorStatus writeItem(const AcGePoint3d& val);
  Acad::ErrorStatus readItem(AcGeVector2d* pVal);
  Acad::ErrorStatus writeItem(const AcGeVector2d& val);
  Acad::ErrorStatus readItem(AcGeVector3d* pVal);
  Acad::ErrorStatus writeItem(const AcGeVector3d& val);
  Acad::ErrorStatus readItem(AcGeScale3d* pVal);
  Acad::ErrorStatus writeItem(const AcGeScale3d& val);
  Acad::ErrorStatus readItem(void* pDest, Adesk::UIntPtr nBytes);
  Acad::ErrorStatus writeItem(const void* pSrc, Adesk::UIntPtr nBytes);
  Acad::ErrorStatus readItem(void** pp);
  Acad::ErrorStatus writeItem(const void* p);
  virtual Acad::ErrorStatus seek(Adesk::Int64 nOffset, int nMethod) = 0;
  virtual Adesk::Int64 tell() const = 0;
  virtual Acad::ErrorStatus addReferences(AcDbIdRefQueue&);
  virtual bool usesReferences() const;
  virtual AcDbAuditInfo* getAuditInfo() const;
  virtual AcDbFilerController& controller() const;
private:
  AcDbDwgFiler& operator =(const AcDbDwgFiler&);
  AcDbFilerController& mController;
};
class ADESK_NO_VTABLE AcDbDxfFiler : public AcRxObject
{
public:
  ACRX_DECLARE_MEMBERS(AcDbDxfFiler);
  virtual int rewindFiler() = 0;
  virtual Acad::ErrorStatus filerStatus() const = 0;
  virtual void resetFilerStatus() = 0;
  virtual Acad::ErrorStatus setError(Acad::ErrorStatus es, const ACHAR* errMsg, ...);
  virtual Acad::ErrorStatus setError(const ACHAR* errMsg, ...);
  virtual const ACHAR* errorMessage() const;
  virtual AcDb::FilerType filerType() const = 0;
  virtual AcDbDatabase* database() const = 0;
  virtual Acad::ErrorStatus dwgVersion(AcDb::AcDbDwgVersion& ver, AcDb::MaintenanceReleaseVersion& maintVer) const;
  ACDBCORE2D_PORT virtual Acad::ErrorStatus extendedDwgMaintenanceReleaseVersion(AcDb::MaintenanceReleaseVersion& maintVer) const;
  virtual int precision() const;
  virtual void setPrecision(int prec);
  enum
  {
    kDfltPrec = -1,
    kMaxPrec = 16
  };
  virtual Acad::ErrorStatus readResBuf(resbuf* pRb);
  virtual Acad::ErrorStatus writeResBuf(const resbuf& rb);
  virtual Acad::ErrorStatus writeObjectId(AcDb::DxfCode code, const AcDbObjectId& id) = 0;
  virtual Acad::ErrorStatus writeInt8(AcDb::DxfCode code, Adesk::Int8) = 0;
  virtual Acad::ErrorStatus writeString(AcDb::DxfCode code, const ACHAR* pVal) = 0;
  virtual Acad::ErrorStatus writeString(AcDb::DxfCode code, const AcString& pVal) = 0;
  virtual Acad::ErrorStatus writeBChunk(AcDb::DxfCode code, const ads_binary& val) = 0;
  virtual Acad::ErrorStatus writeAcDbHandle(AcDb::DxfCode code, const AcDbHandle& val) = 0;
  virtual Acad::ErrorStatus writeInt64(AcDb::DxfCode code, Adesk::Int64 val) = 0;
  virtual Acad::ErrorStatus writeInt32(AcDb::DxfCode code, Adesk::Int32 val) = 0;
  virtual Acad::ErrorStatus writeInt16(AcDb::DxfCode code, Adesk::Int16 val) = 0;
  virtual Acad::ErrorStatus writeUInt64(AcDb::DxfCode code, Adesk::UInt64 val) = 0;
  virtual Acad::ErrorStatus writeUInt32(AcDb::DxfCode code, Adesk::UInt32 val) = 0;
  virtual Acad::ErrorStatus writeUInt16(AcDb::DxfCode code, Adesk::UInt16 val) = 0;
  virtual Acad::ErrorStatus writeUInt8(AcDb::DxfCode code, Adesk::UInt8 val) = 0;
  virtual Acad::ErrorStatus writeBoolean(AcDb::DxfCode code, Adesk::Boolean val) = 0;
  virtual Acad::ErrorStatus writeBool(AcDb::DxfCode code, bool val) = 0;
  virtual Acad::ErrorStatus writeDouble(AcDb::DxfCode code, double val, int prec = kDfltPrec) = 0;
  virtual Acad::ErrorStatus writePoint2d(AcDb::DxfCode code, const AcGePoint2d& val, int prec = kDfltPrec) = 0;
  virtual Acad::ErrorStatus writePoint3d(AcDb::DxfCode code, const AcGePoint3d& val, int prec = kDfltPrec) = 0;
  virtual Acad::ErrorStatus writeVector2d(AcDb::DxfCode code, const AcGeVector2d& val, int prec = kDfltPrec) = 0;
  virtual Acad::ErrorStatus writeVector3d(AcDb::DxfCode code, const AcGeVector3d& val, int prec = kDfltPrec) = 0;
  virtual Acad::ErrorStatus writeScale3d(AcDb::DxfCode code, const AcGeScale3d& val, int prec = kDfltPrec) = 0;
  Acad::ErrorStatus readItem(resbuf* pItem);
  Acad::ErrorStatus writeItem(const resbuf& pItem);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcDbObjectId& id);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const ACHAR* val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcString& val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const ads_binary& val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcDbHandle& val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, Adesk::Int32 val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, Adesk::Int16 val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, Adesk::Int8 val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, Adesk::UInt32 val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, Adesk::UInt16 val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, Adesk::UInt8 val);
#  ifndef Adesk_Boolean_is_bool
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, Adesk::Boolean val);
#  endif
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, bool val);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, double val, int = kDfltPrec);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGePoint2d& val, int prec = kDfltPrec);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGePoint3d& val, int prec = kDfltPrec);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGeVector2d& val, int prec = kDfltPrec);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGeVector3d& val, int prec = kDfltPrec);
  Acad::ErrorStatus writeItem(AcDb::DxfCode dc, const AcGeScale3d& val, int prec = kDfltPrec);
  virtual Acad::ErrorStatus writeXDataStart();
  virtual bool includesDefaultValues() const = 0;
  virtual Acad::ErrorStatus pushBackItem();
  virtual bool atEOF();
  virtual bool atSubclassData(const ACHAR* subClassName);
  virtual bool atExtendedData();
  virtual bool atEndOfObject();
  virtual void haltAtClassBoundaries(bool halt);
  virtual Acad::ErrorStatus writeEmbeddedObjectStart();
  virtual bool atEmbeddedObjectStart();
  virtual double elevation() const;
  virtual double thickness() const;
  virtual bool isModifyingExistingObject() const;
  AcDbDxfFiler();
  virtual ~AcDbDxfFiler();
  AcDbFilerController& controller() const;
private:
  AcDbDxfFiler& operator =(const AcDbDxfFiler&);
  AcDbFilerController& mController;
  virtual Acad::ErrorStatus setVAError(Acad::ErrorStatus, const ACHAR*, va_list);
};
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbHardOwnershipId* pId)
{
  return readHardOwnershipId(pId);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbHardOwnershipId& pId)
{
  return writeHardOwnershipId(pId);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbSoftOwnershipId* pId)
{
  return readSoftOwnershipId(pId);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbSoftOwnershipId& pId)
{
  return writeSoftOwnershipId(pId);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbHardPointerId* pId)
{
  return readHardPointerId(pId);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbHardPointerId& pId)
{
  return writeHardPointerId(pId);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbSoftPointerId* pId)
{
  return readSoftPointerId(pId);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbSoftPointerId& pId)
{
  return writeSoftPointerId(pId);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(ACHAR** pVal)
{
  return readString(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const ACHAR* val)
{
  return writeString(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(ads_binary* pVal)
{
  return readBChunk(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const ads_binary& val)
{
  return writeBChunk(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcDbHandle* pVal)
{
  return readAcDbHandle(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcDbHandle& val)
{
  return writeAcDbHandle(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(Adesk::Int32* pVal)
{
  return readInt32(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(Adesk::Int32 val)
{
  return writeInt32(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(Adesk::Int16* pVal)
{
  return readInt16(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(Adesk::Int16 val)
{
  return writeInt16(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(Adesk::Int8* pVal)
{
  return this->readInt8(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(Adesk::Int8 val)
{
  return this->writeInt8(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(Adesk::UInt32* pVal)
{
  return readUInt32(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(Adesk::UInt32 val)
{
  return writeUInt32(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(Adesk::UInt16* pVal)
{
  return readUInt16(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(Adesk::UInt16 val)
{
  return writeUInt16(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(Adesk::UInt8* pVal)
{
  return readUInt8(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(Adesk::UInt8 val)
{
  return writeUInt8(val);
}
#  if  !defined(Adesk_Boolean_is_bool)
inline Acad::ErrorStatus AcDbDwgFiler::readItem(Adesk::Boolean* pVal)
{
  return readBoolean(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(Adesk::Boolean val)
{
  return writeBoolean(val);
}
#  endif
inline Acad::ErrorStatus AcDbDwgFiler::readItem(bool* pVal)
{
  return readBool(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(bool val)
{
  return writeBool(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(double* pVal)
{
  return readDouble(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(double val)
{
  return writeDouble(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGePoint2d* pVal)
{
  return readPoint2d(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGePoint2d& val)
{
  return writePoint2d(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGePoint3d* pVal)
{
  return readPoint3d(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGePoint3d& val)
{
  return writePoint3d(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGeVector2d* pVal)
{
  return readVector2d(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGeVector2d& val)
{
  return writeVector2d(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGeVector3d* pVal)
{
  return readVector3d(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGeVector3d& val)
{
  return writeVector3d(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(AcGeScale3d* pVal)
{
  return readScale3d(pVal);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcGeScale3d& val)
{
  return writeScale3d(val);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(void* buf, Adesk::UIntPtr cnt)
{
  return readBytes(buf, cnt);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const void* buf, Adesk::UIntPtr cnt)
{
  return writeBytes(buf, cnt);
}
inline Acad::ErrorStatus AcDbDwgFiler::readItem(void** pp)
{
  return readAddress(pp);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const void* p)
{
  return writeAddress(p);
}
inline Acad::ErrorStatus AcDbDxfFiler::readItem(resbuf* pVal)
{
  return readResBuf(pVal);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(const resbuf& val)
{
  return writeResBuf(val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcDbObjectId& id)
{
  return writeObjectId(dc, id);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const ACHAR* val)
{
  return writeString(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const ads_binary& val)
{
  return writeBChunk(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcDbHandle& val)
{
  return writeAcDbHandle(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, Adesk::Int32 val)
{
  return writeInt32(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, Adesk::Int16 val)
{
  return writeInt16(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, Adesk::Int8 val)
{
  return this->writeInt8(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, Adesk::UInt32 val)
{
  return writeUInt32(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, Adesk::UInt16 val)
{
  return writeUInt16(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, Adesk::UInt8 val)
{
  return writeUInt8(dc, val);
}
#  if  !defined(Adesk_Boolean_is_bool) 
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, Adesk::Boolean val)
{
  return writeBoolean(dc, val);
}
#  endif
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, bool val)
{
  return writeBool(dc, val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, double val, int prec)
{
  return writeDouble(dc, val, prec);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGePoint2d& val, int prec)
{
  return writePoint2d(dc, val, prec);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGePoint3d& val, int prec)
{
  return writePoint3d(dc, val, prec);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGeVector2d& val, int prec)
{
  return writeVector2d(dc, val, prec);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGeVector3d& val, int prec)
{
  return writeVector3d(dc, val, prec);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcGeScale3d& val, int prec)
{
  return writeScale3d(dc, val, prec);
}
inline Acad::ErrorStatus AcDbDwgFiler::writeItem(const AcString& val)
{
  return writeString(val);
}
inline Acad::ErrorStatus AcDbDxfFiler::writeItem(AcDb::DxfCode dc, const AcString& val)
{
  return writeString(dc, val);
}
#  pragma  pack (pop)
#endif