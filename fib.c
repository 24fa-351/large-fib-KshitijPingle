// Kshitij Pingle
// CWID: 885626978
// CPSC 351
// Assignment 2 - Large Numbered Fibonacci Sequence
// 22 September 2024

#include <stdio.h>
#include <stdlib.h>

// Function pointer
typedef unsigned long long (*FibFuncPtr)(unsigned long long max);

// Recursive Fibonacci Sequence
unsigned long long fib_recurse(unsigned long long max)
{

   if (max < 2)
   {
      return max;
   }
   return fib_recurse(max - 1) + fib_recurse(max - 2);
}

// Iterative Fibonacci Sequence
unsigned long long fib_iterate(unsigned long long n)
{

   unsigned long long temp = 0;
   unsigned long long previous = 0;
   unsigned long long current = 0;

   for (unsigned long long ix = 1; ix < n; ++ix)
   {
      temp = previous;
      previous = current;
      current += temp;

      if (ix == 1)
      {
         current++; // Update current on first iteration
      }
   }

   return current;
}

int main(unsigned long long argc, char *argv[])
{

   // Receive and process all passed arguments
   unsigned long long max = atoi(argv[1]);

   char fib_method = argv[2][0]; //"i" = iterative, "r" = recursive

   FibFuncPtr fib_routine;

   // Fibonnaci Sequence
   //  0 1 1 2 3 5 8 13 21 34 55 ...

   switch (fib_method)
   {
   case 'i':
      // Call Iterative Fibonacci Function
      fib_routine = fib_iterate;
      break;

   case 'r':
      // Call Recursive Fibonacci Function
      fib_routine = fib_recurse;
      --max;
      break;

   default:
      break;
   }

   unsigned long long fib_num = fib_routine(max);

   printf("%llu", fib_num); //'llu' means unsigned long long

   return 0;
}
