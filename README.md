# Lab 3
### Genes, proteins, bioinformatics galore! 

In this lab you will implement a common bioinformatics algorithm
the Needleman-Wunsch algorithm, a global sequence alignment algorithm,
and the Smith-Waterman algorithm, a local sequence alignment algorithm.

These algorithms are fundamental to modern day genomics. The effciency and speed
of these algorithms is also important. Modern day genetic sequencing machines rely
on these sequence alignment algorithms. These algorithms have been well studied and
even implemented on advanced hardware accelerators such as field gate programmable arrays
(FPGAs), graphics processing units (GPUs), and single instruction multiple data (SIMD) hardware.

Both algorithms are considered dynamic programming algorithms. Dynamic programming (DP) is an 
algorithmic technique for solving an optimization problem by breaking it down into simpler
subproblems and utilizing the fact that the optimal solution to the overall problem depends
upon the optimal solution to its subproblem.  

As part of this assignment, you will see how SARS-CoV-2 compares to SARS-CoV-1 (we will 
look at variations in the protein sequence for the spike protein as well as the proteases),
how SARS-CoV-2 protease compares to other corona viruses proteases, 

## Theory


We will be writing a single program in `main.c` which performs both local and global alignment. 
The command line inputs will specify the following:
```shell
./align [global|local] [infile1.fasta] [infile2.fasta] [outfile.clustal]
```



## Part 1. FASTA format reader, CLUSTAL output writer



## Part 2. Needleman-Wunsch Global Alignment


## Part 3. Smith-Waterman Local Alignment


## Part 4. Analysis, Debugging, Testing

#### Error Handling 
Your program should handle errors such as a user not following the correct interface to run the program. For instance
```shell
./align middle file1.fasta file2.fasta outfile.clustal
```
should return an error stating middle is not a valid program (recall, errors `fprintf`).



## Notes
- The skeleton code provided is meant to get you started. In this assignment, the graders will be evaluating your outputfiles for correctness. Therefore you can change the function signatures and file structure of this code. You may need to in fact. 
- 