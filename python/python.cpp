#include "python.h"

using namespace openpgl;

PYBIND11_MODULE(openpglpy, m)
{
// common.h
PGL_PY_STRUCT(pgl_vec3f)
.def_init()
.def_class_field(pgl_vec3f, x)
.def_class_field(pgl_vec3f, y)
.def_class_field(pgl_vec3f, z);

PGL_PY_STRUCT(pgl_vec2f)
.def_init()
.def_class_field(pgl_vec2f, x)
.def_class_field(pgl_vec2f, y);

PGL_PY_STRUCT(pgl_box3f)
.def_init()
.def_class_field(pgl_box3f, lower)
.def_class_field(pgl_box3f, upper);

// types.h
PGL_PY_ENUM(PGL_SPATIAL_STRUCTURE_TYPE)
.def_value(PGL_SPATIAL_STRUCTURE_TYPE, PGL_SPATIAL_STRUCTURE_KDTREE);

PGL_PY_ENUM(PGL_DIRECTIONAL_DISTRIBUTION_TYPE)
.def_value(PGL_DIRECTIONAL_DISTRIBUTION_TYPE, PGL_DIRECTIONAL_DISTRIBUTION_PARALLAX_AWARE_VMM)
.def_value(PGL_DIRECTIONAL_DISTRIBUTION_TYPE, PGL_DIRECTIONAL_DISTRIBUTION_QUADTREE)
.def_value(PGL_DIRECTIONAL_DISTRIBUTION_TYPE, PGL_DIRECTIONAL_DISTRIBUTION_VMM);

// config.h
PGL_PY_ENUM(PGL_DEVICE_TYPE)
.def_value(PGL_DEVICE_TYPE, PGL_DEVICE_TYPE_CPU_4)
.def_value(PGL_DEVICE_TYPE, PGL_DEVICE_TYPE_CPU_8)
.def_value(PGL_DEVICE_TYPE, PGL_DEVICE_TYPE_CPU_16);

PGL_PY_NAMED_STRUCT(PGLKDTreeArguments, "KDTreeArguments")
.def_init()
.def_class_field(PGLKDTreeArguments, knnLookup)
.def_class_field(PGLKDTreeArguments, minSamples)
.def_class_field(PGLKDTreeArguments, maxSamples)
.def_class_field(PGLKDTreeArguments, maxDepth);

PGL_PY_NAMED_STRUCT(PGLVMMFactoryArguments, "VMMFactoryArguments")
.def_init()
.def_class_field(PGLVMMFactoryArguments, initK)
.def_class_field(PGLVMMFactoryArguments, initKappa)
.def_class_field(PGLVMMFactoryArguments, maxK)
.def_class_field(PGLVMMFactoryArguments, maxEMIterrations)
.def_class_field(PGLVMMFactoryArguments, maxKappa)
.def_class_field(PGLVMMFactoryArguments, convergenceThreshold)
.def_class_field(PGLVMMFactoryArguments, weightPrior)
.def_class_field(PGLVMMFactoryArguments, meanCosinePriorStrength)
.def_class_field(PGLVMMFactoryArguments, meanCosinePrior)
.def_class_field(PGLVMMFactoryArguments, useSplitAndMerge)
.def_class_field(PGLVMMFactoryArguments, splittingThreshold)
.def_class_field(PGLVMMFactoryArguments, mergingThreshold)
.def_class_field(PGLVMMFactoryArguments, partialReFit)
.def_class_field(PGLVMMFactoryArguments, maxSplitItr)
.def_class_field(PGLVMMFactoryArguments, minSamplesForSplitting)
.def_class_field(PGLVMMFactoryArguments, minSamplesForPartialRefitting)
.def_class_field(PGLVMMFactoryArguments, minSamplesForMerging);

PGL_PY_ENUM(PGLDQTLeafEstimator)
.def_value(PGLDQTLeafEstimator, REJECTION_SAMPLING)
.def_value(PGLDQTLeafEstimator, PER_LEAF);

PGL_PY_ENUM(PGLDQTSplitMetric)
.def_value(PGLDQTSplitMetric, MEAN)
.def_value(PGLDQTSplitMetric, SECOND_MOMENT);

PGL_PY_NAMED_STRUCT(PGLDQTFactoryArguments, "DQTFactoryArguments")
.def_init()
.def_class_field(PGLDQTFactoryArguments, leafEstimator)
.def_class_field(PGLDQTFactoryArguments, splitMetric)
.def_class_field(PGLDQTFactoryArguments, splitThreshold)
.def_class_field(PGLDQTFactoryArguments, footprintFactor)
.def_class_field(PGLDQTFactoryArguments, maxLevels);

PGL_PY_NAMED_STRUCT(PGLFieldArguments, "FieldArguments")
.def_init()
.def_class_field(PGLFieldArguments, spatialStructureType)
.def_class_field(PGLFieldArguments, directionalDistributionType)
.def_class_field(PGLFieldArguments, deterministic);

def_method(pglFieldArgumentsSetDefaults);

// data.h
PGL_PY_NAMED_STRUCT(PGLSampleData, "SampleData")
.def_init()
.def_class_field(PGLSampleData, position)
.def_class_field(PGLSampleData, direction)
.def_class_field(PGLSampleData, weight)
.def_class_field(PGLSampleData, pdf)
.def_class_field(PGLSampleData, distance)
.def_class_field(PGLSampleData, flags);

PGL_PY_NAMED_STRUCT(PGLPathSegmentData, "PathSegmentData")
.def_init()
.def_class_field(PGLPathSegmentData, position)
.def_class_field(PGLPathSegmentData, directionIn)
.def_class_field(PGLPathSegmentData, directionOut)
.def_class_field(PGLPathSegmentData, normal)
.def_class_field(PGLPathSegmentData, volumeScatter)
.def_class_field(PGLPathSegmentData, pdfDirectionIn)
.def_class_field(PGLPathSegmentData, isDelta)
.def_class_field(PGLPathSegmentData, scatteringWeight)
.def_class_field(PGLPathSegmentData, transmittanceWeight)
.def_class_field(PGLPathSegmentData, directContribution)
.def_class_field(PGLPathSegmentData, miWeight)
.def_class_field(PGLPathSegmentData, scatteredContribution)
.def_class_field(PGLPathSegmentData, russianRouletteProbability)
.def_class_field(PGLPathSegmentData, eta)
.def_class_field(PGLPathSegmentData, roughness);

// Common.h
def_named_method(cpp::Vector3, "Vector3");
def_named_method(cpp::Vector2, "Vector2");
def_named_method(cpp::Point3, "Point3");
def_named_method(cpp::Point2, "Point2");
def_named_method_overload(cpp::Box3, "Box3FromPoints", pgl_box3f, pgl_point3f, pgl_point3f);
def_named_method_overload(cpp::Box3, "Box3FromFloats", pgl_box3f, float, float, float, float, float, float);

// Field.h
PGL_PY_NAMED_STRUCT(cpp::Field, "Field")
.def_init(cpp::Device*, PGLFieldArguments)
.def_init(cpp::Device*, const std::string&)
.def_class_method(cpp::Field, Store)
.def_class_method(cpp::Field, SetSceneBounds)
.def_class_method(cpp::Field, GetSceneBounds)
.def_class_method(cpp::Field, Update)
.def_class_method(cpp::Field, UpdateSurface)
.def_class_method(cpp::Field, UpdateVolume)
.def_class_method(cpp::Field, Reset)
.def_class_method(cpp::Field, GetIteration)
.def_class_method(cpp::Field, Validate);

// Device.h
PGL_PY_NAMED_STRUCT(cpp::Device, "Device") 
.def_init(PGL_DEVICE_TYPE);

// PathSegment.h
def_named_method(cpp::Reset, "Reset");
def_named_method(cpp::SetPosition, "SetPosition");
def_named_method(cpp::SetNormal, "SetNormal");
def_named_method(cpp::SetDirectionIn, "SetDirectionIn");
def_named_method(cpp::GetDirectionIn, "GetDirectionIn");
def_named_method(cpp::SetPDFDirectionIn, "SetPDFDirectionIn");
def_named_method(cpp::SetDirectionOut, "SetDirectionOut");
def_named_method(cpp::SetVolumeScatter, "SetVolumeScatter");
def_named_method(cpp::SetScatteringWeight, "SetScatteringWeight");
def_named_method(cpp::SetDirectContribution, "SetDirectContribution");
def_named_method(cpp::AddDirectContribution, "AddDirectContribution");
def_named_method(cpp::SetScatteredContribution, "SetScatteredContribution");
def_named_method(cpp::AddScatteredContribution, "AddScatteredContribution");
def_named_method(cpp::SetMiWeight, "SetMiWeight");
def_named_method(cpp::SetRussianRouletteProbability, "SetRussianRouletteProbability");
def_named_method(cpp::SetEta, "SetEta");
def_named_method(cpp::SetIsDelta, "SetIsDelta");
def_named_method(cpp::SetRoughness, "SetRoughness");
def_named_method(cpp::SetTransmittanceWeight, "SetTransmittanceWeight");

// PathSegmentStorage.h
PGL_PY_NAMED_STRUCT(cpp::PathSegmentStorage, "PathSegmentStorage")
.def_init()
.def_class_method(cpp::PathSegmentStorage, Reserve)
.def_class_method(cpp::PathSegmentStorage, Clear)
.def_class_method(cpp::PathSegmentStorage, CalculatePixelEstimate)
.def_class_method(cpp::PathSegmentStorage, GetSamples)
.def_class_method(cpp::PathSegmentStorage, NextSegment)
.def_class_method(cpp::PathSegmentStorage, AddSegment)
.def_class_method(cpp::PathSegmentStorage, AddSample)
.def_class_method(cpp::PathSegmentStorage, SetMaxDistance)
.def_class_method(cpp::PathSegmentStorage, GetMaxDistance)
.def_class_method(cpp::PathSegmentStorage, GetNumSegments)
.def_class_method(cpp::PathSegmentStorage, GetNumSamples)
.def_class_method(cpp::PathSegmentStorage, Validate)
.def_class_method(cpp::PathSegmentStorage, ValidateSegments)
.def_class_method(cpp::PathSegmentStorage, ValidateSamples)
.def_class_method(cpp::PathSegmentStorage, PropagateSamples);

// SampleStorage.h
PGL_PY_NAMED_STRUCT(cpp::SampleStorage, "SampleStorage")
.def_init()
.def_init(std::string)
.def_class_method(cpp::SampleStorage, Store)
.def_class_method(cpp::SampleStorage, AddSample)
.def_class_method(cpp::SampleStorage, AddSamples)
.def_class_method(cpp::SampleStorage, Reserve)
.def_class_method(cpp::SampleStorage, Clear)
.def_class_method(cpp::SampleStorage, ClearSurface)
.def_class_method(cpp::SampleStorage, ClearVolume)
.def_class_method(cpp::SampleStorage, GetSizeSurface)
.def_class_method(cpp::SampleStorage, GetSizeVolume)
.def_class_method(cpp::SampleStorage, GetSampleSurface)
.def_class_method(cpp::SampleStorage, GetSampleVolume);

// SurfaceSamplingDistribution.h
PGL_PY_NAMED_STRUCT(cpp::SurfaceSamplingDistribution, "SurfaceSamplingDistribution")
.def_init(const cpp::Field*)
.def_class_method(cpp::SurfaceSamplingDistribution, Init)
.def_class_method(cpp::SurfaceSamplingDistribution, Clear)
.def_class_method(cpp::SurfaceSamplingDistribution, Sample)
.def_class_method(cpp::SurfaceSamplingDistribution, PDF)
.def_class_method(cpp::SurfaceSamplingDistribution, SamplePDF)
.def_class_method(cpp::SurfaceSamplingDistribution, IncomingRadiancePDF)
.def_class_method(cpp::SurfaceSamplingDistribution, SupportsApplyCosineProduct)
.def_class_method(cpp::SurfaceSamplingDistribution, Validate)
.def_class_method(cpp::SurfaceSamplingDistribution, GetRegion);

// VolumeSamplingDistribution.h
PGL_PY_NAMED_STRUCT(cpp::VolumeSamplingDistribution, "VolumeSamplingDistribution")
.def_init(const cpp::Field*)
.def_class_method(cpp::VolumeSamplingDistribution, Init)
.def_class_method(cpp::VolumeSamplingDistribution, Clear)
.def_class_method(cpp::VolumeSamplingDistribution, Sample)
.def_class_method(cpp::VolumeSamplingDistribution, PDF)
.def_class_method(cpp::VolumeSamplingDistribution, SamplePDF)
.def_class_method(cpp::VolumeSamplingDistribution, IncomingRadiancePDF)
.def_class_method(cpp::VolumeSamplingDistribution, SupportsApplySingleLobeHenyeyGreensteinProduct)
.def_class_method(cpp::VolumeSamplingDistribution, ApplySingleLobeHenyeyGreensteinProduct)
.def_class_method(cpp::VolumeSamplingDistribution, Validate);

}