
void failsafeCityChoice(char desiredCity[],arrayOfStrings_t cityChoices[]) {
    int flip = 0;

    while (1) {
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
