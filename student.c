
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
    float cgpa;
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
int findStudentIndex(const Student *students, int n, int rollNo);
void searchStudentByRollNo(const Student *students, int n);
Student* insertStudent(Student *students, int *n);
void updateStudent(Student *students, int n);
Student* deleteStudent(Student *students, int *n);

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int n;
    Student *students = NULL;

    printf("===== Smart Student Information Management System =====\n\n");
    printf("Enter number of students: ");

    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }
    clearInputBuffer();

    if (n > 0) {
        students = (Student *)malloc(n * sizeof(Student));
        if (!students) {
            printf("Memory allocation failed.\n");
            return 1;
        }
        inputStudents(students, n);
        calculateResults(students, n);
    } else {
        printf("Starting with empty list.\n");
        n = 0;
    }
  if (n > 0) {
        printf("\n===== STUDENT DETAILS =====\n");
        displayAll(students, n);

        printf("\n===== CLASS SUMMARY =====\n");
        displayClassSummary(students, n);

        int topper = findTopperIndex(students, n);
        if (topper != -1) {
            printf("\n===== TOPPER =====\n");
            displayStudent(&students[topper]);
        }
    } else {
        printf("\n--- List is empty. ---\n");
    }

    char ch;
    printf("\nEnter Management Menu? (Y/N): ");
    scanf(" %c", &ch);
    clearInputBuffer();

    if (ch != 'Y' && ch != 'y') {
        printf("\nGoodbye!\n");
        free(students);
        return 0;
    }

    int choice;
    do {
        printf("\n===== MAIN MENU (Students: %d) =====\n", n);
        printf("1. Search by Roll No\n");
        printf("2. Insert Student\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Display All & Summary\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            clearInputBuffer();
            choice = -1;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: searchStudentByRollNo(students, n); break;
            case 2: 
                students = insertStudent(students, &n); 
                if (students) calculateResults(students, n);
                break;
            case 3: 
                updateStudent(students, n); 
                if (students) calculateResults(students, n);
                break;
            case 4: 
                students = deleteStudent(students, &n); 
                if (students) calculateResults(students, n);
                break;
            case 5:
                if (n > 0) {
                    displayAll(students, n);
                    printf("\n===== CLASS SUMMARY =====\n");
                    displayClassSummary(students, n);
                    int topper = findTopperIndex(students, n);
                    printf("\n===== TOPPER =====\n");
                    displayStudent(&students[topper]);
                } else {
                    printf("\n--- List empty. ---\n");
                }
                break;
            case 0: printf("\nGoodbye!\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    free(students);
    return 0;
}
