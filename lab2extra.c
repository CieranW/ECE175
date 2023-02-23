#include <stdio.h>
#include <math.h>

int main(void)
{

    // Problem 1
    int num1, num2, num3;

    printf("Enter three integers separated by a space: \n");
    scanf("%d %d %d", &num1, &num2, &num3);

    if ((num1 > num2 && num1 > num3) || (num1 == num2 || num1 == num3))
    {
        printf("Max integer: %d.\n", num1);
    }
    else if (num2 > num1 && num2 > num3)
    {
        printf("Max integer: %d.\n", num2);
    }
    else if (num1 == num2 || num1 == num3)
    {
        printf("Max integer: %d.\n", num1);
    }
    else
    {
        printf("Max integer: %d.\n", num3);
    }

    // Problem 2
    float studentNumGrade;

    printf("Enter your numeric grade: \n");
    scanf("%f", &studentNumGrade);

    if (studentNumGrade <= 4.0 && studentNumGrade >= 3.5)
    {
        printf("Your letter grade is: A\n");
    }
    else if (studentNumGrade < 3.5 && studentNumGrade >= 2.5)
    {
        printf("Your letter grade is: B\n");
    }
    else if (studentNumGrade < 2.5 && studentNumGrade >= 1.5)
    {
        printf("Your letter grade is: C\n");
    }
    else if (studentNumGrade < 1.5 && studentNumGrade >= 0.5)
    {
        printf("Your letter grade is: D\n");
    }
    else if (studentNumGrade < 0.5 && studentNumGrade >= 0.0)
    {
        printf("Your letter grade is: F\n");
    }
    else
    {
        printf("Please enter a valid numerical value within 4.0 and 0.\n");
    }

    // Problem 3
    float grade1, grade2, grade3, grade1_2difference;

    printf("Enter the grades by the two graders: \n");
    scanf("%f %f", &grade1, &grade2);
    printf("Enter the maximum difference between the two grades: \n");
    scanf("%f", &grade1_2difference);

    if (fabs(grade1 - grade2) < grade1_2difference)
    {
        printf("The final grade is: %.2f", (grade1 - grade2) / 2);
    }
    else
    {
        printf("Enter the grade of the third grader: \n");
        scanf("%f", &grade3);
    }
    return 0;
}