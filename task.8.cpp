#include <iostream>
using namespace std;

int main() {
	double tulip,roseR,roseW,price,discount;

	cout<<"enter number of tulip"<<endl;
	cin>>tulip;
    cout<<"enter number of red rose"<<endl;
   cin>>roseR;
    cout<<"enter number of white rose"<<endl;
   cin>>roseW;
   price=4.10*roseW+2.50*tulip+2*roseR;
   if(price>=200){
       discount=price*0.2;
   } 
  double priceAfterDiscount=price-discount;
cout<<"original price  :"<<price;
cout<<"price after discount"<<priceAfterDiscount;

	return 0;
}