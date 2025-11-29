# Student-IMS

 ## Project Overview
This project is a robust console-based application developed in C that demonstrates dynamic data management, structured programming, and core memory management concepts. It functions as a Smart Student Information Management System capable of handling records for an entire class, calculating academic results, and identifying the class topper.

The code adheres strictly to the principles of modularity and efficient memory usage, making it an excellent showcase of foundational C programming skills.

## Key Features 
The system fulfills the following core requirements:

Dynamic Class Size: Uses dynamic memory allocation (malloc) to create a flexible list of students, allowing the user to define the class size at runtime.

Structured Data Storage: Employs structures (struct) and an array of structures to logically store heterogeneous student data (Roll No, Name, Marks, Total, Average, Grade).

Academic Calculation: Automatically calculates the total marks, average score, and assigns a grade for each student.

Class Analytics: Displays a class summary including the number of students passed/failed and the overall class average.

Topper Identification: Efficiently finds and displays the details of the student with the highest total marks (Class Topper).

Robust Input Handling: Implements input validation and uses safe string handling (fgets) to prevent buffer overflows and correctly handle student names containing spaces.
