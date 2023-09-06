## BCD Integer Project

In this project you will explore a computer representation of integers call Binary Coded Decimal. This
is not a popular way of representation. It is simpler to just convert the integer to base 2, and then
set the bits in a register to the bits in the representation. However, I wanted to provide this
alternative so that you all give some thought to even the usual representation, by dealing with this
alternative representation.

BCD takes the basic integer storage register and breaks it into 4 bit "nibbles". Each cell will store
a digit 0 through 9. The values 0xa through 0xf that are possible in a 4 bit nibbles are not used. This
way a number like 1234 becomes 0x00001234 assuming a 32 bit integer. 

One element of your project is to finish the code for function ato_bcd which takes a string, like
"1234" (different than an actual integer 1234) and work through the characters placing numbers in
the nibbles accordingly.

You will also finish the code for bcd_toa that given an integer type variable which contains an 
integer in BCD format, converts it to a string. This is a little tricky. We know maximum size of the 
string, one byte for each nibble plus one more byte for the null character. But suppressing leading
zeros requires a bit of work. 

Next addition. You will finish the function bcd_add, which given two integer type variables, each 
containing an integer in BCD representation, returns an integer type variable containing the sum,
also in BCD representation. This can be done working nibble by nibble, adding and if the sum is 10 
or more, subtracting 10 for arrive at the digit in that nibble, but carrying a one to the new 
nibble-wise add. Discard any carry-out (that is, ignore happily when the sum goes beyond 99999999 and 
wraps back to small numbers).

For instance,  456+274 = 0x456+0x274 = 0x730 = 730.

Next subtraction. I want you to do this in the same way (mathematically) as computers do subtraction.
They do not subtract, they reuse addition. Rather than a-b they add a+(-b), where -b is very easily 
created from b using 2's complement. 

The same trick works for BCD except use 10's complement. To get 10's complement, work nibble by nibble
on the thing you want to subtract, and replace i by 9-i. This is called the 9's complement. For instance,
the 9's complement of 274 is 99999725 (assuming a 32 bit integer). Note that a number plus its 9's 
completement always equals 99999999. Add 1 and get zero. Hence adding one to the 9's complement of a 
number is the negative of the number, and is called the 10's complement. 

To subtract a - b, take the 9's complement of b and add it to 9, but start with a carry in (to simulate
creating the 10's complement). Example: 456-274 = 00000456+99999725+1 = 00000182 = 182.




the negative 



