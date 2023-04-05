#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

union fraction {
    double doub;
    int64_t integer;
};

union xornum {
    int64_t hex;
    int64_t integer;
};

int main() {
    int i,n;
    int64_t hex;
    double p, q;
    union fraction fr;
    union xornum xn;
    
    scanf("%d", &n);
   
    for (i = 0; i < n; i++) {
        scanf("%lf/%lf xor %llx", &p, &q, &hex);
        xn.hex = hex;
        fr.doub = p / q;
        fr.integer = fr.integer ^ xn.integer;
        printf("%0.15g\n", fr.doub);
    }
}