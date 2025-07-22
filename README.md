# _printf
A copy of the printf function in C

## 📌 Requirements for this project

- Code must comply with the Betty style and document checks.
- Compile code using flags: `-Wall`, `-Werror`, `-Wextra`, `-pedantic`, `-Wno-format`.
- Function prototypes should be included in header file `main.h`.
- Header files should be include guarded.
- Authorized functions and macros:
  - [x] write (man 2 write)
  - [ ] malloc (man 3 malloc)
  - [ ] free (man 3 free)
  - [x] write (man 2 write)
  - [x] va_end (man 3 va_end)
  - [ ] va_copy (man 3 va_copy)
  - [x] va_arg (man 3 va_arg)

## 📃 Files
| File         | Description                          |
|--------------|--------------------------------------|
| `_printf.c`  | Main logic of the `_printf` function |
| `main.h`     | Header file with function prototypes |
| `README.md`  | Project documentation                 |
|`man_3_printf`| Custom man page for '_printf' command|
## 🔧 Functions
| Function         | Description           | Handles format specifier |
|------------------|-----------------------|---------------------------|
| `print_char`     | Prints a character    | `%c`                      |
| `print_str`      | Prints a string       | `%s`                      |
| `print_percent`  | Prints the `%` symbol | `%%`                      |
| `print_int`      | Prints an integer     | `%d`, `%i`                |
## 🧠 Supported Format Specifiers
| Specifier | Description                      |
|-----------|----------------------------------|
| `%c`      | Prints a single character        |
| `%s`      | Prints a string                  |
| `%%`      | Prints a literal percent sign    |
| `%d`      | Prints a decimal (base 10) number |
| `%i`      | Prints an integer (base 10)      |

## 🤝 Team

Malik Bouanani  🚀
  
Haitu Nguyen 💅