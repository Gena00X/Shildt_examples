#ifndef MONTH_H
#define MONTH_H
using namespace std;
//for upr12() function
//g++ -o main.exe upr_12.cpp
/*January - 31 days
February - 28(29) days
March - 31 days
April - 30 days
May - 31 days
June - 30 days
July - 31 days
August - 31 days
September - 30 days
October - 31 days
November - 30 days
December - 31 days*/
const char* months[12]={
"January", 
"February", 
"March", 
"April", 
"May", 
"June", 
"July", 
"August", 
"September", 
"October", 
"November", 
"December"
};

/*
Monday - понедельник 
Tuesday - вторник 
Wednesday - среда 
Thursday - четверг 
Friday - пятница 
Saturday - суббота 
Sunday - воскресенье Week
*/

const char* days_of_week[7]=
{
"Sunday",
"Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday",
"Saturday"
};

const int days[12]={
31,
28,
31,
30,
31,
30,
31,
31,
30,
31,
30,
31
};

struct month_and_days{
	char* month;
	int days;
	month_and_days(char* m, int d):month(m), days(d){}
	//month_and_days(){}
};



void printheder(const char* col1, const char* col2){
	cout.width(13);
	cout<<left<<col1;
	/* cout.width(5);
	cout<<left<<"-"; */
	cout.width(5);
	cout<<col2<<'\n';
}
void printmonth(const char* month, const int day){
	cout.width(13);
	cout<<left<<month;
	/* cout.width(5);
	cout<<left<<"-"; */
	cout.width(5);
	cout<<right<<day<<'\n';
}

void makeData(month_and_days** data,const char** months, const int* days){
	for(int i = 0; i < 12; i++){
		data[i]=new month_and_days((char*)months[i],(int)days[i]);
	}
}
	


#endif //MONTH_H