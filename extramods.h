/*
This file will help you program easily that it contains some functions which are used often.
===============================================
NEW FUNCTIONS WIP!!!
If you find bugs in these completed functions,please contact me!
My Website:https://github.com/Entity303-E3/C-mods
===============================================
Version:1.0.2
Updating log:
2021/07/22: Update to 1.0.0
	create this mod
2021/07/22: Update to 1.0.1
	fix some bugs(change_x_2_dec(),change_x_2_y())
2021/07/27: Update to 1.0.2
	improve the method of calculation(sum())
===============================================
CONTENTS:
----------------------------------Hexadecimal--------------------------------
	change_2_bin(int)	return string:
		change decimal into binary

	change_2_dec(string)	      return int:
		change binary into decimal

	change_x_2_dec(string,int)	return int:
		change a number into decimal

	change_x_2_y(string,int,int)	return string:
		change a number into another number
ATTENTION:ALL FUNCTIONS UNSIGNED!
--------------------------------------------------------------------------------

---------------------------------------Data------------------------------------
	change_str_2_int(string)	return long long:(unsigned)
		change a string into long long(19 BITS MAX!!!)
--------------------------------------------------------------------------------

-----------------------------------Judging-------------------------------------
	str_in_str(string,string)	return bool:
		judge whether a string is in another string
--------------------------------------------------------------------------------

----------------------------------Calculation----------------------------------
	sum(long long,  long long，long long）	return long long:
		sum from a to b, adding c at once
--------------------------------------------------------------------------------
===============================================
=================Programs Here!!!!!!!!!!===============*/
#include<bits/stdc++.h>
using namespace std;
string change_2_bin(int a){
	string b,d;
	int c=0;
	while(a){
		b+=a%2+48;
		a/=2;
		c++;
	}
	c=0;
	for(int i=b.length()-1;i>=0;i--){
		d+=b[i];
		c++;
	}
	return d;
}
int change_2_dec(string a){
	int b,num=0,cnt=1;
	for(int i=a.length()-1;i>=0;i--){
		b=a[i]-48;
		num+=cnt*b;
		cnt*=2;
	}
	return num;
}
int change_x_2_dec(string a,int s){
	if(s<=36){
		int b,t,num=0,cnt=1;
		for(int i=a.length()-1;i>=0;i--){
			t=a[i];
			if(t<58){
				b=t-48;
			}
			else{
				b=t-55;
			}
			num+=cnt*b;
			cnt*=s;
		}
		return num;
	}
	else{
		return -1;
	}
}
string change_x_2_y(string a,int b,int c){
	int dec_num=change_x_2_dec(a,b);
	if(c<=36){
		string x,y;
		int s=0;
		while(dec_num){
			if(dec_num%c>=10){
				x+=dec_num%c+55;
				dec_num/=c;
				s++;
			}
			else{
				x+=dec_num%c+48;
				dec_num/=c;
				s++;
			}
		}
		s=0;
		for(int i=x.length()-1;i>=0;i--){
			y+=x[i];
			s++;
		}
	return y;
	}
	else{
		return "DATA OUT OF RANGE!";
	}
}
long long change_str_2_int(string a){
	long long num=0,t,cnt=1;
	for(int i=a.length()-1;i>=0;i--){
		t=a[i]-48;
		num+=t*cnt;
		cnt*=10;
	}
	return num;
}
bool str_in_str(string a,string b){
	if(a.length()>b.length()){
		return false;
	}
	else{
		string index="";
		for(int i=0;i<=b.length()-a.length();i++){
			index="";
			for(int j=i;j<i+a.length();j++){
				index+=b[j];
			}
			if(a==index){
			return true;
			}
		}
		return false;
	}
}
long long sum(long long a,long long b,long long c){
	long long num=(a+b)*((b-a)/c+1)/2;
	return num;
}