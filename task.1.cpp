#include <iostream>
using namespace std;

int main(){
    
    string countryName,ireland;
    int ticket,discount;
  cout<<"enter your country name";
    cin>> countryName;
    cout<<"enter your ticket price(in dollars)";
    cin>>ticket;
    if(countryName!= "ireland"){
        discount = ticket*0.05;
    }
    else {
        discount= ticket*0.1;
    }
   int discountTicket=ticket-discount;
    cout<<"discount ticket price;"<<discountTicket;
    
    return 0;
}