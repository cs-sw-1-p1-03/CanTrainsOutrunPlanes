#include "ctype.h"
#include "stdbool.h"


void scanChar(char input[],arrayOfStrings_t match[],int arrayLength,char text[]){
    int flip = 0;
    do{
        printf("%s",text);
        scanf("%s",input);
        for (int i = 0; i < arrayLength;i++) {
            if (strcmp(input, match[i].string) == 0) {
                flip = 1;
                break;
            }
        }
        if (flip)
            break;

    }while(strcmp(input,"exit")!=0);

}

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

int scanNumber(char text[]){
    char input[5];
    do {
        printf("%s",text);
        scanf("%5s", input);
    } while (!digitCheck(input));

    int result = atoi(input);
    return result;
}