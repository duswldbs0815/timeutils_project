#include <stdio.h>
#include <dlfcn.h>

typedef int (*check_hms_fn)(const char*);
typedef int (*diff_seconds_fn)(const char*, const char*);

int main() {
    void* handle = dlopen("./build/libtimeutils.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        return 1;
    }

    dlerror(); 

    check_hms_fn check_hms = (check_hms_fn)dlsym(handle, "check_hms");
    if (dlerror()) return 1;

    diff_seconds_fn diff_seconds =
        (diff_seconds_fn)dlsym(handle, "diff_seconds");
    if (dlerror()) return 1;

    printf("parse 01:30:00 -> %d sec\n", check_hms("01:30:00"));
    printf("diff 02:30:00 - 01:45:20 -> %d sec\n",
           diff_seconds("02:30:00", "01:45:20"));

    dlclose(handle);
    return 0;
}
