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

<ul>
<li>
Is it necessarily correct according to the C standard?
<p style="margin:1em;">
&#9755; <b>No!</b>
<li>
Does it (sometimes) work on the machine we are using?
<p style="margin:1em;">
&#9755; <b>Aye!</b>
</ul>

That is Pirate Programming.

### Pirate Boarding: hooking the return address

This repository contains an example of Pirate Programming in C to hook
the return address to divert the control flow of a program. This is 
also called <a href="https://phrack.org/issues/49/smashing-the-stack-for-fun-and-profit">Smashing 
the Stack</a> and is a common hacker exploit.

Pirate Long John von Neumann replaces one code
flow with another by Smashing the Stack. 
He finds where on the stack is the return address leading back to the calling ship
and replaces it with the address of his pirate ship:

```c
*(&i + PIRATE_SECRET) = return_to;
```
where ```i``` is the name of a variable on the stack. Therefore ```&i```
is an address on the stack, the starting place for a guess where 
might be stored the resturn address.

This &quot;hooking&quot; of the resturn address is done inside the 
function ```caribbean_voyage()```. When ```caribbean_voyage()```
returns, it returns to the replacement address. The ship has been boarded.

### Von Neumann architecture

There is a bit of subtlety in the joke Pirate Long John Von Neumann. 

An important prerequisite to boarding the ship is that 
data and instructions are in the same memory. Hence, instructions
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

### Real life pirates

The hacker magazine Phrack described this in an article 
<a href="https://phrack.org/issues/49/smashing-the-stack-for-fun-and-profit">Smashing 
the Stack for Fun and Profit</a> by Aleph One (1996). His name is Elias Levy.
We are Smashing the Stack for Education and Non-Profits ... (ugh!).


