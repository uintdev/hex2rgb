/*
Hex to RGB converter

gcc -o hex2rgb hex2rgb.c
./hex2rgb [hex]
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int unsigned segby = 0;
char* segarr[2];
char** hex;
int rgb[2];

int validation(char* data) {
    int unsigned inputCount;

    inputCount = strlen(data);

    if (data[strspn(data, "0123456789abcdefABCDEF")] != 0) {
    	printf("Error: Format is invalid.\n");
        return 1;
    }
    else if (inputCount == 3) {
        segby = 1;
    } else if (inputCount == 6) {
        segby = 2;
    } else {
        printf("Error: Hex must be 3 or 6 characters long.\n");
        return 1;
    }
}

char** segregate(char* data) {
    segarr[0] = strndup(data, segby);
    segarr[1] = strndup(data + segby, segby);
    segarr[2] = strndup(data + segby + segby, segby);

    return segarr;
}

int* rgbify(char* data) {
    int loopomax = 3;
    int loopo = 0;
    char** hex = segregate(data);
    while (loopo < loopomax) {
        if (segby == 1) {
            strcat(hex[loopo], hex[loopo]);
        }
        rgb[loopo] = strtol(hex[loopo], NULL, 16);
        loopo++;
    }

    free(segarr[0]);
    free(segarr[1]);
    free(segarr[2]);

    return rgb;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("%s: Too few arguments.\n", argv[0]);
        printf("%s [hex]\n", argv[0]);
        return 1;
    }

    if (validation(argv[1]) == 1) exit(1);

    int *rgbdata = rgbify(argv[1]);

    printf("rgb(%d,%d,%d)\n", rgbdata[0], rgbdata[1], rgbdata[2]);

    return 0;
}
