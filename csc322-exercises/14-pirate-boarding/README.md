

# Pirate Programming

Pirate programming is the art of making a program do what you want,
without being overly concerned with whether the method is elegant,
portable, conventional, or even entirely correct.

In particular, Pirate Programming may involve taking perfectly innocent
C language constructs and doing things that the language specification
does not promise will work.

For example, let ```pirate_ship``` be the name of a function in a C
language file. A line like the following is Pirate Programming

```c
return_to = (long int) pirate_ship;
```

Pirates treat a function pointer as an integer in order to manipulate
the program flow  in non-standard ways.

No.

Is it necessarily correct according to the C standard?

No.

Does it work on the machine on which we are sailing?

*Aye.*

That is Pirate Programming.

This repository contains an example of Pirate Programming in C.

Long John von Neumann does not politely call a function.

He hooks the stack.

He finds the return address and replaces it with the address of his
pirate ship:

```c
*(&i + PIRATE_SECRET) = return_to;
```

When ```caribbean_voyage()``` returns, the ship does not return to where it
was supposed to go.

It has been boarded.