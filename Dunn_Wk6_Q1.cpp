// Implement:
// The default constructor
// A one int parameter constructor that
//   sets the first member to the parameter
//   and the second to 0.
// A two int parameter constructor.
// Overload * on a Pair and an int
// (x, y)*c = (x*c, y*c)
// Overload + on two objects of type Pair.
// (a, b) + (c, d) = (a + c, b + d)

#include <iostream>
using namespace std;

class Pair
{
    public:
        Pair();
        Pair(int first, int second);
        Pair(int first);
        int accessFirst();
        int accessSecond();
        // other members and friends
        friend Pair operator+(const Pair&, const Pair&);
        friend Pair operator*(const Pair&, int);
        friend istream& operator>> (istream&, Pair&);
        friend ostream& operator<< (ostream&, const Pair&);
    private:
        int f;
        int s;
};
int main()
{
    Pair x;
    Pair y(2,3);
    Pair z(4);
    cout << x.accessFirst()<< endl;
    cout << x.accessSecond()<< endl;
    cout << y.accessFirst()<< endl;
    cout << y.accessSecond()<< endl;
    cout << z.accessFirst()<< endl;
    cout << z.accessSecond()<< endl;
    cout << endl;
    cout << "x " << x << endl
         << "y " << y << endl
         << "z " << z
    << endl << endl;
    x = y + z;
    cout << "y + z  " << x << endl;
    cout << "y * 2  " << y * 2 << endl;
    return 0;
}

Pair operator+(const Pair& lhs, const Pair& rhs)
{
    //Complete the function
    return Pair((lhs.f + rhs.f), (lhs.s + rhs.s));
}

Pair operator*(const Pair& lhs, int rhs)
{
    //Complete the function
    return Pair((lhs.f * rhs), (lhs.s * rhs));

}

istream& operator>> (istream& ins, Pair& second)
{
    //Complete the function
    ins >> second.f >> second.s;
    return ins;
}

ostream& operator<< (ostream& outs, const Pair& second)
{
    //Complete the function
    outs << "(" << second.f << ", " << second.s << ")";
    return outs;
}

Pair::Pair(int firstValue, int secondValue):f(firstValue), s(secondValue)
{
    //Complete the function
    f = firstValue;
    s = secondValue;
}

Pair::Pair(int firstValue):f(firstValue), s(0)
{   
    //Complete the function
    f = firstValue;
    s = 0;

}

Pair::Pair(): f(0), s(0)
{   
    //Complete the function
    f = 0;
    s = 0;

}

int Pair::accessFirst()
{
    //Complete the function
    return f;

}

int Pair::accessSecond()
{
    //Complete the function
    return s;

}