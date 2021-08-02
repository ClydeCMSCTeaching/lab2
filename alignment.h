//
// Created by Austin Clyde on 8/1/21.
//

#ifndef LAB3_ALIGNMENT_H
#define LAB3_ALIGNMENT_H

void needleman_wunsch_alignment(const char *seq1,
                                const int seq1_len,
                                const char *seq2,
                                const int seq2_len,
                                int (*scoringf)(char,char),
                                char **align1,
                                int *align1_len,
                                char **align2,
                                int *align2_len
                                );

#endif //LAB3_ALIGNMENT_H
