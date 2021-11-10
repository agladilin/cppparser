/*
 * Copyright 2018 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**************************************************************************************************
 *** This file was autogenerated from GrUnrolledBinaryGradientColorizer.fp; do not modify.
 **************************************************************************************************/
#ifndef GrUnrolledBinaryGradientColorizer_DEFINED
#  define GrUnrolledBinaryGradientColorizer_DEFINED
#  include "include/core/SkTypes.h"
#  include "src/gpu/GrCoordTransform.h"
#  include "src/gpu/GrFragmentProcessor.h"
class GrUnrolledBinaryGradientColorizer : public GrFragmentProcessor
{
public:
  static const int kMaxColorCount = 16;
  static std::unique_ptr<GrFragmentProcessor> Make(const SkPMColor4f* colors, const SkScalar* positions, int count);
  GrUnrolledBinaryGradientColorizer(const GrUnrolledBinaryGradientColorizer& src);
  std::unique_ptr<GrFragmentProcessor> clone() const override;
  const char* name() const override
  {
    return "UnrolledBinaryGradientColorizer";
  }
  int32_t intervalCount;
  SkPMColor4f scale0_1;
  SkPMColor4f scale2_3;
  SkPMColor4f scale4_5;
  SkPMColor4f scale6_7;
  SkPMColor4f scale8_9;
  SkPMColor4f scale10_11;
  SkPMColor4f scale12_13;
  SkPMColor4f scale14_15;
  SkPMColor4f bias0_1;
  SkPMColor4f bias2_3;
  SkPMColor4f bias4_5;
  SkPMColor4f bias6_7;
  SkPMColor4f bias8_9;
  SkPMColor4f bias10_11;
  SkPMColor4f bias12_13;
  SkPMColor4f bias14_15;
  SkRect thresholds1_7;
  SkRect thresholds9_13;
private:
  GrUnrolledBinaryGradientColorizer(int32_t intervalCount, SkPMColor4f scale0_1, SkPMColor4f scale2_3, SkPMColor4f scale4_5, SkPMColor4f scale6_7, SkPMColor4f scale8_9, SkPMColor4f scale10_11, SkPMColor4f scale12_13, SkPMColor4f scale14_15, SkPMColor4f bias0_1, SkPMColor4f bias2_3, SkPMColor4f bias4_5, SkPMColor4f bias6_7, SkPMColor4f bias8_9, SkPMColor4f bias10_11, SkPMColor4f bias12_13, SkPMColor4f bias14_15, SkRect thresholds1_7, SkRect thresholds9_13)
    : INHERITED(kGrUnrolledBinaryGradientColorizer_ClassID, kNone_OptimizationFlags)
    , intervalCount(intervalCount)
    , scale0_1(scale0_1)
    , scale2_3(scale2_3)
    , scale4_5(scale4_5)
    , scale6_7(scale6_7)
    , scale8_9(scale8_9)
    , scale10_11(scale10_11)
    , scale12_13(scale12_13)
    , scale14_15(scale14_15)
    , bias0_1(bias0_1)
    , bias2_3(bias2_3)
    , bias4_5(bias4_5)
    , bias6_7(bias6_7)
    , bias8_9(bias8_9)
    , bias10_11(bias10_11)
    , bias12_13(bias12_13)
    , bias14_15(bias14_15)
    , thresholds1_7(thresholds1_7)
    , thresholds9_13(thresholds9_13)
  {
  }
  GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;
  void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
  bool onIsEqual(const GrFragmentProcessor&) const override;
  GR_DECLARE_FRAGMENT_PROCESSOR_TEST
  typedef GrFragmentProcessor INHERITED;
};
#endif
