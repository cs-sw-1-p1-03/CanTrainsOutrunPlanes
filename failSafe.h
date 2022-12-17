#include "ctype.h"
#include "stdbool.h"

/**
 * Function compare does scanf until input is matching a string of match array.
 * @param input The function returns the input when match is found.
 * @param match Array of strings to match specify possible inputs.
 * @param arrayLength Number of strings to be compared.
 * @param text Is what prompts before scan.
 */
void scanChar(char input[],arrayOfStrings_t match[],int arrayLength,char text[]){
    int found = 0;
    do{
        printf("%s",text);
        scanf("%s",input);
        for (int i = 0; i < arrayLength && found == 0; i++) {
            if (strcmp(input, match[i].string) == 0) {
                found = 1;

            }
        }
    }while(strcmp(input,"exit")!=0 && found == 0);

}
/**
 * Function to check if a string is made of numbers only.
 * @param key Takes in the string this is to be checked.
 * @return returns either the boolean true or false value, based on whether the string is a number or not.
 */
bool digitCheck(char key[])
{
    for(int i = 0; i < strlen(key); i++)
    {
        if(isdigit(key[i])==0)
        {
            return false;
        }
    }
    return true;
}

/**
 * Fucntion scans an input until the user insert a number.
 * @param text is what prompts before the scan
 * @return returns the finale number input in int.
 */
int scanNumber(char text[]){
    char input[5];
    do {
        printf("%s",text);
        scanf("%5s", input);
    } while (!digitCheck(input));

    int result = atoi(input);
    return result;
}