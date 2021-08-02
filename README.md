# Lab 2
### Genes, proteins, bioinformatics galore!

In this lab you will implement a common bioinformatics algorithm
the Needleman-Wunsch algorithm (NWA), a global sequence alignment algorithm.

This algorithm are fundamental to modern day genomics. The effciency and speed
of this algorithm is also important. Modern day genetic sequencing machines rely
on sequence alignment algorithms. These algorithms have been well studied and
even implemented on advanced hardware accelerators such as field gate programmable arrays
(FPGAs), graphics processing units (GPUs), and single instruction multiple data (SIMD) hardware.

NWA considered dynamic programming algorithms. Dynamic programming (DP) is an
algorithmic technique for solving an optimization problem by breaking it down into simpler
subproblems and utilizing the fact that the optimal solution to the overall problem depends
upon the optimal solution to its subproblem.

As part of this assignment, you will see how SARS-CoV-2 compares to SARS-CoV-1 (we will
look at variations in the protein sequence for the spike protein as well as the proteases),
how SARS-CoV-2 protease compares to other corona viruses proteases,


We will be writing a single program in `main.c` which performs global alignment.
The command line inputs will specify the following:
```shell
./align [edit|blosum] [infile1.fasta] [infile2.fasta] [outfile.txt]
```
where edit or blosum will indicate which scoring function we will use for the alignment

When you turn in your program, make sure to remove any debugging statements. **Your program should not print anything except the errors I have written into `scoring.c`.**

In the first 30 minutes of the lab assignment in class I will cover 
the basics of global alignment and how the algorithm works.

## Part 1. FASTA format reader, output writer, Matrices
In the daily exercise 3, you wrote some basic code for detecting the number of residues in an `.fasta` file.

We want to implement a `matrix.h` and `matrix.c` which you can take directly from your DE3.

We will then want to implement a `fasta.h` and `fasta.c` set of files which has a function
```c
void readFastaFormat(const char *filename,  char **sequence1, unsigned int* length1);
```
which takes a `filename`, then a pointer to a string `sequence1` where the result should go, then a pointer to an `int` where the length of the string should go.

We also want to create a new set of files `utils.c` and `utils.h` which implements a function to write out the two alignments you create to the specified outfile. 
When writing out to a file, you can open a file pointer as you did in the DE3, except use `"w"` to indicate write. You can use
`fprintf` to print directly to a file by giving the file pointer as the first argument, then just using a normal `printf` style
format string followed by the things you are printing. Remember to use `fclose` to close the file pointer after writing.

You'll also want to add your string reverse function and the maximum function to `utils.h` and `utils.c`.

## Part 2. Needleman-Wunsch Global Alignment


## Part 3. Analysis, Debugging, Testing

#### Error Handling
Your program should handle errors such as a user not following the correct interface to run the program. For instance
```shell
./align middle file1.fasta file2.fasta outfile.clustal
```
should return an error stating middle is not a valid scoring function, the choices are `blosum` or `edit`. 



## Notes
- The skeleton code provided is meant to get you started. In this assignment, the graders will be evaluating your outputfiles for correctness. Therefore you can change the function signatures and file structure of this code. You may need to in fact.
- Function pointers: what happens when you want to use one function for scoring sometimes and another function for scoring other times? In thie lab, we want to switch the scoring functions we use depending on the user provided argument. Well, luckily functions have a type and we can pass them to other functions when needed.

```c

int func1(char a, char b) {
    return(1);
}
int func2(char a, char b) {
    return(2);
}

int func3(int (*f)(char, char) ) {
    int func_call_result = (*f)('a', 'b');
    return(func_call_result);
}

int main() {
    int (*fun_ptr)(char,char);
    if (5 < 7) {
        fun_ptr = &func1;
    } else {
        fun_ptr = &func2;
    }
    
    result = func3(fun_ptr);
}
```
The `result` here ends up equalling 1 since we pass func1 to func3, which gets called. Notice the syntax with dereferencing pointers. You'll

- Recall to compares strings one must use `strcmp` rather than `==`. `==` would compare pointer addresses, but not actually check to see if those values inside are equal.

- Variadic functions are fucntions which take an unspecified number of arguments. C has some built in infrastructure for creating variadic functions from the library `stdargs.h`. The following example takes a count of arguments, `count`, and then automatically allows a variable number of parameters to be passed. You might want to use this at some point.
```c
int maximum(int count, ...){
    va_list list;
    int max = INT_MIN;
    int num;
    va_start(list, count); 
    for(int j=0; j < count; j++) {
        num =  va_arg(list, int));
        if (num > max) {
            max = num;
        }
    }

    va_end(list);

    return max;
}
```