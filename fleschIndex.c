//importing the header file
#include "fleschIndex.h"

//function to take file name and turn file into a dynamically allocated character array.
char * readFile(char * fileName)
{
    //opening file for reading
    FILE * openFile = fopen(fileName, "r");

    if (openFile== NULL)
    {
        printf("Can't open file!\n");
        return NULL;
    }

    //setting default values and allocating dynamically allocated char pointer array
    char * characters = malloc(sizeof(char*));

    int charIndex = 0;
    
    //taking each character from the file and putting it into the array whilst reallocating the array size
    while (!feof(openFile))
    {
        characters[charIndex] = fgetc(openFile);
        charIndex++;
        characters = realloc(characters, sizeof(char*) * (charIndex + 1));
    }

    characters[charIndex] = '\0';
    return characters;
}

//calculating flesch index
int calculateFleschIndex(int syllables, int words, int sentences)
{
    int index = round(206.835 - 84.6 * (syllables / words) - 1.015 * (words / sentences));
    return index;
}

//outputting the flesch scores
void outputFormattedFleschScores(int syllables, int words, int fleshIndex, int sentenceCount)
{
    printf("Flesch Index = %d\nSyllable Count = %d\nWord Count = %d\nSentence Count = %d\n", fleshIndex, syllables, words, sentenceCount);
}

//checking if a character is a vowel
int hasSyllable (char character)
{
    if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//checking if a character is punctuation
int hasPunctuation (char character)
{
    if (character == '!' || character == '.' || character == ';' || character == '?' || character == ':')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

