#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
        int real,imag;
    public: 
        Complex(int r=0,int i=0):real(r),imag(i){}
        Complex operator+(Complex const &obj)
        {
            Complex ru;
            ru.real = real+obj.real;
            ru.imag = imag+obj.imag;
            return ru;
        }    
        void print() {
            cout<<real<<"+i"<<imag<<endl;
        }
};

int main()
{
    Complex c1(1,3),c2(2,4);
    Complex c3 = c1+c2;
    c3.print();
}