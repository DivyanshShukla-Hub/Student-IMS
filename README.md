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



 ## C Concepts Demonstrated

Structures & Arrays : The Student struct is defined, and Student *students is used to manage an array of structures dynamically.
Dynamic Memory : The function malloc() is used in main() to allocate memory for the student list, and free() is used to release it.
Pointers : Pointers are used extensively, particularly in passing the dynamic student array (Student *students) to functions like inputStudents and calculateResults.
Functions & Modularity : The code is organized into separate, reusable functions (inputStudents, calculateResults, displayStudent, etc.) for clear separation of concerns.
Control Structures : for loops handle input and calculation repetition, and if-else if chains in calculateGrade() implement the conditional logic.





