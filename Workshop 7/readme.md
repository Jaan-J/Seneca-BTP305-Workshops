# Workshop 7: STL Algorithms

In this workshop, you use the Algorithm category of the Standard Template Library.

You are going to create an application that manages a collection of songs.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- copy data from a file into a sequential container
- use the numeric library to accumulate data values 
- use a lambda expression to specify an operation on each value in a data set 
- use the algorithm library to sort data values



## Part 1 (0%)

The first portion of this workshop consists of modules:
- `w7` (supplied)
- `SongCollection`

Enclose all your source code within the `sdds` namespace and include the necessary guards in each header file.

In the specs below, functions marked with `DO NOT USE MANUAL LOOPS` should not use `for` or `while` in the implementation; these functions should use STL Algorithms.  The STL Algorithms you choose should use lambda expressions to process the collection; the lambdas should **capture the necessary variables from context only by value** (the stream object is the only one allowed to be captured by reference). Check course notes to identify which algorithm is appropriate in each situation.  Using manual loops will lead to **rejection** of the workshop or **severe penalties** (at the discretion of your professor).





### `SongCollection` Module

This modules defines a simple structure called `Song`, capable of storing the following information about a single song:
- artist
- title
- album
- price
- release year
- length of the song

No need to add any member functions to this structure. Choose appropriate types for each attribute.


Also, define a class called `SongCollection` that manages a collection of objects of type `Song`.



***Public Members for `SongCollection`***

- a custom constructor that receives as a parameter the name of the file containing the information about the songs to be added to the collection. This function should load into the attributes all the songs in the file.

  If the filename is incorrect, this constructor should throw an exception.

  Each line from the file contains information about a single song in the following format:
  ```
  TITLE ARTIST ALBUM YEAR LENGTH PRICE
  ```
  The fields are not separated by delimiters; each field has a fixed size: `TITLE`, `ARTIST` and `ALBUM` have **exactly** 25 characters; while `YEAR`, `LENGTH` and `PRICE` have **exactly** 5 characters.

  The length of a song in the input file is stored in seconds.

  Any blank space at the begining/end of a token is not part of the token and should be removed.

- `void SongCollection::display(std::ostream& out) const`: print the content of the collection into the parameter (one song / line). Use the insertion operator (see below). ***DO NOT USE MANUAL LOOPS!***



***Free Helpers***

- `std::ostream& operator<<(std::ostream& out, const Song& theSong)`: inserts one song into the first parameter, using the following format (the width of each field is specified in brackets):
  ```
  | TITLE(20) | ARTIST(15) | ALBUM(20) | YEAR(6) | LENGTH | PRICE |
  ```

  Look in the sample output to see how the numbers should be formatted and the alignment of each field.


**Add any other member that is required by your design!**







### `w7` Module (supplied)


The tester module for the first portion has been supplied. **Do not modify the existing code!**

When doing the workshop, you are encouraged to write your own tests, focusing on a single implemented feature at the time, until you get all functionality in place.



### Sample Output

When the program is started with the command (the file `songs.txt` is provided):
```
ws songs.txt
```
the output should look like the one from the `sample_output.txt` file.




## Part 2 (100%)

The second part of this workshop upgrades your solution to include more functionality in the `SongCollection` module.

**:warning:Important:** Your solution should not use the same algorithm twice.



### `SongCollection` Module


***Public Members***

- `void SongCollection::display(std::ostream& out) const`: update this function to display the playtime of the entire collection (the total playtime is the sum of the length attribute of all songs). See the sample output for the format.  ***DO NOT USE MANUAL LOOPS!***

- `void sort()`: receives as a parameter the name of the field used to sort the collection of songs in ascending order. The parameter can have one of the values `title`, `album`, or `length`.  ***DO NOT USE MANUAL LOOPS!***

- `void cleanAlbum()`: removes the token `[None]` from the album field of the songs that do not have a valid album.  ***DO NOT USE MANUAL LOOPS!***

- `bool inCollection() const`: receives the name of an artist as a parameter, and returns `true` if the collection contains any song by that artist.  ***DO NOT USE MANUAL LOOPS!***

- `std::list<Song> getSongsForArtist() const`: receives the name of an artist as a parameter, and returns the list of songs of that artist available in the collection.  ***DO NOT USE MANUAL LOOPS!***
