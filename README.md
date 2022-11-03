<h1 align="center">
📖 push_swap
</h1>

<p align="center">
	<b><i>Because Swap_push isn’t as natural</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/jlima91/get_next_line_42?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/jlima91/get_next_line_42?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/jlima91/get_next_line_42?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/jlima91/get_next_line_42?color=green" />
</p>

## ✏️ Summary
```
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for an
optimized data sorting.
```
## 💡 About the project

```
Writing a sorting algorithm is always a very important step in a developer’s journey. It
is often the first encounter with the concept of complexity.
Sorting algorithms and their complexity are part of the classic questions discussed
during job interviews. It’s probably a good time to look at these concepts since you’ll
have to face them at some point.
The learning objectives of this project are rigor, use of C, and use of basic algorithms.
Especially focusing on their complexity.
Sorting values is simple. To sort them the fastest way possible is less simple. Especially
because from one integers configuration to another, the most efficient sorting solution can
differ.
```
You can read the project subject [here](https://github.com/jlima91/push_swap_42/blob/master/push_swap.pdf)


## 🛠️ Usage

#### 1. Compiling the program

To compile, go to the program path and run:

```
make
``` 
#### 2. Executing the program

To execute the program, run:
```
$ ./push_swap $ARG
```
where ```$ARG``` is a space separated list of integers, e.g. ```ARG="1 5 2 4 3"```


## 🛠️ USED ALGORITHM

I used a variation of the [Quicksort](https://en.wikipedia.org/wiki/Quicksort) algorithm. Basicly I pick small chunks of numbers. For example: if the pool of numbers is 100, I will divide it in 10 chunks of 10 numbers each. It varies according to the pool number. The first chunk has 10 smallest numbers of the pool. I then push the smallest ones to stack b. I don't push the smallest number of all first but the the smallest that is closest to be pushed, this saves a lot of moves. While I'm rotating the stack a to push numbers to b, b is also being rotated to sort the numbers that are already there. When the rotation in a and in b match, I use the command to rotate both stack at the same time and save a move. My algorithm performed maximum in all tests except the last one, it performed a level bellow max. 

