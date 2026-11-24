#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[30];
    char branch[20];
    float marks;
};

struct Student s[50];
int n = 0;             

int findByRoll(int roll) {
    int i;
    for (i = 0; i < n; i++) {
        if (s[i].roll == roll) return i;
    }
    return -1;   /* not found */
}

void printHeader() {
    printf("\n%-8s%-15s%-12s%s\n", "Roll", "Name", "Branch", "Marks");
}

void printRow(int i) {
    printf("%-8d%-15s%-12s%.2f\n", s[i].roll, s[i].name, s[i].branch, s[i].marks);
}

void addStudent() {
    int roll;
    if (n == 50) { printf("List is full!\n"); return; }
    printf("Roll no: ");
    scanf("%d", &roll);
    if (findByRoll(roll) != -1) {            /* duplicate check */
        printf("Roll no already exists!\n");
        return;
    }
    s[n].roll = roll;
    printf("Name (no spaces): ");
    scanf("%29s", s[n].name);
    printf("Branch: ");
    scanf("%19s", s[n].branch);
    do {
        printf("Marks (0-100): ");
        scanf("%f", &s[n].marks);
    } while (s[n].marks < 0 || s[n].marks > 100);
    n++;
    printf("Student added.\n");
}

void updateStudent() {
    int roll, i;
    printf("Roll no to update: ");
    scanf("%d", &roll);
    i = findByRoll(roll);
    if (i == -1) { printf("Student not found!\n"); return; }
    printf("New name: ");
    scanf("%29s", s[i].name);
    printf("New branch: ");
    scanf("%19s", s[i].branch);
    printf("New marks: ");
    scanf("%f", &s[i].marks);
    printf("Record updated.\n");
}

void deleteStudent() {
    int roll, i, j;
    printf("Roll no to delete: ");
    scanf("%d", &roll);
    i = findByRoll(roll);
    if (i == -1) { printf("Student not found!\n"); return; }
    for (j = i; j < n - 1; j++) {            /* shift elements left */
        s[j] = s[j + 1];
    }
    n--;
    printf("Record deleted.\n");
}

void displayAll() {
    int i;
    if (n == 0) { printf("No records.\n"); return; }
    printHeader();
    for (i = 0; i < n; i++) printRow(i);
    printf("\nTotal students: %d\n", n);
}

void studentReport() {
    int roll, i;
    printf("Roll no: ");
    scanf("%d", &roll);
    i = findByRoll(roll);
    if (i == -1) { printf("Student not found!\n"); return; }
    printf("\n--- Student Report ---\n");
    printf("Roll   : %d\nName   : %s\nBranch : %s\nMarks  : %.2f\n",
           s[i].roll, s[i].name, s[i].branch, s[i].marks);
}

void branchReport() {
    char branch[20];
    int i, count = 0;
    float sum = 0;
    printf("Branch: ");
    scanf("%19s", branch);
    printHeader();
    for (i = 0; i < n; i++) {
        if (strcmp(s[i].branch, branch) == 0) {
            printRow(i);
            count++;
            sum += s[i].marks;
        }
    }
    if (count == 0) printf("No students in this branch.\n");
    else printf("\nStudents: %d   Average marks: %.2f\n", count, sum / count);
}

void searchByName() {
    char name[30];
    int i, found = 0;
    printf("Name: ");
    scanf("%29s", name);
    for (i = 0; i < n; i++) {
        if (strcmp(s[i].name, name) == 0) {
            if (!found) printHeader();
            printRow(i);
            found = 1;
        }
    }
    if (!found) printf("Student not found!\n");
}

void searchByRoll() {
    int roll, i;
    printf("Roll no: ");
    scanf("%d", &roll);
    i = findByRoll(roll);
    if (i == -1) { printf("Student not found!\n"); return; }
    printHeader();
    printRow(i);
}

void bubbleSort(int by) {
    int i, j, swap;
    struct Student temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            swap = 0;
            if (by == 1 && s[j].roll > s[j + 1].roll) swap = 1;
            if (by == 2 && strcmp(s[j].name, s[j + 1].name) > 0) swap = 1;
            if (by == 3 && s[j].marks < s[j + 1].marks) swap = 1;
            if (swap) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

void sortStudents() {
    int by;
    printf("Sort by: 1.Roll no  2.Name  3.Marks : ");
    scanf("%d", &by);
    if (by < 1 || by > 3) { printf("Invalid choice!\n"); return; }
    bubbleSort(by);
    displayAll();
}

void rankList() {
    int i;
    if (n == 0) { printf("No records.\n"); return; }
    bubbleSort(3);
    printf("\n%-8s%-8s%-15s%-12s%s\n", "Rank", "Roll", "Name", "Branch", "Marks");
    for (i = 0; i < n; i++) {
        printf("%-8d%-8d%-15s%-12s%.2f\n", i + 1, s[i].roll, s[i].name, s[i].branch, s[i].marks);
    }
}

void topperList() {
    int i;
    if (n == 0) { printf("No records.\n"); return; }
    bubbleSort(3);
    printf("\n--- Top 3 Students ---");
    printHeader();
    for (i = 0; i < n && i < 3; i++) printRow(i);
}

int main() {
    int choice;
    do {
        printf("\n===== STUDENT RECORD MANAGEMENT =====\n");
        printf("Module 1: 1.Add  2.Update  3.Delete\n");
        printf("Module 2: 4.Display all  5.Student report  6.Branch report\n");
        printf("Module 3: 7.Search by roll no  8.Search by name\n");
        printf("Module 4: 9.Sort  10.Rank list  11.Topper list\n");
        printf("0.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: updateStudent(); break;
            case 3: deleteStudent(); break;
            case 4: displayAll(); break;
            case 5: studentReport(); break;
            case 6: branchReport(); break;
            case 7: searchByRoll(); break;
            case 8: searchByName(); break;
            case 9: sortStudents(); break;
            case 10: rankList(); break;
            case 11: topperList(); break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
    return 0;
}
