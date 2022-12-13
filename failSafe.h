
void failsafeCityChoice(char desiredCity[],arrayOfStrings_t cityChoices[],char text[]) {
    int flip = 0;

    while (1) {
        printf("%s",text);
        scanDesiredCity(desiredCity);

        for (int i = 0; i < 50; i++) {
            if (strcmp(desiredCity, cityChoices[i].string) == 0) {
                flip = 1;
                break;
            }
        }
        if (flip == 1) {
            break;
        }
    }
}
void scanfChar(char input[],char* matchArray[],int arrayLength,char text[]){
    int flip = 0;
    do{
        scanf("%s",input);
        for (int i = 0; i < arrayLength;i++) {
            if (strcmp(input, matchArray[i]) == 0) {
                flip = 1;
                break;
            }
        }
        if (flip)
            break;

    }while(strcmp(input,"exit")!=0);

}
