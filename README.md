# Student Management System

This C program implements a student management system using a linked list structure. It allows users to perform various operations on student data, such as adding, updating, searching, and deleting student records. The program also supports calculating the average GPA and finding the student with the highest GPA.

## Features

- **Add a student**: Insert new student records into the system.
- **Display all students**: Show a list of all students with their details (ID, Name, Age, GPA).
- **Search for a student by ID**: Find and display a student based on their ID.
- **Update student information**: Modify the data (Name, Age, or GPA) of an existing student.
- **Delete a student**: Remove a student record based on their ID.
- **Calculate average GPA**: Compute the average GPA of all students.
- **Find student with the highest GPA**: Automatically search and display the student with the highest GPA.
- **Input validation**: Ensures valid data entry for all fields (no numbers in name, valid age, GPA in the range of 0.0 to 4.0, and unique ID).

## Data Structures

### `struct student`
Represents an individual student's data:
- `int id`: Unique identifier for each student.
- `char name[50]`: Name of the student.
- `int age`: Age of the student.
- `float gpa`: Grade Point Average of the student (0.0 to 4.0).

### `struct node`
Represents a node in the linked list where each node contains:
- `struct student data`: The student's data.
- `struct node *next`: Pointer to the next node in the list.

## Functions

- **`addStudent`**: Adds a new student to the list.
- **`displayStudents`**: Displays all students.
- **`searchStudentByID`**: Searches for a student by their ID.
- **`updateStudent`**: Updates a student's information.
- **`deleteStudent`**: Deletes a student by their ID.
- **`calculateAverageGPA`**: Calculates and returns the average GPA of all students.
- **`searchHighestGPA`**: Finds and displays the student with the highest GPA.
- **`NumberinString`**: Validates that a student's name does not contain any numeric characters.

## How to Run

1. Clone or download the source code from the repository.
2. Compile the code using a C compiler:
   ```bash
   gcc -o student_management main.c
