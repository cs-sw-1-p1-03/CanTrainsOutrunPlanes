
void failsafeCityChoice(char departureCity[],arrayOfStrings_t cityChoices[]) {
    int flip = 0;

    while (1) {
        scanDepartureCity(departureCity);

        for (int i = 0; i < 50; i++) {
            if (strcmp(departureCity, cityChoices[i].string) == 0) {
                flip = 1;
                break;
            }
        }
        if (flip == 1) {
            break;
        }
    }
}
