#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (tm.tm_mon + 1 == 4 && tm.tm_mday == 25) {
        printf("Det er 25 april, og du fyller 25! Dette skjer bare en gang i livet. Gratulerer så mye med dagen!!\n");

        time_t currentTime = mktime(&tm);

        tm.tm_mon = 3; 
        tm.tm_mday = 26;
        tm.tm_hour = 0;
        tm.tm_min = 0;
        tm.tm_sec = 0;
        time_t targetTime = mktime(&tm);

        int secondsDifference = difftime(targetTime, currentTime);

        int hoursDifference = secondsDifference / 3600;

        printf("Du har %d timer igjen av bursdagen din. Nyt de!\n", hoursDifference);
    } else {
        printf("Du har ikke bursdag, gå og legg deg!\n");
    }

    return 0;
}