#include<stdio.h>
#include<string.h>

int s, m, n, j, k, *arr, i;
char *T, *P;
int max(a, b) {
	return a > b ? a : b;
}

int last(char a) {
	int	i = n;
	while(i > 0) {
		if(a == T[i]) {		
			break;
		}
		i--;
	}
	return i;
}

int main() {
	T = "abcdaaecdaabceabcdaedcgabd";
	P = "abcd";
	s = 0; n = strlen(T); m = strlen(P);

	while(s < n - m) {
		j = m;
		while (j > 0 && T[j + s - 1] == P[j - 1]){
			j--;
		}
		if(j==0) {
			arr[i++] = s++;
		} else {
			k = last(T[j+s-1]);
			s += max(j-k, 1);
		}
	}
}