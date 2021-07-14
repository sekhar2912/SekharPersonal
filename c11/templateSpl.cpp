#include <iostream>

using namespace std;

// legal: base function template
template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType arg);

// legal: explicit/full function template specialization
template <>
std::string Foo<std::string, char>(char arg) { return "Full"; }

// illegal: partial function template specialization of the return type
//          function template partial specialization is not allowed
// template <typename ArgumentType>
// void Foo<void, ArgumentType>(ArgumentType arg);

// legal: overloads the base template for a pointer argument type
template <typename ReturnType, typename ArgumentType>
ReturnType Foo(ArgumentType *argPtr) { return "PtrOverload"; }

// legal: base function name reused. Not considered an overload. ill-formed: non-overloadable declaration (see below)
template <typename ArgumentType>
std::string Foo(ArgumentType arg) { return "Return1"; }

// legal: base function name reused. Not considered an overload. ill-formed: non-overloadable declaration (see below)
template <typename ReturnType>
ReturnType Foo(char arg) { return "Return2"; }



// note: to be compiled in conjunction with the definitions of Foo above

int main(int argc, char *argv[])
{
    char c = 'c';
    std::string r0, r1, r2, r3;
    // let the compiler resolve the call
    r0 = Foo(c);
    std::cout << "ro " << r0 << std::endl;
    // explicitly specify which function to call
    r1 = Foo<std::string>(c);
    std::cout << "r1 " << r1 << std::endl;
    r2 = Foo<std::string, char>(c);
    std::cout << "r2 " << r2 << std::endl;
    r3 = Foo<std::string, char>(&c);
    std::cout << "r3 " << r3 << std::endl;

    return 0;
}
