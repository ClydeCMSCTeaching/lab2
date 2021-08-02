#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include "alignment.h"
#include "scoring/scoring.h"

void needleman_wunsch_alignment(const char *seq1,
                                const int seq1_len,
                                const char *seq2,
                                const int seq2_len,
                                int (*scoringf)(char,char),
                                char **align1,
                                int *align1_len,
                                char **align2,
                                int *align2_len
                                ) {
    return;
}