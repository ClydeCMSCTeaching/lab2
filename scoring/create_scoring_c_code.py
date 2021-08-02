# No need to understand this file.
# This file is an example of meta-programming. Using one programming langauge to write code for another programming lanauge.
# Switch statements in C are very fast, so ideally I wanted to load this scoring matrix blosum62.txt into a switch statement. A
# as you see in scoring_temp.txt, the output is very long would be nearly impossible to write by hand.

from itertools import combinations
file = 'blosum62.txt'

lines = []
with open(file, 'r') as fin:
    for line in fin:
        line = filter(lambda x : len(x) >= 1, map(lambda x : x.strip(), line.split(" ")))
        lines.append(list(line)[:-1]) # remove last part of row

#remove first part from all but first line
for i in range(1, len(lines)):
    lines[i] = lines[i][1:]

#remove last row
lines = lines[:-1]

mapper = {}
keys = lines[0]
values = lines[1:]
for i in range(0, len(keys)):
    for j in range(0, len(keys)):
        mapper[(keys[i], keys[j])] =  values[i][j]

clumper = {}
for a, b in mapper.keys():
    if a not in clumper:
        clumper[a] = [b]
    else:
        clumper[a].append(b)

with open("scoring_temp.txt", 'w') as f:
    f.write("switch (a) {\n")
    for a, bs in clumper.items():
        f.write(f"\tcase '{a.upper()}':\n")
        f.write(f"\tcase '{a.lower()}':\n")
        f.write("\t\t switch(b) {\n")
        for b in bs:
            f.write(f"\t\t\tcase '{b.upper()}':\n")
            f.write(f"\t\t\tcase '{b.lower()}':\n")
            f.write(f"\t\t\t\treturn {mapper[(a,b)]};\n")
        f.write('\t\t\tdefault:\n\t\t\t\tfprintf("Error in Scoring. Not found (%c,%c)", a, b);\n\t\t\t\treturn 0;\n')
        f.write("\t\t\t}\n")
        f.write("\t\t\tbreak;\n")
    f.write('\tdefault:\n\t\tfprintf("Error in Scoring. Not found (%c,%c)", a, b);\n\t\treturn 0;\n')

    f.write("}\n")
