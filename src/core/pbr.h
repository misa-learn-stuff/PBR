#ifndef CORE_PBR_H
#define CORE_PBR_H

// Global Include Files
#include <type_traits>
#include <algorithm>
#include <cinttypes>
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>
#include <assert.h>
#include <string.h>
#include <glog/logging.h>

namespace pbr {

// Global Constants
#ifdef _MSC_VER
#define MaxFloat std::numeric_limits<float>::max()
#define Infinity std::numeric_limits<float>::infinity()
#else
	static PBRT_CONSTEXPR Float MaxFloat = std::numeric_limits<Float>::max();
	static PBRT_CONSTEXPR Float Infinity = std::numeric_limits<Float>::infinity();
#endif

	inline float Lerp(float t, float v1, float v2) { return (1 - t) * v1 + t * v2; }

}  // namespace pbr

#endif  // CORE_PBR_H