// C program
#include <stdio.h>

// Add the given value to the sum of other values in a local array.
int sumValueWithOtherData( int value ) 
{
    int local_array[2];
    int* pElement = NULL;
    int sum = 0;

    // Fill the array with {10,20} using a pointer
    pElement = &local_array[0];
    *pElement++ = 10;
    *pElement++ = 20;

    // Add the 10 + 20 + value into 'result'
    sum = local_array[0] + local_array[1] + value;

    printf("Inside the function we find sum = %d\n", sum);

    // Clear out the array (This is the logic error)
    pElement[0] = 0;	// This is actually the same memory location that 'sum' exists at.
    pElement[1] = 0;    // This is the lower 32-bit portion of the address contained in pElement

    return sum;
}

void main()
{
    int value_to_add = 10;
    int result = -1;	   // Some initial value
    result = sumValueWithOtherData( value_to_add );
    printf("Returned value was %d\n", result); 
}
