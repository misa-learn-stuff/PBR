#pragma once

#ifndef CORE_GEOMETRY_H
#define CORE_GEOMETRY_H

#include <assert.h>
#include "pbr.h"
using namespace std;

namespace pbr {

	template <typename T> inline bool isNaN(const T x) { return std::isnan(x); }
	template <> inline bool isNaN(const int x) { return false; }

	template <typename T> class Point2;
	template <typename T> class Point3;
	template <typename T> class Normal3;

#pragma region Vector2

	// Vector Declarations
	template <typename T> class Vector2 {
	public:
		Vector2() { x = y = 0; }
		Vector2(T xx, T yy) : x(xx), y(yy) { DCHECK(!HasNaNs()); }
		explicit Vector2(const Point2<T>& p);
		explicit Vector2(const Point3<T>& p);
		bool HasNaNs() const { return isNaN(x) || isNaN(y); }
		T operator[] (int i) const {
			DCHECK(i >= 0 && i <= 1);
			if (i == 0) return x;
			else return y;
		}
		T& operator[] (int i) {
			DCHECK(i >= 0 && i <= 1);
			if (i == 0) return x;
			else return y;
		}
		Vector2<T> operator- () const {
			return Vector2<T>(-x, -y);
		}
		Vector2<T> operator+ (const Vector2<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Vector2<T>(x + v.x, y + v.y);
		}
		Vector2<T>& operator+= (const Vector2<T>& v) {
			DCHECK(!v.HasNaNs());
			x += v.x;
			y += v.y;
			return *this;
		}
		Vector2<T> operator- (const Vector2<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Vector2<T>(x - v.x, y - v.y);
		}
		Vector2<T>& operator-= (const Vector2<T>& v) {
			DCHECK(!v.HasNaNs());
			x -= v.x;
			y -= v.y;
			return *this;
		}
		template <typename U>
		Vector2<T> operator* (U s) const {
			DCHECK(!isNaN(s));
			return Vector2<T>((T)(x * s), (T)(y * s));
		}
		template <typename U>
		Vector2<T>& operator*= (U s) {
			DCHECK(!isNaN(s));
			x *= s;
			y *= s;
			return *this;
		}
		template <typename U>
		Vector2<T> operator/ (U f) const {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			return Vector2(x * s, y * s);
		}
		template <typename U>
		Vector2<T>& operator/= (U f) {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			x *= s;
			y *= s;
			return *this;
		}
		bool operator== (const Vector2<T>& v) const { return x == v.x && y == v.y; }
		bool operator!= (const Vector2<T>& v) const { return x != v.x || y != v.y; }
		float LengthSquared() const { return x * x + y * y; }
		float Length() const { return sqrt(LengthSquared()); }

		// Vector2 Public Data
		T x, y;
	};

	template<typename T> Vector2<T>::Vector2(const Point2<T>& p) : x(p.x), y(p.y) { DCHECK(!HasNaNs()); }
	template<typename T> Vector2<T>::Vector2(const Point3<T>& p) : x(p.x), y(p.y) { DCHECK(!HasNaNs()); }
	template <typename T> inline ostream& operator<<(ostream& os, const Vector2<T>& v) {
		os << "[ " << v.x << ", " << v.y << " ]";
		return os;
	}
	template<typename T, typename U> inline Vector2<T> operator* (U s, const Vector2<T>& v) {
		DCHECK(!v.HasNaNs());
		return v * s; 
	}
	template<typename T> Vector2<T> inline Abs(const Vector2<T>& v) {
		DCHECK(!v.HasNaNs());
		return Vector2<T>(abs(v.x), abs(v.y)); 
	}
	template<typename T> inline T Dot(const Vector2<T>& v1, const Vector2<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		return v1.x * v2.x + v1.y * v2.y; 
	}
	template<typename T> inline T AbsDot(const Vector2<T>& v1, const Vector2<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		return abs(Dot(v1, v2)); 
	}
	template<typename T> inline Vector2<T> Normalize(const Vector2<T>& v) {
		DCHECK(!v.HasNaNs());
		return Vector2<T>(v / v.Length()); 
	}
	template<typename T> inline T MinComponent(const Vector2<T>& v) {
		DCHECK(!v.HasNaNs());
		return std::min(v.x, v.y); 
	}
	template<typename T> inline T MaxComponent(const Vector2<T>& v) {
		DCHECK(!v.HasNaNs());
		return std::max(v.x, v.y); 
	}
	template<typename T> inline Vector2<T> Permute(const Vector2<T>& v, int x, int y) {
		DCHECK(!v.HasNaNs());
		return Vector2<T>(v[x], v[y]); 
	}
	template<typename T> inline int MaxDimension(const Vector2<T>& v) {
		DCHECK(!v.HasNaNs());
		return v.x > v.y ? 0 : 1; 
	}
	template<typename T> inline float Cross(const Vector2<T>& v1, const Vector2<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		// Cross Product: (v x w)
		// (v x w) = v.x * w.y - v.y * w.x
		return (v1x * v2y) - (v1y * v2x);
	}
	template<typename T> inline Vector2<T> Max(const Vector2<T>& v1, const Vector2<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		return Vector2<T>(std::max(v1.x, v2.x), std::max(v1.y, v2.y));
	}
	template<typename T> inline Vector2<T> Min(const Vector2<T>& v1, const Vector2<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		return Vector2<T>(std::min(v1.x, v2.x), std::min(v1.y, v2.y));
	}

	typedef Vector2<float> Vector2f;
	typedef Vector2<int> Vector2i;

#pragma endregion Vector2

#pragma region Vector3

	template <typename T> class Vector3 {
	public:
		Vector3() { x = y = z = 0; }
		Vector3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) { DCHECK(!HasNaNs()); }
		explicit Vector3(const Point3<T>& p);
		explicit Vector3(const Normal3<T>& n);
		bool HasNaNs() const { return isNaN(x) || isNaN(y) || isNaN(z); }
		T operator[] (int i) const {
			DCHECK(i >= 0 && i <= 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}
		T& operator[] (int i) {
			DCHECK(i >= 0 && i <= 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}
		Vector3<T> operator- () const {
			return Vector3<T>(-x, -y, -z);
		}
		Vector3<T> operator+ (const Vector3<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Vector3<T>(x + v.x, y + v.y, z + v.z);
		}
		Vector3<T>& operator+= (const Vector3<T>& v) {
			DCHECK(!v.HasNaNs());
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		Vector3<T> operator- (const Vector3<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Vector3<T>(x - v.x, y - v.y, z - v.z);
		}
		Vector3<T>& operator-= (const Vector3<T>& v) {
			DCHECK(!v.HasNaNs());
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		template<typename U>
		Vector3<T> operator* (U s) const {
			DCHECK(!isNaN(s));
			return Vector3<T>((T)(x * s), (T)(y * s), (T)(z * s));
		}
		template<typename U>
		Vector3<T>& operator*= (U s) {
			DCHECK(!isNaN(s));
			x *= s; y *= s; z *= s;
			return *this;
		}
		template<typename U>
		Vector3<T> operator/ (U f) const {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			return Vector3<T>(x * s, y * s, z * s);
		}
		template<typename U>
		Vector3<T>& operator/= (U f) {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			x *= s; y *= s; z *= s;
			return *this;
		}
		bool operator== (const Vector3<T> v) const { return x == v.x && y == v.y && z == v.z; }
		bool operator!= (const Vector3<T> v) const { return x != v.x || y != v.y || z != v.z; }
		float LengthSquared() const { return x * x + y * y + z * z; }
		float Length() const { return sqrt(LengthSquared()); }

		// Vector3 Public Data
		T x, y, z;
	};

	template<typename T> Vector3<T>::Vector3(const Point3<T>& p) : x(p.x), y(p.y), z(p.z) {}
	template<typename T> Vector3<T>::Vector3(const Normal3<T>& n) : x(n.x), y(n.y), z(n.z) {}
	template <typename T> inline ostream& operator<<(ostream& os, const Vector3<T>& v) {
		os << "[ " << v.x << ", " << v.y << ", " << v.z << " ]";
		return os;
	}
	template<typename T, typename U> inline Vector3<T> operator* (U s, const Vector3<T>& v) {
		DCHECK(!v.HasNaNs());
		return v * s; 
	}
	template<typename T> inline Vector3<T> Abs(const Vector3<T>& v) {
		DCHECK(!v.HasNaNs());
		return Vector3<T>(abs(v.x), abs(v.y), abs(v.z)); 
	}
	template<typename T> inline T Dot(const Vector3<T>& v1, const Vector3<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
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
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		double v1x = v1.x, v1y = v1.y, v1z = v1.z;
		double v2x = v2.x, v2y = v2.y, v2z = v2.z;
		return Vector3<T>(
			(v1y * v2z) - (v1z * v2y),
			(v1z * v2x) - (v1x * v2z),
			(v1x * v2y) - (v1y * v2x);
		);
	}
	template<typename T> inline Vector3<T> Cross(const Vector3<T>& v1, const Normal3<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		double v1x = v1.x, v1y = v1.y, v1z = v1.z;
		double v2x = v2.x, v2y = v2.y, v2z = v2.z;
		return Vector3<T>(
			(v1y * v2z) - (v1z * v2y),
			(v1z * v2x) - (v1x * v2z),
			(v1x * v2y) - (v1y * v2x);
		);
	}
	template<typename T> inline Vector3<T> Cross(const Normal3<T>& v1, const Vector3<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		double v1x = v1.x, v1y = v1.y, v1z = v1.z;
		double v2x = v2.x, v2y = v2.y, v2z = v2.z;
		return Vector3<T>(
			(v1y * v2z) - (v1z * v2y),
			(v1z * v2x) - (v1x * v2z),
			(v1x * v2y) - (v1y * v2x);
		);
	}
	template<typename T> inline Vector3<T> Normalize(const Vector3<T>& v) {
		DCHECK(!v.HasNaNs());
		return Vector2<T>(v / v.Length());
	}
	template<typename T> inline T MinComponent(const Vector3<T>& v) {
		DCHECK(!v.HasNaNs());
		return min(v.x, v.y, v.z);
	}
	template<typename T> inline T MaxComponent(const Vector3<T>& v) {
		DCHECK(!v.HasNaNs());
		return max(v.x, v.y, v.z);
	}
	template<typename T> inline Vector3<T> Permute(const Vector3<T>& v, int x, int y) {
		DCHECK(!v.HasNaNs());
		return Vector3<T>(v[x], v[y], v[z]);
	}
	template<typename T> inline int MaxDimension(const Vector3<T>& v) {
		DCHECK(!v.HasNaNs());
		return v.x > v.y ? (v.x > v.z ? 0 : 2) : (v.y > v.z ? 1 : 2);
	}
	template<typename T> inline Vector3<T> Max(const Vector3<T>& v1, const Vector3<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		return Vector2<T>(std::max(v1.x, v2.x), std::max(v1.y, v2.y), std::max(v1.z, v2.z));
	}
	template<typename T> inline Vector3<T> Min(const Vector3<T>& v1, const Vector3<T>& v2) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs());
		return Vector2<T>(std::min(v1.x, v2.x), std::min(v1.y, v2.y), std::min(v1.z, v2.z));
	}
	template <typename T> inline void CoordinateSystem(
		const Vector3<T>& v1, Vector3<T>* v2, Vector3<T>* v3) {
		DCHECK(!v1.HasNaNs() && !v2.HasNaNs() && !v3.HasNaNs());
		if (std::abs(v1.x) > std::abs(v1.y))
			*v2 = Vector3<T>(-v1.z, 0, v1.x) / std::sqrt(v1.x * v1.x + v1.z * v1.z);
		else
			*v2 = Vector3<T>(0, v1.z, -v1.y) / std::sqrt(v1.y * v1.y + v1.z * v1.z);
		*v3 = Cross(v1, *v2);
	}

	typedef Vector3<float> Vector3f;
	typedef Vector3<int> Vector3i;

#pragma endregion Vector3

#pragma region Point2

	template<typename T> class Point2 {
	public:
		Point2() { x = y = 0; }
		Point2(T xx, T yy) :x(xx), y(yy) { DCHECK(!HasNaNs()); }

		explicit Point2(const Vector2<T>& v) :x(v.x), y(v.y) { DCHECK(!HasNaNs()); }
		explicit Point2(const Point3<T>& p) :x(p.x), y(p.y) { DCHECK(!HasNaNs()); }

		template<typename U> explicit Point2(const Point2<U>& p) :x((T)p.x), y((T)p.y) { DCHECK(!HasNaNs()); }
		template<typename U> explicit Point2(const Vector2<U>& v) :x((T)v.x), y((T)v.y) { DCHECK(!HasNaNs()); }
		template<typename U> explicit operator Vector2<U>() const { return Vector2<U>((U)x, (U)y); }

		bool HasNaNs() const { return isNaN(x) || isNaN(y); }

		T operator[] (int i) const {
			DCHECK(i >= 0 && i <= 1);
			if (i == 0) return x;
			else return y;
		}
		T& operator[] (int i) {
			DCHECK(i >= 0 && i <= 1);
			if (i == 0) return x;
			else return y;
		}
		Point2<T> operator- () const {
			return Point2<T>(-x, -y);
		}
		Point2<T> operator+ (const Vector2<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Point2<T>(x + v.x, y + v.y);
		}
		Point2<T> operator+ (const Point2<T>& p) const {
			DCHECK(!p.HasNaNs());
			return Point2<T>(x + p.x, y + p.y);
		}
		Point2<T>& operator+= (const Vector2<T>& v) {
			DCHECK(!v.HasNaNs());
			x += v.x;
			y += v.y;
			return *this;
		}
		Point2<T>& operator+= (const Point2<T>& p) {
			DCHECK(!p.HasNaNs());
			x += p.x;
			y += p.y;
			return *this;
		}
		Vector2<T> operator- (const Point2<T>& p) const {
			DCHECK(!p.HasNaNs());
			return Vector2<T>(x - p.x, y - p.y);
		}
		Point2<T> operator- (const Vector2<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Point2<T>(x - v.x, y - v.y);
		}
		Point2<T>& operator-= (const Vector2<T>& v) {
			DCHECK(!v.HasNaNs());
			x -= v.x;
			y -= v.y;
			return *this;
		}
		template<typename U>
		Point2<T> operator* (U s) const {
			return Point2<T>((T)(x * s), (T)(y * s));
		}
		template<typename U>
		Point2<T>& operator*= (U s) {
			x *= s;
			y *= s;
			return *this;
		}
		template<typename U>
		Point2<T> operator/ (U f) const {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			return Point2<T>(x * s, y * s);
		}
		template<typename U>
		Point2<T>& operator/= (U f) {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			x *= s;
			y *= s;
			return *this;
		}
		bool operator== (const Point2<T> v) const { return x == v.x && y == v.y; }
		bool operator!= (const Point2<T> v) const { return x != v.x || y != v.y; }

		T x, y;
	};

	template <typename T> inline ostream& operator<<(ostream& os, const Point2<T>& p) {
		os << "[ " << p.x << ", " << p.y << " ]";
		return os;
	}
	template<typename T, typename U> inline Point2<T> operator* (U s, const Point2<T>& p) {
		DCHECK(!p.HasNaNs());
		return p * s; 
	}
	template <typename T> inline float Distance(const Point2<T>& p1, const Point2<T>& p2) {
		return (p1 - p2).Length();
	}
	template <typename T> inline float DistanceSquared(const Point2<T>& p1, const Point2<T>& p2) {
		return (p1 - p2).LengthSquared();
	}
	template<typename T> inline Point2<T> Max(const Point2<T>& p1, const Point2<T>& p2) {
		return Point2<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y));
	}
	template<typename T> inline Point2<T> Min(const Point2<T>& p1, const Point2<T>& p2) {
		return Point2<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y));
	}
	template <typename T> Point2<T> Floor(const Point2<T>& p) {
		return Point2<T>(std::floor(p.x), std::floor(p.y));
	}
	template <typename T> Point2<T> Ceil(const Point2<T>& p) {
		return Point2<T>(std::ceil(p.x), std::ceil(p.y));
	}
	template <typename T> Point2<T> Lerp(float t, const Point2<T>& v0, const Point2<T>& v1) {
		return (1 - t) * v0 + t * v1;
	}

	typedef Point2<float> Point2f;
	typedef Point2<int> Point2i;

#pragma endregion Point2

#pragma region Point3

	template<typename T> class Point3 {
	public:
		Point3() { x = y = z = 0; }
		Point3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) { DCHECK(!HasNaNs()); }

		explicit Point3(const Vector3<T>& v) :x(v.x), y(v.y), z(v.z) { DCHECK(!HasNaNs()); }
		explicit Point3(const Point2<T>& p) :x(p.x), y(p.y) { DCHECK(!HasNaNs()); }

		template<typename U> explicit Point3(const Point3<U>& p) :x((T)p.x), y((T)p.y), z((T)p.z) { DCHECK(!HasNaNs()); }
		template<typename U> explicit Point3(const Vector3<U>& v) :x((T)v.x), y((T)v.y), z((T)v.y) { DCHECK(!HasNaNs()); }
		template <typename U> explicit operator Vector3<U>() const { return Vector3<U>((U)x, (U)y, (U)z); }

		bool HasNaNs() const { return isNaN(x) || isNaN(y) || isNaN(z); }

		T operator[] (int i) const {
			DCHECK(i >= 0 && i <= 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}
		T& operator[] (int i) {
			DCHECK(i >= 0 && i <= 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}
		Point3<T> operator- () const {
			return Point3<T>(-x, -y, -z);
		}
		Point3<T> operator+ (const Vector3<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Point3<T>(x + v.x, y + v.y, z + v.z);
		}
		Point3<T> operator+ (const Point3<T>& p) const {
			DCHECK(!p.HasNaNs());
			return Point3<T>(x + p.x, y + p.y, z + p.z);
		}
		Point3<T>& operator+= (const Vector3<T>& v) {
			DCHECK(!v.HasNaNs());
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}
		Point3<T>& operator+= (const Point3<T>& p) {
			DCHECK(!p.HasNaNs());
			x += p.x;
			y += p.y;
			z += p.z;
			return *this;
		}
		Vector3<T> operator- (const Point3<T>& p) const {
			DCHECK(!p.HasNaNs());
			return Vector3<T>(x - p.x, y - p.y, z - p.z);
		}
		Point3<T> operator- (const Vector3<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Point3<T>(x - v.x, y - v.y, z - v.z);
		}
		Point3<T>& operator-= (const Vector3<T>& v) {
			DCHECK(!v.HasNaNs());
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		template<typename U>
		Point3<T> operator* (U s) const {
			DCHECK(!isNaN(s));
			return Point3<T>((T)(x * s), (T)(y * s), (T)(z * s));
		}
		template<typename U>
		Point3<T>& operator*= (U s) {
			DCHECK(!isNaN(s));
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}
		template<typename U>
		Point3<T> operator/ (U f) const {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			return Point3<T>(x * s, y * s, z * s);
		}
		template<typename U>
		Point3<T>& operator/= (U f) {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}
		bool operator== (const Point3<T> p) const { return x == p.x && y == p.y && z == p.z; }
		bool operator!= (const Point3<T> p) const { return x != p.x || y != p.y || z != p.z; }

		T x, y, z;
	};

	template <typename T> inline ostream& operator<<(ostream& os, const Point3<T>& p) {
		os << "[ " << p.x << ", " << p.y << " ]";
		return os;
	}
	template<typename T, typename U> inline Point3<T> operator* (U s, const Point3<T>& p) {
		DCHECK(!p.HasNaNs());
		return p * s; 
	}
	template <typename T> inline float Distance(const Point3<T>& p1, const Point3<T>& p2) {
		return (p1 - p2).Length();
	}
	template <typename T> inline float DistanceSquared(const Point3<T>& p1, const Point3<T>& p2) {
		return (p1 - p2).LengthSquared();
	}
	template<typename T> inline Point3<T> Max(const Point3<T>& p1, const Point3<T>& p2) {
		return Point3<T>(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z));
	}
	template<typename T> inline Point3<T> Min(const Point3<T>& p1, const Point3<T>& p2) {
		return Point3<T>(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z));
	}
	template <typename T> Point3<T> Permute(const Point3<T>& p, int x, int y, int z) {
		return Point3<T>(p[x], p[y], p[z]);
	}
	template <typename T> Point3<T> Floor(const Point3<T>& p) {
		return Point3<T>(std::floor(p.x), std::floor(p.y), std::floor(p.z));
	}
	template <typename T> Point3<T> Ceil(const Point3<T>& p) {
		return Point3<T>(std::ceil(p.x), std::ceil(p.y), std::ceil(p.z));
	}
	template <typename T> Point3<T> Abs(const Point3<T>& p) {
		return Point3<T>(std::abs(p.x), std::abs(p.y), std::abs(p.z));
	}

	typedef Point3<float> Point3f;
	typedef Point3<int> Point3i;

#pragma endregion Point3

#pragma region Normal3

	template<typename T> class Normal3 {
	public:
		Normal3() { x = y = z = 0; }
		Normal3(T xx, T yy, T zz) :x(xx), y(yy), z(zz) { DCHECK(!HasNaNs()); }
		explicit Normal3(const Vector3<T>& v) :x(v.x), y(v.y), z(v.z) { DCHECK(!HasNaNs()); }

		bool HasNaNs() const { return isNaN(x) || isNaN(y) || isNaN(z); }

		T operator[] (int i) const {
			DCHECK(i >= 0 && i <= 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}
		T& operator[] (int i) {
			DCHECK(i >= 0 && i <= 2);
			if (i == 0) return x;
			else if (i == 1) return y;
			else return z;
		}
		Normal3<T> operator- () const {
			return Normal3<T>(-x, -y, -z);
		}
		Normal3<T> operator+ (const Normal3<T>& p) const {
			DCHECK(!p.HasNaNs());
			return Normal3<T>(x + p.x, y + p.y, z + p.z);
		}
		Normal3<T>& operator+= (const Normal3<T>& p) {
			DCHECK(!p.HasNaNs());
			x += p.x;
			y += p.y;
			z += p.z;
			return *this;
		}
		Normal3<T> operator- (const Normal3<T>& v) const {
			DCHECK(!v.HasNaNs());
			return Normal3<T>(x - v.x, y - v.y, z - v.z);
		}
		Normal3<T>& operator-= (const Normal3<T>& v) {
			DCHECK(!v.HasNaNs());
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}
		template<typename U>
		Normal3<T> operator* (U s) const {
			DCHECK(!isNaN(s));
			return Normal3<T>((T)(x * s), (T)(y * s), (T)(z * s));
		}
		template<typename U>
		Normal3<T>& operator*= (U s) {
			DCHECK(!isNaN(s));
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}
		template<typename U>
		Normal3<T> operator/ (U f) const {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			return Normal3<T>(x * s, y * s, z * s);
		}
		template<typename U>
		Normal3<T>& operator/= (U f) {
			CHECK_NE(f, 0);
			float s = (float)1 / f;
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}
		bool operator== (const Normal3<T> p) const { return x == p.x && y == p.y && z == p.z; }
		bool operator!= (const Normal3<T> p) const { return x != p.x || y != p.y || z != p.z; }

		T x, y, z;
	};

	template <typename T> inline ostream& operator<<(ostream& os, const Normal3<T>& p) {
		os << "[ " << p.x << ", " << p.y << " ]";
		return os;
	}
	template<typename T, typename U> inline Normal3<T> operator* (U s, const Normal3<T>& p) { 
		return p * s; 
	}
	template <typename T> inline Normal3<T> Normalize(const Normal3<T>& n) {
		return n / n.Length();
	}
	template <typename T> inline T Dot(const Normal3<T>& n1, const Vector3<T>& v2) {
		DCHECK(!n1.HasNaNs() && !v2.HasNaNs());
		return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
	}
	template <typename T> inline T Dot(const Vector3<T>& v1, const Normal3<T>& n2) {
		DCHECK(!v1.HasNaNs() && !n2.HasNaNs());
		return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
	}
	template <typename T> inline T Dot(const Normal3<T>& n1, const Normal3<T>& n2) {
		DCHECK(!n1.HasNaNs() && !n2.HasNaNs());
		return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
	}
	template <typename T> inline T AbsDot(const Normal3<T>& n1, const Vector3<T>& v2) {
		DCHECK(!n1.HasNaNs() && !v2.HasNaNs());
		return std::abs(n1.x * v2.x + n1.y * v2.y + n1.z * v2.z);
	}
	template <typename T> inline T AbsDot(const Vector3<T>& v1, const Normal3<T>& n2) {
		DCHECK(!v1.HasNaNs() && !n2.HasNaNs());
		return std::abs(v1.x * n2.x + v1.y * n2.y + v1.z * n2.z);
	}
	template <typename T> inline T AbsDot(const Normal3<T>& n1, const Normal3<T>& n2) {
		DCHECK(!n1.HasNaNs() && !n2.HasNaNs());
		return std::abs(n1.x * n2.x + n1.y * n2.y + n1.z * n2.z);
	}
	template <typename T> inline Normal3<T> Faceforward(const Normal3<T>& n, const Vector3<T>& v) {
		return (Dot(n, v) < 0.f) ? -n : n;
	}
	template <typename T> inline Normal3<T> Faceforward(const Normal3<T>& n, const Normal3<T>& n2) {
		return (Dot(n, n2) < 0.f) ? -n : n;
	}
	template <typename T> inline Vector3<T> Faceforward(const Vector3<T>& v, const Vector3<T>& v2) {
		return (Dot(v, v2) < 0.f) ? -v : v;
	}
	template <typename T> inline Vector3<T> Faceforward(const Vector3<T>& v, const Normal3<T>& n2) {
		return (Dot(v, n2) < 0.f) ? -v : v;
	}
	template <typename T> Normal3<T> Abs(const Normal3<T>& v) {
		return Normal3<T>(std::abs(v.x), std::abs(v.y), std::abs(v.z));
	}

	typedef Normal3<float> Normal3f;

#pragma endregion Normal3

#pragma region Bounds2

	template<typename T> class Bounds2 {
	public:
		Bounds2() {
			T minNum = numeric_limits<T>::lowest();
			T maxNum = numeric_limits<T>::max();
			pMin = Point2<T>(minNum, minNum);
			pMax = Point2<T>(maxNum, maxNum);
		}
		Bounds2(const Point2<T>& p1, const Point2<T>& p2)
			: pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y))
			, pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y)) {}

		explicit Bounds2(const Point2<T>& p) : pMin(p), pMax(p) {}
		template <typename U> explicit operator Bounds2<U>() const {
			return Bounds2<U>((Point2<U>)pMin, (Point2<U>)pMax);
		}

		inline const Point2<T>& operator[](int i) const {
			DCHECK(i == 0 || i == 1);
			return (i == 0) ? pMin : pMax;
		}

		inline Point2<T>& operator[](int i) {
			DCHECK(i == 0 || i == 1);
			return (i == 0) ? pMin : pMax;
		}

		Vector2<T> Diagonal() const { return pMax - pMin; }

		T SurfaceArea() const {
			Vector2<T> d = Diagonal();
			return d.x * d.y;
		}

		int MaximumExtent() const {
			Vector2<T> d = Diagonal();
			if (d.x > d.y) return 0;
			else return 1;
		}

		bool operator==(const Bounds2<T>& b) const {
			return b.pMin == pMin && b.pMax == pMax;
		}

		bool operator!=(const Bounds2<T>& b) const {
			return b.pMin != pMin || b.pMax != pMax;
		}

		Point2<T> Lerp(const Point2f& t) const {
			return Point2<T>(pbr::Lerp(t.x, pMin.x, pMax.x), pbr::Lerp(t.y, pMin.y, pMax.y));
		}

		Vector2<T> Offset(const Point2<T>& p) const {
			Vector2<T> o = p - pMin;
			o.x /= (pMax.x - pMin.x);
			o.y /= (pMax.y - pMin.y);
			return o;
		}

		void BoundingSphere(Point2<T>* center, float* radius) const {
			*center = (Point2<T>)((pMax + pMin) / 2);
			*radius = Inside(*center, *this) ? Distance(*center, pMax) : 0;
		}

	public:
		Point2<T> pMin;
		Point2<T> pMax;
	};

	typedef Bounds2<float> Bounds2f;
	typedef Bounds2<int> Bounds2i;

	template<typename T> std::ostream& operator<<(std::ostream& os, const Bounds2<T>& b) {
		os << "[ " << b.pMin << " - " << b.pMax << " ]";
		return os;
	}

	template <typename T> Bounds2<T> Union(const Bounds2<T>& b, const Point2<T>& p) {
		// Important: assign to pMin/pMax directly and don't run the Bounds2()
		// constructor, since it takes min/max of the points passed to it.  In
		// turn, that breaks returning an invalid bound for the case where we
		// intersect non-overlapping bounds (as we'd like to happen).
		Bounds2<T> ret;
		ret.pMin = Min(b.pMin, p);
		ret.pMax = Max(b.pMax, p);
		return ret;
	}

	template <typename T> Bounds2<T> Union(const Bounds2<T>& b, const Bounds2<T>& b2) {
		Bounds2<T> ret;
		ret.pMin = Min(b.pMin, b2.pMin);
		ret.pMax = Max(b.pMax, b2.pMax);
		return ret;
	}

	template<typename T> Bounds2<T> Intersect(const Bounds2<T>& b1, const Bounds2<T>& b2) {
		// Important: assign to pMin/pMax directly and don't run the Bounds2()
		// constructor, since it takes min/max of the points passed to it.  In
		// turn, that breaks returning an invalid bound for the case where we
		// intersect non-overlapping bounds (as we'd like to happen).
		Bounds2<T> ret;
		ret.pMin = Max(b1.pMin, b2.pMin);
		ret.pMax = Min(b1.pMax, b2.pMax);
		return ret;
	}

	template<typename T> bool Overlap(const Bounds2<T>& b1, const Bounds2<T>& b2) {
		bool x = b1.pMax.x >= b2.pMin.x && b1.pMin.x <= b2.pMax.x;
		bool y = b1.pMax.y >= b2.pMin.y && b1.pMin.y <= b2.pMax.y;
		return x && y;
	}

	template<typename T> bool Inside(const Point2<T>& p, const Bounds2<T> b) {
		return (p.x >= b.pMin.x && p.x <= b.pMax.x) &&
			(p.y >= b.pMin.y && p.y <= b.pMax.y);
	}

	template <typename T> bool InsideExclusive(const Point2<T>& pt, const Bounds2<T>& b) {
		return (pt.x >= b.pMin.x && pt.x < b.pMax.x&& pt.y >= b.pMin.y &&
			pt.y < b.pMax.y);
	}

	template<typename T, typename U> Bounds2<T> Expand(const Bounds2<T> b, const U delta) {
		return Bounds2<T>(b.pMin - Vector2<T>((T)delta, (T)delta), b.pMax + Vector2<T>((T)delta, (T)delta));
	}

#pragma endregion Bounds2

#pragma region Bounds3

	template<typename T> class Bounds3 {
	public:
		Bounds3() {
			T minNum = numeric_limits<T>::lowest();
			T maxNum = numeric_limits<T>::max();
			pMin = Point3<T>(minNum, minNum, minNum);
			pMax = Point3<T>(maxNum, maxNum, maxNum);
		}
		Bounds3(const Point3<T>& p1, const Point3<T>& p2)
			: pMin(std::min(p1.x, p2.x), std::min(p1.y, p2.y), std::min(p1.z, p2.z))
			, pMax(std::max(p1.x, p2.x), std::max(p1.y, p2.y), std::max(p1.z, p2.z)) {}

		explicit Bounds3(const Point3<T>& p) : pMin(p), pMax(p) {}
		template <typename U> explicit operator Bounds3<U>() const {
			return Bounds3<U>((Point3<U>)pMin, (Point3<U>)pMax);
		}

		inline const Point3<T>& operator[](int i) const {
			DCHECK(i == 0 || i == 1);
			return (i == 0) ? pMin : pMax;
		}

		inline Point3<T>& operator[](int i) {
			DCHECK(i == 0 || i == 1);
			return (i == 0) ? pMin : pMax;
		}

		Point3<T> Corner(int corner) const {
			DCHECK(corner >= 0 && corner < 8);
			return Point3<T>((*this)[(corner & 1)].x,
				(*this)[(corner & 2) ? 1 : 0].y,
				(*this)[(corner & 4) ? 1 : 0].z);
		}

		bool operator==(const Bounds3<T>& b) const {
			return b.pMin == pMin && b.pMax == pMax;
		}
		bool operator!=(const Bounds3<T>& b) const {
			return b.pMin != pMin || b.pMax != pMax;
		}

		Vector3<T> Diagonal() const { return pMax - pMin; }

		T SurfaceArea() const {
			Vector3<T> d = Diagonal();
			return d.x * d.y * d.z;
		}

		T Volume() const {
			Vector2<T> d = Diagonal();
			return d.x * d.y * d.z;
		}

		int MaximumExtent() const {
			Vector3<T> d = Diagonal();
			if (d.x > d.y && d.x > d.z) return 0;
			else if (d.y > d.z) return 1;
			else return 2;
		}

		Point3<T> Lerp(const Point3<T>& t) const {
			return Point3<T>(pbr::Lerp(t.x, pMin.x, pMax.x), pbr::Lerp(t.y, pMin.y, pMax.y), pbr::Lerp(t.z, pMin.z, pMax.z));
		}

		Vector3<T> Offset(const Point3<T>& p) const {
			Vector3<T> o = p - pMin;
			o.x /= (pMax.x - pMin.x);
			o.y /= (pMax.y - pMin.y);
			o.z /= (pMax.z - pMin.z);
			return o;
		}

		void BoundingSphere(Point3<T>* center, float* radius) const {
			*center = (Point3<T>)((pMax + pMin) / 2);
			*radius = Inside(*center, *this) ? Distance(*center, pMax) : 0;
		}

	public:
		Point3<T> pMin;
		Point3<T> pMax;
	};

	typedef Bounds3<float> Bounds3f;
	typedef Bounds3<int> Bounds3i;

	template<typename T> std::ostream& operator<<(std::ostream& os, const Bounds3<T>& b) {
		os << "[ " << b.pMin << " - " << b.pMax << " ]";
		return os;
	}

	template<typename T> Bounds3<T> Union(const Bounds3<T>& b1, const Bounds3<T>& b2) {
		// Important: assign to pMin/pMax directly and don't run the Bounds2()
		// constructor, since it takes min/max of the points passed to it.  In
		// turn, that breaks returning an invalid bound for the case where we
		// intersect non-overlapping bounds (as we'd like to happen).
		Bounds3<T> ret;
		ret.pMin = Min(b1.pMin, b2.pMin);
		ret.pMax = Max(b1.pMax, b2.pMax);
		return ret;
	}

	template<typename T> Bounds3<T> Union(const Bounds3<T>& b, const Point3<T>& p) {
		Bounds3<T> ret;
		ret.pMin = Min(b.pMin, p);
		ret.pMax = Max(b.pMax, p);
		return ret;
	}

	template<typename T> Bounds3<T> Intersect(const Bounds3<T>& b1, const Bounds3<T>& b2) {
		// Important: assign to pMin/pMax directly and don't run the Bounds2()
		// constructor, since it takes min/max of the points passed to it.  In
		// turn, that breaks returning an invalid bound for the case where we
		// intersect non-overlapping bounds (as we'd like to happen).
		Bounds3<T> ret;
		ret.pMin = Max(b1.pMin, b2.pMin);
		ret.pMax = Min(b1.pMax, b2.pMax);
		return ret;
	}

	template<typename T> bool Overlap(const Bounds3<T>& b1, const Bounds3<T>& b2) {
		bool x = b1.pMax.x >= b2.pMin.x && b1.pMin.x <= b2.pMax.x;
		bool y = b1.pMax.y >= b2.pMin.y && b1.pMin.y <= b2.pMax.y;
		bool z = b1.pMax.z >= b2.pMin.z && b1.pMin.z <= b2.pMax.z;
		return x && y && z;
	}

	template<typename T> bool Inside(const Point3<T>& p, const Bounds3<T> b) {
		return
			(p.x >= b.pMin.x && p.x <= b.pMax.x) &&
			(p.y >= b.pMin.y && p.y <= b.pMax.y) &&
			(p.z >= b.pMin.z && p.z <= b.pMax.z);
	}

	template <typename T> bool InsideExclusive(const Point3<T>& p, const Bounds3<T>& b) {
		return 
			(p.x >= b.pMin.x && p.x < b.pMax.x && p.y >= b.pMin.y &&
			p.y < b.pMax.y&& p.z >= b.pMin.z && p.z < b.pMax.z);
	}

	template<typename T, typename U> Bounds3<T> Expand(const Bounds3<T> b, const U delta) {
		return Bounds3<T>(
			b.pMin - Vector3<T>((T)delta, (T)delta, (T)delta), 
			b.pMax + Vector3<T>((T)delta, (T)delta, (T)delta));
	}

	// Minimum squared distance from point to box; returns zero if point is inside.
	template <typename T, typename U> inline float DistanceSquared(const Point3<T>& p, const Bounds3<U>& b) {
		Float dx = std::max({ Float(0), b.pMin.x - p.x, p.x - b.pMax.x });
		Float dy = std::max({ Float(0), b.pMin.y - p.y, p.y - b.pMax.y });
		Float dz = std::max({ Float(0), b.pMin.z - p.z, p.z - b.pMax.z });
		return dx * dx + dy * dy + dz * dz;
	}

	template <typename T, typename U> inline float Distance(const Point3<T>& p, const Bounds3<U>& b) {
		return std::sqrt(DistanceSquared(p, b));
	}

#pragma endregion Bounds3

#pragma region Ray

	class Ray {
		Ray() :tMax(Infinity), time(0.f) {}
		Ray(const Point3f& o, const Vector3f& d, float tMax = Infinity, float time = 0.f)
			: o(o), d(d), tMax(tMax), time(time) {}

		Point3f operator() (float t) {
			return o + d * t;
		}

	public:
		Point3f o;
		Vector3f d;
		mutable float tMax;
		float time;
	};

#pragma endregion Ray

#pragma region RayDifferential



#pragma endregion RayDifferential

}

#endif  // CORE_GEOMETRY_H