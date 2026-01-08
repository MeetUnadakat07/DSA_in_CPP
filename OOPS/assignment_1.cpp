#include<iostream>
using namespace std;

class Complex {
public:
    int real;
    int img;

    Complex(int real, int img) {
        this -> real = real;
        this -> img = img;
    }

    void show() {
        if(img > 0) {
            cout << real << " + " << img << "i";
        } else {
            cout << real << img << "i";
        }
    }

    Complex operator-(Complex &obj) {
        int resReal = this -> real - obj.real;
        int resImg = this -> img - obj.img;
        Complex c3(resReal, resImg);
        return c3;
    }
};

int main() {
    Complex c1(4, 2);
    Complex c2(6, 5);
    Complex c3 = c1 - c2;
    c3.show();
}