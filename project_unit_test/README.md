# 🧪 Unit Test for `cmd_line.c` (Embedded CLI Parser)

## 📌 Overview

This project demonstrates how to write **unit tests for embedded C code** (`cmd_line.c`) and run them on a **Linux environment** without hardware.

It simulates:

* CLI command parsing
* Function dispatch
* RTOS-like behavior (optional)

---

## 🎯 Objectives

* Validate `cmd_line_parser()` logic
* Achieve high test coverage
* Run tests on Linux (host-based testing)
* Support embedded development workflow (CI/CD ready)

---

## 📂 Project Structure

```
project/
├── src/
│   └── cmd_line.c
├── include/
│   └── cmd_line.h
├── test/
│   ├── test_cmd_line.c
├── mock/
│   └── xprintf.h
└── Makefile

---

## ⚙️ Build & Run

### 🔹 Build

```bash
make
```

### 🔹 Run unit tests

```bash
./test_runner
```

### 🔹 Run RTOS simulation test

```bash
make run
```

### 🔹 Clean build

```bash
make clean
```

---

## 🧪 Test Coverage

### ✅ Tested Scenarios

| Test Case            | Description                   | Expected Result   |
| -------------------- | ----------------------        | ----------------- |
| CMD_SUCCESS          | Valid command (`help`)        | Function executed |
| CMD_TBL_NOT_FOUND    | NULL command table            | Error returned    |
| CMD_TOO_LONG         | aaaaaaaaaaaaaaaaaaaaaaaaaaaaa | Error returned    |
| CMD_NOT_FOUND        | uart2                         | Error returned    |

---

## 🧠 Test Strategy

### ✔ Data-driven testing

Test cases are defined in a structure:

```c
typedef struct {
    char *name_test;
    pf_cmd_func func;
    uint8_t* cmd;
    int8_t expected_result;
} test_case_t;
```

---

### ✔ Command table simulation

```c
cmd_line_t test_data[] = {
    {(uint8_t*)"help", mock_func},
    {0, 0}
};
```

---

### ✔ Mock function

```c
void mock_func(uint8_t *cmd) {
    func_called++;
}
```

---

### ✔ Test runner

```c
void run_test(test_case_t *tc) {
    uint8_t ret = cmd_line_parser(test_data, tc->cmd);

    if (ret == tc->expected_result) {
        printf("[PASS]: %s\n", tc->name_test);
    } else {
        printf("[FAIL]: %s\n", tc->name_test);
    }
}
```

---

## 🔄 RTOS Simulation (Advanced)

The project includes a **fake RTOS layer** to simulate:

* Task (`pthread`)
* Queue
* CLI task loop

### Example flow:

```
Test → Queue → CLI Task → cmd_line_parser → Handler
```

---

## 🚀 Advanced Features

* Host-based testing (no hardware required)
* Mocked dependencies (`xprintf`)
* RTOS simulation (FreeRTOS-like)
* Extendable for CI/CD pipelines

---

## 📊 Optional: Code Coverage

To enable coverage:

```bash
gcc -fprofile-arcs -ftest-coverage ...
gcov src/cmd_line.c
```

---

## 🧩 Future Improvements

* Integrate **Ceedling**
* Add **fuzz testing**
* Add **GitHub Actions CI**
* Port to real **FreeRTOS POSIX**

---

## 👨‍💻 Author

Embedded Developer

* C / C++ / RTOS / IoT
* Focus on testable and scalable embedded systems

---

## 📌 Notes

* Designed for learning & professional embedded testing
* Works on Linux (Ubuntu recommended)
* No MCU required

---
