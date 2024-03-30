#include <stdio.h>

#define STUDENTS 3  
#define SUBJECTS 5

int main() {
    int marks[STUDENTS][SUBJECTS]; 
    int totalStudents[STUDENTS];   
    int totalSubjects[SUBJECTS] = {0};   
    float averageSubjects[SUBJECTS];

 
    printf("Enter marks for %d students and %d subjects:\n", STUDENTS, SUBJECTS);
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d:\n", i + 1);
        totalStudents[i] = 0; 
        for (int j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            totalStudents[i] += marks[i][j]; 
            totalSubjects[j] += marks[i][j];
        }
    }


    for (int i = 0; i < SUBJECTS; i++) {
        averageSubjects[i] = (float)totalSubjects[i] / STUDENTS;
    }

    printf("\nTotal marks for each student:\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("Student %d: %d\n", i + 1, totalStudents[i]);
    }


    printf("\nAverage marks for each subject:\n");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d: %.2f\n", i + 1, averageSubjects[i]);
    }

    return 0;
}