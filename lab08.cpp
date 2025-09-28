#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned);
unsigned fib(unsigned);
unsigned mult(unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    //cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Function definitions below are NOT tail recursive!
 * TODO: make them tail recursive :)
*******************************************************************************/

// Helper function: The actual tail-recursive implementation
unsigned fact_tail_rec(unsigned n, unsigned acc) {
    if (n <= 1) {
        return acc; // Base case returns the accumulated result
    }
    // Recursive call is the LAST operation, passing the new accumulated result (acc * n)
    return fact_tail_rec(n - 1, acc * n);
}

// Wrapper function for the public interface
unsigned fact(unsigned n) {
    return fact_tail_rec(n, 1); // Start with acc = 1
}

// Helper function: The actual tail-recursive implementation
// 'curr' holds F(n), 'next' holds F(n+1)
unsigned fib_tail_rec(unsigned n, unsigned a, unsigned b) {
    if (n == 0) {
        return a; // Base case: 'a' will hold F(0)
    }
    // Recursive call is the LAST operation
    // The next call shifts the sequence: F(n-1) becomes 'b', and F(n) becomes 'a + b'
    return fib_tail_rec(n - 1, b, a + b);
}

// Wrapper function for the public interface
unsigned fib(unsigned n) {
    // F(0)=0, F(1)=1. We start the sequence with these:
    return fib_tail_rec(n, 0, 1);
}

// Tail-recursive helper function
unsigned mult_tail_recursive_helper(unsigned x, unsigned y, unsigned accumulator) {
    // base case
    if (y == 0) {
        return accumulator; // Return the accumulated result
    }
    // recursive case
    // The recursive call is the very last operation, making it tail-recursive
    return mult_tail_recursive_helper(x, y - 1, accumulator + x);
}

// Main function to start the tail-recursive process
unsigned mult(unsigned x, unsigned y) {
    return mult_tail_recursive_helper(x, y, 0);
}

// Helper function: The actual tail-recursive implementation
unsigned power_tail_rec(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) {
        return acc; // Base case returns the accumulated result
    }
    // Recursive call is the LAST operation, multiplying acc by x
    return power_tail_rec(x, y - 1, acc * x);
}

// Wrapper function for the public interface
unsigned power(unsigned x, unsigned y) {
    return power_tail_rec(x, y, 1); // Start with acc = 1
}

// Helper function: The actual tail-recursive implementation for Range Product
unsigned product_tail_rec(unsigned current, unsigned y, unsigned acc) {
    if (current > y) { // Check if 'current' has passed the upper bound 'y'
        return acc;    // Base case returns the accumulated result
    }
    // Recursive call is the LAST operation, multiplying acc by the current number
    return product_tail_rec(current + 1, y, acc * current);
}

// Wrapper function for the public interface (calculates x * (x+1) * ... * y)
unsigned product(unsigned x, unsigned y) {
    // Assuming x <= y for a valid range product. If x > y, it should probably return 1.
    if (x > y) return 1;
    return product_tail_rec(x, y, 1); // Start with current=x and acc=1
}
