# Student Record Management System (C)

A basic console project in C based on **DSA concepts: Arrays, Searching, Sorting**.

## Modules
| Module | Name | Features |
|--------|------|----------|
| 1 | Student Registration and Record Storage | Add student (roll no, name, branch, marks) into an array, update, delete, duplicate roll no check |
| 2 | Display and Report | Tabular display, student-wise report, branch-wise report, total student count |
| 3 | Searching | Linear search by roll no and by name, handles record-not-found |
| 4 | Sorting and Ranking | Bubble sort by roll no / name / marks, rank list, top 3 topper list |

## Run
```
gcc student_management.c -o sms
./sms
```

## Notes
- Stores up to 50 students in an array of structures.
- Enter name and branch without spaces (e.g. `Asha_Sharma`).
- Data is kept in memory only (not saved after exit).
