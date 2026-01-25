#include "data_lab.hpp"
#include <cstdint>

namespace data_lab {

int32_t add(int32_t a, int32_t b) {

    int32_t sum, carry;

    // Use and and xor to decompose addition
    sum = a ^ b; 
    carry = (a & b) << 1; 

    // We need to calculate sum + carry
    // This may generate a new carry, so we need to decompose again
    // The longest propagation of carry in a int32_t addition is 31 times,
    // so we repeat 31 times
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; carry = (a & b) << 1; 
    a = sum; b = carry; sum = a ^ b; 

    return sum;

}

int32_t subtract(int32_t a, int32_t b) {
    
    // a minus b is equivalent to a plus -b
    // Use 2-complement to get -b
    return add(a, add(~b, 1));

}

int32_t multiply(int32_t a, int32_t b) {

    int32_t result = 0;
    
    for (int32_t i = 0; i < 32; ++i) {
        if (1 << i & b) {
            result = add(result, a << i);
        }
    }

    return result;

}

int32_t divide(int32_t a, int32_t b) {
    return a / b;
}

int32_t modulo(int32_t a, int32_t b) {
    return a % b;
}

}  // namespace data_lab