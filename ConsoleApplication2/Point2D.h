#pragma once

class Point3D;

class Point2D
{
public:
	int x{};
	int y{};
	Point2D() = default;
	Point2D(int x, int y) :x{ x }, y{ y } {};

	Point2D(const Point2D&) = delete;


	operator Point3D (); 

};

class Point3D{
public:
	int x;
	int y;
	int z;
	Point3D(int x, int y, int z) :x{ x }, y{ y }, z{z} {};

	operator Point2D () {
		return Point2D(x, y);
	}
};
