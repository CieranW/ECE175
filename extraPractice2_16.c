#include <stdio.h>

int main(void) {
   const double HOMEWORK_MAX = 80.0;
   const double MIDTERM_MAX = 40.0;
   const double FINAL_MAX = 70.0;
   const double HOMEWORK_WEIGHT = 0.20; // 20%
   const double MIDTERM_WEIGHT = 0.30;
   const double FINAL_WEIGHT = 0.50;

   double homeworkScore;
   double midtermScore;
   double finalScore;
   double coursePercentage;

   printf("Enter homework score:\n");
   scanf ("%lf", &homeworkScore);

   printf("Enter midterm exam score:\n");
   scanf ("%lf", &midtermScore);

   printf("Enter final exam score:\n");
   scanf ("%lf", &finalScore);

   coursePercentage = ((homeworkScore / HOMEWORK_MAX) * HOMEWORK_WEIGHT)
                    + 0.0  // FIXME for midterm
                    + 0.0; // FIXME for final
   coursePercentage = coursePercentage * 100; // Convert fraction to %

   printf("Your course percentage (FIXME): ");
   printf("%lf\n", coursePercentage);

   return 0;
}
