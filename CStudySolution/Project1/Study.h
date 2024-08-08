#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {}
};

class Derived1 : public Base {
public:
    void Method1() {
        std::cout << "Method1 in Derived1 called" << std::endl;
    }
};

class Derived2 : public Base {
public:
    void Method2() {
        std::cout << "Method2 in Derived2 called" << std::endl;
    }
};

void TestDynamicCast(Base* basePtr) {
    Derived1* derived1Ptr = dynamic_cast<Derived1*>(basePtr);
    if (derived1Ptr) {
        derived1Ptr->Method1();
    } else {
        std::cout << "Failed to cast to Derived1" << std::endl;
    }

    Derived2* derived2Ptr = dynamic_cast<Derived2*>(basePtr);
    if (derived2Ptr) {
        derived2Ptr->Method2();
    } else {
        std::cout << "Failed to cast to Derived2" << std::endl;
    }
}

int main() {
    Base* basePtr1 = new Derived1;
    TestDynamicCast(basePtr1);
    delete basePtr1;

    Base* basePtr2 = new Derived2;
    TestDynamicCast(basePtr2);
    delete basePtr2;

    return 0;
}