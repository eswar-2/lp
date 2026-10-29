#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "r");
    FILE *cp = fopen("copy.txt", "w");

    char c;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, cp);
    }

    fclose(fp);
    fclose(cp);

    return 0;
}
