#ifndef LAB3_SCORING_H
#define LAB3_SCORING_H

/*
 * Computes edit distance between two chars
 * Returns a score
 */
int edit_distance_scoring(char a, char b);

/*
 * Computes a score between two amino acid codes
 * returns an int score.
 */
int blosum62_protein_scoring(char a, char b);

#endif