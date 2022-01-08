/*
By Mohammed Abdallah
Last Updated on February 19th, 2021
*/

//importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//defining prototypes
char * readFile ( char * filename);
int calculateFleschIndex(int syllables, int words, int sentences);
void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount);
int hasSyllable (char character);
int hasPunctuation (char character);
