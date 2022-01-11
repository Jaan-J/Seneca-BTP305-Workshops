# Workshop 8: Smart Pointers

In this workshop, you merge two lists and use a smart pointer to ensure that memory is deallocated in the possible presence of an exception.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- create a program component of quadratic complexity
- use a smart pointer to move an object


## Part 1 (0%)

The first portion of this workshop consists of modules:
- `w8` (supplied)
- `Element` (incomplete)
- `List` (incomplete)
- `Utilities` (supplied header, incomplete implementation)

Your tasks for this part of the workshop are:
- Add a `validate()` function to the `Element` module
- Add an operator `+=` overload to the `List` module using raw pointer syntax
- Complete the `mergeRaw()` function in the `Utilities` module using raw pointer syntax



### `Element` Module

The `Element` module holds product code, price and description information.
- The `Description` structure holds product code and user-friendly description.  
- The `Price` structure holds product code and current price.  
- The `Product` structure holds user-friendly description and product price. 


**Your Task:** Add a `validate()` function to the `Product` type.  Your function reports an exception if the object’s price is negative. Your function receives nothing and returns nothing.



### `List` Module

The `List` module defines a class that retrieves a list of records stored in a text file, holds the elements in an STL vector, provides access to them by index and displays them to an output stream. 

**Your Task:** Add an operator `+=` overload to the `List` template. Your function receives the address of an object to be stored in the `List` container and moves the object into that container. Your overload returns nothing.


### `Utilities` Module

**Your Task:** Implement the `mergeRaw()` function.  This function compares the elements in the two received lists for common product codes and builds the user-friendly list from the matching pairs.  For each successful comparison, your function allocates dynamic memory of `Product` type using that description and the price. Your function then validates the `Product` object and adds it to its list. Your function returns a copy of this list.






### `w8` Module (supplied)


The tester module has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output


When the program is started with the command (the input files are provided):
```
w8.exe Descriptions.dat BadPrices.dat Prices.dat
```
the output should look like the one from the `sample_output.txt` file.




## Part 2 (100%)

The second part of this workshop upgrades your solution to use smart pointers.

Your tasks for this part of the workshop are:
- Add an operator `+=` overload to the `List` module using smart pointer syntax
- Complete the `mergeSmart()` function in the `Utilities` module using smart pointer syntax



### `w8` Module (supplied)


The tester module has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output


When the program is started with the command (the input files are provided):
```
w8.exe Descriptions.dat BadPrices.dat Prices.dat
```
the output should look like the one from the `sample_output.txt` file.
