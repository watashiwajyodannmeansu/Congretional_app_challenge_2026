# Documentation for the string_to_else.c file in the directory "utils/ctypes"

## The string_to_else.c file is an included C file meant to aid in turning strings (char *) into other types.

---

## str_to_int

> Turns a decimal string into an integer.

**returns int64_t (long signed int), or exits with status $![0-9] if \mathbb{u}=set of long ints$.**

*string (char *) argument*

|statistic|value|
|---------|-----|
|Worst case|O(==N==)|
|Average case|$\Omega$(==N==)|
|Best case|$\Theta$(==N==)|

---

- [x] str_to_int
- [] str_to_float