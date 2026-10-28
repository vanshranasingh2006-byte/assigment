#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int real;
    int imag;
    public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator -(Complex const &obj)
    {
        Complex res;
        res.real = real - obj.real;
        res.imag = imag - obj.imag;
        return res;
    }

    Complex operator *(Complex const &obj)
    {
        Complex res;
        res.real = this->real * obj.real - this->imag * obj.imag;
        res.imag = this->real * obj.imag + this->imag * obj.real;
        return res;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }


};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 - c2;
    c3.display();
    return 0;
}