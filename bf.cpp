#include <iostream>
#include <map>
#include <conio.h>

int main(int argc, char** argv) {
	std::string source = "++++[>+++<-]>[-<++++>]<[->+>+<<]>>>,<[->-<]<[->>>+<<<]>>[->+>+<<]>>[<.>]<.";
	int stack[30000];
	int index = 0;
	
	int loopstack[30000];
	int top = 0;
	std::map<int,int> loopdict;
	
	for(int i = 0; i < source.length(); i++) {
		char tok = source[i];
		if(tok == '[') {
			loopstack[top] = i;
			top++;
		}
		if(tok == ']') {
			top--;
			int s0 = i;
			int s1 = loopstack[top];
			loopstack[top] = -1;
			loopdict[s0] = s1;
			loopdict[s1] = s0;
		}
	}
	
	int ip = 0;
	while(ip < source.length())
	{
		if(source[ip] == '+') {
			stack[index]++;
			if(stack[index] > 255)
				stack[index] = 0;
		} else if(source[ip] == '-') {
			stack[index]--;
			if(stack[index] < 0)
				stack[index] = 255;
		} else if(source[ip] == '.') {
			std::cout << (char)stack[index];
		} else if(source[ip] == ',') {
			stack[index] = getch();
		} else if(source[ip] == '<') {
			index--;
			if(index < 0)
				index = 29999;
		} else if(source[ip] == '>') {
			index++;
			if(index > 29999)
				index = 0;
		} else if(source[ip] == '[') {
			if(stack[index] == 0) {
				ip = loopdict[ip];
			}
		} else if(source[ip] == ']') {
			if(stack[index] != 0) {
				ip = loopdict[ip];
			}
		}  
		ip++;
	}
	
	return 0;
}
