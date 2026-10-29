#include <stdio.h>

int main() {
    FILE *fp = fopen("file.txt", "r");
    FILE *cp = fopen("copy.txt", "w");

    int buf_size = 4;
    char buffer[buf_size];
    int n;
    while ((n = fread(&buffer, 1, buf_size, fp)) != 0) {
        fwrite(&buffer, 1, buf_size, cp);
    }

    fclose(fp);
    fclose(cp);

    return 0;
}