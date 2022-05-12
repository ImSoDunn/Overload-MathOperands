//class Rational;
//private data: int n, (fraction numerator) and int d (fraction denominator).
//public interface:
//constructors:
//two int args, to allow setting rational to any legal value
//one int arg, to construct rationals with arg numerator and denominator 1.
//overload << and >> to allow writing to screen in form 325/430
//and reading it from the keyboard in the same format.
//Notes: either n or d may contain a negative quantity.
//overload + - * / < <= > >= ==
//Put definitions in separate file for separate compilation
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
class Rational
{
    public:
        Rational(int numerator, int denominator);
        Rational(int numerator); // sets denominator to 1
        Rational(); // sets numerator to 0, denominator to 1
        friend Rational operator+(const Rational&, const Rational&);
        friend Rational operator-(const Rational&, const Rational&);
        friend Rational operator*(const Rational&, const Rational&);
        friend Rational operator/(const Rational&, const Rational&);
        friend bool operator<(const Rational&, const Rational&);
        friend bool operator<=(const Rational&, const Rational&);
        friend bool operator>(const Rational&, const Rational&);
        friend bool operator >=(const Rational&, const Rational&);
        friend bool operator ==(const Rational&, const Rational&);
        friend ostream& operator <<(istream&, Rational&);
        friend istream& operator >>(ostream&, Rational&);
    private:
        int n;
        int d;
};
void normalize(int &n, int &d);
int gcd(int n, int d);
int lcm (int n, int d);
//Implementations of the members of class Rational.
//private members of class Rational
//  int n;
//  int d;
Rational::Rational(int numer, int denom)
{
    normalize(numer, denom);
    n = numer;
    d = denom;
}

//sets denominator to 1
Rational::Rational(int numer)
{
    //Complete the function
    int denum = 1;
    normalize(numer, denum);
    n = numer;
    d = 1;

}

// sets numerator to 0, denominator to 1
Rational::Rational()
{
    //Complete the function
    n = 0;
    d = 1;
    //cout << n << d;

}

Rational operator +(const Rational& rat1, const Rational& rat2)
{
    //Complete the function
    int great = gcd(rat1.d, rat2.d);
    int common = lcm(rat1.d, rat2.d);
    return rat1;
}

Rational operator -(const Rational& rat1, const Rational& rat2)
{
    //Complete the function
    return rat1 - rat2; 
}

Rational operator *(const Rational& rat1 , const Rational& rat2)
{
    //Complete the function
    return rat1 * rat2;
}

Rational operator/(const Rational& rat1, const Rational& rat2)
{
    //Complete the function
    return rat1 / rat2;

}

//precondition: all relational operators require  d > 0
bool operator <(const Rational&, const Rational&)
{
    //Complete the function
    return true;
}

bool operator <=(const Rational&, const Rational&)
{
    //Complete the function
    return true;

}
bool operator >(const Rational&, const Rational&)
{
    //Complete the function
    return true;

}

bool operator >=(const Rational&, const Rational&)
{
    //Complete the function
    return true;

}

bool operator==(const Rational&, const Rational&)
{
    //Complete the function
    return true;

}


//NOTE:
//The first param MUST NOT be const. The
//second one is written, so it cannot be const either.
istream& operator >>(istream& in_str, Rational& right)
{
    //Complete the function
    //int numer = right.n;

    //normalize(right.n, right.d);
    return in_str;
}

//The first parameter should not be const, the
//second is read only and should be const.
ostream& operator <<(ostream& out_str, const Rational& right)
{
    //Complete the function
    return out_str;

}

//postcondition: return value is gcd of the absolute values
//of m and n depends on function int abs(int); declared in
//cstdlib
int gcd(int m, int n)
{
    int t;
    m = abs (m); // don't care about signs.
    n = abs (n);
    if(n < m)    // make m >= n so algorithm will work!
    {
        t = m;
        m = n;
        n = t;
    }
    int r;
    r = m % n;
    while(r != 0)
    {
        r = m%n;
        m = n;
        n = r;
    }
    return m; 
}
int lcm(int a, int b)
{
    return (a*b) / gcd(a, b);
}
//postcondition: n and d (to be numerator and denominator
//of a fraction)have all common factors removed, and d > 0.
void normalize(int& n, int& d)
{
// remove common factors:
for (int i= std::abs(std::min(n, d)); i > 0; i--)
{
    if ((n % i == 0) && (d % i == 0))
    {
        n = n / i;
        d = d / i;
        
    if (d < 0)
    {
        if (n < 0)
        {
            n = std::abs(n);
            d = std::abs(d);
            
        } else
        {
            n = n * -1;
            d = std::abs(d);
        }
    }
        //cout << n << endl;
        //cout << d << endl;
        break;
    }
}

//Complete the function
//fix things so that if the fraction is 'negative'
//it is n that carries the sign. If both n and d are
//negative, each is made positive.
//Complete the function
}
// Testing part is included in the main function. You do not need to write them

int main()
{
    Rational x(4, 3);
    Rational y(1, 2);
    Rational z;

    cout << x + y;



    /***cout << "Testing declarations" << endl;
    cout << "Rational x, y(2), z(-5,-6), w(1,-3);" << endl;
    Rational x, y(2), z(-5,-6), w(1,-3);
    cout << "z = " << z << ", y = " << y << ",  z = " << z
    << ", w = " << w << endl;
    cout << "Testing >> overloading: \nEnter "
    << "a fraction in the format "
    << "integer_numerator/integer_denominator"
    << endl;
    cin >> x;
    cout << "You entered the equivalent of: " << x << endl;
    cout << z << " -  (" << w << ") = " << z - w << endl;
    cout << "Testing the constructor and normalization routines: " << endl;
    y =Rational(-128, -48);
    cout << "y =Rational(-128, -48) outputs as " << y << endl;
    y =Rational(-128, 48);
    cout << "y =Rational(-128, 48)outputs as " << y << endl;
    y = Rational(128,-48);
    cout << "y = Rational(128, -48) outputs as " << y << endl;
    Rational a(1,1);
    cout << "Rational a(1,1); a outputs as: " << a << endl;
    Rational ww = y*a;
    cout <<  y << " * " << a << " = " << ww << endl;
    w = Rational(25,9);
    z = Rational(3,5);
    cout << "Testing arithmetic and relational "
    << " operator overloading" << endl;
    cout << w << " * " << z << " = " << w * z << endl;
    cout << w << " + " << z << " = " << w + z << endl;
    cout << w << " - " << z << " = " << w - z << endl;
    cout << w << " / " << z << " = " << w / z << endl;
    cout << w << " <  " << z << " = " << (w < z) << endl;
    cout << w << " < " << w << " = " << (w < w) << endl;
    cout << w << " <= " << z << " = " << (w <= z) << endl;
    cout << w << " <= " << w << " = " << (w <= w) << endl;
    cout << w << " >  " << z << " = " << (w > z) << endl;
    cout << w << " > " << w << " = " << (w > w) << endl;
    cout << w << " >= " << z << " = " << (w >= z) << endl;
    cout << w << " >= " << w << " = " << (w >= w) << endl;
    w = Rational(-21,9);
    z = Rational(3,5);
    cout << w << " * " << z << " = " << w * z << endl;
    cout << w << " + " << z << " = " << w + z << endl;
    cout << w << " - " << z << " = " << w - z << endl;
    cout << w << " / " << z << " = " << w / z << endl;
    cout << w << " <  " << z << " = " << (w < z) << endl;
    cout << w << " < " << w << " = " << (w < w) << endl;
    cout << w << " <= " << z << " = " << (w <= z) << endl;
    cout << w << " <= " << w << " = " << (w <= w) << endl;
    cout << w << " >  " << z << " = " << (w > z) << endl;
    cout << w << " > " << w << " = " << (w > w) << endl;
    cout << w << " >= " << z << " = " << (w >= z) << endl;
    cout << w << " >= " << w << " = " << (w >= w) << endl; ***/
    return 0;
}