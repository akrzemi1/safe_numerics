#include <cassert>
#include <stdexcept>
#include <iostream>

#include "../include/safe_integer.hpp"
//#include "../include/safe_compare.hpp"

void detected_msg(bool detected){
    std::cout << (detected ? "error detected!" : "error NOT detected! ") << std::endl;
}

int main(int argc, const char * argv[]){
    std::cout << "example 3: ";
    std::cout << "implicit conversions change data values" << std::endl;
    std::cout << "Not using safe numerics" << std::endl;
    try{
        int x = -1000;
        // the following silently produces an incorrect result
        char y = x;
        detected_msg(false);
    }
    catch(...){
        assert(false); // never arrive here
    }
    // solution: replace int with safe<int> and char with safe<char>
    std::cout << "Using safe numerics" << std::endl;
    try{
        using namespace boost::numeric;
        safe<int> x = -1000;
        // throws exception when conversion change data value
        safe<char> y = x;
        assert(false); // never arrive here
    }
    catch(std::range_error & e){
        std::cout << e.what() << std::endl;
        detected_msg(true);
    }
    return 0;
}
