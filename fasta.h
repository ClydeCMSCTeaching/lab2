#ifndef LAB3_FASTA_H
#define LAB3_FASTA_H


/**
 * params:
 *      filename -> string filename to where to read from
 * returns:
 *      sequence1 -> pointer to a CHAR ARRAY (not a string)
 *      length1 -> length of the array
 */
void readFastaFormat(const char *filename,  char **sequence1, unsigned int* length1);


#endif //LAB3_FASTA_H
