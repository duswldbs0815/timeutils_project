#include "time_utils.h"
#include <stdio.h>
#include <ctype.h>

void seconds_to_hms(int sec, int *h, int *m, int *s)
{
    if (sec < 0)
    {
        sec = 0;
    }
    *h = sec / 3600;
    sec %= 3600;
    *m = sec / 60;
    *s = sec % 60;
}

int hms_to_seconds(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

void format_hms(int h, int m, int s, char *str)
{
    sprintf(str, "%02d:%02d:%02d", h, m, s);
}

int is_hms(int h, int m, int s)
{
    if (h < 0)
        return 0;
    if (m < 0 || m >= 60)
        return 0;
    if (s < 0 || s >= 60)
        return 0;
    return 1;
}

static int check_2digit(const char *p)
{
    if (!isdigit((unsigned char)p[0]) || !isdigit((unsigned char)p[1]))
        return -1;
    return (p[0] - '0') * 10 + (p[1] - '0');
}

int check_hms(const char *str)
{
    if (!str)
        return -1;

    if (!(isdigit(str[0]) && isdigit(str[1]) &&
          str[2] == ':' &&
          isdigit(str[3]) && isdigit(str[4]) &&
          str[5] == ':' &&
          isdigit(str[6]) && isdigit(str[7]) &&
          str[8] == '\0'))
        return -1;

    int h = check_2digit(str + 0);
    int m = check_2digit(str + 3);
    int s = check_2digit(str + 6);

    if (!is_hms(h, m, s))
        return -1;
    return hms_to_seconds(h, m, s);
}

void seconds_to_dhms(int sec, int *d, int *h, int *m, int *s)
{
    if (sec < 0)
        sec = 0;
    *d = sec / 86400;
    sec %= 86400;
    seconds_to_hms(sec, h, m, s);
}

int diff_seconds(const char *t1, const char *t2)
{
    int a = check_hms(t1);
    int b = check_hms(t2);
    if (a < 0 || b < 0)
        return 0;
    return a - b;
}
