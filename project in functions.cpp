#include<iostream>
using namespace std;

// Train data
string trainArray[10]     = {"green line", "pink line", "teizgum"};
string fromCityArray[10]  = {"lahore",  "liya", "pindi"};
string toCityArray[10]    = {"karachi", "quetta", "lahore"};
string departureArray[10] = {"06:00",  "12:00", "18:00"};
int    fareArray[10]      = {2500, 2000, 1000};
int    seatsArray[10]     = {98,   88,   114};
int    totalTrains        = 3;

// Passenger data
string nameArray[100]      = {"ali",   "sara",      "ahmad",    "fatima",    "usman"};
int    ageArray[100]       = {25,       32,           19,          27,          35};
string psngrPassArray[100] = {"ali123", "sara456",   "ahmed789", "fatima321", "usman654"};
int    totalPassengers     = 5;

// Booking data
string bookedByArray[100]      = {"ali",  "sara",      "ahmed",     "fatima",   "ali",     "usman"};
string bookedTrainArray[100]   = {"green line","pink line","green line","teizgum","teizgum","pink line"};
int    bookedFareArray[100]    = {2500, 2000, 2500, 1000, 1000, 2000};
string bookingStatusArray[100] = {"active","active","active","active","cancelled","active"};
int    totalBookings           = 6;

void clearScreen() {
    system("clear");
}

void pressEnterToContinue() {
    cout << endl << "press ENTER key to continue..";
    cin.ignore();
    cin.get();
}

void printTrainTableHeader() {
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "Train\t\tFrom\t\tTo\t\tDeparture\t\tFare\t\tSeats" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;
}

void printTrainRow(int index) {
    cout << trainArray[index]     << "\t\t"
         << fromCityArray[index]  << "\t\t"
         << toCityArray[index]    << "\t\t"
         << departureArray[index] << "\t\t"
         << fareArray[index]      << "\t\t"
         << seatsArray[index]     << endl;
}

// Returns index of train by name, -1 if not found
int findTrainIndex(string name) {
    for (int i = 0; i < totalTrains; i++) {
        if (trainArray[i] == name) return i;
    }
    return -1;
}

void adminSearchTrain() {
    string trainName;
    cout << "ENTER train name to Search : ";
    cin.ignore();
    getline(cin, trainName);

    int idx = findTrainIndex(trainName);
    if (idx != -1) {
        printTrainTableHeader();
        printTrainRow(idx);
    } else {
        cout << "record against name not found" << endl;
    }
    pressEnterToContinue();
}

void adminAddTrain() {
    if (totalTrains >= 10) {
        cout << "train list is full, cannot add more trains" << endl;
        pressEnterToContinue();
        return;
    }

    string newTrainName, newFromCity, newToCity, newDepartureTime;
    int    newFare, newTotalSeats;

    cout << "---Add new train---" << endl;
    cout << "ENTER train name : ";
    cin.ignore();
    getline(cin, newTrainName);
    cout << "ENTER city it departs from : ";
    cin >> newFromCity;
    cout << "ENTER city it arrives to   : ";
    cin >> newToCity;
    cout << "ENTER departure time       : ";
    cin >> newDepartureTime;
    cout << "ENTER fare                 : ";
    cin >> newFare;
    cout << "ENTER total seats          : ";
    cin >> newTotalSeats;

    trainArray[totalTrains]     = newTrainName;
    fromCityArray[totalTrains]  = newFromCity;
    toCityArray[totalTrains]    = newToCity;
    departureArray[totalTrains] = newDepartureTime;
    fareArray[totalTrains]      = newFare;
    seatsArray[totalTrains]     = newTotalSeats;

    cout << "Train added successfully!" << endl;
    printTrainTableHeader();
    printTrainRow(totalTrains);

    totalTrains++;
    pressEnterToContinue();
}

void adminTotalRevenue() {
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "            Total Revenue Report            " << endl;
    cout << "--------------------------------------------" << endl;

    int totalRevenue = 0;
    for (int i = 0; i < totalTrains; i++) {
        int trainRevenue  = 0;
        int trainBookings = 0;
        for (int j = 0; j < totalBookings; j++) {
            if (bookedTrainArray[j] == trainArray[i] && bookingStatusArray[j] == "active") {
                trainRevenue  += bookedFareArray[j];
                trainBookings++;
            }
        }
        cout << "Train : " << trainArray[i]
             << "\tBookings : " << trainBookings
             << "\tRevenue : "  << trainRevenue << endl;
        totalRevenue += trainRevenue;
    }
    cout << "--------------------------------------------" << endl;
    cout << "TOTAL REVENUE : " << totalRevenue << endl;
    cout << "--------------------------------------------" << endl;
    pressEnterToContinue();
}

void printAllBookings() {
    if (totalBookings == 0) {
        cout << "no bookings found" << endl;
        return;
    }
    cout << "No.\tPassenger\tTrain\t\tFare\tStatus" << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < totalBookings; i++) {
        cout << (i + 1)             << "\t"
             << bookedByArray[i]    << "\t\t"
             << bookedTrainArray[i] << "\t"
             << bookedFareArray[i]  << "\t"
             << bookingStatusArray[i] << endl;
    }
}

void adminViewAllBookings() {
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "               All Bookings                 " << endl;
    cout << "--------------------------------------------" << endl;
    printAllBookings();
    cout << "--------------------------------------------" << endl;
    pressEnterToContinue();
}

void cancelBookingByIndex(int idx) {
    if (bookingStatusArray[idx] == "cancelled") {
        cout << "this booking is already cancelled" << endl;
        return;
    }
    bookingStatusArray[idx] = "cancelled";
    int trainIdx = findTrainIndex(bookedTrainArray[idx]);
    if (trainIdx != -1) seatsArray[trainIdx]++;
    cout << "booking number " << (idx + 1) << " cancelled successfully" << endl;
    cout << "refund amount  : " << bookedFareArray[idx] << endl;
}

void adminCancelBooking() {
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "             Cancel a Booking               " << endl;
    cout << "--------------------------------------------" << endl;

    if (totalBookings == 0) {
        cout << "no bookings found" << endl;
        pressEnterToContinue();
        return;
    }

    printAllBookings();
    cout << "--------------------------------------------" << endl;
    cout << "ENTER booking number to cancel (0 to go back) : ";
    int cancleNum;
    cin >> cancleNum;

    if (cancleNum == 0) {
        // go back
    } else if (cancleNum < 1 || cancleNum > totalBookings) {
        cout << "invalid booking number" << endl;
    } else {
        cancelBookingByIndex(cancleNum - 1);
    }
    pressEnterToContinue();
}

void adminOccupancyReport() {
    clearScreen();
    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "          Train Occupancy Report            " << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < totalTrains; i++) {
        int activeBookings = 0;
        for (int j = 0; j < totalBookings; j++) {
            if (bookedTrainArray[j] == trainArray[i] && bookingStatusArray[j] == "active") {
                activeBookings++;
            }
        }
        int totalSeats = seatsArray[i] + activeBookings;
        int percentage = (totalSeats > 0) ? (activeBookings * 100) / totalSeats : 0;

        cout << endl;
        cout << "Train  : " << trainArray[i] << endl;
        cout << "Booked : " << activeBookings << " / " << totalSeats
             << "   (" << percentage << "% full)"
             << "   Available : " << seatsArray[i] << endl;

        int filled = percentage / 5;
        cout << "[";
        for (int b = 0; b < 20; b++) cout << (b < filled ? '#' : '-');
        cout << "]" << endl;
    }
    cout << "--------------------------------------------" << endl;
    pressEnterToContinue();
}

bool adminLogin() {
    string username;
    int    password;
    for (int i = 3; i > 0; i--) {
        cout << "                         attempts left : " << i << endl;
        cout << "ENTER username : ";
        cin  >> username;
        cout << "ENTER password : ";
        cin  >> password;

        if (username == "admin" && password == 123) return true;

        if (i == 1) {
            cout << "invalid username & password" << endl;
            pressEnterToContinue();
        } else {
            cout << "invalid username & password   try again" << endl << endl;
        }
    }
    return false;
}

void adminMenu() {
    string adminOption;
    while (true) {
        clearScreen();
        cout << endl;
        cout << "welcome to admin menu" << endl;
        cout << "------------------------------------" << endl << endl;
        cout << "1. Search train"          << endl;
        cout << "2. Add new train"         << endl;
        cout << "3. Check Total revenue"   << endl;
        cout << "4. View all bookings"     << endl;
        cout << "5. Cancel a booking"      << endl;
        cout << "6. Train occupancy report" << endl;
        cout << "7. Logout"                << endl;
        cout << endl << "choose an option : ";
        cin  >> adminOption;

        if      (adminOption == "1") adminSearchTrain();
        else if (adminOption == "2") adminAddTrain();
        else if (adminOption == "3") adminTotalRevenue();
        else if (adminOption == "4") adminViewAllBookings();
        else if (adminOption == "5") adminCancelBooking();
        else if (adminOption == "6") adminOccupancyReport();
        else if (adminOption == "7") { cout << "admin logged out successfully" << endl; break; }
        else {
            cout << "invalid option" << endl;
            pressEnterToContinue();
        }
    }
}

void adminPortal() {
    clearScreen();
    cout << endl;
    cout << "--------------------" << endl;
    cout << "----Admin Portal----" << endl;
    cout << "--------------------" << endl << endl;

    if (adminLogin()) adminMenu();

    pressEnterToContinue();
}


void passengerViewAllTrains() {
    printTrainTableHeader();
    for (int i = 0; i < totalTrains; i++) printTrainRow(i);
    pressEnterToContinue();
}

void passengerBookTicket() {
    string psngrName, psngrPswrd, cnfrmPsngrPswrd, bookTicketName, cnfrmBooking;
    int    age;

    while (true) {
        cout << "-------------" << endl;
        cout << "----login----" << endl;
        cout << "ENTER your name : ";
        cin.ignore();
        getline(cin, psngrName);
        cout << "Create password        : ";
        cin >> psngrPswrd;
        cout << "Confirm password       : ";
        cin >> cnfrmPsngrPswrd;

        if (psngrPswrd != cnfrmPsngrPswrd) {
            cout << "passwords do not match   please try again" << endl;
            continue;
        }

        cout << "ENTER your age : ";
        cin  >> age;

        cout << endl << "available trains :" << endl;
        printTrainTableHeader();
        for (int i = 0; i < totalTrains; i++) printTrainRow(i);

        cout << "ENTER train name for booking : ";
        cin.ignore();
        getline(cin, bookTicketName);

        int idx = findTrainIndex(bookTicketName);
        if (idx == -1) {
            cout << "record of train not found" << endl;
            pressEnterToContinue();
            break;
        }

        if (seatsArray[idx] <= 0) {
            cout << "sorry, no seats available on this train" << endl;
        } else {
            cout << endl << "Booking summary :" << endl;
            cout << "Train : " << trainArray[idx]    << endl;
            cout << "From  : " << fromCityArray[idx] << "   to : " << toCityArray[idx] << endl;
            cout << "Time  : " << departureArray[idx] << endl;
            cout << "Fare  : " << fareArray[idx]      << endl;
            cout << endl << "Do you confirm your booking (1 for yes & 0 for no) : ";
            cin  >> cnfrmBooking;

            if (cnfrmBooking == "1") {
                nameArray[totalPassengers]      = psngrName;
                ageArray[totalPassengers]       = age;
                psngrPassArray[totalPassengers] = psngrPswrd;
                totalPassengers++;

                bookedByArray[totalBookings]      = psngrName;
                bookedTrainArray[totalBookings]   = trainArray[idx];
                bookedFareArray[totalBookings]    = fareArray[idx];
                bookingStatusArray[totalBookings] = "active";
                totalBookings++;

                seatsArray[idx]--;

                cout << "booking confirmed successfully!" << endl;
                cout << "your booking number is : " << totalBookings << endl;
            } else {
                cout << "you cancelled your booking" << endl;
            }
        }
        break;
    }
    pressEnterToContinue();
}

void passengerViewTicket() {
    string searchName;
    cout << "--------------------------------------------" << endl;
    cout << "            View my ticket                  " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "ENTER your name : ";
    cin.ignore();
    getline(cin, searchName);

    bool anyFound = false;
    for (int i = 0; i < totalBookings; i++) {
        if (bookedByArray[i] == searchName) {
            cout << "--------------------------------------------" << endl;
            cout << "Booking No. : " << (i + 1)           << endl;
            cout << "Passenger   : " << bookedByArray[i]  << endl;
            cout << "Train       : " << bookedTrainArray[i] << endl;
            cout << "Fare        : " << bookedFareArray[i] << endl;
            cout << "Status      : " << bookingStatusArray[i] << endl;
            anyFound = true;
        }
    }
    if (!anyFound) cout << "no booking found against your name" << endl;
    cout << "--------------------------------------------" << endl;
    pressEnterToContinue();
}

void passengerCancelTicket() {
    string searchName;
    cout << "--------------------------------------------" << endl;
    cout << "            Cancel my ticket                " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "ENTER your name : ";
    cin.ignore();
    getline(cin, searchName);

    bool anyFound = false;
    for (int i = 0; i < totalBookings; i++) {
        if (bookedByArray[i] == searchName && bookingStatusArray[i] == "active") {
            cout << "Booking No. : " << (i + 1)
                 << "   Train : " << bookedTrainArray[i]
                 << "   Fare : "  << bookedFareArray[i]
                 << "   Status : "<< bookingStatusArray[i] << endl;
            anyFound = true;
        }
    }

    if (!anyFound) {
        cout << "no active booking found against your name" << endl;
    } else {
        int cancleNum;
        cout << "ENTER booking number to cancel (0 to go back) : ";
        cin  >> cancleNum;

        if (cancleNum == 0) {
            // go back
        } else if (cancleNum < 1 || cancleNum > totalBookings) {
            cout << "invalid booking number" << endl;
        } else {
            int idx = cancleNum - 1;
            if (bookedByArray[idx] != searchName) {
                cout << "this booking does not belong to you" << endl;
            } else {
                cancelBookingByIndex(idx);
            }
        }
    }
    cout << "--------------------------------------------" << endl;
    pressEnterToContinue();
}

void passengerPortal() {
    string psngrOption;
    while (true) {
        clearScreen();
        cout << endl;
        cout << "------------------------" << endl;
        cout << "----Passenger Menu------" << endl;
        cout << "------------------------" << endl << endl;
        cout << "1. View all trains"   << endl;
        cout << "2. Book ticket"       << endl;
        cout << "3. View my ticket"    << endl;
        cout << "4. Cancel my ticket"  << endl;
        cout << "5. Exit"              << endl;
        cout << "Choose an option : ";
        cin  >> psngrOption;

        if      (psngrOption == "1") passengerViewAllTrains();
        else if (psngrOption == "2") passengerBookTicket();
        else if (psngrOption == "3") passengerViewTicket();
        else if (psngrOption == "4") passengerCancelTicket();
        else if (psngrOption == "5") break;
        else {
            cout << "invalid option" << endl;
            pressEnterToContinue();
        }
    }
}


void showMainMenu() {
    cout << endl;
    cout << "!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!!" << endl;
    cout << "!!                welcome to train reservation system                     !!" << endl;
    cout << "!!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!!" << endl << endl;
    cout << "1. Admin"     << endl;
    cout << "2. Passenger" << endl;
    cout << "3. Exit"      << endl;
    cout << "choose your option : ";
}

int main() {
    //drivers code
    string useroption;

    while (true) {
        clearScreen();
        showMainMenu();
        cin >> useroption;

        if      (useroption == "1") adminPortal();
        else if (useroption == "2") passengerPortal();
        else if (useroption == "3") { cout << "you exited successfully" << endl; break; }
        else {
            cout << "you entered wrong option" << endl;
            pressEnterToContinue();
        }
    }
    return 0;
}