#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <assert.h>

#define kMicroSecondsPerSecond (1000 * 1000)

typedef long timestamp;

__thread char time_part[32];
__thread char sec_part[10];
__thread time_t last_sec;

timestamp tr_now() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long sec = tv.tv_sec;
    return kMicroSecondsPerSecond * sec + tv.tv_usec;
}

void format_time(timestamp now, char **t, char **ms) {

    time_t sec = now / kMicroSecondsPerSecond;
    int micro_sec = now % kMicroSecondsPerSecond;

    if (sec != last_sec) {
        struct tm tm_time;
        gmtime_r(&sec, &tm_time);
        int len = snprintf(time_part, sizeof(time_part), "%4d%02d%02d %02d:%02d:%02d",
                           tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
                           tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);
        assert(len == 17);
    }

    int len = snprintf(sec_part, sizeof(time_part), ".%06d ", micro_sec);
    assert(len == 8);
    *t = time_part;
    *ms = sec_part;
}


int main(void) {
    char *t;
    char *s;
    while (1) {
        format_time(tr_now(), &t, &s);
        printf("%s------%s\n", t, s);
    }
}

