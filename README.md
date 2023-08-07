
<p align="center">
  <img src="https://www.alxafrica.com/wp-content/uploads/2022/01/header-logo.png">
</p>

# 0x11. C - printf

## Group Project

Project Time: Jul 21, 2023 6:00 AM to Jul 26, 2023 6:00 AM

## Description

In the Alx program we do not use the standard library, unless we necessarily have to. But most of the time we build our own implementations of the standard functions we need and use those to solve a problem.

So this is our implementation of the standard printf function in the c programming language. It is our first pair programming project in the Alx program.

NOTE: This is not a full implementation of the printf function, but some parts of it we need for now.

## General

The printf function is a variadic function that is used to write a formatted output to the standard output stream (i.e. the monitor).

Our implementation follows the same syntax of the standard printf function, except for the function name. The function prototype we used for our implementation is:

`int _printf(const char *format, ...);`

The printf function takes two arguments, the format string and an ellipsis (which are variable arguments). It returns the number of characters printed on the standard output.

The format string is used to specify how the variable arguments are formatted. This is achieved by using conversion specification characters in the format string. The conversion specification characters are used to determine format options such as the alignment, field width, number of character to print, and other information used to format a given variable argument.

The conversion specification characters follow the following syntax:

`%[flags][width][.precision][modifier]specifier`

- `flags`: This are flag characters that alter the normal behavior of the output.
- `width`: The width is a non-negative integer that is used to define the width of the format field.
- `precision`: The precision is a non-negative integer preceded by a dot, and is used to determine the number of digits or character to be written.
- `modifier`: This are length modifiers used to specify the datatype of the argument given.
- `specifier`: This used to determine the type of conversion to be applied.

So the conversion specification syntax begins with a `%` character and end with the `specifier` character. All the other options in between are optional, but the percent sign and the specifier are mandatory. If a conversion specification does not follow the syntax above, like if you write the format options in the incorrect order, then it will be an invalid conversion syntax and the behavior of printf in such cases is undefined. In our implementation of printf invalid conversion syntax is printed as-is to the standard output.

For example in the conversion specification `"%-7.4hd"`,

- `-` is a flag character, used to left align the output in the format field
- `7` is the width of the format field
- `.4` is the precision
- `h` is the length modifier
- `d` is used to indicate the type of conversion, in this case integer conversion

Normal characters that are not part of the conversion specification in the format string are printed as-is to the standard output.

## Features

So in this project these are the features of the standard printf we implemented.

| Flags | \- , \+ , #,  0, and blank( ) |
| --- | --- |
| **Width** | Non-negative integer |
| Precision | Non-negative integer |
| Modifiers | *h* and *l* only |
| Specifiers | c (Character conversion)<br>s (String conversion)<br>d, i (Signed integer conversion)<br>u (Unsigned integer conversion)<br>o (Unsigned octal conversion)<br>x, X (Unsigned hexadecimal conversion) |
| Custom Specifiers | b (Binary conversion)<br>S (String conversion, but prints non-printable characters in hex)<br>r (Reverse string conversion)<br>R (Rot13 conversion) |

As you can see we handled most of the standard character and integer conversions as well as we could. Other conversion specifiers of the standard library such as float and double conversions are not handled in the project. Another thing is we have added some custom conversion specifiers, which are not found in the standard printf function, as part of the project.

## Usage

To use this implementation of printf in your project, simply copy the files in your project directory and compile them with your file that contains the main function and that should work.

## Contributors

Eyob Melkamu ([eyob721](https://github.com/eyob721 "eyob721"))

Ezra Teshome ([Ezralx](https://github.com/Ezralx "Ezralx"))
