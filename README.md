# Sorting algorithms
## About sorting algorithms:
- Algorithms used to sort data (for example: You need to sort data from a file and you don't want to do it manually, you put it into a programme and it sorts your data --> the programme uses sorting algorithms)
- There are different types of sorting algorithms:
  - Algorithms, that are only running in RAM (unified memory of your computer).
  - Algorithms, that are running in your files.
- Algorithms, that are here are only running in your RAM. They are better to use for smaller data.

## Algorithms in this project:
- **Selection sort**
  - Goes thru the array, searches for the lowest number and then replaces numbers from the beginning of the array.
- **Insert sort (and its derivatives)**
  - Insert sort starts from the beginning, takes the number, compares it to other (already sorted) numbers and inserts it to its right place).
  - There are also its derivatives: Insert sort with a sentinel (right or left).
- **Bubble sort (and its derivatives)**
  - Bubble sort always compares only two numbers next to each other. If the number is smaller, they change positions --> this goes, until the small number meets a smaller number.
  - Bubble sort also has derivatives: Ripple sort and Shaker sort.

## Time complexity of the algorithms:
| Algorithm | Best Case | Average Case | Worst Case |
| :--- | :--- | :--- | :--- |
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ |
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ |
| **Sequential Search** | $O(1)$ | $O(n)$ | $O(n)$ |
| **Binary Search** | $O(1)$ | $O(\log n)$ | $O(\log n)$ |

# Information about the project
- This is a project, that I have built to understand the algorithms deeper and actually know, how every one of them works.
- The project is written purely in the programming language C.
- All programmes are "in-memory", sorted in the RAM of your computer.

# How to run the project:
## 1. Clone the repository
git clone git@github.com:Honza468/C_sorting_algorithms.git

## 2. Compile the programme
gcc file_name.c -o file_name

## 3. Run the programme
./file_name
