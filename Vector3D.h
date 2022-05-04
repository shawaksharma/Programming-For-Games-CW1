#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

class Vector3D {
    public:
        Vector3D(double x = 0, double y = 0, double z = 0);
        Vector3D(const Vector3D &vector);
        double compute_magnitude();
        Vector3D& operator=(const Vector3D& rhs);
        Vector3D operator+(const Vector3D rhs);
        Vector3D operator-(const Vector3D rhs);
        Vector3D operator*(const double scalar);
        Vector3D operator/(const double scalar);
        double operator*(const Vector3D rhs);
        Vector3D operator%(const Vector3D rhs);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(double x);
        void set_y(double y);
        void set_z(double y);
        void print_vector();

    private:
        double x;
        double y;
        double z;
};

Vector3D unit_vector(Vector3D vector);
Vector3D orthogonal_unit_vector(Vector3D vector1, Vector3D vector2);

#endif