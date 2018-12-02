#include "3D_Point"

3D_Point::3D_Point(double x_new, double y_new, double z_new) {
	Point(x_new, y_new);
	z = z_new;
}

3D_Point::SetCoordinates(double x_new, double y_new, double z_new) {
	Point::SetCoordinates(n_new,y_new);
	z = z_new;
}

3D_Point::GetZ() {
	return z;
}
