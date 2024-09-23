//Kshitij Pingle
//CWID: 885626978
//CPSC 351
//Assignment 2 - Large Numbered Fibonacci Sequence
//22 September 2024

#include <stdio.h>
#include <stdlib.h>

//Recursive Fibonacci Sequence
unsigned long long fib_recurse(unsigned long long n) {

   if (n < 2) {
      return n;
   }
   return fib_recurse(n - 1) + fib_recurse(n - 2);
}


//Iterative Fibonacci Sequence
unsigned long long fib_iterate(unsigned long long n) {
      
   unsigned long long temp = 0;
   unsigned long long previous = 0;
   unsigned long long current = 0;
   
   for (unsigned long long i = 1; i < n; ++i) {     //Sorry prof, I like my 'i' counter vars
      temp = previous;
      previous = current;
      current += temp;
      
      if (i == 1) {
         current++;     //Update current on first iteration
      }
      
   }

   return current;
}

int main(unsigned long long argc, char *argv[]) {

   //Receive and process all passed arguments
   unsigned long long num1 = atoi(argv[1]);

   char fib_method = argv[2][0];           //"i" = iterative, "r" = recursive

   unsigned long long num2 = 0;

   FILE *file = fopen(argv[3], "r");       //"r" = read

   fscanf(file, "%llu", &num2);            //Get single num from file
   fclose(file);

   unsigned long long max = num1 + num2;

   unsigned long long fib_num = 0;

   //Fibonnaci Sequence
      // 0 1 1 2 3 5 8 13 21 34 55 ...

   switch (fib_method) {
      case 'i':
         //Call Iterative Fibonacci Function
         fib_num = fib_iterate(max);
         break;

      case 'r':
         //Call Recursive Fibonacci Function
         //fib_num = fib_recurse_provider(max - 1);
         fib_num = fib_recurse(max - 1);
         break;
   
      default:
         break;
   }

   printf("%llu", fib_num);       //'llu' means unsigned long long

   return 0;
}
