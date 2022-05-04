#include "Vector3D.h"
#include "Bin.h"
#include <math.h>
#include <iostream>

//Constructor
Vector3D::Vector3D(double x, double y, double z) {
    this-> x = x;
    this-> y = y;
    this-> z = z;
}

//Copy constructor
Vector3D::Vector3D(const Vector3D &vector) {
    x = vector.x;
    y = vector.y;
    z = vector.z;
}

//Getters
double Vector3D::get_x() const { return x; }
double Vector3D::get_y() const { return y; }
double Vector3D::get_z() const { return z; }

//Setters
void Vector3D::set_x(double x){ this->x = x; }
void Vector3D::set_y(double y){ this->y = y; }
void Vector3D::set_z(double z){ this->z = z; }


//Operator Overloading
//Overloading assignment operator
Vector3D& Vector3D::operator=(const Vector3D& rhs) {
    if(this == &rhs) {  //if already equal, return straight away
		return (*this);
	}
    this->set_x(rhs.get_x());   //else, set variables
    this->set_y(rhs.get_y());
    this->set_z(rhs.get_z());
    return (*this);
}

//Adding vectors
Vector3D Vector3D::operator+(const Vector3D rhs) {
    double new_x = x + rhs.get_x(); 
    double new_y = y + rhs.get_y();
    double new_z = z + rhs.get_z();
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

//Subtracting vectors
Vector3D Vector3D::operator-(const Vector3D rhs) {
    double new_x = x - rhs.get_x();
    double new_y = y - rhs.get_y();
    double new_z = z - rhs.get_z();
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

//Calculating scalar product
double Vector3D::operator*(const Vector3D rhs) {
    double new_x = x * rhs.get_x();
    double new_y = y * rhs.get_y();
    double new_z = z * rhs.get_z();
    double scalar_product = (new_x + new_y + new_z);
    return scalar_product;
}

//Calculating vector product
Vector3D Vector3D::operator%(const Vector3D rhs) {
    double new_x = (y*rhs.get_z()) - (z*rhs.get_y());
    double new_y = (z*rhs.get_x()) - (x*rhs.get_z());
    double new_z = (x*rhs.get_y()) - (y*rhs.get_x());
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

//Multiplying by a scalar
Vector3D Vector3D::operator*(const double scalar) {
    double new_x = x * scalar;
    double new_y = y * scalar;
    double new_z = z * scalar;
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

//Dividing by a scalar
Vector3D Vector3D::operator/(const double scalar) {
    double new_x = x / scalar;
    double new_y = y / scalar;
    double new_z = z / scalar;
    Vector3D new_vector(new_x, new_y, new_z);
    return new_vector;
}

//Computing Magnitude
double Vector3D::compute_magnitude() {
    double magnitude = sqrt(pow(x, 2) + pow(y,2) + pow(z,2));
    return magnitude;
}

//To print vectors faster and easier for testing purposes
void Vector3D::print_vector() {
    std::cout << "(" << get_x() << ", " << get_y() << ", " << get_z() << ")";

}

//Producing unit vector
Vector3D unit_vector(Vector3D vector) {
    double vector_magnitude = vector.compute_magnitude();   //Calling the compute_magnitude() instead of rewriting formula
    return vector / vector_magnitude;   //Calling the overloaded division operator, for optimisation, return in one line instead of creating another vector object
}

//Producing orthogonal unit vector
Vector3D orthogonal_unit_vector(Vector3D vector1, Vector3D vector2) {
    Vector3D new_vector = vector1 % vector2;    //Calling vector product overloaded operator instead of rewriting formula
    return unit_vector(new_vector);     //Calling unit_vector instead of doing repeating code, for optimisation, returning in one line is possible here than assigning it to a new created vector
}