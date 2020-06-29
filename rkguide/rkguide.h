// Copyright 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#pragma once


#include <embree/common/math/vec2.h>
#include <embree/common/math/vec3.h>

namespace rkguide
{

    typedef embree::Vec2<float> Vector2;
    typedef embree::Vec3<float> Vector3;

    template <int VecSize>
    inline float sum( const embree::vfloat<VecSize> &v)
    {
        float sum = 0.0f;
        for ( int i = 0; i < VecSize; i++)
        {
            sum += v[i];
        }
        return sum;
    }


    inline Vector2 toSphericalCoordinates(const Vector3 &v) {
        Vector2 result(
            std::acos(v.z),
            std::atan2(v.y, v.x)
        );
        if (result.y < 0)
            result.y += 2*M_PI;
        return result;
    }

    inline Vector3 sphericalDirection(const float &cosTheta, const float &sinTheta, const float &cosPhi, const float &sinPhi)
    {
        return Vector3( sinTheta * cosPhi,
	        		    sinTheta * sinPhi,
					    cosTheta);
    };

    inline Vector3 sphericalDirection(const float &theta, const float &phi)
    {
        const float cosTheta = std::cos(theta);
        const float sinTheta = std::sin(theta);
        const float cosPhi = std::cos(phi);
        const float sinPhi = std::sin(phi);

        return sphericalDirection(cosTheta, sinTheta, cosPhi, sinPhi);
    };

    inline Vector3 squareToUniformSphere(const Vector2 sample){
        float z = 1.0f - 2.0f * sample.y;
        float r = std::sqrt(std::max(0.f,(1.0f - z*z)));
        float sinPhi, cosPhi;
        sincosf(2.0f * M_PI * sample.x, &sinPhi, &cosPhi);
        return Vector3(r * cosPhi, r * sinPhi, z);
    }

}