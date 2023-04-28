#include "Point2D.h"

Point2D::operator Point3D () {
	return Point3D(x, y, 0);
}
