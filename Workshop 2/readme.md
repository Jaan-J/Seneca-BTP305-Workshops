# Workshop 2: Move and Copy Semantics

In this workshop, you work with a large dynamically allocated array of C++ Standard Library strings and compare the performance of copy and move operations on that collection.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- retrieve records from a text file using an input file stream  object
- count the number of records in a text file
- monitor the time spent on a particular task using the `std::chrono` library
- implement **copy semantics** for a class with a resource
- implement **move semantics** for a class with a resource
- identify the processing-intensive operations in copy and move assignments

## Part 1 (0%)

This workshop consists of three modules:
- `w2` (supplied)
- `TimedEvents`
- `StringSet`

Enclose all your source code within the `sdds` namespace and include the necessary guards in each header file.



### `w2` Module (supplied)


**Do not modify this module!**  Look at the code and make sure you understand it.



### `TimedEvents` Module

Design and code a class named `TimedEvents` that manages a **statically** allocated array of `Event` objects.  Your class predefines the maximum number of event objects at 10. The **instance variables** for your class should include:
- the number of records currently stored
- the start time for the current event (an object of type `std::chrono::steady_clock::time_point`; see documentation [here](https://en.cppreference.com/w/cpp/chrono/time_point))
- the end time for the current event (an object of type `std::chrono::steady_clock::time_point`)
- an array of `Event`s of structure type. The structure should contain the following fields:
  - a string with the event name.
  - a string with the predefined units of time
  - the duration of the event (an object of type `std::chrono::steady_clock::duration`; see documentation [here](https://en.cppreference.com/w/cpp/chrono/duration))


Your class includes the following member functions:
- a default constructor
- `startClock()`: a modifier that starts the timer for an event
- `stopClock()`: a modifier that stops the timer for an event
- `addEvent()`: a modifier that receives the address of a C-style null-terminated string that holds the name of the event.  This function will update the next time-record in the array:
  - stores into the name attribute the C-style string at the pointed to address
  - stores `"nanoseconds"` as the units of time
  - calculates and stores the duration of the event (use `std::chrono::duration_cast<std::chrono::nanoseconds>()`, see documentation [here](https://en.cppreference.com/w/cpp/chrono/duration/duration_cast))
- a **friend insertion operator** that receives a reference to an `std::ostream` object and a `TimedEvents` object. This operator should insert in the `std::ostream` object the records from the array in the following format:

  ```
  Execution Times:
  --------------------------
  EVENT_NAME DURATION UNITS
  EVENT_NAME DURATION UNITS
  ...
  --------------------------
  ```

  The **name** of the event should be in a field of size 21, aligned on the left; the **duration** should be in a field of size 13, aligned on the right.

Starting and stopping the timer means getting the current time (use `std::chrono::steady_clock::now()`; see documentation [here](https://en.cppreference.com/w/cpp/chrono/steady_clock/now)).



### `StringSet` Module


Design and code a class named `StringSet` that manages a **dynamically** allocated array of elements of type `std::string`. Your class keeps track of the number of strings currently stored and defines the following member functions:
- a no-argument default constructor
- a 1-argument constructor that receives the address of a C-style null terminated string containing the name of a file from which this member function populates the current object. This function
  1. reads the file to count the number of strings present in the file (the record delimiter should be a single space `' '`)
  2. allocates memory for that number of strings in the array
  3. re-reads the file and loads the strings into the array.
- `size_t size()`: a query that returns the number of strings stored in the current object.
- `std::string operator[](size_t)`: a query that returns a copy of the string at the index received as the function parameter. If the index is invalid, this function should return an empty string.

To review the syntax for reading from a text file using an `std::ifstream` object see the chapter in your notes entitled [Custom File Operators](https://ict.senecacollege.ca/~btp200/pages/content/custo.html).

Add any other members that your design requires (without changing the specs above)!





 
## Part 2 (100%)

For this part of the workshop, upgrade the `StringSet` class to include a **move constructor** and a **move assignment operator**.  No other modules need to be changed.

### Sample Output

When the program is started with the command:
```
ws gutenberg_shakespeare
```
the output should look like the one from the `sample_output.txt` file.

**Note:** See that in the sample output the *move operations* are **many orders of magnitude** faster than the *copy operations*.  If your output doesn't have such a significant difference in times, keep working on your implementation (the actual numbers will be different every time you run the application).
