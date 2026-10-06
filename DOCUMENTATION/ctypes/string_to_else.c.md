# Documentation for the string_to_else.c file in the directory "utils/ctypes"

## The string_to_else.c file is an included C file meant to aid in turning strings (char *) into other types

---

## str_to_int

> Turns a decimal string into an integer.

**Returns int64_t (long signed int), or exits with a status in $set\;of\;long\;ints-[0,9]$.**

*string (char \*) argument*

|statistic|value|return type|
|---------|-----|-----------|
|Worst case|O(==N==)|long int|
|Average case|$\Omega$(==N==)|long int|
|Best case|$\Theta$(==1==)|exit status in [0,9] if $\mathbb{U}=\mathbb{Z}$|

---

## str_to_float

> Turns a decimal string into a double float.

**Returns double, or exits with a status in $set\;of\;long\;ints$.**

*string (char \*) argument*

|statistic|value|return type|
|---------|-----|-----------|
|Worst case|O(==N==)|double|
|Average case|$\Omega$(==N==)|double|
|Best case|$\Theta$(==N==)|exit status in $set\;of\;short\;signed\;ints$|

---

## CONCLUSION

### Useful functions

- str_to_int

- str_to_float
