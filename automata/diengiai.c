#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char str[100];
	int i, L;
	printf("Nhap xau.. :"); fflush(stdin); gets(str);
	i= 0; L = strlen(str);


	if(isdigit(str[i])){ 	//Nếu ký hiệu đọc được là một chữ số
		i = i + 1;		//Đọc ký hiệu tiếp trên xâu vào
		while(isdigit(str[i])) 
			i = i + 1; // đang q1: vẫn là chữ số, đọc tiếp

		if(i == L) printf("%s la so nguyen \n",str); //Đọc hết xâu vào
		else if(str[i] != '.') printf("%s khong duoc doan nhan (%d)\n",str,i+1);
		else { 	//Đã đọc được dãy số và dấu ‘.’
			i = i + 1;
			if (i == L || !isdigit(str[i])) printf("Loi\n");
			else{
				while(isdigit(str[i])) i = i + 1;

			    if(i==L) printf("%s la so thuc dau phay tinh \n",str);
			    else {
			    	if (str[i] != 'e' && str[i] != 'E')
			    		printf("%s khong duoc doan nhan(%d)\n",str,i+1);
			    	else{
			    		i++;
			    		if (str[i]!='-' && str[i]!='+')
			    			printf("%s khong duoc doan nhan (%d)\n",str,i+1);
			    		else{
			    			i = i + 1;
							if (i == L || !isdigit(str[i])) printf("%s khong duoc doan nhan (%d)\n",str,i+1);
							else{
								while(isdigit(str[i])) i = i + 1;
								if(i==L) printf("Dau phay dong");
								else printf("%s khong duoc doan nhan (%d)\n",str,i+1);
							} 
			    		}
			    	}
			    }
			}
			
		}
	}	 
	else printf("%s khong duoc doan nhan (%d)\n",str,i+1);
	return 0;
}//