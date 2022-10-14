#pragma once

#ifndef CORE_GEOMETRY_H
#define CORE_GEOMETRY_H

#include <assert.h>
#include "pbr.h"
using namespace std;

namespace pbr {

	template <typename T>
	inline bool isNaN(const T x) {
		return std::isnan(x);
	}
	
#pragma region Vector2

	// Vector Declarations
	template <typename T> class Vector2 {
	public:
		Vector2() { x = y = 0; }
		Vector2(T xx, T yy) : x(xx), y(yy) { assert(!hasNaNs()); }
		T operator[] (int i) const {
			assert(i >= 0 && i <= 1);
			if (i == 0) return x;
			else return y;
		}
		T& operator[] (int i) {
			assert(i >= 0 && i <= 1);
			if (i == 0) return x;
			else return y;
		}
		Vector2<T> operator- () const {
			return Vector2<T>(-x, -y);
		}
		Vector2<T> operator+ (const Vector2<T>& v) const {
			return Vector2<T>(x + v.x, y + v.y);
		}
		Vector2<T>& operator+= (const Vector2<T>& v) {
			x += v.x;
			y += v.y;
			return *this;
		}
		Vector2<T> operator- (const Vector2<T>& v) const {
			return Vector2<T>(x - v.x, y - v.y);
		}
		Vector2<T>& operator-= (const Vector2<T>& v) {
			x -= v.x;
			y -= v.y;
			return *this;
		}
		template <typename U>
		Vector2<T> operator* (U s) const {
			return Vector2<T>(x * s, y * s);
		}
		template <typename U>
		Vector2<T>& operator*= (U s) {
			x *= s;
			y *= s;
			return *this;
		}
		template <typename U>
		Vector2<T> operator/ (U f) const {
			assert(f != 0);
			float s = (float)1 / f;
			return Vector2(x * s, y * s);
		}
		template <typename U>
		Vector2<T>& operator/= (U f) {
			assert(f != 0);
			float s = (float)1 / f;
			x *= s;
			y *= s;
			return *this;
		}
		bool operator== (const Vector2<T>& v) const { return x == v.x && y == v.y; }
		bool operator!= (const Vector2<T>& v) const { return x != v.x || y != v.y; }
		bool hasNaNs() const { return isnan(x) || isnan(y); }
		float LengthSquared() const { return x * x + y * y; }
		float Length() const { return sqrt(LengthSquared()); }

		// Vector2 Public Data
		T x, y;
	};

	template <typename T> inline ostream& operator<<(ostream& os, const Vector2<T>& v) {
		os << "[ " << v.x << ", " << v.y << " ]";
		return os;
	}
	template<typename T, typename U> inline Vector2<T> operator* (U s, const Vector2<T>& v) { return v * s; }
	template<typename T> Vector2<T> inline Abs(const Vector2<T>& v) { return Vector2<T>(abs(v.x), abs(v.y)); }
	
	template<typename T> inline T Dot(const Vector2<T>& v1, const Vector2<T>& v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}
	template<typename T> inline T AbsDot(const Vector2<T>& v1, const Vector2<T>& v2) {
		return abs(Dot(v1, v2));
	}
	template<typename T> inline float Cross(const Vector2<T>& v1, const Vector2<T>& v2) {
		// Cross Product: (v x w)
		// (v x w) = v.x * w.y - v.y * w.x
		return (v1x * v2y) - (v1y * v2x);
	}
	template<typename T> inline Vector2<T> Normalize(const Vector2<T>& v) {
		return Vector2<T>(v / v.Length());
	}
	template<typename T> inline T MinComponent(const Vector2<T>& v) {
		return min(v.x, v.y);
	}
	template<typename T> inline T MaxComponent(const Vector2<T>& v) {
		return max(v.x, v.y);
	}
	template<typename T> inline Vector2<T> Min(const Vector2<T>& v1, const Vector2<T>& v2) {
		return Vector2<T>(min(v1.x, v2.x), min(v1.y, v2.y));
	}
	template<typename T> inline Vector2<T> Max(const Vector2<T>& v1, const Vector2<T>& v2) {
		return Vector2<T>(max(v1.x, v2.x), max(v1.y, v2.y));
	}
	template<typename T> inline Vector2<T> Permute(const Vector2<T>& v, int x, int y) {
		return Vector2<T>(v[x], v[y]);
	}
	template<typename T> inline int MaxDimension(const Vector2<T>& v) {
		return v.x > v.y ? 0 : 1;
	}

	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;

#pragma endregion Vector2

#pragma region Vector3

template <typename T> class Vector3 {
public:
	Vector3() { x = y = z = 0; }
	Vector3(T xx, T yy, T zz):x(xx), y(yy), z(zz) { assert(!hasNaNs()); }
	T operator[] (int i) const{
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		else if (i == 1) return y;
		else return z;
	}
	T& operator[] (int i) {
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		else if (i == 1) return y;
		else return z;
	}
	Vector3<T> operator- () const { 
		return Vector3<T>(-x, -y, -z); 
	}
	Vector3<T> operator+ (const Vector3<T>& v) const {
		return Vector3<T>(x + v.x, y + v.y, z + v.z);
	}
	Vector3<T>& operator+= (const Vector3<T>& v) {
		x += v.x; 
		y += v.y; 
		z += v.z;
		return *this;
	}
	Vector3<T> operator- (const Vector3<T>& v) const {
		return Vector3<T>(x - v.x, y - v.y, z - v.z);
	}
	Vector3<T>& operator-= (const Vector3<T>& v) {
		x -= v.x; 
		y -= v.y; 
		z -= v.z;
		return *this;
	}
	template<typename U>
	Vector3<T> operator* (U s) const {
		return Vector3<T>(x * s, y * s, z * s);
	}
	template<typename U>
	Vector3<T>& operator*= (U s) {
		x *= s; y *= s; z *= s;
		return *this;
	}
	template<typename U>
	Vector3<T> operator/ (U f) const {
		assert(f != 0);
		float s = (float)1 / f;
		return Vector3<T>(x * s, y * s, z * s);
	}
	template<typename U>
	Vector3<T>& operator/= (U f) {
		assert(f != 0);
		float s = (float)1 / f;
		x *= s; y *= s; z *= s;
		return *this;
	}
	bool operator== (const Vector3<T> v) const { return x == v.x && y == v.y && z == v.z; }
	bool operator!= (const Vector3<T> v) const { return x != v.x || y != v.y || z != v.z; }
	bool hasNaNs() const { return isnan(x) || isnan(y) || isnan(z); }
	float LengthSquared() const { return x * x + y * y + z * z; }
	float Length() const { return sqrt(LengthSquared()); }

	// Vector3 Public Data
	T x, y, z;
};

template <typename T> inline ostream& operator<<(ostream& os, const Vector3<T>& v) {
	os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
	return os;
}
template<typename T, typename U> inline Vector3<T> operator* (U s, const Vector3<T>& v) { return v * s; }
template<typename T> inline Vector3<T> Abs(const Vector3<T>& v) { return Vector3<T>(abs(v.x), abs(v.y), abs(v.z)); }
template<typename T> inline T Dot(const Vector3<T>& v1, const Vector3<T>& v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}
template<typename T> inline T AbsDot(const Vector3<T>& v1, const Vector3<T>& v2) {
	return abs(Dot(v1, v2));
}
template<typename T> inline Vector3<T> Cross(const Vector3<T>& v1, const Vector3<T>& v2) {
	// Cross Product: (v x w)
	// (v x w).x = v.y * w.z - v.z * w.y
	// (v x w).y = v.z * w.x - v.x * w.z
	// (v x w).z = v.x * w.y - v.y * w.x
	double v1x = v1.x, v1y = v1.y, v1z = v1.z;
	double v2x = v2.x, v2y = v2.y, v2z = v2.z;
	return Vector3<T>(
		(v1y * v2z) - (v1z * v2y),
		(v1z * v2x) - (v1x * v2z),
		(v1x * v2y) - (v1y * v2x);
	);
}
template<typename T> inline Vector3<T> Normalize(const Vector3<T>& v) {
	return Vector2<T>(v / v.Length());
}
template<typename T> inline T MinComponent(const Vector3<T>& v) {
	return min(v.x, v.y, v.z);
}
template<typename T> inline T MaxComponent(const Vector3<T>& v) {
	return max(v.x, v.y, v.z);
}
template<typename T> inline Vector3<T> Min(const Vector3<T>& v1, const Vector3<T>& v2) {
	return Vector3<T>(min(v1.x, v2.x), min(v1.y, v2.y), min(v1.z, v2.z));
}
template<typename T> inline Vector3<T> Max(const Vector3<T>& v1, const Vector3<T>& v2) {
	return Vector3<T>(max(v1.x, v2.x), max(v1.y, v2.y), max(v1.z, v2.z));
}
template<typename T> inline Vector3<T> Permute(const Vector3<T>& v, int x, int y) {
	return Vector3<T>(v[x], v[y], v[z]);
}
template<typename T> inline int MaxDimension(const Vector3<T>& v) {
	return v.x > v.y ? (v.x > v.z ? 0 : 2) : (v.y > v.z ? 1 : 2);
}

typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;

#pragma endregion Vector3

#pragma region Point2

template<typename T> class Point2 {
public:
	Point2() { x = y = 0; }
	Point2(T xx, T yy) :x(xx), y(yy) { }

	explicit Point2(const Vector2<T>& v) :x(v.x), y(v.y) { assert(!hasNaNs()); }
	//explicit Point2(const Point3<T>& p) :x(p.x), y(p.y) { assert(!hasNaNs()); }

	template<typename U> explicit Point2(const Point2<U>& p) :x((T)p.x), y((T)p.y) { assert(!hasNaNs()); }
	template<typename U> explicit Point2(const Vector2<U>& v) :x((T)v.x), y((T)v.y) { assert(!hasNaNs()); }
	template <typename U> explicit operator Vector2<U>() const { return Vector2<U>(x, y); }
	
	T operator[] (int i) const {
		assert(i >= 0 && i <= 1);
		if (i == 0) return x;
		else return y;
	}
	T& operator[] (int i) {
		assert(i >= 0 && i <= 1);
		if (i == 0) return x;
		else return y;
	}
	Point2<T> operator- () const {
		return Point2<T>(-x, -y);
	}
	Point2<T> operator+ (const Vector2<T>& v) const {
		assert(!v.hasNaNs());
		return Point2<T>(x + v.x, y + v.y);
	}
	Point2<T> operator+ (const Point2<T>& p) const {
		assert(!p.hasNaNs());
		return Point2<T>(x + p.x, y + p.y);
	}
	Point2<T>& operator+= (const Vector2<T>& v) {
		assert(!v.hasNaNs());
		x += v.x;
		y += v.y;
		return *this;
	}
	Point2<T>& operator+= (const Point2<T>& p) {
		assert(!p.hasNaNs());
		x += p.x;
		y += p.y;
		return *this;
	}
	Vector2<T> operator- (const Point2<T>& p) const {
		assert(!p.hasNaNs());
		return Vector2<T>(x - p.x, y - p.y);
	}
	Point2<T> operator- (const Vector2<T>& v) const {
		assert(!v.hasNaNs());
		return Point2<T>(x - v.x, y - v.y);
	}
	Point2<T>& operator-= (const Vector2<T>& v) {
		assert(!v.hasNaNs());
		x -= v.x;
		y -= v.y;
		return *this;
	}
	template<typename U>
	Point2<T> operator* (U s) const {
		return Point2<T>(x * s, y * s);
	}
	template<typename U>
	Point2<T>& operator*= (U s) {
		x *= s;
		y *= s;
		return *this;
	}
	template<typename U>
	Point2<T> operator/ (U f) const {
		assert(f != 0);
		float s = (float)1 / f;
		return Point2<T>(x * s, y * s);
	}
	template<typename U>
	Point2<T>& operator/= (U f) {
		assert(f != 0);
		float s = (float)1 / f;
		x *= s;
		y *= s;
		return *this;
	}
	bool hasNaNs() const { return isnan(x) || isnan(y); }
	bool operator== (const Point2<T> v) const { return x == v.x && y == v.y; }
	bool operator!= (const Point2<T> v) const { return x != v.x || y != v.y; }

	T x, y;
};

template <typename T> inline ostream& operator<<(ostream& os, const Point2<T>& p) {
	os << "[ " << p.x << ", " << p.y << " ]";
	return os;
}
template<typename T, typename U> inline Point2<T> operator* (U s, const Point2<T>& p) { return p * s; }

typedef Point2<float> Point2f;
typedef Point2<int> Point2i;

#pragma endregion Point2

#pragma region Point3

template<typename T> class Point3 {
public:
	Point3() { x = y = z = 0; }
	Point3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) { }

	explicit Point3(const Vector3<T>& v) :x(v.x), y(v.y), z(v.z) { assert(!hasNaNs()); }
	//explicit Point3(const Point2<T>& p) :x(p.x), y(p.y) { assert(!hasNaNs()); }

	template<typename U> explicit Point3(const Point3<U>& p) :x((T)p.x), y((T)p.y), z((T)p.z) { assert(!hasNaNs()); }
	template<typename U> explicit Point3(const Vector3<U>& v) :x((T)v.x), y((T)v.y), z((T)v.y) { assert(!hasNaNs()); }
	template <typename U> explicit operator Vector3<U>() const { return Vector3<U>(x, y, z); }

	T operator[] (int i) const {
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		else if (i == 1) return y;
		else return z;
	}
	T& operator[] (int i) {
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		else if (i == 1) return y;
		else return z;
	}
	Point3<T> operator- () const {
		return Point3<T>(-x, -y, -z);
	}
	Point3<T> operator+ (const Vector3<T>& v) const {
		assert(!v.hasNaNs());
		return Point3<T>(x + v.x, y + v.y, z + v.z);
	}
	Point3<T> operator+ (const Point3<T>& p) const {
		assert(!p.hasNaNs());
		return Point3<T>(x + p.x, y + p.y, z + p.z);
	}
	Point3<T>& operator+= (const Vector3<T>& v) {
		assert(!v.hasNaNs());
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Point3<T>& operator+= (const Point3<T>& p) {
		assert(!p.hasNaNs());
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}
	Vector3<T> operator- (const Point3<T>& p) const {
		assert(!p.hasNaNs());
		return Vector3<T>(x - p.x, y - p.y, z - p.z);
	}
	Point3<T> operator- (const Vector3<T>& v) const {
		assert(!v.hasNaNs());
		return Point3<T>(x - v.x, y - v.y, z - v.z);
	}
	Point3<T>& operator-= (const Vector3<T>& v) {
		assert(!v.hasNaNs());
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	template<typename U>
	Point3<T> operator* (U s) const {
		return Point3<T>(x * s, y * s, z * s);
	}
	template<typename U>
	Point3<T>& operator*= (U s) {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	template<typename U>
	Point3<T> operator/ (U f) const {
		assert(f != 0);
		float s = (float)1 / f;
		return Point3<T>(x * s, y * s, z * s);
	}
	template<typename U>
	Point3<T>& operator/= (U f) {
		assert(f != 0);
		float s = (float)1 / f;
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	bool hasNaNs() const { return isnan(x) || isnan(y); }
	bool operator== (const Point3<T> p) const { return x == p.x && y == p.y && z == p.z; }
	bool operator!= (const Point3<T> p) const { return x != p.x || y != p.y || z != p.z; }

	T x, y, z;
};

template <typename T> inline ostream& operator<<(ostream& os, const Point3<T>& p) {
	os << "[ " << p.x << ", " << p.y << " ]";
	return os;
}
template<typename T, typename U> inline Point3<T> operator* (U s, const Point3<T>& p) { return p * s; }

typedef Point3<float> Point3f;
typedef Point3<int> Point3i;

#pragma endregion Point3

#pragma region Normal3

template<typename T> class Normal3 {
public:
	Normal3() { x = y = z = 0; }
	Normal3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) { }

	explicit Normal3(const Vector3<T>& v) :x(v.x), y(v.y), z(v.z) { assert(!hasNaNs()); }

	T operator[] (int i) const {
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		else if (i == 1) return y;
		else return z;
	}
	T& operator[] (int i) {
		assert(i >= 0 && i <= 2);
		if (i == 0) return x;
		else if (i == 1) return y;
		else return z;
	}
	Normal3<T> operator- () const {
		return Normal3<T>(-x, -y, -z);
	}
	Normal3<T> operator+ (const Normal3<T>& p) const {
		assert(!p.hasNaNs());
		return Normal3<T>(x + p.x, y + p.y, z + p.z);
	}
	Normal3<T>& operator+= (const Normal3<T>& p) {
		assert(!p.hasNaNs());
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}
	Normal3<T> operator- (const Normal3<T>& v) const {
		assert(!v.hasNaNs());
		return Normal3<T>(x - v.x, y - v.y, z - v.z);
	}
	Normal3<T>& operator-= (const Normal3<T>& v) {
		assert(!v.hasNaNs());
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	template<typename U>
	Normal3<T> operator* (U s) const {
		return Normal3<T>(x * s, y * s, z * s);
	}
	template<typename U>
	Normal3<T>& operator*= (U s) {
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	template<typename U>
	Normal3<T> operator/ (U f) const {
		assert(f != 0);
		float s = (float)1 / f;
		return Normal3<T>(x * s, y * s, z * s);
	}
	template<typename U>
	Normal3<T>& operator/= (U f) {
		assert(f != 0);
		float s = (float)1 / f;
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}
	bool hasNaNs() const { return isnan(x) || isnan(y); }
	bool operator== (const Normal3<T> p) const { return x == p.x && y == p.y && z == p.z; }
	bool operator!= (const Normal3<T> p) const { return x != p.x || y != p.y || z != p.z; }

	T x, y, z;
};

template <typename T> inline ostream& operator<<(ostream& os, const Normal3<T>& p) {
	os << "[ " << p.x << ", " << p.y << " ]";
	return os;
}
template<typename T, typename U> inline Normal3<T> operator* (U s, const Normal3<T>& p) { return p * s; }

typedef Normal3<float> Normal3f;
typedef Normal3<int> Normal3i;

#pragma endregion Normal3

#pragma region Bounds2

#pragma endregion Bounds2

#pragma region Bounds3

#pragma endregion Bounds3

#pragma region Ray

#pragma endregion Ray

#pragma region RayDifferential

#pragma endregion RayDifferential

};

#endif  // CORE_GEOMETRY_H