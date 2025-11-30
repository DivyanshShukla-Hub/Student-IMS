

char calculateGrade(float avg) {
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    return 'F';
}

void calculateResults(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        students[i].total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++)
            students[i].total += students[i].marks[j];

        students[i].average = students[i].total / NUM_SUBJECTS;
        students[i].cgpa = students[i].average / 10.0;
        students[i].grade = calculateGrade(students[i].average);
    }
}

void displayClassSummary(const Student *students, int n) {
    float sum = 0;
    int pass = 0, fail = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].average;
        if (students[i].grade == 'F') fail++;
        else pass++;
    }
    printf("Total Students : %d\n", n);
    if(n > 0) printf("Class Average  : %.2f\n", sum / n);
    printf("Pass Count     : %d\n", pass);
    printf("Fail Count     : %d\n", fail);
}

int findTopperIndex(const Student *students, int n) {
    if (n == 0) return -1;
    int top = 0;
    for (int i = 1; i < n; i++)
        if (students[i].total > students[top].total)
            top = i;
    return top;
}