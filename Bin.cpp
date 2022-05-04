#include "Vector3D.h"
#include "Bin.h"


//Constructor
Bin::Bin(const int bin_size) {
    Vector3D* new_vector_array = new Vector3D[bin_size];
    vector_array = new_vector_array;
    length = 0;
    capacity = bin_size;
}

//Destructor
Bin::~Bin() {
    delete[] vector_array;      //Deleting memory
}

//Copy Constructor
Bin::Bin(const Bin &bin){       //Copying values
    length = bin.length;
    capacity = bin.capacity;
    Vector3D* new_vector_array = new Vector3D[capacity];
    vector_array = new_vector_array;
    for (int i = 0; i < length; i++) {
        vector_array[i].set_x(bin.vector_array[i].get_x());     //Copying array
        vector_array[i].set_y(bin.vector_array[i].get_y());
        vector_array[i].set_z(bin.vector_array[i].get_z());
    }
}

//Getters
double Bin::getX(int a) const { return vector_array[a].get_x(); }
double Bin::getY(int a) const { return vector_array[a].get_y(); }
double Bin::getZ(int a) const { return vector_array[a].get_z(); }

//Add method
void Bin::add(double x, double y, double z) {   //Using doubles instead of floats, due to high degree of calculations
    if (length >= capacity) {                   //and very small allocation (almost negligible for this program) of extra memory for doubles,
        extend();                               //mainting accuracy was a higher priority for this program
    }
    vector_array[length].set_x(x);      //If length of array is equal to or bigger than its capacity, call the extend method
    vector_array[length].set_y(y);      //Add element at the end of the array and increase length
    vector_array[length].set_z(z);
    length++;
}

//Extending the bin method (called when bin is at full capacity)
void Bin::extend() {                                            //Extending the array by +1 then 2x so the method is not repeating if a user keeps adding to the array,
    capacity = 2*(capacity+1);                                  //this would impact performance
    Vector3D* new_vector_array = new Vector3D[capacity];
    for (int i = 0; i < length; i++) {
        new_vector_array[i].set_x(vector_array[i].get_x());     //Copying array after extending capacity
        new_vector_array[i].set_y(vector_array[i].get_y());
        new_vector_array[i].set_z(vector_array[i].get_z());
    }
    delete[] vector_array;      //Deleting old memory
    vector_array = new_vector_array;
}

//Removing element b from array
void Bin::remove(int b) {
    for (int i = b; i < length-1; i++) {
        vector_array[i].set_x(vector_array[i+1].get_x());       //Shunting all subsequent elements
        vector_array[i].set_y(vector_array[i+1].get_y());
        vector_array[i].set_z(vector_array[i+1].get_z());
    }
    length--;
    vector_array[length].set_x(0);      //Reducing the length and clearing the last element
    vector_array[length].set_y(0);
    vector_array[length].set_z(0);
}
Bin& Bin::operator=(const Bin& rhs)
{
	if(this == &rhs) {      //If already equal, return straight away
		return (*this);
	}
	capacity = rhs.capacity;         //Else, set new variables
    length = rhs.length;
    for (int i = 0; i < length; i++) {
        vector_array[i].set_x(rhs.vector_array[i].get_x());     //Set array variables to rhs array
        vector_array[i].set_y(rhs.vector_array[i].get_y());
        vector_array[i].set_z(rhs.vector_array[i].get_z());
    }
	return (*this);
}