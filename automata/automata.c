#include<stdio.h>
#include<string.h>

enum state {q0, q1, q2, q3};
enum state Delta[4][2] = {{q1,q0}, {q1,q2}, {q1,q3}, {q1,q0}};
char c, str[100], *token, tmpstr[100];
int i, L, check;
enum state q = q0;

int main() {
	printf("Nhap xau...: "); fflush(stdin); gets(str);
	check = 1; strcpy(tmpstr, str);
	token = strtok(str, " ");

	while( token != NULL && check == 1 ) {
		i = 0; L = strlen(token); c = token[i] - 'a';
		
		while( i < L ) {
			if (c == 0 || c == 1) {
				q = Delta[q][c];
				i++;
				c = token[i] - 'a';
			} else { 
				printf("Loi dau vao %s...\n", token); 
				check = 0;
				break;
			}
		}
		printf("i: %d, L: %d", i, L);
		if(i == L)
		{
			if (q == q3) {
				printf("\n Xau %s duoc doan nhan!\n\n", token);
				check = 1;

			}
			else {
				check = 0;
				printf("\n Xau %s khong duoc doan nhan!\n\n", token);		
			}
		}
   		token = strtok(NULL, " ");
	}

	if(check == 1) printf("\n Cau %s duoc doan nhan!\n\n", tmpstr);
	else if (check == 0) printf("\n Cau %s khong duoc doan nhan!\n\n", tmpstr);
		
	return 0;		
}