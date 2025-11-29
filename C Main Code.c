#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define NUM_SUBJECTS 5

typedef struct {
    int rollNo;
    char name[MAX_NAME];
    float marks[NUM_SUBJECTS];
    float total;
    float average;
    char grade;
} Student;

void inputStudents(Student *students, int n);
void calculateResults(Student *students, int n);
char calculateGrade(float avg);
void displayStudent(const Student *s);
void displayAll(const Student *students, int n);
void displayClassSummary(const Student *students, int n);
int findTopperIndex(const Student *students, int n);
void clearInputBuffer();

