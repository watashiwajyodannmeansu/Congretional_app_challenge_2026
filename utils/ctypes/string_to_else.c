#ifndef malloc
    #include <stdlib.h>
#endif
#ifndef fprintf
    #include <stdio.h>
#endif
#ifndef int64_t
    #include <stdint.h>
#endif
int64_t str_to_int(char *str) {
    int64_t out=0;
    short int k;
    for (short unsigned int i=0;str[i]!='\0';i++) {
        out*=10;
        if (i==0&&str[i]=='-') {continue;}
        k=str[i]-'0';
        if (k<0||k>=10) {
            fprintf(stderr, "INVALID INTEGER STRING!");
            exit(k);
        }
        out+=k;
        if ((out-k)/10>out) {
            fprintf(stderr, "INT TOO LARGE!");
            exit(out);
        }
    }
    if (str[0]=='-') {out*=-1;}
    return out;
}