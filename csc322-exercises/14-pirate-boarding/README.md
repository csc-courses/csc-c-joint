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

## Why Long John von Neumann?

In the beginning, there was no particular reason for a computer's
program and its data to live in the same memory.

Indeed, there are good reasons to keep them separate. A computer can
have one memory for instructions and another for data. This is generally
called a **Harvard architecture**, and variations of this idea are still
used today.

But another possibility is much more interesting:

**What if the program itself were stored in memory, alongside the data?**

In 1944, **John von Neumann** joined the discussions surrounding this
work. In 1945 he wrote the famous *First Draft of a Report on the
EDVAC*, which described a computer in which instructions and numerical
data would be stored in the same memory. The report circulated widely
and became enormously influential. :contentReference[oaicite:0]{index=0}

The name **von Neumann architecture** stuck.

If instructions and data occupy the same memory, then the program is
**data**.

And if the program is data, perhaps we can manipulate it.

Perhaps we can even steal its return address.

That is where the boarding begins.