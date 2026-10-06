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
        //shift over by 1 digit
        out*=10;
        //ignore minus sign
        if (i==0&&str[i]=='-') {continue;}
        //check digit value
        k=str[i]-'0';
        if (k<0||k>=10) {
            fprintf(stderr, "INVALID INTEGER STRING!");
            exit(k);
        }
        //if good, add
        out+=k;
        //check if integer overflow happened
        if ((out-k)/10>out) {
            fprintf(stderr, "INT TOO LARGE!");
            exit(out);
        }
    }
    if (str[0]=='-') {out*=-1;}
    return out;
}

double str_to_float(char *str) {
    short unsigned int decimal_pos;
    short unsigned int str_len;
    for (decimal_pos=0;str[decimal_pos]!='.'|str[decimal_pos]!='\0';decimal_pos++) {}
    for (str_len=0;str[str_len]!='\0';str_len++) {}
    if (str_len<decimal_pos) {
        fprintf(stderr, "INVALID DECIMAL POINT");
        exit(str_len-decimal_pos);
    }
    char *str_2=(char *)malloc(str_len);
    for (short unsigned int i=0;i<str_len;i++) {
        if (i<decimal_pos) {str_2[i]=str[i];}
        if (i>decimal_pos) {str_2[i-1]=str[i];}
    }
    decimal_pos=str_len-decimal_pos;
    long unsigned int power=1;
    for (short unsigned int i=0;i<decimal_pos;i++) {
        power*=10;
    }
    return (double)(str_to_int(str_2)/power);
}