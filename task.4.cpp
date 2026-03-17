#include <iostream>
using namespace std;

int main() {
    int holidays,days=365,workingDays,timeForGames,difference;
    
    cout<<"enter number of holidays  "<<endl;
    cin>>holidays;
    workingDays=days- holidays;
    timeForGames=(workingDays*63+holidays*127);
    difference=30000- timeForGames;
    int min = difference%60;
    int hours= difference/60;
    
    if(hours>=80) {
        cout<<"Tom sleeps well"<<endl<<hours<<"hours"<<min<<" minutes less for play";
    }
    else  cout<<"tom will run away"<<endl<<hours<<"hours"<<min<<"minutes for play";
    
	return 0;
}