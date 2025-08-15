# 🧸 C Cuddle – A DataFrame Library in C

## 📌 Overview

**C Cuddle** is a C library designed to mimic the core functionality of Python's pandas DataFrame, implemented as part of the first-year project at Epitech. The project focuses on creating a minimal data analysis library in pure C, capable of reading CSV files and performing essential data manipulation operations.

This project was an opportunity to explore data structures, memory management, algorithm optimization, and software design in a low-level language.

---

## 🧠 Objectives

- Recreate fundamental features of a DataFrame (like in pandas) in C.
- Handle structured tabular data: reading, writing, filtering, grouping, and applying transformations.
- Work with custom data types and generic function pointers.
- Deepen understanding of memory allocation and pointer logic.
- Develop reusable, testable, and modular C code.

---

## ⚙️ Features Implemented

### 📄 Basic I/O

- `df_read_csv`: Load a CSV file into a structured `dataframe_t`.
- `df_write_csv`: Export a `dataframe_t` back to CSV format.

### 🧾 Data Inspection

- `df_info`: Display column names and types.
- `df_describe`: Display count, mean, std, min, and max for numerical columns.

### 🔍 Data Filtering

- `df_filter`: Filter rows based on a condition (function pointer).

### 📊 Data Sorting

- `df_sort`: Return a new dataframe sorted based on a specified column.

### 🔢 Data Overview

- `df_head`: Display the first `n` rows of the dataframe.
- `df_tail`: Display the last `n` rows of the dataframe.
- `df_shape`: Print the number of rows and columns in the dataframe (`X rows × Y columns`).

### ▶️ Example Execution (main.c)

### 🧱 Makefile Commands

- `make`: Compile all source files (excluding `main.c`) into object files and archive them into the static library `libcuddle.a`.

- `make debug`: Build the static library and compile `src/main.c` to generate the executable `cuddle`. This is the target to use when you want to test your project with your custom `main.c`.

- `make clean`: Remove all object files and temporary build artifacts from the `src/` directory.

- `make fclean`: Perform `make clean` and also remove the compiled library (`libcuddle.a`) and the executable (`cuddle`).

- `make re`: Shortcut to fully clean and rebuild the project (equivalent to `make fclean` followed by `make`).

- `make test`: Perform a full rebuild (`make re`) and compile the executable (`make debug`) in one step to test the executable.

- `make coding_style`: Run the Epitech coding style checker and display the report. It uses the `coding-style.sh` script and outputs results to `coding-style-reports.log`.

- `make push`: Clean all build files and remove the coding style report file. This is intended to prepare your project directory before pushing it to Git.


- `df_read_csv`: Load the CSV file `data.csv` into a `dataframe_t`.
- `df_info`: Display the column names and their types.
- `df_describe`: Output summary statistics for the numerical columns.
- `df_shape`: Retrieve and print the number of rows and columns in the dataframe.
- `df_filter`: Keep only the rows where the `"age"` column is greater than 30.
- `df_head`: Extract the first `n` rows (with both valid and oversized values).
- `df_tail`: Extract the last `n` rows (with both valid and oversized values).
- `df_write_csv`: Export all processed dataframes into separate CSV files:
  - `result.csv`: Full original dataframe.
  - `basic head.csv`: First 3 rows.
  - `basic tail.csv`: Last 3 rows.
  - `null head.csv`: Attempt to get first 15 rows (more than available).
  - `all tail.csv`: Attempt to get last 15 rows (more than available).
  - `filtered.csv`: Filtered rows where `age > 30`.
- Once built with `make test`, run the executable using `./cuddle` to test your implementation with the current `main.c`.

This `main.c` file provides a complete demonstration of the library’s core functionalities in a single run. You can modify it as you want to make your own test.
