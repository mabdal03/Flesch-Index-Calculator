//importing header file
#include "fleschIndex.h"

int main(int argc, char* argv[]){
    
    //opening the character array from file 
    char * charArray = readFile(argv[1]);

    //setting default values
    int sentenceCount = 0, wordCount = 0, numSyllable = 0, syllableAdded = 0, indexValue = 0;

    if (charArray != NULL)
    {
    while (charArray[indexValue] != '\0')
        {
            //counts number of sentences.
            if (hasPunctuation(charArray[indexValue]) == 1 && hasPunctuation(charArray[indexValue + 1]) == 0)
            {
                sentenceCount++;
            }

            //counts number of words.
            if (charArray[indexValue] == ' ' && charArray[indexValue+1] != ' ' && charArray[indexValue+1] != '\n')
            {            
                wordCount++;
                if (syllableAdded > 1){
                    numSyllable = numSyllable + (syllableAdded - 1);
                }
                syllableAdded = 0;
            }
            else if (charArray[indexValue] == '\n' || charArray[indexValue] == '\0')
            {
                wordCount++;
                if (syllableAdded > 1){
                    numSyllable = numSyllable + (syllableAdded - 1);
                }
                syllableAdded = 0;
            }


            //counts number of syllables greater than 1 per word.
            if (hasSyllable(charArray[indexValue]) == 1 && hasSyllable(charArray[indexValue + 1]) == 1  && hasSyllable(charArray[indexValue - 1]) == 0)
                {
                    syllableAdded++;
                }
            else if (hasSyllable(charArray[indexValue]) == 1 && hasSyllable(charArray[indexValue-1]) == 0)
                {
                    syllableAdded++;
                    if (charArray[indexValue] == 'e' && (charArray[indexValue + 1] == ' ' || charArray[indexValue + 1] == '\n' || charArray[indexValue + 1] == '\0' || hasPunctuation(charArray[indexValue + 1]) == 1))
                    {
                        syllableAdded--;
                    }
                }

            indexValue++;
        }

        //the total number of syllables = #syllables per word greater than one plus # of words
        numSyllable = numSyllable + wordCount;

        //output flesch score
        outputFormattedFleschScores(numSyllable, wordCount, calculateFleschIndex(numSyllable, wordCount, sentenceCount), sentenceCount);
        
    }
    
    free(charArray);
    return 0;
}
