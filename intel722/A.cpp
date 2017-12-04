#include <iostream>
#include <string>

using namespace std;

int main(){
	string format;
	string time;
	int hours;
	int minutes;
	char c;

	cin >> format;
	cin >> time;

	for(int i=0; i<5; i++){
		c = time[i];
		switch(i){
			case 0:
				hours = 10*((int)c-48);
				break;
			case 1:
				hours+= (int)c-48;
				break;
			case 3:
				minutes = 10*((int)c-48);
				break;
			case 4:
				minutes+= (int)c-48;
			default:
				break;
		}
	}

	if(format=="12"){
		if(hours==0){
			hours = 10;
		}else if(hours>12){
			hours = hours%10;
		}
		if(minutes>59){
			minutes = 30 + minutes%10;
		}
	}else if(format=="24"){
		if(hours>23){
			hours = 10 + hours%10;
		}
		if(minutes>59){
			minutes = 30 + minutes%10;
		}
	}else{
		cout<<-1<<endl;
	}

	if(hours<10){
		cout << "0" ;
	}

	cout << hours << ":";

	if(minutes<10){
		cout << "0";
	}

	cout << minutes;


	return 0;
}