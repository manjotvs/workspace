////////////////////////////////////////////////////////////////////////////////
// 6) Unit Testing (10 points)
//    Write a unit test for validatePointerAndData that exercises all code paths
//    and branch conditions

// @param dataPtr - int32_t pointer to data to be used
//
// @return TRUE if pointer is non-NULL, data value is positive, non-zero and not
//         equal to the sentinel value 0x7FFFFFFF, FALSE otherwise
//

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

#define SENTINEL_VALUE 0x7FFFFFFF

bool validatePointerAndData(int32_t* dataPtr) {
    if (dataPtr == NULL) {
        return false;
    }

    int32_t data = *dataPtr;
    if (data <= 0 || data == SENTINEL_VALUE) {
        return false;
    }

    return true;
}

void swapNibbleHighestBits(uint8_t* b)
{
    uint8_t mask1 = 0x80; // mask for the highest bit in the first nibble
    uint8_t mask2 = 0x08; // mask for the highest bit in the second nibble
    uint8_t nibble1 = (*b >> 7) & 0x01; // extract the first nibble
    uint8_t nibble2 = (*b >> 3) & 0x01; // extract the second nibble

    // swap the highest bits in each nibble
    if ((nibble1) != (nibble2)) {
        *b ^= 0x1<<3;
        *b ^= 0x1<<7;
    }

}

int main() {
    int32_t valid_data = 42;
    int32_t* valid_data_ptr = &valid_data;
    assert(validatePointerAndData(valid_data_ptr));

    int32_t negative_data = -42;
    int32_t* negative_data_ptr = &negative_data;
    assert(!validatePointerAndData(negative_data_ptr));

    int32_t zero_data = 0;
    int32_t* zero_data_ptr = &zero_data;
    assert(!validatePointerAndData(zero_data_ptr));

    int32_t sentinel_data = SENTINEL_VALUE;
    int32_t* sentinel_data_ptr = &sentinel_data;
    assert(!validatePointerAndData(&sentinel_data));

    int32_t* null_data_ptr = NULL;
    assert(!validatePointerAndData(null_data_ptr));

    printf("All tests passed.\n");

    uint8_t a = 0x80;
    swapNibbleHighestBits(&a);
    printf("a: %d\n", a);
    return 0;
}