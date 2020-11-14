/**
 *  Write a program to add two distances in inch-feet using structure.
 The values of the distances is to be taken from the user.
 */
#include <stdio.h>

struct Distance {
   int feet;
   float inch;
} d1, d2, result;

int main() {
   printf("Enter 1st distance\n");
   printf("Enter feet: ");
   scanf("%d", &d1.feet);
   printf("Enter inch: ");
   scanf("%f", &d1.inch);
 
   printf("\nEnter 2nd distance\n");
   printf("Enter feet: ");
   scanf("%d", &d2.feet);
   printf("Enter inch: ");
   scanf("%f", &d2.inch);

   result.feet = d1.feet + d2.feet;
   result.inch = d1.inch + d2.inch;

   while (result.inch >= 12.0) {
      result.inch = result.inch - 12.0;
      ++result.feet;
   }
   printf("\nSum of distances = %d\'-%.1f\"", result.feet, result.inch);
   return 0;
}