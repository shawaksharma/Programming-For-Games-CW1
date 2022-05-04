#include "Vector3D.h"
#include "Bin.h"
#include <iostream>

using namespace std;

int main() {

    cout << "\n\nTESTING VECTOR3D CLASS";    
    
    //Test returning x, y, z components
    cout << "\n\nTest 1: Return x, y, z component of a vector.\n";
    Vector3D vector_test(1,5,9);
    Vector3D vector1(vector_test);   //Testing copy constructor
    vector1.set_x(10);   //Testing setters
    vector1.set_y(10);
    vector1.set_z(10);
    cout << "(Testing setters and return) Vector 1: "; vector1.print_vector(); cout << "\n"; //print_vector() tests getters
    vector1 = vector_test;
    cout << "(Testing assignment operator) Vector 1: "; vector1.print_vector(); cout << "\n"; 
    
    //Test computing magnitude 
    cout << "\n\nTest 2: Compute magnitude of a vector.\n";
    cout << "Magnitude of "; vector1.print_vector(); cout << " = " << vector1.compute_magnitude() << "\n";
    
    //Testing additon and subtraction
    cout << "\n\nTest 3: Add and subtract vectors.\n";
    Vector3D vector2(10, -2, 1.5);
    Vector3D add_result = vector1 + vector2;
    Vector3D subtract_result = vector1 - vector2;
    cout << "Vector 1: "; vector1.print_vector(); cout << "\n";
    cout << "Vector 2: "; vector2.print_vector(); cout << "\n";
    vector1.print_vector(); cout << " + "; vector2.print_vector(); cout << " = "; add_result.print_vector(); cout << "\n";
    vector1.print_vector(); cout << " - "; vector2.print_vector(); cout << " = "; subtract_result.print_vector(); cout << "\n";
    
    //Testing operators to multiply and divide by a scalar
    cout << "\n\nTest 4: Multiply, divide vectors by a scalar.\n";
    Vector3D multiply_result = vector1 * 10;
    Vector3D divide_result = vector2 / 10;
    vector1.print_vector(); cout << " * 10 = "; multiply_result.print_vector(); cout << "\n";
    vector2.print_vector(); cout << " / 10 = "; divide_result.print_vector(); cout << "\n";

    //Testing operators to calculate scalar product and vector product
    cout << "\n\nTest 5: Scalar and vector product.\n";
    double scalar_product = vector1 * vector2;
    Vector3D vector_product = vector1 % vector2;
    vector1.print_vector(); cout << " * "; vector2.print_vector(); cout << " = " << scalar_product << "\n";
    vector1.print_vector(); cout << " % "; vector2.print_vector(); cout << " = "; vector_product.print_vector(); cout << "\n";

    //Testing producing a unit vector from a given vector
    cout << "\n\nTest 6: Producing a unit vector.\n";
    Vector3D unit_vector1 = unit_vector(vector1);
    cout << "Unit vector of "; vector1.print_vector(); cout << " is "; unit_vector1.print_vector(); cout << "\n";
    cout << "Magnitude = " << unit_vector1.compute_magnitude() << "\n";

    //Testing returning a orthogonal unit vector from two given vectors
    cout << "\n\nTest 7: Returning a orthogonal unit vector.\n";
    Vector3D orthogonal_unit_vector1 = orthogonal_unit_vector(vector1, vector2);
    cout << "Orthogonal unit vector of "; vector1.print_vector(); cout << " and "; vector2.print_vector(); cout << " is "; orthogonal_unit_vector1.print_vector(); cout << "\n";
    cout << "Magnitude = " << orthogonal_unit_vector1.compute_magnitude() << "\n";


    cout << "\n\nTESTING BIN CLASS";

    //Testing getX, getY, getZ
    cout << "\n\nTest 8: Testing getX, getY, getZ.\n";
    Bin bin1(3);
    bin1.add(1,2,3);
    bin1.add(4,5,6);
    cout << "(" << bin1.getX(0) << ", " << bin1.getY(0) << ", " << bin1.getZ(0) << ") = Element 0\n";
    cout << "(" << bin1.getX(1) << ", " << bin1.getY(1) << ", " << bin1.getZ(1) << ") = Element 1\n";

    //Testing add and extending allocated memory
    cout << "\n\nTest 9: Testing add and extending memory (adding 5 elements to an array with a size of 3).\n";
    bin1.add(7,8,9);
    bin1.add(-1.5,7,3.25);
    bin1.add(-9,5,1);
    cout << "(" << bin1.getX(0) << ", " << bin1.getY(0) << ", " << bin1.getZ(0) << ") = Element 0\n";
    cout << "(" << bin1.getX(1) << ", " << bin1.getY(1) << ", " << bin1.getZ(1) << ") = Element 1\n";
    cout << "(" << bin1.getX(2) << ", " << bin1.getY(2) << ", " << bin1.getZ(2) << ") = Element 2\n";
    cout << "(" << bin1.getX(3) << ", " << bin1.getY(3) << ", " << bin1.getZ(3) << ") = Element 3\n";
    cout << "(" << bin1.getX(4) << ", " << bin1.getY(4) << ", " << bin1.getZ(4) << ") = Element 4\n";

    //Testing remove
    cout << "\n\nTest 10: Testing remove by removing element 1.\n";
    bin1.remove(1);
    cout << "(" << bin1.getX(0) << ", " << bin1.getY(0) << ", " << bin1.getZ(0) << ") = Element 0\n";
    cout << "(" << bin1.getX(1) << ", " << bin1.getY(1) << ", " << bin1.getZ(1) << ") = Element 1\n";
    cout << "(" << bin1.getX(2) << ", " << bin1.getY(2) << ", " << bin1.getZ(2) << ") = Element 2\n";
    cout << "(" << bin1.getX(3) << ", " << bin1.getY(3) << ", " << bin1.getZ(3) << ") = Element 3\n";

    //Testing copy constructor
    cout << "\n\nTest 11: Testing copy constructor.\n";
    Bin bin2(bin1);
    cout << "\nBIN1: \n";
    cout << "(" << bin1.getX(0) << ", " << bin1.getY(0) << ", " << bin1.getZ(0) << ") = Element 0\n";
    cout << "(" << bin1.getX(1) << ", " << bin1.getY(1) << ", " << bin1.getZ(1) << ") = Element 1\n";
    cout << "(" << bin1.getX(2) << ", " << bin1.getY(2) << ", " << bin1.getZ(2) << ") = Element 2\n";
    cout << "(" << bin1.getX(3) << ", " << bin1.getY(3) << ", " << bin1.getZ(3) << ") = Element 3\n";

    cout << "\nBIN2 (Created from copy constructor): \n";
    cout << "(" << bin2.getX(0) << ", " << bin2.getY(0) << ", " << bin2.getZ(0) << ") = Element 0\n";
    cout << "(" << bin2.getX(1) << ", " << bin2.getY(1) << ", " << bin2.getZ(1) << ") = Element 1\n";
    cout << "(" << bin2.getX(2) << ", " << bin2.getY(2) << ", " << bin2.getZ(2) << ") = Element 2\n";
    cout << "(" << bin2.getX(3) << ", " << bin2.getY(3) << ", " << bin2.getZ(3) << ") = Element 3\n";

    //Testing assignment operator
    cout << "\n\nTest 12: Testing assignment operator.\n";
    Bin bin3(5);
    cout << "\nBIN3 (Before operator used): \n";
    cout << "(" << bin3.getX(0) << ", " << bin3.getY(0) << ", " << bin3.getZ(0) << ") = Element 0\n";
    cout << "(" << bin3.getX(1) << ", " << bin3.getY(1) << ", " << bin3.getZ(1) << ") = Element 1\n";
    cout << "(" << bin3.getX(2) << ", " << bin3.getY(2) << ", " << bin3.getZ(2) << ") = Element 2\n";
    cout << "(" << bin3.getX(3) << ", " << bin3.getY(3) << ", " << bin3.getZ(3) << ") = Element 3\n";
    cout << "(" << bin3.getX(4) << ", " << bin3.getY(4) << ", " << bin3.getZ(4) << ") = Element 4\n";

    bin3 = bin2;
    cout << "\nBIN3 (After bin3 = bin 2): \n";
    cout << "(" << bin3.getX(0) << ", " << bin3.getY(0) << ", " << bin3.getZ(0) << ") = Element 0\n";
    cout << "(" << bin3.getX(1) << ", " << bin3.getY(1) << ", " << bin3.getZ(1) << ") = Element 1\n";
    cout << "(" << bin3.getX(2) << ", " << bin3.getY(2) << ", " << bin3.getZ(2) << ") = Element 2\n";
    cout << "(" << bin3.getX(3) << ", " << bin3.getY(3) << ", " << bin3.getZ(3) << ") = Element 3\n";

    cout << "\nEnd of Tests\n\n";
    return 0;
}