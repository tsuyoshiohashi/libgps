#ifndef _GPS_H_
#define _GPS_H_

struct location {
    double latitude;
    double longitude;
    double speed;
    double altitude;
    double course;
    double utc_time;
    int utc_date;
};
typedef struct location loc_t;

// Initialize device
extern void gps_init(void);
// Activate device
extern void gps_on(void);
// Get the actual location
extern void gps_location(loc_t *);

// Turn off device (low-power consumption)
extern void gps_off(void);
typedef struct tm tm_t;
// Get Date and utc time
void gps_time(tm_t *);

// -------------------------------------------------------------------------
// Internal functions
// -------------------------------------------------------------------------

// convert deg to decimal deg latitude, (N/S), longitude, (W/E)
void gps_convert_deg_to_dec(double *, char, double *, char);
double gps_deg_dec(double);

#endif
