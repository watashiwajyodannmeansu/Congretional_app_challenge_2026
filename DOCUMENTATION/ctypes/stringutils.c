int stringcmp(char *cmp1, int cmp1_len, char *cmp2, int cmp2_len) {
	int out=0;
	int min=cmp1_len;
	int max=cmp2_len;
	if (cmp2_len>cmp1_len) {
		min=cmp2_len;
		max=cmp1_len;
	}
	for (int i=0;i<min;i++) {out+=(cmp1[i]!=cmp2[i]);}
	if (min==cmp1_len) {
	for (int i=min;i<max;i++) {out+=(cmp2[i]=='\0');}
	} else {
	for (int i=min;i<max;i++) {out+=(cmp1[i]=='\0');} 
	}
	return out;
}
//Whoopsies! wrong directory :/ sorry about that :<
