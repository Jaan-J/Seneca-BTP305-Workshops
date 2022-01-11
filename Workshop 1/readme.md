# Workshop 1: Across Translation Units

In this workshop, you implement aspects of linkage, storage duration, namespaces, header guards, and operating system interfaces.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:
- receive program arguments from the command line
- guard a class definition from duplication in a translation unit
- access a variable defined in a different translation unit
- declare a local variable that resides in memory throughout the lifetime of the program
- upgrade code to accept and manage a user-defined string of any length


## The application

The application tracks events that occur at given times in a day, and executes a set of actions on the current event.

The application maintains a system clock (representing the time of day), then loads from a file the actions that must be executed:
- `T` - *time*: all following actions must be executed (in sequence) when the system clock reaches the time following `T`
- `S` - *start*: at the current time, a new event starts; the name of the event follows `S`
- `E` - *end*: the current event has ended and no other event is happening right now
- `P` - *print*: display the current event to the screen
- `A` - *archive*: add the current event to an archive of current events for future reference.




## Part 1 (0%)

This workshop consists of two modules:
- `w1` (partially supplied)
- `Event`



### `w1` Module (partially supplied)

Study the code supplied and make sure you understand it.

Finish the implementation of the `main` function, by completing the parts marked with `TODO`:

- write the prototype of the `main` function to receive a set of standard command line arguments
- echo the set of arguments to standard output in the following format:
```
1: first argument
2: second argument
3: third argument
4: ...
```

**Do not modify this module in any other place!**



### `Event` Module

The `Event` module defines a system clock, as a global variable named `g_sysClock` that stores only positive integers.  The value of the clock represents the time of day as the number of seconds since midnight (an integer between 0 and 86400; choose an appropriate type). This clock will be accessed when a new event starts and from the `main` function.



This module also defines a class named `Event` in the namespace `sdds` that stores some information about an event:

- a C-style null-terminated string of up to 128 characters *including the null byte terminator* representing the description of the event.

- the time when the event starts, expressed in number of seconds that passed from midnight. The time must be an integer between 0 and 86400 (choose an appropriate type).

**Public Members**
- Default constructor
- `display()`: a query that displays to the screen the content of an `Event` instance in the following format:
    ```
    COUNTER. HH:MM:SS => DESCRIPTION
    ```
    If no description has been stored in the current object, this query should print:
    ```
    COUNTER. | No Event |
    ```
    where
    - `COUNTER` is a field of size 2, that holds the number of times that this function has been called (use a local-to-function variable that remains in memory for the lifetime of the program) **Do not use global/member variables to store the counter!**
    - `HH:MM:SS` represents the time when the event started, expressed in hours, minutes and seconds
- `set()`: a modifier that receives the address of an array of characters (by default, the parameter is null).
    - If the address is not null and the array is not empty, this function starts a new event and stores the information about this event in the current instance.
    - If the address is null or the array is empty, this function resets the current instance to an empty state.

Add any other **private** members that your design requires (without changing the specs above)!






 
## Part 2 (100%)

For this part of the workshop, upgrade your `Event` class to accept a description in the form of a C-style null-terminated string of any length.  **Make sure your program doesn't have memory leaks.**


### Sample Output

When the program is started with the command:
```
ws monday.txt missing.txt tuesday.txt
```
the output should look like the one from the `sample_output.txt` file.


