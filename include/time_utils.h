#ifndef TIME_UTILS_H
#define TIME_UTILS_H


void seconds_to_hms(int sec, int* h, int* m, int* s);
int  hms_to_seconds(int h, int m, int s);


void format_hms(int h, int m, int s, char* str);  


int  is_hms(int h, int m, int s);
int  check_hms(const char* str);                   


void seconds_to_dhms(int sec, int* d, int* h, int* m, int* s);
int  diff_seconds(const char* t1, const char* t2);

#endif
