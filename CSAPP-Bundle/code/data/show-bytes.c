/* $begin show-bytes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
    for (int i = 0; i < len; i++) {
        printf(" %.2x", start[i]); // line:data:show_bytes_printf
    }
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer)&x, sizeof(int)); // line:data:show_bytes_amp1
}

void show_float(float x) {
    show_bytes((byte_pointer)&x, sizeof(float)); // line:data:show_bytes_amp2
}

void show_pointer(void *x) {
    show_bytes((byte_pointer)&x, sizeof(void *)); // line:data:show_bytes_amp3
}
/* $end show-bytes */

/* $begin test-show-bytes */
void test_show_bytes(int val) {
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
/* $end test-show-bytes */

void simple_show_a() {
    /* $begin simple-show-a */
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    show_bytes(valp, 4);
    /* $end simple-show-a */
}

void simple_show_b() {
    /* $begin simple-show-b */
    int val = 0x12345678;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    show_bytes(valp, 4);
    /* $end simple-show-b */
}

void float_eg() {
    int x = 3490593;
    float f = (float)x;
    printf("x = %d\n", x);
    show_int(x);
    show_float(f);

    x = 3510593;
    f = (float)x;
    printf("x = %d\n", x);
    show_int(x);
    show_float(f);
}

void string_ueg() {
    /* $begin show-ustring */
    const char *s = "ABCDEF";
    show_bytes((byte_pointer)s, strlen(s));
    show_bytes((byte_pointer)s, strlen(s) + 1);
    /* $end show-ustring */
}

void string_leg() {
    /* $begin show-lstring */
    const char *s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));
    show_bytes((byte_pointer)s, strlen(s) + 1);
    /* $end show-lstring */
}

void show_twocomp() {
    /* $begin show-twocomp */
    int x = 12345;
    int mx = -x;

    show_bytes((byte_pointer)&x, sizeof(int));
    show_bytes((byte_pointer)&mx, sizeof(int));
    /* $end show-twocomp */
}

int main(int argc, char *argv[]) {
    int val = 12345;

    if (argc > 1) {
        if (argc > 1) {
            val = strtol(argv[1], NULL, 0);
        }
        printf("calling test_show_bytes\n");
        test_show_bytes(val);
    } else {
        printf("calling show_twocomp\n");
        show_twocomp();
        printf("Calling simple_show_a\n");
        simple_show_a();
        printf("Calling simple_show_b\n");
        simple_show_b();
        printf("Calling float_eg\n");
        float_eg();
        printf("Calling string_ueg\n");
        string_ueg();
        printf("Calling string_leg\n");
        string_leg();
    }
    return 0;
}
