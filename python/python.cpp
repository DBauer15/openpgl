#include "python.h"

PYBIND11_MODULE(openpglpy, m)
{
// common.h
PGL_PY_STRUCT(pgl_vec3f);

PGL_PY_STRUCT(pgl_vec2f);

PGL_PY_STRUCT(pgl_box3f);

def_method(pglVec3f);
def_method(pglVec3fAdd);
def_method(pglVec2f);
def_method(pglVec2fAdd);
def_method(pglPoint3f);
def_method(pglPoint2f);
def_method(pglBox3f);

// data.h
PGL_PY_STRUCT(PGLSampleData)
.def_class_field(PGLSampleData, position)
.def_class_field(PGLSampleData, direction)
.def_class_field(PGLSampleData, weight)
.def_class_field(PGLSampleData, pdf)
.def_class_field(PGLSampleData, distance)
.def_class_field(PGLSampleData, flags);

PGL_PY_STRUCT(PGLPathSegmentData)
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

// region.h
PGL_PY_STRUCT(PGLRegion);

// samplestorage.h
PGL_PY_STRUCT(PGLSampleStorage);

def_method(pglNewSampleStorage);
def_method(pglNewSampleStorageFromFile);
def_method(pglReleaseSampleStorage);
def_method(pglSampleStorageStoreToFile);
def_method(pglSampleStorageAddSample);
def_method(pglSampleStorageAddSamples);
def_method(pglSampleStorageReserve);
def_method(pglSampleStorageClear);
def_method(pglSampleStorageClearSurface);
def_method(pglSampleStorageClearVolume);
def_method(pglSampleStorageGetSizeSurface);
def_method(pglSampleStorageGetSizeVolume);
def_method(pglSampleStorageGetSampleSurface);
def_method(pglSampleStorageGetSampleVolume);

// pathsegmentstorage.h
PGL_PY_STRUCT(PGLPathSegmentStorage);
def_method(pglReleasePathSegmentStorage);
def_method(pglPathSegmentStorageReserve);
def_method(pglPathSegmentStorageClear);
def_method(pglPathSegmentSetMaxDistance);
def_method(pglPathSegmentGetMaxDistance);
def_method(pglPathSegmentGetNumSegments);
def_method(pglPathSegmentGetNumSamples);
def_method(pglPathSegmentStoragePrepareSamples);
def_method(pglPathSegmentStorageCalculatePixelEstimate);
def_method(pglPathSegmentStorageGetSamples);
def_method(pglPathSegmentStorageAddSample);
def_method(pglPathSegmentStorageNextSegment);
def_method(pglPathSegmentStorageAddSegment);
def_method(pglPathSegmentStorageValidateSamples);
def_method(pglPathSegmentStorageValidateSegments);
def_method(pglPathSegmentStoragePropagateSamples);

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

PGL_PY_STRUCT(PGLKDTreeArguments)
.def_init()
.def_class_field(PGLKDTreeArguments, knnLookup)
.def_class_field(PGLKDTreeArguments, minSamples)
.def_class_field(PGLKDTreeArguments, maxSamples)
.def_class_field(PGLKDTreeArguments, maxDepth);

PGL_PY_STRUCT(PGLVMMFactoryArguments)
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

PGL_PY_STRUCT(PGLDQTFactoryArguments)
.def_init()
.def_class_field(PGLDQTFactoryArguments, leafEstimator)
.def_class_field(PGLDQTFactoryArguments, splitMetric)
.def_class_field(PGLDQTFactoryArguments, splitThreshold)
.def_class_field(PGLDQTFactoryArguments, footprintFactor)
.def_class_field(PGLDQTFactoryArguments, maxLevels);

PGL_PY_STRUCT(PGLFieldArguments)
.def_init()
.def_class_field(PGLFieldArguments, spatialStructureType)
.def_class_field(PGLFieldArguments, directionalDistributionType)
.def_class_field(PGLFieldArguments, deterministic);

def_method(pglFieldArgumentsSetDefaults);

// device.h
def_lambda(pglNewDevice, [](PGL_DEVICE_TYPE deviceType){ return py::capsule(pglNewDevice(deviceType)); });
def_lambda(pglDeviceNewField, [](py::capsule device, PGLFieldArguments args) { return py::capsule(pglDeviceNewField((PGLDevice) device.ptr(), args)); });
def_lambda(pglDeviceNewFieldFromFile, [](py::capsule device, const char* fieldName) { return py::capsule(pglDeviceNewFieldFromFile((PGLDevice) device.ptr(), fieldName)); });
def_lambda(pglReleaseDevice, [](py::capsule device) { pglReleaseDevice((PGLDevice) device.ptr()); });

// field.h
PGL_PY_STRUCT(PGLField);
// def_method(pglReleaseField);
// def_method(pglFieldStoreToFile);
// def_method(pglFieldGetIteration);
// def_method(pglFieldSetSceneBounds);
// def_method(pglFieldGetSceneBounds);
// def_method(pglFieldUpdate);
// def_method(pglFieldUpdateSurface);
// def_method(pglFieldUpdateVolume);
// def_method(pglFieldReset);
// def_method(pglFieldNewSurfaceSamplingDistribution);
// def_method(pglFieldInitSurfaceSamplingDistribution);
// def_method(pglFieldNewVolumeSamplingDistribution);
// def_method(pglFieldInitVolumeSamplingDistribution);
// def_method(pglFieldValidate);

// surfacesamplingdistribution.h
PGL_PY_STRUCT(PGLSurfaceSamplingDistribution);
// def_method(pglReleaseSurfaceSamplingDistribution);
// def_method(pglSurfaceSamplingDistributionApplyCosineProduct);
// def_method(pglSurfaceSamplingDistributionSupportsApplyCosineProduct);
// def_method(pglSurfaceSamplingDistributionSample);
// def_method(pglSurfaceSamplingDistributionPDF);
// def_method(pglSurfaceSamplingDistributionSamplePDF);
// def_method(pglSurfaceSamplingDistributionIncomingRadiancePDF);
// def_method(pglSurfaceSamplingDistributionValidate);
// def_method(pglSurfaceSamplingDistributionClear);
// def_method(pglSurfaceSamplingGetRegion);

// volumesamplingdistribution.h
PGL_PY_STRUCT(PGLVolumeSamplingDistribution);
// def_method(pglReleaseVolumeSamplingDistribution);
// def_method(pglVolumeSamplingDistributionSample);
// def_method(pglVolumeSamplingDistributionPDF);
// def_method(pglVolumeSamplingDistributionSamplePDF);
// def_method(pglVolumeSamplingDistributionIncomingRadiancePDF);
// def_method(pglVolumeSamplingDistributionValidate);
// def_method(pglVolumeSamplingDistributionClear);
// def_method(pglVolumeSamplingDistributionApplySingleLobeHenyeyGreensteinProduct);
// def_method(pglVolumeSamplingDistributionSupportsApplySingleLobeHenyeyGreensteinProduct);
// def_method(pglVolumeSamplingGetRegion);

}