# 🎓 Student Database Management System (C)

A simple **Student Database Management System** built using the **C programming language**.
This console-based application allows users to **store, view, search, and delete student records** using file handling.

The program saves student information in a **binary file**, allowing data to persist even after the program closes.

---

# 🚀 Features

* ➕ Add new student records
* 📋 View all student records
* 🔎 Search student by roll number
* ❌ Delete student record
* 💾 Data stored using **file handling**
* 🖥️ Menu-driven console interface

---

# 🛠️ Technologies Used

* C Programming Language
* Structures (`struct`)
* File Handling (`fopen`, `fread`, `fwrite`)
* Conditional Statements
* Loops
* Standard Input / Output

---

# 📂 Project Structure

```id="ps1q9s"
Student-Database-System/
│
└── student_management.c
```

The program stores data inside the file:

```id="4h1srm"
student_info.dat
```

This file is automatically created when the first student record is added.

---

# 🧱 Student Structure

The program uses a **structure** to store student information.

```id="aqz4t7"
struct student{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
    char vill[20];
    float per;
};
```

Each student record contains:

* First Name
* Last Name
* Roll Number
* Class
* Address
* Percentage

---

# ⚙️ Program Menu

When the program runs, the user sees this menu:

```id="6b0g4g"
====== STUDENT DATABASE MANAGEMENT SYSTEM ======

1. Add Student Records
2. Student Records
3. Search Records
4. Delete Records
5. Exit
```

---

# ➕ Add Student Record

Allows the user to input student details.

Example:

```id="scl29o"
Enter First Name: John
Enter Last Name: Smith
Enter Roll Number: 12
Enter Class: 10
Enter Address: Delhi
Enter Percentage: 85.5
```

The record is saved in the file **student_info.dat**.

---

# 📋 View Student Records

Displays all stored students.

Example output:

```id="84x4zb"
==== STUDENT RECORDS ====

Name : John Smith
Roll : 12
Class : 10
Address : Delhi
Percentage : 85.50
------------------------
```

---

# 🔎 Search Student

Allows searching for a student using the **roll number**.

Example:

```id="9no09v"
Enter roll number to search: 12
```

Output:

```id="p6ttb8"
Student Found
Name : John Smith
Class : 10
Address : Delhi
Percentage : 85.50
```

---

# ❌ Delete Student Record

Deletes a student record using the roll number.

Process used:

1. Read the original file
2. Copy all records except the one to delete
3. Save them in a temporary file
4. Replace the original file

Example:

```id="7vhoy8"
Enter roll number to delete: 12
Record deleted successfully
```

---

# ▶️ How to Compile and Run

### Step 1 — Compile

```id="o0n9ta"
gcc student_management.c -o student
```

### Step 2 — Run

```id="91y49b"
./student
```

(Windows users can run)

```id="g7jplj"
student.exe
```

---

# 🧪 Sample Output

```id="g4acnt"
====== STUDENT DATABASE MANAGEMENT SYSTEM ======

1. Add Student Records
2. Student Records
3. Search Records
4. Delete Records
5. Exit

Enter your choice: 1
Enter First Name: Alex
Enter Last Name: Brown
Enter Roll Number: 5
Enter Class: 10
Enter Address: Mumbai
Enter Percentage: 91.2
```

---
# 📚 Concepts Practiced
This project demonstrates:
* Structures in C
* File Handling
* Binary File Storage
* Menu Driven Programs
* Searching Algorithms
* Data Deletion using Temporary Files
* Console Applications

---
# 📌 Future Improvements
Possible enhancements:
* Update student records
* Sort students by percentage
* Add student ID validation
* Use text file format (CSV)
* Add graphical interface
* Connect with database (MySQL)

---
# 👨‍💻 Author
Takundah Gorogodo

Computer Science Student | Software Developer

---
# 📄 License

This project is created for **learning and educational purposes**.
