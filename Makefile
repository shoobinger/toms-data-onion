##
# Project Title
#
# @file
# @version 0.1

common = ascii85.c

layer2 : layer2.c $(common)
	gcc -lm $^ -o $@

layer1 : layer1.c $(common)
	gcc -lm $^ -o $@

layer0 : layer0.c $(common)
	gcc -lm $^ -o $@


# end
