#include<bits/stdc++.h>
using namespace std;

//Cach de quy binh thuong 
void ThapHaNoi(int n , char A , char B , char C)
{
	if(n == 1){
		cout<<"Dich chuyen tu "<<A<<" -> "<<B<<" voi "<<C<<" lam trung gian"<<endl;
		return;
	}	
	ThapHaNoi(n - 1 , A , C , B);
	ThapHaNoi(1 , A , B , C);
	ThapHaNoi(n - 1 , C , B , A);
}
//Su dung cach khu de quy 
struct Call{
	int n;
	char a;
	char b;
	char c;
};
struct Stack{
	int top;
	Call*e;
};
void init(Stack &s){
	s.top = -1;
	s.e = NULL;
}
bool empty(Stack e){
	return e.top == -1;
}
void push(Stack &s , Call element){
	//Check if stack empty 
	if(empty(s)){
		//Add element to stack  
		s.e = new Call[1];
	}else{
		//Update stack 
		//Realloc : (Kieudulieu*) realloc(phantucapphat , (vi tri cap phat + 2)*sizeof(Kieudulieu))
		s.e = (Call*) realloc(s.e , (s.top + 2)*sizeof(Call));
	}
	//update top element 
	s.top++;
	//Assign at top 
	s.e[s.top] = element;
}
void pop(Stack &s, Call &element){
	//Get element in top stack 
	if(empty(s)){
		return;
	}
	element = s.e[s.top];
	//Check case 
	//1.Stack have 1 element , index 0 
	if(s.e == 0){
		delete []s.e;
		init(s);
	}else{
		s.e = (Call*) realloc(s.e , s.top*sizeof(Call));
		s.top--;
	}
}
void HaNoiTown(Call first_call){
	//Init variable 
	Stack stack;
	Call call_in , call_out;//Call data input , call data output 

	//Init stack 
	init(stack);
	call_in = first_call;
	//Push data into stack 
	push(stack , first_call);

	while(!empty(stack)){
		//Get element top 
		pop(stack , call_out);

		//Check if n in call_out equal 1 (tuong duong voi dia con 1 dia de xu ly )
		if(call_out.n == 1){
			cout<<"Dich chuyen 1 dia tu "<<call_out.a <<" -> "<<call_out.b<<endl;
		}else{
			//Move n - 1 ele from call_in.a sang call_in.b
			call_in.n = call_out.n - 1; 
			call_in.a = call_out.b;
			call_in.b = call_out.a;
			call_in.c = call_out.c;
			//Put to stack to handle 
			push(stack , call_in);

			//Move last ele from call_out.a to call_out.c
			call_in = call_out;
			call_in.n = 1;
			//put to stack 
			push(stack , call_in);

			//Move n - 1 ele from call call_out.c to call_out.b 
			call_in.n = call_out.n - 1; 
			call_in.a = call_out.a;
			call_in.b = call_out.c;
			call_in.c = call_out.b;
			push(stack , call_in);
		}
	}

}
int main()
{
	cout<<"De quy nhu binh thuong"<<endl;
	ThapHaNoi(3, 'A' , 'B' , 'C');
	
	cout<<"Khu de quy"<<endl;
	Call call = {3 , 'A' , 'B' , 'C'};
	HaNoiTown(call);
	return 0;
}
