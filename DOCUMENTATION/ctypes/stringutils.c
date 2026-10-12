int stringcmp(char *cmp1, int cmp1_len, char *cmp2, int cmp2_len) {
    int out=0;
    int min=cmp1_len;
    int max=cmp2_len;
    if (cmp2_len>cmp1_len) {
        min=cmp2_len;
        max=cmp1_len;
    }
    return out;
}