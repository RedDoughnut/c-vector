# cpp-python-vector
A vector implementation in CPP python.h, inspired by C++'s `std::vector` (this one is integer only)

Includes an example in main function

Functions:
no
  
Compile and execute with: (Linux)
```
gcc -o vector vector.cpp \
$(python3-config --cflags --embed) \
-F/Library/Frameworks \
-framework Python
```
