// This program stores student data, calculates total, percentage, grade, topper and average

#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percent;
    char grade;
};

int main() {
    int n, i, j;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    for(i = 0; i < n; i++) {
        printf("\nEnter roll and name: ");
        scanf("%d %s", &s[i].roll, s[i].name);

        s[i].total = 0;

        printf("Enter marks of 5 subjects:\n");
        for(j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percent = s[i].total / 5.0;

        if(s[i].percent >= 90) s[i].grade = 'A';
        else if(s[i].percent >= 75) s[i].grade = 'B';
        else if(s[i].percent >= 50) s[i].grade = 'C';
        else s[i].grade = 'F';
    }

    int topper = 0;
    float class_total = 0;

    for(i = 0; i < n; i++) {
        class_total += s[i].percent;

        if(s[i].percent > s[topper].percent) {
            topper = i;
        }
    }

    printf("\nTopper: %s\n", s[topper].name);

    printf("\nStudents who failed:\n");
    for(i = 0; i < n; i++) {
        if(s[i].grade == 'F') {
            printf("%s\n", s[i].name);
        }
    }

    printf("\nClass average = %.2f\n", class_total / n);

    return 0;
}