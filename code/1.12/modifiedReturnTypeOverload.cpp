#include <iostream>

class A {
public:
    A()
    {
        std::cout << "constructor of A is called" << std::endl;
    }
};
class B {
public:
    B()
    {
        std::cout << "constructor of B is called" << std::endl;
    }

};


A foo1(int x)
{
    std::cout << "foo1 called" << std::endl;
    return A();
}

B foo2(int x)
{
    std::cout << "foo2 called" << std::endl;
    return B();
}


class C {
public:
    C(int x)
    :_x(x)
    {
        _used = false;
        std::cout << "constructor of C is called" <<std::endl;
    }

    ~C()
    {
        if (!_used) {
            std::cerr << "error: ambiguous use of function" << "overloaded on return type" << std::endl;
        }

    }

    operator A()
    {
        _used = true;
        std::cout << "operator A() is called" << std::endl;
        return foo1(_x);
    }

    operator B()
    {
        _used = true;
        std::cout << "operator B() is called" << std::endl;
        return foo2(_x);
    }
private:
    const int _x;
    bool _used;
};

C foo(int x)
{
    return C(x);
}

int main()
{
    A a;
    B b;
    a = foo(3);
    b = foo(4);
    foo(5);
    return 0;
}
