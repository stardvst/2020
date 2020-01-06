// run with valgrind
// run with /usr/bin/time (+valgrind)

#include <string>
#include <iostream>

struct S
{
    static const std::string &getMagic()
    {
        // double-checked locking is performed for initializing this (since c++11) 
        static const std::string m{ "magic" };
        return m;
    }

    const std::string &s = getMagic();

    const std::string &getMagicRef() const
    {
        // no overhead, returns "cached" member data
        return s;
    }
};

auto main() -> int
{
    /*
    S::getMagic().size();
    S::getMagic().size();
    S::getMagic().size();
    return S::getMagic().size();
    */

    S o;
    /*
    o.s.size();
    o.s.size();
    o.s.size();
    return o.s.size();
    */

    //o.getMagicRef().size();
    //o.getMagicRef().size();
    //o.getMagicRef().size();
    //return o.getMagicRef().size();

    std::size_t total = 0;
    for (auto i = 0; i < 100000000; ++i)
        //total += o.getMagicRef().size() + i;
        total += o.getMagic().size() + i;

    std::cout << total << '\n';

    return 0;
}