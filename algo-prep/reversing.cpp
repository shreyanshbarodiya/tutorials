#include <iostream>
#include <string>

using namespace std;

void reverse(char *str) {
    char * end = str;
    char tmp;
    if (str) {
		while (*end) {
			++end;
		}
		--end; 
		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}  
}

void reverse_string(string &s){
	int begin=0;
	int end= s.length()-1;
	char tmp;

	if(end!=-1){
		while(begin<end){
			tmp = s[end];
			s[end] = s[begin];
			s[begin] = tmp;
			end--;
			begin++;
		}
	}

}

int main(){

	char str[] = "ajbkdbasfa";
/*	
	
	reverse(str);
	
	string s_rev(str);

*/
	scanf("%s",str);
	string s(str);
	reverse_string(s);
//	printf("%s\n", str);

	cout<<s<<endl;
//	cout<<s_rev<<endl;
	
	return 0;
}