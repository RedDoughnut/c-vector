#include <Python.h>
#include <stdio.h>

int main() {

    Py_Initialize();

    PyRun_SimpleString("a = []; a.append(1); a.append(2)\nfor i in a:\n    print(i)");

    if (Py_FinalizeEx() < 0) {
        return 120;
    }

    return 0;
}