#include <stdio.h>
#include "target.h"

int main(void) {
# if __GNUC__ && !__GNUC_STDC_INLINE__
    printf("gnuc----\n");
# else
    printf("not gnuc----\n");
# endif
    int x = plus(1, 2);
    printf("%x\n", x);
}
