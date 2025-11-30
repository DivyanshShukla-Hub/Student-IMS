#include <stdio.h>

#define MAX 50

int main() {
    int roll;
    char name[MAX];

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", name);  // takes full name

    printf("\n--- Student Details ---\n");
    printf("Roll Number: %d\n", roll);
    printf("Name: %s\n", name);

    return 0;
}


