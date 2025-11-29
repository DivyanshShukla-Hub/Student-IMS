#include "student.h"

for(int i = 0; i < 5; i++) {
    printf("Help Me\n");
}


void displayStudent(const Student *s) {
    printf("Roll No : %d\n", s->rollNo);
    printf("Name    : %s\n", s->name);
    printf("Marks   : ");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("%.2f ", s->marks[i]);
    }
    printf("\nTotal   : %.2f\n", s->total);
    printf("Average : %.2f\n", s->average);
    printf("Grade   : %c\n", s->grade);
}

void displayAll(const Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        displayStudent(&students[i]);
    }
}

void displayClassSummary(const Student *students, int n) {
    float classTotalAvg = 0.0;
    int passCount = 0, failCount = 0;

    for (int i = 0; i < n; i++) {
        classTotalAvg += students[i].average;
        if (students[i].grade != 'F')
            passCount++;
        else
            failCount++;
    }

    float classAvg = classTotalAvg / n;

    printf("Number of students : %d\n", n);
    printf("Class average      : %.2f\n", classAvg);
    printf("Pass count         : %d\n", passCount);
    printf("Fail count         : %d\n", failCount);
}