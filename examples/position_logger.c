#include <stdio.h>
#include <stdlib.h>
#include <gps.h>
#include <time.h>

// JST = GMT + 9
#define TZ 9

int main(void) {
    // Open
    gps_init();
    gps_on();
    loc_t data;
    struct tm l_tm;

    while (1) {
        gps_location(&data);
        //printf("%lf %lf\n", data.latitude, data.longitude);
        //printf("date: %d\n", data.utc_date);
        //printf("time: %lf\n", data.utc_time);
        gps_time(&l_tm);
        printf("Year : %d\n",l_tm.tm_year+2000);
        printf("Month : %d\n",l_tm.tm_mon);
        printf("Day : %d\n",l_tm.tm_mday);
       
        printf("Hour : %d\n",l_tm.tm_hour + TZ);
        printf("Min : %d\n",l_tm.tm_min);
        printf("Sec : %d\n",l_tm.tm_sec);
    }

    return EXIT_SUCCESS;
}

