/*
 * The following tables present the important format specifiers. The format specifiers are sticky except
 * for the field width, which is reste after each application.
 * The manipulators without any arguments require the header <iostream>, and the manpulators with 
 * arguments require the header <iomanip>.
 *
 * Displaying of boolean value:
 *  Manipulator               Stream type           Description
 *  std::boolalpha            input and output      Displays the boolean as a word.
 *  std::noboolalpha          input and output      Displays the boolean as number (default).
 *
 * Set the filed width and the fill character:
 *  Manipulator               Stream type           Description 
 *  std::setw(val)            input and output      Sets the filed width to val.
 *  std::setfill(c)           output stream         Sets the fill character to c (default: spaces).
 *
 * Alignment of the text:
 *  Manipulator               Stream type           Description 
 *  std::left                 output                Aligns the ouput left.
 *  std::right                output                Aligns the output right.
 *  std::internal             output                Aligns the signs of numbers left, the values right.
 *
 * Positive signs and upper or lower case:
 *  Manipulator               Stream type           Description
 *  std::showpos              output                Display positive signs.
 *  std::noshowpos            output                Doesn't display positive signs (default).
 *  std::uppercase            output                Uses upper case characters for numeric values.
 *  std::lowercase            output                Uses lower case characters for numeric values.
 *
 * Display of the numeric base. There are special rules for floating point numbers:
 *  - The number of significant digits (digits after comma) is by default 6.
 *  - If the number of significant digits is not big enough the numbers are displyed in scientific.
 *  - Leading and trailing eros are not be displayed.
 *  - If possible the decimal point is not be displayed.
 *  Manipulator               Stream type           Description 
 *  std::oct                  input and output      Uses natural numbers in octal format.
 *  std::dec                  input and ouptut      Usus natural numbers in decimal format (default).
 *  std::hex                  input and output      Uses natural numbers in hexadecimal foramt.
 *  std::showbase             output                Display the numeric base.
 *  std::noshowbase           output                Doesn't display the numeric base (default).
 *
 * Floating point nubers:
 *  Manipulator               Stream type           Description 
 *  std::setprecision(val)    output                Adjusts the precision of the output to val.
 *  std::showpoint            output                Displays the decimal point.
 *  std::noshowpoint          output                Doesn't display the decimal point (default).
 *  std::fixed                output                Displays the floating-point number in decimal format.
 *  std::scientific           output                Displays the floating-point number in scientific.
 *  std::hexfloat             output                Displays the floating-point number in hex format.
 *  std::defaultfloat         output                Displays the floating-point number in default format.
*/
#include <iostream>
#include <iomanip>

int main(){
  std::cout << "std::setw, std::setfill and std::left, rignt and internal:\n";
  std::cout.fill('#');
  std::cout << -12345 << std::endl;
  std::cout << std::setw(10) << -12345 << std::endl;
  std::cout << std::setw(10) << std::left << -12345 << std::endl;
  std::cout << std::setw(10) << std::right << -12345 << std::endl;
  std::cout << std::setw(10) << std::internal << -12345 << std::endl;

  std::cout << std::endl;

  std::cout << "std::showpos:\n";

  std::cout << 2023 << std::endl;
  std::cout << std::showpos << 2023 << std::endl;
  std::cout << std::noshowpos << std::endl;

  std::cout << "std::uppercase:\n";
  std::cout << 12345678.9 << std::endl;
  std::cout << std::uppercase << 12345678.9 << std::endl;

  std::cout << std::nouppercase << std::endl;

  std::cout << "std::showbase and std::oct, dec and hex:\n";
  std::cout << 2023 << std::endl;
  std::cout << std::oct << 2023 << std::endl;
  std::cout << std::hex << 2023 << std::endl;

  std::cout << std::endl;

  std::cout << std::showbase;
  std::cout << std::dec << 2023 << std::endl;
  std::cout << std::oct << 2023 << std::endl;
  std::cout << std::hex << 2032 << std::endl;

  std::cout << std::dec << std::endl;

  std::cout << 123.456789 << std::endl;
  std::cout << std::fixed << std::endl;
  std::cout << std::setprecision(3) << 123.456789 << std::endl;
  std::cout << std::setprecision(4) << 123.456789 << std::endl;
  std::cout << std::setprecision(5) << 123.456789 << std::endl;
  std::cout << std::setprecision(6) << 123.456789 << std::endl;
  std::cout << std::setprecision(7) << 123.456789 << std::endl;
  std::cout << std::setprecision(8) << 123.456789 << std::endl;
  std::cout << std::setprecision(9) << 123.456789 << std::endl;
 
  std::cout << std::endl;
  std::cout << std::setprecision(6) << 123.456789 << std::endl;
  std::cout << std::scientific << std::endl;
  std::cout << std::setprecision(6) << 123.456789 << std::endl;
  std::cout << std::setprecision(3) << 123.456789 << std::endl;
  std::cout << std::setprecision(4) << 123.456789 << std::endl;
  std::cout << std::setprecision(5) << 123.456789 << std::endl;
  std::cout << std::setprecision(6) << 123.456789 << std::endl;
  std::cout << std::setprecision(7) << 123.456789 << std::endl;
  std::cout << std::setprecision(8) << 123.456789 << std::endl;
  std::cout << std::setprecision(9) << 123.456789 << std::endl;
  
  return 0;
}
