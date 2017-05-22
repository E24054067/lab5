#include<iostream>
#include<string>
#include <sstream>
using namespace std;
class HugeInt{
	friend istream & operator>> (istream &in, HugeInt &a);
	friend ostream & operator <<(ostream &out,const HugeInt &a);
	public:
		HugeInt(int temp=0){
			size=0;
			ptr= new int[40];
			for(int i=0;i<40;++i){
				ptr[i]=0;}
			for(int i=0;temp!=0;i++){
				ptr[i]=temp%10;
				size++;
				temp/=10;}
		}
		HugeInt(string temp){
			ptr= new int[40];
			for(int i=0;i<40;++i){
				ptr[i]=0;}
			string x;
			size=temp.size();
			for(int i=size-1,j=0;i>=0;i--,++j){
		        x=temp[i];
		        istringstream buffer(x);
		        buffer >> ptr[j];}

//			for(int i=0;i<size;i++)cout<<ptr[i]<<endl;
			}
		HugeInt operator + ( const HugeInt &class2 ){
			HugeInt temp(0);
			int carry=0;
			for(int i=0;i<40;++i){
				temp.ptr[i]=ptr[i]+class2.ptr[i]+carry;
				if(temp.ptr[i]>=10)	{
					temp.ptr[i]%=10;
					carry=1;}
				else	carry=0;	
//				cout<<temp.ptr[i];
				}

		return temp;

		}

		HugeInt operator -(const HugeInt &class2){
			HugeInt temp(0);
			int borrow=0;
			for(int i=0;i<40;++i){
				temp.ptr[i]=ptr[i]-class2.ptr[i]-borrow;
				if(temp.ptr[i]<0){
					temp.ptr[i]+=10;
					borrow=1;}
				else borrow=0;
			}
			return temp;
		}
		HugeInt operator =(const HugeInt &right){
			for(int i=0;i<40;++i){
				ptr[i]=right.ptr[i];}
			}	
					
					
	private:
		int *ptr;
		int size;
	
};

istream & operator>> (istream &in, HugeInt &a){
	string input;
	in>>input;
	HugeInt temp(input);
	a=temp;
	return in;
}

ostream & operator <<(ostream &out,const HugeInt &a){
	int size=0;
	for(int i=39;i>=0;--i){
		if(a.ptr[i]!=0){
		size=i+1;
		 break;}
	}
	for(int i=size-1;i>=0;--i)
		out<<a.ptr[i];
	return out;
}
 
int main() {
  HugeInt x;
  HugeInt y(28825252);
  HugeInt z("314159265358979323846");
  HugeInt result; 
  cin >> x;
  result = x+y;
  cout  <<  x  <<  "+"  <<  y  <<  " = " << result << endl; 
 result =z-x;
 cout << result << endl; 
 
 return 0; } 
 
