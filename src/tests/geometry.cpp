#include "tests/gtest/gtest.h"
#include "pbr.h"
#include "geometry.h"

using namespace pbr;

#pragma region Vector2

TEST(TestVector2, Initializer) {
	Vector2f vec1;
	EXPECT_EQ(0, vec1.x);
	EXPECT_EQ(0, vec1.y);

	const Vector2f vec2{1, 2};
	EXPECT_EQ(1, vec2.x);
	EXPECT_EQ(2, vec2.y);
}

TEST(TestVector2, Indexer) {
	const Vector2f vec1{5, 6};
	EXPECT_EQ(5, vec1[0]);
	EXPECT_EQ(6, vec1[1]);

	Vector2f vec2{ 1, 2 };
	vec2[0] = 7;
	EXPECT_EQ(7, vec2.x);
	EXPECT_EQ(2, vec2.y);
}

TEST(TestVector2, AddSubtract) {
	const Vector2f vec1{ 1, 2 };
	const Vector2f vec2{ 3, 4 };

	Vector2f vec3 = -vec2;
	EXPECT_EQ(-3, vec3.x);
	EXPECT_EQ(-4, vec3.y);

	Vector2f vec4 = vec1 + vec2;
	EXPECT_EQ(4, vec4.x);
	EXPECT_EQ(6, vec4.y);

	Vector2f vec5 = vec2 - vec1;
	EXPECT_EQ(2, vec5.x);
	EXPECT_EQ(2, vec5.y);

	vec5 += vec1;
	EXPECT_EQ(3, vec5.x);
	EXPECT_EQ(4, vec5.y);

	vec5 -= vec1;
	EXPECT_EQ(2, vec5.x);
	EXPECT_EQ(2, vec5.y);
}

TEST(TestVector2, Scale) {
	const Vector2f vec1{ 1, 2 };
	const Vector2f vec2{ 3, 4 };

	Vector2f vec3 = vec1 * 3;
	EXPECT_EQ(3, vec3[0]);
	EXPECT_EQ(6, vec3[1]);

	Vector2f vec4 = 2.0 * vec2;
	EXPECT_EQ(6, vec4[0]);
	EXPECT_EQ(8, vec4[1]);

	Vector2f vec5 = vec3 / 6;
	EXPECT_EQ(0.5, vec5[0]);
	EXPECT_EQ(1, vec5[1]);
}

TEST(TestVector2, Comparison) {
	const Vector2f vec1{ 1, 2 };
	const Vector2f vec2{ 3, 4 };
	const Vector2f vec3{ 3, 3 };
	const Vector2f vec4{ 4, 4 };
	const Vector2f vec5{ 3, 4 };

	EXPECT_TRUE(vec1 == vec1);
	EXPECT_TRUE(vec2 == vec2);

	EXPECT_FALSE(vec1 == vec2);
	EXPECT_TRUE(vec1 != vec2);

	EXPECT_FALSE(vec2 == vec3);
	EXPECT_TRUE(vec2 != vec3);

	EXPECT_FALSE(vec2 == vec4);
	EXPECT_TRUE(vec2 != vec4);

	EXPECT_FALSE(vec2 != vec5);
	EXPECT_TRUE(vec2 == vec5);
}

TEST(TestVector2, Length) {
	const Vector2f vec1{ -1, 2 };
	const Vector2f vec2{ 3, -4 };

	float length = vec2.Length();
	EXPECT_EQ(length, 5);

	float lengthSquared = vec1.LengthSquared();
	EXPECT_EQ(lengthSquared, 5);
}

TEST(TestVector2, Absolute) {
	const Vector2f vec1{ -1, 2 };
	const Vector2f vec2{ 3, -4 };

	Vector2f vec3 = Abs(vec1);
	EXPECT_EQ(vec3.x, 1);
	EXPECT_EQ(vec3.y, 2);

	Vector2f vec4 = Abs(vec2);
	EXPECT_EQ(vec4.x, 3);
	EXPECT_EQ(vec4.y, 4);
}

#pragma endregion Vector2

#pragma region Vector3

TEST(TestVector3, Initializer) {
	Vector3f vec1;
	EXPECT_EQ(0, vec1.x);
	EXPECT_EQ(0, vec1.y);
	EXPECT_EQ(0, vec1.z);

	const Vector3f vec2{ 1, 2, 3 };
	EXPECT_EQ(1, vec2.x);
	EXPECT_EQ(2, vec2.y);
	EXPECT_EQ(3, vec2.z);
}

TEST(TestVector3, Indexer) {
	const Vector3f vec1{ 5, 6, 7 };
	EXPECT_EQ(5, vec1[0]);
	EXPECT_EQ(6, vec1[1]);
	EXPECT_EQ(7, vec1[2]);

	Vector3f vec2{ 1, 2, 3 };
	vec2[0] = 7;
	EXPECT_EQ(7, vec2.x);
	EXPECT_EQ(2, vec2.y);
	EXPECT_EQ(3, vec2.z);
}

TEST(TestVector3, AddSubtract) {
	const Vector3f vec1{ 1, 2, 3 };
	const Vector3f vec2{ 3, 4, 5 };

	Vector3f vec3 = -vec2;
	EXPECT_EQ(-3, vec3.x);
	EXPECT_EQ(-4, vec3.y);
	EXPECT_EQ(-5, vec3.z);

	Vector3f vec4 = vec1 + vec2;
	EXPECT_EQ(4, vec4.x);
	EXPECT_EQ(6, vec4.y);
	EXPECT_EQ(8, vec4.z);

	Vector3f vec5 = vec2 - vec1;
	EXPECT_EQ(2, vec5.x);
	EXPECT_EQ(2, vec5.y);
	EXPECT_EQ(2, vec5.z);

	vec5 += vec1;
	EXPECT_EQ(3, vec5.x);
	EXPECT_EQ(4, vec5.y);
	EXPECT_EQ(5, vec5.z);

	vec5 -= vec1;
	EXPECT_EQ(2, vec5.x);
	EXPECT_EQ(2, vec5.y);
	EXPECT_EQ(2, vec5.z);
}

TEST(TestVector3, Scale) {
	const Vector3f vec1{ 1, 2, 3 };
	const Vector3f vec2{ 3, 4, 5 };

	Vector3f vec3 = vec1 * 3;
	EXPECT_EQ(3, vec3[0]);
	EXPECT_EQ(6, vec3[1]);
	EXPECT_EQ(9, vec3[2]);

	Vector3f vec4 = 2.0 * vec2;
	EXPECT_EQ(6, vec4[0]);
	EXPECT_EQ(8, vec4[1]);
	EXPECT_EQ(10, vec4[2]);

	Vector3f vec5 = vec3 / 6;
	EXPECT_EQ(0.5, vec5[0]);
	EXPECT_EQ(1, vec5[1]);
	EXPECT_EQ(1.5, vec5[2]);
}

TEST(TestVector3, Comparison) {
	const Vector3f vec1{ 1, 2, 3 };
	const Vector3f vec2{ 3, 4, 5 };
	const Vector3f vec3{ 3, 3, 3 };
	const Vector3f vec4{ 4, 4, 4 };
	const Vector3f vec5{ 3, 4, 5 };

	EXPECT_TRUE(vec1 == vec1);
	EXPECT_TRUE(vec2 == vec2);

	EXPECT_FALSE(vec1 == vec2);
	EXPECT_TRUE(vec1 != vec2);

	EXPECT_FALSE(vec2 == vec3);
	EXPECT_TRUE(vec2 != vec3);

	EXPECT_FALSE(vec2 == vec4);
	EXPECT_TRUE(vec2 != vec4);

	EXPECT_FALSE(vec2 != vec5);
	EXPECT_TRUE(vec2 == vec5);
}

TEST(TestVector3, Length) {
	const Vector3f vec1{ -1, 2, 2 };
	const Vector3f vec2{ 3, 4, -5 };

	float length = vec1.Length();
	EXPECT_EQ(length, 3);

	float lengthSquared = vec2.LengthSquared();
	EXPECT_EQ(lengthSquared, 50);
}

TEST(TestVector3, Absolute) {
	const Vector3f vec1{ -1, 2, -3 };
	const Vector3f vec2{ 3, -4, 5 };

	Vector3f vec3 = Abs(vec1);
	EXPECT_EQ(1, vec3.x);
	EXPECT_EQ(2, vec3.y);
	EXPECT_EQ(3, vec3.z);

	Vector3f vec4 = Abs(vec2);
	EXPECT_EQ(3, vec4.x);
	EXPECT_EQ(4, vec4.y);
	EXPECT_EQ(5, vec4.z);
}

#pragma endregion Vector3

#pragma region Point2

TEST(TestPoint2, Initializer) {
	Point2f p1;
	EXPECT_EQ(0, p1.x);
	EXPECT_EQ(0, p1.y);

	const Point2f p2{ 1, 2 };
	EXPECT_EQ(1, p2.x);
	EXPECT_EQ(2, p2.y);

	const Vector2f v{ 1, 2 };
	Point2f p3(v);
	EXPECT_EQ(1, p3.x);
	EXPECT_EQ(2, p3.y);

	const Point2i p4{ 1, 2 };
	Point2f p5(p4);
	EXPECT_EQ(1, p5.x);
	EXPECT_EQ(2, p5.y);

	const Vector2f v2{ 3, 4 };
	Point2f p6(v2);
	EXPECT_EQ(3, p6.x);
	EXPECT_EQ(4, p6.y);

	Vector2f v3 = (Vector2f)p4;
	EXPECT_EQ(1, v3.x);
	EXPECT_EQ(2, v3.y);
}

TEST(TestPoint2, Indexer) {
	const Point2f p1{ 5, 6 };
	EXPECT_EQ(5, p1[0]);
	EXPECT_EQ(6, p1[1]);

	Point2f p2{ 1, 2 };
	p2[0] = 7;
	EXPECT_EQ(7, p2.x);
	EXPECT_EQ(2, p2.y);
}

TEST(TestPoint2, AddSubtract) {
	const Point2f p1{ 1, 2 };
	const Point2f p2{ 3, 4 };

	Point2f p = -p2;
	EXPECT_EQ(-3, p.x);
	EXPECT_EQ(-4, p.y);
	
	Vector2f v = p2 - p1;
	EXPECT_EQ(2, v.x);
	EXPECT_EQ(2, v.y);

	Point2f p3 = p2 - v;
	EXPECT_EQ(1, p3.x);
	EXPECT_EQ(2, p3.y);
	
	Point2f p4 = p3 + v;
	EXPECT_EQ(3, p4.x);
	EXPECT_EQ(4, p4.y);

	Point2f p5 = p1 + p2;
	EXPECT_EQ(4, p5.x);
	EXPECT_EQ(6, p5.y);

	p5 += v;
	EXPECT_EQ(6, p5.x);
	EXPECT_EQ(8, p5.y);

	p5 -= v;
	EXPECT_EQ(4, p5.x);
	EXPECT_EQ(6, p5.y);

	p5 += p1;
	EXPECT_EQ(5, p5.x);
	EXPECT_EQ(8, p5.y);
}

TEST(TestPoint2, Scale) {
	const Point2f p1{ 1, 2 };
	const Point2f p2{ 3, 4 };

	Point2f p3 = p1 * 3;
	EXPECT_EQ(3, p3[0]);
	EXPECT_EQ(6, p3[1]);

	Point2f p4 = 2.0 * p2;
	EXPECT_EQ(6, p4[0]);
	EXPECT_EQ(8, p4[1]);

	Point2f p5 = p3 / 6;
	EXPECT_EQ(0.5, p5[0]);
	EXPECT_EQ(1, p5[1]);
}

TEST(TestPoint2, Comparison) {
	const Point2f p1{ 1, 2 };
	const Point2f p2{ 3, 4 };
	const Point2f p3{ 3, 3 };
	const Point2f p4{ 4, 4 };
	const Point2f p5{ 3, 4 };

	EXPECT_TRUE(p1 == p1);
	EXPECT_TRUE(p2 == p2);

	EXPECT_FALSE(p1 == p2);
	EXPECT_TRUE(p1 != p2);

	EXPECT_FALSE(p2 == p3);
	EXPECT_TRUE(p2 != p3);

	EXPECT_FALSE(p2 == p4);
	EXPECT_TRUE(p2 != p4);

	EXPECT_FALSE(p2 != p5);
	EXPECT_TRUE(p2 == p5);
}

#pragma endregion Point2

#pragma region Point3

TEST(TestPoint3, Initializer) {
	Point3f p1;
	EXPECT_EQ(0, p1.x);
	EXPECT_EQ(0, p1.y);

	const Point3f p2{ 1, 2, 3 };
	EXPECT_EQ(1, p2.x);
	EXPECT_EQ(2, p2.y);
	EXPECT_EQ(3, p2.z);

	const Vector3f v{ 1, 2, 3 };
	Point3f p3(v);
	EXPECT_EQ(1, p3.x);
	EXPECT_EQ(2, p3.y);
	EXPECT_EQ(3, p3.z);

	const Point3i p4{ 1, 2, 3 };
	Point3f p5(p4);
	EXPECT_EQ(1, p5.x);
	EXPECT_EQ(2, p5.y);
	EXPECT_EQ(3, p5.z);

	const Vector3f v2{ 3, 4, 3 };
	Point3f p6(v2);
	EXPECT_EQ(3, p6.x);
	EXPECT_EQ(4, p6.y);
	EXPECT_EQ(3, p6.z);

	Vector3f v3 = (Vector3f)p4;
	EXPECT_EQ(1, v3.x);
	EXPECT_EQ(2, v3.y);
	EXPECT_EQ(3, v3.z);
}

TEST(TestPoint3, Indexer) {
	const Point3f p1{ 5, 6, 7 };
	EXPECT_EQ(5, p1[0]);
	EXPECT_EQ(6, p1[1]);
	EXPECT_EQ(7, p1[2]);

	Point3f p2{ 1, 2, 3 };
	p2[0] = 7;
	EXPECT_EQ(7, p2.x);
	EXPECT_EQ(2, p2.y);
	EXPECT_EQ(3, p2.z);
}

TEST(TestPoint3, AddSubtract) {
	const Point3f p1{ 1, 2, 3 };
	const Point3f p2{ 3, 4, 5 };

	Point3f p = -p2;
	EXPECT_EQ(-3, p.x);
	EXPECT_EQ(-4, p.y);
	EXPECT_EQ(-5, p.z);

	Vector3f v = p2 - p1;
	EXPECT_EQ(2, v.x);
	EXPECT_EQ(2, v.y);
	EXPECT_EQ(2, v.z);

	Point3f p3 = p2 - v;
	EXPECT_EQ(1, p3.x);
	EXPECT_EQ(2, p3.y);
	EXPECT_EQ(3, p3.z);

	Point3f p4 = p3 + v;
	EXPECT_EQ(3, p4.x);
	EXPECT_EQ(4, p4.y);
	EXPECT_EQ(5, p4.z);

	Point3f p5 = p1 + p2;
	EXPECT_EQ(4, p5.x);
	EXPECT_EQ(6, p5.y);
	EXPECT_EQ(8, p5.z);

	p5 += v;
	EXPECT_EQ(6, p5.x);
	EXPECT_EQ(8, p5.y);

	p5 -= v;
	EXPECT_EQ(4, p5.x);
	EXPECT_EQ(6, p5.y);
	EXPECT_EQ(8, p5.z);

	p5 += p1;
	EXPECT_EQ(5, p5.x);
	EXPECT_EQ(8, p5.y);
	EXPECT_EQ(11, p5.z);
}

TEST(TestPoint3, Scale) {
	const Point3f p1{ 1, 2, 3 };
	const Point3f p2{ 3, 4, 5 };

	Point3f p3 = p1 * 3;
	EXPECT_EQ(3, p3[0]);
	EXPECT_EQ(6, p3[1]);
	EXPECT_EQ(9, p3[2]);

	Point3f p4 = 2.0 * p2;
	EXPECT_EQ(6, p4[0]);
	EXPECT_EQ(8, p4[1]);
	EXPECT_EQ(10, p4[2]);

	Point3f p5 = p3 / 6;
	EXPECT_EQ(0.5, p5[0]);
	EXPECT_EQ(1, p5[1]);
	EXPECT_EQ(1.5, p5[2]);
}

TEST(TestPoint3, Comparison) {
	const Point3f p1{ 1, 2, 3 };
	const Point3f p2{ 3, 4, 5 };
	const Point3f p3{ 3, 3, 3 };
	const Point3f p4{ 4, 4, 4 };
	const Point3f p5{ 3, 4, 5 };

	EXPECT_TRUE(p1 == p1);
	EXPECT_TRUE(p2 == p2);

	EXPECT_FALSE(p1 == p2);
	EXPECT_TRUE(p1 != p2);

	EXPECT_FALSE(p2 == p3);
	EXPECT_TRUE(p2 != p3);

	EXPECT_FALSE(p2 == p4);
	EXPECT_TRUE(p2 != p4);

	EXPECT_FALSE(p2 != p5);
	EXPECT_TRUE(p2 == p5);
}

#pragma endregion Point3

#pragma region Point3

TEST(TestNormal3, Initializer) {
	Normal3f p1;
	EXPECT_EQ(0, p1.x);
	EXPECT_EQ(0, p1.y);

	const Normal3f p2{ 1, 2, 3 };
	EXPECT_EQ(1, p2.x);
	EXPECT_EQ(2, p2.y);
	EXPECT_EQ(3, p2.z);

	const Vector3f v{ 1, 2, 3 };
	Normal3f p3(v);
	EXPECT_EQ(1, p3.x);
	EXPECT_EQ(2, p3.y);
	EXPECT_EQ(3, p3.z);

	const Vector3f v2{ 3, 4, 3 };
	Normal3f p6(v2);
	EXPECT_EQ(3, p6.x);
	EXPECT_EQ(4, p6.y);
	EXPECT_EQ(3, p6.z);
}

TEST(TestNormal3, Indexer) {
	const Normal3f p1{ 5, 6, 7 };
	EXPECT_EQ(5, p1[0]);
	EXPECT_EQ(6, p1[1]);
	EXPECT_EQ(7, p1[2]);

	Normal3f p2{ 1, 2, 3 };
	p2[0] = 7;
	EXPECT_EQ(7, p2.x);
	EXPECT_EQ(2, p2.y);
	EXPECT_EQ(3, p2.z);
}

TEST(TestNormal3, AddSubtract) {
	const Normal3f p1{ 1, 2, 3 };
	const Normal3f p2{ 3, 4, 5 };
	const Normal3f p{ 2, 2, 2 };

	Normal3f p3 = p2 - p;
	EXPECT_EQ(1, p3.x);
	EXPECT_EQ(2, p3.y);
	EXPECT_EQ(3, p3.z);

	Normal3f p4 = p3 + p;
	EXPECT_EQ(3, p4.x);
	EXPECT_EQ(4, p4.y);
	EXPECT_EQ(5, p4.z);

	Normal3f p5 = p1 + p2;
	EXPECT_EQ(4, p5.x);
	EXPECT_EQ(6, p5.y);
	EXPECT_EQ(8, p5.z);

	p5 += p;
	EXPECT_EQ(6, p5.x);
	EXPECT_EQ(8, p5.y);

	p5 -= p;
	EXPECT_EQ(4, p5.x);
	EXPECT_EQ(6, p5.y);
	EXPECT_EQ(8, p5.z);

	p5 += p1;
	EXPECT_EQ(5, p5.x);
	EXPECT_EQ(8, p5.y);
	EXPECT_EQ(11, p5.z);

	Normal3f p6 = -p2;
	EXPECT_EQ(-3, p6.x);
	EXPECT_EQ(-4, p6.y);
	EXPECT_EQ(-5, p6.z);
}

TEST(TestNormal3, Scale) {
	const Normal3f p1{ 1, 2, 3 };
	const Normal3f p2{ 3, 4, 5 };

	Normal3f p3 = p1 * 3;
	EXPECT_EQ(3, p3[0]);
	EXPECT_EQ(6, p3[1]);
	EXPECT_EQ(9, p3[2]);

	Normal3f p4 = 2.0 * p2;
	EXPECT_EQ(6, p4[0]);
	EXPECT_EQ(8, p4[1]);
	EXPECT_EQ(10, p4[2]);

	Normal3f p5 = p3 / 6;
	EXPECT_EQ(0.5, p5[0]);
	EXPECT_EQ(1, p5[1]);
	EXPECT_EQ(1.5, p5[2]);
}

TEST(TestNormal3, Comparison) {
	const Normal3f p1{ 1, 2, 3 };
	const Normal3f p2{ 3, 4, 5 };
	const Normal3f p3{ 3, 3, 3 };
	const Normal3f p4{ 4, 4, 4 };
	const Normal3f p5{ 3, 4, 5 };

	EXPECT_TRUE(p1 == p1);
	EXPECT_TRUE(p2 == p2);

	EXPECT_FALSE(p1 == p2);
	EXPECT_TRUE(p1 != p2);

	EXPECT_FALSE(p2 == p3);
	EXPECT_TRUE(p2 != p3);

	EXPECT_FALSE(p2 == p4);
	EXPECT_TRUE(p2 != p4);

	EXPECT_FALSE(p2 != p5);
	EXPECT_TRUE(p2 == p5);
}

#pragma endregion Normal3