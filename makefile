align: main.c fasta.h fasta.c clustal.c clustal.h
	clang -Wall main.c fasta.c clustal.c -o align

clean:
	rm *.o align