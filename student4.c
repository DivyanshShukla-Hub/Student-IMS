
int findStudentIndex(const Student *students, int n, int rollNo) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollNo == rollNo)
            return i;
    }
    return -1;
}

void searchStudentByRollNo(const Student *students, int n) {
    if (n == 0) {
        printf("\n--- List empty ---\n");
        return;
    }
    int roll;
    printf("Enter Roll No: ");
    while (scanf("%d", &roll) != 1) {
        printf("Invalid. Enter again: ");
        clearInputBuffer();
    }
    clearInputBuffer();

    int idx = findStudentIndex(students, n, roll);
    if (idx == -1) printf("\nRoll No %d not found.\n", roll);
    else {
        printf("\nStudent found:\n");
        displayStudent(&students[idx]);
    }
}

Student* insertStudent(Student *students, int *n) {
    printf("\n--- INSERT STUDENT ---\n");
    int roll;
    do {
        printf("Enter NEW Roll No: ");
        if (scanf("%d", &roll) != 1) {
            clearInputBuffer(); roll = -1; continue;
        }
        clearInputBuffer();
        if (findStudentIndex(students, *n, roll) != -1) {
            printf("Roll No exists. Enter unique Roll No.\n");
            roll = -1;
        }
    } while (roll == -1);

    Student *newList = (Student *)realloc(students, (*n + 1) * sizeof(Student));
    if (!newList) { printf("Memory error.\n"); return students; }
    students = newList;
    int idx = *n;
    (*n)++;
    students[idx].rollNo = roll;

    printf("Enter Name: \n");
    fgets(students[idx].name, MAX_NAME, stdin);
    students[idx].name[strcspn(students[idx].name, "\n")] = 0;

    printf("Enter %d subject marks:\n", NUM_SUBJECTS);
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject %d: ", i+1);
        while (scanf("%f", &students[idx].marks[i]) != 1 || students[idx].marks[i] < 0) {
            clearInputBuffer(); printf("Invalid. Enter again: ");
        }
    }
    clearInputBuffer();
    printf("\nStudent inserted successfully.\n");
    return students;
}

void updateStudent(Student *students, int n) {
    if (n == 0) { printf("\n--- List empty ---\n"); return; }
    int roll;
    printf("Enter Roll No to update: ");
    if (scanf("%d", &roll) != 1) { clearInputBuffer(); return; }
    clearInputBuffer();
    int idx = findStudentIndex(students, n, roll);
    if (idx == -1) { printf("Roll No not found.\n"); return; }

    printf("Enter NEW Name: ");
    fgets(students[idx].name, MAX_NAME, stdin);
    students[idx].name[strcspn(students[idx].name, "\n")] = 0;
    printf("Enter NEW marks:\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject %d: ", i+1);
        while (scanf("%f", &students[idx].marks[i]) != 1 || students[idx].marks[i] < 0) {
            clearInputBuffer(); printf("Invalid. Enter again: ");
        }
    }
    clearInputBuffer();
    printf("Student updated.\n");
}

Student* deleteStudent(Student *students, int *n) {
    if (*n == 0) { printf("\n--- List empty ---\n"); return students; }
    int roll;
    printf("Enter Roll No to delete: ");
    if (scanf("%d", &roll) != 1) { clearInputBuffer(); return students; }
    clearInputBuffer();
    int idx = findStudentIndex(students, *n, roll);
    if (idx == -1) { printf("Roll No not found.\n"); return students; }

    for (int i = idx; i < *n - 1; i++) students[i] = students[i + 1];
    (*n)--;
    if (*n == 0) {
        printf("\nStudent deleted. List now empty.\n");
        free(students);
        return NULL;
    }
    Student *newList = (Student *)realloc(students, (*n) * sizeof(Student));
    if (!newList) { printf("Realloc failed. Data safe."); return students; }
    printf("\nStudent deleted.\n");
    return newList;
}