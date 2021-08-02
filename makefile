align: main.c fasta.h fasta.c alignment.h alignment.c scoring/scoring.h scoring/scoring.c utils.h utils.c matrix.c matrix.h
	clang -Wall main.c fasta.c alignment.c scoring/scoring.c utils.c matrix.c -o align

clean:
	rm *.o align