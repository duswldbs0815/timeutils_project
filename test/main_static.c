#include <stdio.h>
#include "time_utils.h"

int main() {
    int h, m, s, d;
    char buf[9];

    seconds_to_hms(3661, &h, &m, &s);
    format_hms(h, m, s, buf);
    printf("3661 sec -> %s\n", buf);

    printf("check 02:10:00 -> %d sec\n", check_hms("02:10:00"));
    printf("diff 02:30:00 - 01:45:20 -> %d sec\n",
           diff_seconds("02:30:00", "01:45:20"));

    seconds_to_dhms(90061, &d, &h, &m, &s);
    format_hms(h, m, s, buf);
    printf("90061 sec -> %d day %s\n", d, buf);

    return 0;
}
