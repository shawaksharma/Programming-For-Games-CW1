#ifndef _BIN_H_
#define _BIN_H_

class Bin {
    public:
        Bin(int bin_size);
        ~Bin();
        Bin(const Bin &bin);
        double getX(int a) const;
        double getY(int a) const;
        double getZ(int a) const;
        void add(double x, double y, double z);
        void extend();
        void remove(int b);
        Bin& operator=(const Bin& rhs);

    private:
        int length;
        int capacity;
        Vector3D *vector_array;

};

#endif