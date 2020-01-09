#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream fil;
	fstream fit;
	string name="",str,ans;
	string t,t1="cout<<\" ",t2="=\" <<",t3="<<endl;\n";
	fit.open("target1.cpp",ios::out);
	if(!fit){
		cout<<"NEw file not created\n";
		return 0;
	}cout<<"NEw file created\n";
	//fit>>"GG";
	
	char ch='=';
	fil.open("1.cpp");
	if(!fil){
		cout<<"File not found"<<endl;
	}
	else{int flag=0;
		while(!fil.eof()){
			flag=0;
			name=" ";
			getline(fil,str);
			fit<<str<<endl;
			size_t found=str.find(ch);
			if(found != string::npos){
				// name=str.substr(0,found);
				// if(name[0]=='=' || (name[1]=='=' && (name[0]=='+' ||name[0]=='-' ||name[0]=='*' ||name[0]=='/' ||name[0]=='%'))){
				// 	name=prev;
				// }
				// else{
				// 	if(name.back()=='+' ||name.back()=='-'||name.back()=='*' ||name.back()=='/' ||name.back()=='%'){
				// 		name.erase(name.size()-1);
				// 	}
				// }
				for(int i=found-1;i>=0;--i){
					if(str[i]==' ' && flag ==1){
						break;
					}
					if(str[i]!=' ' && str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/' && str[i]!='%'){
							flag=1;
							t=str[i];
							name.insert(0,t);
					}
				}
				cout<<name<<endl;
				ans+="cout<<";
				ans+='"';
				ans+=name;
				ans+=" = ";
				ans+='"';
				ans+="<<";
				ans+=name;
				ans+="<<endl;";
				// fit<<t1;
				// fit<<name<<t2<<name<<t3;
				fit<<ans<<endl;
				ans="";

			}

			cout<<str<<endl;
		}
		fil.close();
		fit.close();
	}

	return 0;

}