void inputStudents(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i+1);

        printf("Roll No: ");
        while (scanf("%d", &students[i].rollNo) != 1) {
            clearInputBuffer();
            printf("Enter again: ");
        }
        clearInputBuffer();

        printf("Name: ");
        fgets(students[i].name, MAX_NAME, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0;

        printf("Enter marks:\n");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("Subject %d: ", j+1);
            while (scanf("%f", &students[i].marks[j]) != 1 || students[i].marks[j] < 0) {
                clearInputBuffer();
                printf("Invalid. Enter again: ");
            }
        }
        clearInputBuffer();
    }
}

void displayStudent(const Student *s) {
    printf("\nRoll No : %d\n", s->rollNo);
    printf("Name    : %s\n", s->name);
    printf("Marks   : ");
    for (int i = 0; i < NUM_SUBJECTS; i++)
        printf("%.2f ", s->marks[i]);
    printf("\nTotal   : %.2f\n", s->total);
    printf("Average : %.2f\n", s->average);
    printf("CGPA    : %.2f / 10.0\n", s->cgpa);
    printf("Grade   : %c\n", s->grade);
}

void displayAll(const Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i+1);
        displayStudent(&students[i]);
    }
}