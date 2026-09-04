# Pirate Programming

```
author: bjr
last-update: 
	4 sep 2026
```

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

### Pirate Boarding: hooking the return address

This repository contains an example of Pirate Programming in C to hook
the return address to divert the control follow of a program. This is 
also called *Smashing the Stack* and was a common way to exploit code to
gain access to a computer.


Pirate Long John von Neumann does not politely call a function.
He finds a return address on the stack and replaces it with the address of his
pirate ship:

```c
*(&i + PIRATE_SECRET) = return_to;
```

This is done inside the function ```caribbean_voyage()```. When the 
functions returns, it returns to this address. The ship has been boarded.

### Von Neumann architecture

There is a bit of subtlety in the joke Pirate Long John Von Neumann. The 
key here is that data and instructions are in the same memory. Hence, instructions
are data and data are instructions. 

It is not always the case that data amd memory are stored together, with each
being able to be interpreted as the other.  A computer can
have one memory for instructions and another for data. This is 
called a **Harvard architecture**, after the early The Harvard Mark I,
designed by Harvard mathematician Howard Aiken and built by IBM at Harvard in 1944.

In 1945 the Princeton mathematician **John von Neumann** 
he wrote the famous *First Draft of a Report on the EDVAC*, 
which described a computer in which instructions and numerical
data would be stored in the same memory. The report circulated widely
and became enormously influential. This architecture is called
either **Princeton architecture** or  **von Neumann architecture**.
