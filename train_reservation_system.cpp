#include<iostream>
using namespace std;
int main() {

	string useroption, psngrOption, adminOption, username, trainName,searchName;
	int    password, activeBookings, totalSeats, percentage, filled,age,foundIndex;
	int    i, j, b, newfare, newTotalSeats;
	bool   found,anyFound;
	int    totalRevenue, trainRevenue, trainBookings,cancleNum, idx;
	string newTrainName, newFromCity, newToCity, newDepartureTime;
	string psngrName, psngrPswrd, cnfrmPsngrPswrd, cnfrmBooking, bookTicketName;

// train arrays
	string trainArray[10]     = {"green line", "pink line", "teizgum"};
	string fromCityArray[10]  = {"lahore",  "liya", "pindi"};
	string toCityArray[10]    = {"karachi",  "quetta",  "lahore"};
	string departureArray[10] = {"06:00",   "12:00",  "18:00"};
	int    fareArray[10]      = {2500, 2000,  1000};
	int    seatsArray[10]     = {100, 90,   115};
	int    totalTrains        = 3;

	// passenger arrays
	string nameArray[100]      = {"ali",  "sara",  "ahmad", "fatima", "usman"};
	int    ageArray[100]       = {25,             32,           19,            27,              35};
	string psngrPassArray[100] = {"ali123",       "sara456",    "ahmed789",   "fatima321",    "usman654"};
	int    totalPassengers     = 5;

	// booking arrays
	string bookedByArray[100]      = {"ali",  "sara",   "ahmed", "fatima", "ali", "usman"};
	string bookedTrainArray[100]   = {"green line",  "pink line", "green line", "teizgum", "teizgum","pink line"};
	int    bookedFareArray[100]    = {2500, 2000, 2500,1000,1000,2000};
	string bookingStatusArray[100] = {"active","active","active","active","cancelled","active"};
	int    totalBookings           = 6;

	// seats updated to reflect active bookings
	seatsArray[0] = 98;
	seatsArray[1] = 88;
	seatsArray[2] = 114;

	int trains = 10;

	while(true) {
		system("clear");
		cout<<endl;

		cout<<"!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!!"<<endl;
		cout<<"!!                welcome to train reservation system                     !!"<<endl;
		cout<<"!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!!"<<endl<<endl;

		cout<<"1. Admin "<<endl;
		cout<<"2. Passenger "<<endl;
		cout<<"3. Exit "<<endl;
		cout<<"choose your option :  ";
		cin>>useroption;

		if(useroption=="1") {
			//admin portal
			system("clear");
			cout<<endl;
			cout<<"--------------------"<<endl;
			cout<<"----Admin Portal----"<<endl;
			cout<<"--------------------"<<endl<<endl;

			for(i=3; i>0; i--) {
				cout<<"                                     attempts left : "<<i<<endl;
				cout<<"ENTER username : ";
				cin>>username;
				cout<<"ENTER password : ";
				cin>>password;
				if(username=="admin" && password==123) {
					//admin menu
					while(true) {
						system("clear");
						cout<<endl;

						cout<<"welcome to  admin menu"<<endl;
						cout<<"------------------------------------"<<endl<<endl;
						cout<<"1. Search train "<<endl;
						cout<<"2. Add new train "<<endl;
						cout<<"3. Check Total revenue "<<endl;
						cout<<"4. View all bookings"<<endl;
						cout<<"5. Cancle a booking"<<endl;
						cout<<"6. Train occupuncy report "<<endl;
						cout<<"7. Logout "<<endl;
						cout<<endl<<"choose a option : ";
						cin>>adminOption;

						if(adminOption=="1") {
							//search train
							cout<<"ENTER train name to Search : ";
							cin.ignore();
							getline(cin,trainName);

							foundIndex = -1;
							found = false;
							for(j=0; j<totalTrains; j++) {
								if(trainName==trainArray[j]) {
									found = true;
									foundIndex = j;
								}
							}
							if(found==true) {
								cout<<"Train     \t     From     \t     to     \t     Departure time     \t     Fare     \t     Total seats"<<endl;
								cout<<trainArray[foundIndex]<<"     \t     "<<fromCityArray[foundIndex]<<"     \t     "<<toCityArray[foundIndex];
								cout<<"     \t     "<<departureArray[foundIndex]<<"     \t\t     "<<fareArray[foundIndex]<<"     \t     "<<seatsArray[foundIndex]<<endl;
							} else {
								cout<<"record against name not found"<<endl;
							}

							cout<<endl<<"press ENTER key to continue..";
							cin.ignore();
							cin.get();

						} else if(adminOption=="2") {
							//add train
							cout<<" ---Add new train----"<<endl;
							cout<<"ENTER train name : ";
							cin.ignore();
							getline(cin,newTrainName);
							cout<<"ENTER city from it departure : ";
							cin>>newFromCity;
							cout<<"ENTER city to its departure : ";
							cin>>newToCity;
							cout<<"ENTER departure time : ";
							cin>>newDepartureTime;
							cout<<"ENTER fare : ";
							cin>>newfare;
							cout<<"ENTER total seats : ";
							cin>>newTotalSeats;

							if(totalTrains < 10) {
								trainArray[totalTrains]     = newTrainName;
								fromCityArray[totalTrains]  = newFromCity;
								toCityArray[totalTrains]    = newToCity;
								departureArray[totalTrains] = newDepartureTime;
								fareArray[totalTrains]      = newfare;
								seatsArray[totalTrains]     = newTotalSeats;

								cout<<"Train added successfully!"<<endl;
								cout<<"Train    \t    From    \t    to    \t    Departure time    \t    Fare    \t    Total seats"<<endl;
								cout<<trainArray[totalTrains]<<"    \t    "<<fromCityArray[totalTrains]<<"    \t    "<<toCityArray[totalTrains];
								cout<<"    \t    "<<departureArray[totalTrains]<<"    \t \t   "<<fareArray[totalTrains]<<"    \t    "<<seatsArray[totalTrains]<<endl;

								totalTrains++;
							} else {
								cout<<"train list is full cannot add more trains"<<endl;
							}
							cout<<endl<<"press ENTER key to continue..";
							cin.ignore();
							cin.get();

						} else if(adminOption=="3") {
							//total revenue
							cout<<endl;
							cout<<"--------------------------------------------"<<endl;
							cout<<"            Total Revenue Report            "<<endl;
							cout<<"--------------------------------------------"<<endl;

							totalRevenue = 0;
							for(i=0; i<totalTrains; i++) {
								trainRevenue  = 0;
								trainBookings = 0;
								for(j=0; j<totalBookings; j++) {
									if(bookedTrainArray[j]==trainArray[i] && bookingStatusArray[j]=="active") {
										trainRevenue  += bookedFareArray[j];
										trainBookings++;
									}
								}
								cout<<"Train : "<<trainArray[i]<<"    \t    Bookings : "<<trainBookings<<"    \t    Revenue : "<<trainRevenue<<endl;
								totalRevenue += trainRevenue;
							}
							cout<<"--------------------------------------------"<<endl;
							cout<<"TOTAL REVENUE :  "<<totalRevenue<<endl;
							cout<<"--------------------------------------------"<<endl;

							cout<<endl<<"press ENTER key to continue..";
							cin.ignore();
							cin.get();

						} else if(adminOption=="4") {
							//view all booking
							cout<<endl;
							cout<<"--------------------------------------------"<<endl;
							cout<<"             All Bookings                   "<<endl;
							cout<<"--------------------------------------------"<<endl;

							if(totalBookings==0) {
								cout<<"no bookings found"<<endl;
							} else {
								cout<<"No.    \t    Passenger    \t    Train    \t    Fare    \t    Status"<<endl;
								cout<<"--------------------------------------------"<<endl;
								for(i=0; i<totalBookings; i++) {
									cout<<(i+1)<<"    \t    "<<bookedByArray[i]<<"    \t    "<<bookedTrainArray[i];
									cout<<"    \t    "<<bookedFareArray[i]<<"    \t    "<<bookingStatusArray[i]<<endl;
								}
							}
							cout<<"--------------------------------------------"<<endl;
							cout<<endl<<"press ENTER key to continue..";
							cin.ignore();
							cin.get();

						} else if(adminOption=="5") {
							//cancle a booking
							cout<<endl;
							cout<<"--------------------------------------------"<<endl;
							cout<<"             Cancle a Booking               "<<endl;
							cout<<"--------------------------------------------"<<endl;

							if(totalBookings==0) {
								cout<<"no bookings found"<<endl;
							} else {
								cout<<"No.    \t    Passenger    \t    Train    \t    Fare    \t    Status"<<endl;
								cout<<"--------------------------------------------"<<endl;
								for(i=0; i<totalBookings; i++) {
									cout<<(i+1)<<"    \t    "<<bookedByArray[i]<<"    \t    "<<bookedTrainArray[i];
									cout<<"    \t    "<<bookedFareArray[i]<<"    \t    "<<bookingStatusArray[i]<<endl;
								}
								cout<<"--------------------------------------------"<<endl;
								cout<<"ENTER booking number to cancle (0 to go back) : ";
								cin>>cancleNum;
								if(cancleNum==0) {
									// go back
								} else if(cancleNum<1 || cancleNum>totalBookings) {
									cout<<"invalid booking number"<<endl;
								} else {
									idx = cancleNum - 1;
									if(bookingStatusArray[idx]=="cancelled") {
										cout<<"this booking is already cancelled"<<endl;
									} else {
										bookingStatusArray[idx] = "cancelled";
										for(i=0; i<totalTrains; i++) {
											if(trainArray[i]==bookedTrainArray[idx]) {
												seatsArray[i]++;
												break;
											}
										}
										cout<<"booking number "<<cancleNum<<" cancelled successfully"<<endl;
										cout<<"refund amount : "<<bookedFareArray[idx]<<endl;
									}
								}
							}
							cout<<endl<<"press ENTER key to continue..";
							cin.ignore();
							cin.get();

						} else if(adminOption=="6") {
							// train occupuncy
							system("clear");
							cout<<endl;
							
							cout<<"--------------------------------------------"<<endl;
							cout<<"         Train Occupuncy Report             "<<endl;
							cout<<"--------------------------------------------"<<endl;

							for(i=0; i<totalTrains; i++) {
								activeBookings = 0;
								for(j=0; j<totalBookings; j++) {
									if(bookedTrainArray[j]==trainArray[i] && bookingStatusArray[j]=="active") {
										activeBookings++;
									}
								}
								totalSeats  = seatsArray[i] + activeBookings;
								percentage  = 0;
								if(totalSeats > 0) {
									percentage = (activeBookings * 100) / totalSeats;
								}
								cout<<endl;
								cout<<"Train : "<<trainArray[i]<<endl;
								cout<<"Booked : "<<activeBookings<<"  /  "<<totalSeats<<"   ("<<percentage<<"% full)   Available : "<<seatsArray[i]<<endl;
								filled = percentage / 5;
								cout<<"[";
								for(b=0; b<20; b++) {
									if(b<filled) {
										cout<<"#";
									} else {
										cout<<"-";
									}
								}
								cout<<"]"<<endl;
							}
							cout<<"--------------------------------------------"<<endl;
							
							cout<<endl<<"press ENTER key to continue..";
							cin.ignore();
							cin.get();
							

						} else if(adminOption=="7") {
							// Logout
							cout<<"admin logged out successfully"<<endl;
							break;
						} else {
							cout<<"invalid information"<<endl;
							cout<<"press ENTER key to continue...";
							cin.ignore();
							cin.get();
						}

					}
					break;
				} else if(i==1) {
					cout<<"invalid username & password"<<endl;
					cout<<endl<<"press ENTER key to continue..";
					cin.ignore();
					cin.get();
					break;
				} else {
					cout<<"invalid username & password   try again"<<endl<<endl;
				}

			}
			cout<<endl<<"press ENTER key to continue..";
			cin.ignore();
			cin.get();

		} else if(useroption=="2") {
			//passenger portal

			while(true) {
				system("clear");
				cout<<endl;

				cout<<"------------------------"<<endl;
				cout<<"----Passenger Menu------"<<endl;
				cout<<"------------------------"<<endl<<endl;
				cout<<"1. View all trains"<<endl;
				cout<<"2. Book ticket"<<endl;
				cout<<"3. View my ticket"<<endl;
				cout<<"4. Cancle my ticket "<<endl;
				cout<<"5. Exit"<<endl;
				cout<<"Choose a option :  ";
				cin>>psngrOption;

				if(psngrOption=="1") {
					//view all train
					cout<<"Train    \t    From    \t    to    \t    Departure time    \t    Fare    \t    Total seats"<<endl;
					cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
					for(i=0; i<totalTrains; i++) {
						cout<<trainArray[i]<<"    \t    "<<fromCityArray[i]<<"    \t    "<<toCityArray[i];
						cout<<"    \t    "<<departureArray[i]<<"   \t \t    "<<fareArray[i]<<"    \t    "<<seatsArray[i]<<endl;


					}
					cout<<endl<<"press ENTER key to continue..";
					cin.ignore();
					cin.get();


				} else if(psngrOption=="2") {
					//book ticket
					while(true) {
						cout<<"-------------"<<endl;
						cout<<"----login----"<<endl;
						cout<<"ENTER your name : ";
						cin.ignore();
						getline(cin,psngrName);
						cout<<"Create password : ";
						cin>>psngrPswrd;
						cout<<"Again type password to confirm : ";
						cin>>cnfrmPsngrPswrd;

						if(psngrPswrd==cnfrmPsngrPswrd) {
							cout<<"enter your age : ";
							cin>>age;

							cout<<endl<<"available trains :"<<endl;
							cout<<"Train    \t    From    \t    to    \t    Departure time    \t    Fare    \t    Available seats"<<endl;
							cout<<"--------------------------------------------"<<endl;
							for(i=0; i<totalTrains; i++) {
								cout<<trainArray[i]<<"    \t    "<<fromCityArray[i]<<"    \t    "<<toCityArray[i];
								cout<<"    \t    "<<departureArray[i]<<"  \t  \t    "<<fareArray[i]<<"    \t    "<<seatsArray[i]<<endl;
							}

							cout<<"ENTER train name for booking : ";
							cin.ignore();
							getline(cin,bookTicketName);

							foundIndex = -1;
							found = false;
							for(i=0; i<totalTrains; i++) {
								if(bookTicketName==trainArray[i]) {
									found = true;
									foundIndex = i;
								}
							}
							if(found==true) {
								if(seatsArray[foundIndex]<=0) {
									cout<<"sorry no seats available on this train"<<endl;
								} else {
									cout<<endl<<"Booking summary :"<<endl;
									cout<<"Train : "<<trainArray[foundIndex]<<endl;
									cout<<"From  : "<<fromCityArray[foundIndex]<<"    to : "<<toCityArray[foundIndex]<<endl;
									cout<<"Time  : "<<departureArray[foundIndex]<<endl;
									cout<<"Fare  : "<<fareArray[foundIndex]<<endl;
									cout<<endl<<"Do you confirm your booking (1 for yes & 0 for no) : ";
									cin>>cnfrmBooking;

									if(cnfrmBooking=="1") {
										nameArray[totalPassengers]      = psngrName;
										ageArray[totalPassengers]       = age;
										psngrPassArray[totalPassengers] = psngrPswrd;
										totalPassengers++;

										bookedByArray[totalBookings]      = psngrName;
										bookedTrainArray[totalBookings]   = trainArray[foundIndex];
										bookedFareArray[totalBookings]    = fareArray[foundIndex];
										bookingStatusArray[totalBookings] = "active";
										totalBookings++;

										seatsArray[foundIndex]--;

										cout<<"booking confirmed successfully!"<<endl;
										cout<<"your booking number is : "<<totalBookings<<endl;

									} else {
										cout<<"you cancle your booking "<<endl;
									}
								}
							} else {
								cout<<"record of train not found"<<endl;
								cout<<"press ENTER key to continue..."<<endl;
								cin.ignore();
								cin.get();
							}
							break;
						} else {
							cout<<"incorrect passwords    plz try again to login"<<endl;
						}
					}
					cout<<endl<<"press ENTER key to continue..";
					cin.ignore();
					cin.get();

				} else if(psngrOption=="3") {
					//view ticket
					cout<<"--------------------------------------------"<<endl;
					cout<<"            View my ticket                  "<<endl;
					cout<<"--------------------------------------------"<<endl;
					cout<<"ENTER your name : ";
					cin.ignore();
					getline(cin,searchName);

					anyFound = false;
					for(i=0; i<totalBookings; i++) {
						if(bookedByArray[i]==searchName) {
							cout<<"--------------------------------------------"<<endl;
							cout<<"Booking No. : "<<(i+1)<<endl;
							cout<<"Passenger   : "<<bookedByArray[i]<<endl;
							cout<<"Train       : "<<bookedTrainArray[i]<<endl;
							cout<<"Fare        : "<<bookedFareArray[i]<<endl;
							cout<<"Status      : "<<bookingStatusArray[i]<<endl;
							anyFound = true;
						}
					}
					if(anyFound==false) {
						cout<<"no booking found against your name"<<endl;
					}
					cout<<"--------------------------------------------"<<endl;

					cout<<endl<<"press ENTER key to continue..";
					cin.ignore();
					cin.get();

				} else if(psngrOption=="4") {
					//cancle ticket
					cout<<"--------------------------------------------"<<endl;
					cout<<"            Cancle my ticket                "<<endl;
					cout<<"--------------------------------------------"<<endl;
					cout<<"ENTER your name : ";
					cin.ignore();
					getline(cin,searchName);

					anyFound = false;
					for(i=0; i<totalBookings; i++) {
						if(bookedByArray[i]==searchName && bookingStatusArray[i]=="active") {
							cout<<"Booking No. : "<<(i+1)<<"    Train : "<<bookedTrainArray[i]<<"    Fare : "<<bookedFareArray[i]<<"    Status : "<<bookingStatusArray[i]<<endl;
							anyFound = true;
						}
					}
					if(anyFound==false) {
						cout<<"no active booking found against your name"<<endl;
					} else {
						cout<<"ENTER booking number to cancle (0 to go back) : ";
						cin>>cancleNum;
						if(cancleNum==0) {
							// go back
						} else if(cancleNum<1 || cancleNum>totalBookings) {
							cout<<"invalid booking number"<<endl;
						} else {
							idx = cancleNum - 1;
							if(bookedByArray[idx]!=searchName) {
								cout<<"this booking does not belong to you"<<endl;
							} else if(bookingStatusArray[idx]=="cancelled") {
								cout<<"this booking is already cancelled"<<endl;
							} else {
								bookingStatusArray[idx] = "cancelled";
								for(i=0; i<totalTrains; i++) {
									if(trainArray[i]==bookedTrainArray[idx]) {
										seatsArray[i]++;
										break;
									}
								}
								cout<<"your booking cancelled successfully"<<endl;
								cout<<"refund amount : "<<bookedFareArray[idx]<<endl;
							}
						}
					}
					cout<<"--------------------------------------------"<<endl;

					cout<<endl<<"press ENTER key to continue..";
					cin.ignore();
					cin.get();

				} else if(psngrOption=="5") {
					break;
				} else {
					cout<<"invalid option "<<endl;
					cout<<"press ENTER key to continue....";
					cin.ignore();
					cin.get();
				}

			}

		} else if(useroption=="3") {
			//exit
			cout<<"you exited successfully";
			break;
		} else {
			cout<<" you enter wrong option"<<endl;
			cout<<endl<<"press ENTER  key to continue....";
			cin.ignore();
			cin.get();
		}
	}
	return 0;
}
