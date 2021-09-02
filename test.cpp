#include <iostream>
struct test
{
    int m1;
    double m2;
};


int main(int argc, char const *argv[])
{
    test a[10];

    std::cout << "size: " << sizeof(test) << std::endl;
    std::cout << "alignment: " << alignof(test) << std::endl;
    std::cout << "[0]: " << a << std::endl;
    std::cout << "[1]: " << a + 1 << std::endl;
    auto d = offsetof(test, m2);
    std::cout << "m2 offset: " << (typeid(d) == typeid(0UL)) << std::endl;
    return 0;
}
