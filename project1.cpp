#include<iostream>
#include<fstream>
using namespace std;

const string TRAINS_FILE     = "trains.txt";
const string PASSENGERS_FILE = "passengers.txt";
const string BOOKINGS_FILE   = "bookings.txt";

string trainArray[10];
string fromCityArray[10];
string toCityArray[10];
string departureArray[10];
int    fareArray[10];
int    seatsArray[10];
int    totalTrains = 0;

string nameArray[100];
int    ageArray[100];
string psngrPassArray[100];
int    totalPassengers = 0;

string bookedByArray[100];
string bookedTrainArray[100];
int    bookedFareArray[100];
string bookingStatusArray[100];
int    totalBookings = 0;

string regNameArray[100];
string regPassArray[100];
int    totalRegPassengers = 0;

void saveTrains() {
    fstream file(TRAINS_FILE, ios::out);
    for (int i = 0; i < totalTrains; i++) {
        file << trainArray[i]     << "\n"
             << fromCityArray[i]  << "\n"
             << toCityArray[i]    << "\n"
             << departureArray[i] << "\n"
             << fareArray[i]      << "\n"
             << seatsArray[i]     << "\n";
    }
    file.close();
}

void savePassengers() {
    fstream file(PASSENGERS_FILE, ios::out);
    for (int i = 0; i < totalPassengers; i++) {
        file << nameArray[i]      << "\n"
             << ageArray[i]       << "\n"
             << psngrPassArray[i] << "\n";
    }
    file.close();
}

void saveBookings() {
    fstream file(BOOKINGS_FILE, ios::out);
    for (int i = 0; i < totalBookings; i++) {
        file << bookedByArray[i]      << "\n"
             << bookedTrainArray[i]   << "\n"
             << bookedFareArray[i]    << "\n"
             << bookingStatusArray[i] << "\n";
    }
    file.close();
}

void saveRegPassengers() {
    fstream file("regpassengers.txt", ios::out);
    for (int i = 0; i < totalRegPassengers; i++) {
        file << regNameArray[i] << "\n"
             << regPassArray[i] << "\n";
    }
    file.close();
}

void saveAllData() {
    saveTrains();
    savePassengers();
    saveBookings();
    saveRegPassengers();
}

void loadTrains() {
    fstream file(TRAINS_FILE, ios::in);
    if (!file) {
        trainArray[0]="green line";   fromCityArray[0]="lahore";  toCityArray[0]="karachi"; departureArray[0]="06:00"; fareArray[0]=2500; seatsArray[0]=98;
        trainArray[1]="pink line";    fromCityArray[1]="liya";    toCityArray[1]="quetta";  departureArray[1]="12:00"; fareArray[1]=2000; seatsArray[1]=88;
        trainArray[2]="khyber mail";  fromCityArray[2]="pindi";   toCityArray[2]="lahore";  departureArray[2]="18:00"; fareArray[2]=1000; seatsArray[2]=114;
        trainArray[3]="pak business"; fromCityArray[3]="sialkot"; toCityArray[3]="karachi"; departureArray[3]="24:00"; fareArray[3]=4500; seatsArray[3]=48;
        totalTrains = 4;
        saveTrains();
        return;
    }
    totalTrains = 0;
    string fareLine, seatsLine;
    while (getline(file, trainArray[totalTrains])) {
        getline(file, fromCityArray[totalTrains]);
        getline(file, toCityArray[totalTrains]);
        getline(file, departureArray[totalTrains]);
        getline(file, fareLine);
        getline(file, seatsLine);
        fareArray[totalTrains]  = atoi(fareLine.c_str());
        seatsArray[totalTrains] = atoi(seatsLine.c_str());
        totalTrains++;
    }
    file.close();
}

void loadPassengers() {
    fstream file(PASSENGERS_FILE, ios::in);
    if (!file) {
        nameArray[0]="ali";    ageArray[0]=25; psngrPassArray[0]="ali123";
        nameArray[1]="sara";   ageArray[1]=32; psngrPassArray[1]="sara456";
        nameArray[2]="ahmad";  ageArray[2]=19; psngrPassArray[2]="ahmed789";
        nameArray[3]="fatima"; ageArray[3]=27; psngrPassArray[3]="fatima321";
        nameArray[4]="usman";  ageArray[4]=35; psngrPassArray[4]="usman654";
        nameArray[5]="akbar";  ageArray[5]=21; psngrPassArray[5]="akbar555";
        nameArray[6]="maya";   ageArray[6]=35; psngrPassArray[6]="maya125";
        nameArray[7]="tokyo";  ageArray[7]=23; psngrPassArray[7]="tokyo999";
        totalPassengers = 8;
        savePassengers();
        return;
    }
    totalPassengers = 0;
    string ageLine;
    while (getline(file, nameArray[totalPassengers])) {
        getline(file, ageLine);
        getline(file, psngrPassArray[totalPassengers]);
        ageArray[totalPassengers] = atoi(ageLine.c_str());
        totalPassengers++;
    }
    file.close();
}

void loadBookings() {
    fstream file(BOOKINGS_FILE, ios::in);
    if (!file) {
        bookedByArray[0]="ali";    bookedTrainArray[0]="green line";   bookedFareArray[0]=2500; bookingStatusArray[0]="active";
        bookedByArray[1]="sara";   bookedTrainArray[1]="pink line";    bookedFareArray[1]=2000; bookingStatusArray[1]="active";
        bookedByArray[2]="ahmed";  bookedTrainArray[2]="green line";   bookedFareArray[2]=2500; bookingStatusArray[2]="active";
        bookedByArray[3]="fatima"; bookedTrainArray[3]="khyber mail";  bookedFareArray[3]=1000; bookingStatusArray[3]="active";
        bookedByArray[4]="ali";    bookedTrainArray[4]="khyber mail";  bookedFareArray[4]=1000; bookingStatusArray[4]="cancelled";
        bookedByArray[5]="usman";  bookedTrainArray[5]="pink line";    bookedFareArray[5]=2000; bookingStatusArray[5]="active";
        bookedByArray[6]="akbar";  bookedTrainArray[6]="pak business"; bookedFareArray[6]=4500; bookingStatusArray[6]="active";
        bookedByArray[7]="maya";   bookedTrainArray[7]="pink line";    bookedFareArray[7]=2000; bookingStatusArray[7]="active";
        bookedByArray[8]="tokyo";  bookedTrainArray[8]="pak business"; bookedFareArray[8]=4500; bookingStatusArray[8]="active";
        totalBookings = 9;
        saveBookings();
        return;
    }
    totalBookings = 0;
    string fareLine;
    while (getline(file, bookedByArray[totalBookings])) {
        getline(file, bookedTrainArray[totalBookings]);
        getline(file, fareLine);
        getline(file, bookingStatusArray[totalBookings]);
        bookedFareArray[totalBookings] = atoi(fareLine.c_str());
        totalBookings++;
    }
    file.close();
}

void loadRegPassengers() {
    fstream file("regpassengers.txt", ios::in);
    if (!file) {
        regNameArray[0]="ali";    regPassArray[0]="ali123";
        regNameArray[1]="sara";   regPassArray[1]="sara456";
        regNameArray[2]="ahmed";  regPassArray[2]="ahmed789";
        regNameArray[3]="fatima"; regPassArray[3]="fatima321";
        regNameArray[4]="usman";  regPassArray[4]="usman654";
        regNameArray[5]="akbar";  regPassArray[5]="akbar555";
        regNameArray[6]="maya";   regPassArray[6]="maya125";
        regNameArray[7]="tokyo";  regPassArray[7]="tokyo999";
        totalRegPassengers = 8;
        saveRegPassengers();
        return;
    }
    totalRegPassengers = 0;
    while (getline(file, regNameArray[totalRegPassengers])) {
        getline(file, regPassArray[totalRegPassengers]);
        totalRegPassengers++;
    }
    file.close();
}

void loadAllData() {
    loadTrains();
    loadPassengers();
    loadBookings();
    loadRegPassengers();
}

bool verifyPassenger(string name, string password) {
    for (int i = 0; i < totalRegPassengers; i++) {
        if (regNameArray[i] == name && regPassArray[i] == password) {
            return true;
        }
    }
    return false;
}

void clearScreen()          { system("clear"); }
void pressEnterToContinue() {
    cout << endl << "press ENTER key to continue..";
    cin.ignore();
    cin.get();
}

void printTrainTableHeader() {
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "Train\t\t\tFrom\t\tTo\t\tDeparture\tFare\tSeats" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
}

void printTrainRow(int index) {
    cout << trainArray[index]     << "\t\t"
         << fromCityArray[index]  << "\t\t"
         << toCityArray[index]    << "\t\t"
         << departureArray[index] << "\t\t"
         << fareArray[index]      << "\t"
         << seatsArray[index]     << endl;
}

int findTrainIndex(string name) {
    for (int i = 0; i < totalTrains; i++)
        if (trainArray[i] == name) return i;
    return -1;
}

void cancelBookingByIndex(int idx) {
    if (bookingStatusArray[idx] == "cancelled") {
        cout << "this booking is already cancelled" << endl;
        return;
    }
    bookingStatusArray[idx] = "cancelled";
    int trainIdx = findTrainIndex(bookedTrainArray[idx]);
    if (trainIdx != -1) seatsArray[trainIdx]++;
    saveAllData();
    cout << "booking " << (idx+1) << " cancelled successfully" << endl;
    cout << "refund amount : " << bookedFareArray[idx] << endl;
}

void printAllBookings() {
    if (totalBookings == 0) { cout << "no bookings found" << endl; return; }
    cout << "No.\tPassenger\tTrain\t\tFare\tStatus" << endl;
    cout << "------------------------------------------------------" << endl;
    for (int i = 0; i < totalBookings; i++) {
        cout << (i+1)                 << "\t"
             << bookedByArray[i]      << "\t\t"
             << bookedTrainArray[i]   << "\t"
             << bookedFareArray[i]    << "\t"
             << bookingStatusArray[i] << endl;
    }
}

void adminSearchTrain() {
    string trainName;
    cout << "ENTER train name to search : ";
    cin.ignore();
    getline(cin, trainName);
    int idx = findTrainIndex(trainName);
    if (idx != -1){ 
        printTrainTableHeader();
        printTrainRow(idx);
        }else cout << "record not found" << endl;
        pressEnterToContinue();
}

void adminAddTrain() {
    if (totalTrains >= 10) {
        cout << "train list is full" << endl;
        pressEnterToContinue();
        return;
    }
    cout << "---Add new train---" << endl;
    cout << "ENTER train name     : ";
    cin.ignore();
    getline(cin, trainArray[totalTrains]);
    cout << "ENTER city from      : "; 
    cin >> fromCityArray[totalTrains];
    cout << "ENTER city to        : ";
    cin >> toCityArray[totalTrains];
    cout << "ENTER departure time (HH:MM)  : ";
    cin >> departureArray[totalTrains];
    cout << "ENTER fare           : ";
    cin >> fareArray[totalTrains];
    cout << "ENTER total seats    : "; 
    cin >> seatsArray[totalTrains];
    cout << "Train added successfully!" << endl;
    printTrainTableHeader();
    printTrainRow(totalTrains);
    totalTrains++;
    saveTrains();
    pressEnterToContinue();
}

void adminTotalRevenue() {
    cout << "\n--------------------------------------------" << endl;
    cout << "            Total Revenue Report            " << endl;
    cout << "--------------------------------------------" << endl;
    int totalRevenue = 0;
    for (int i = 0; i < totalTrains; i++) {
        int trainRevenue = 0, trainBookings = 0;
        for (int j = 0; j < totalBookings; j++) {
            if (bookedTrainArray[j]==trainArray[i] && bookingStatusArray[j]=="active") {
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

void adminViewAllBookings() {
    cout << "\n------------------------------------------------------" << endl;
    cout << "                       All Bookings                     " << endl;
    cout << "--------------------------------------------------------" << endl;
    printAllBookings();
    cout << "--------------------------------------------------------" << endl;
    pressEnterToContinue();
}

void adminCancelBooking() {
    if (totalBookings == 0) { cout << "no bookings found" << endl;
    pressEnterToContinue();
    return; }
    printAllBookings();
    cout << "ENTER booking number to cancel (0 to go back) : ";
    int num; cin >> num;
    if      (num == 0) {}
    else if (num < 1 || num > totalBookings) cout << "invalid number" << endl;
    else cancelBookingByIndex(num - 1);
    pressEnterToContinue();
}

void adminOccupancyReport() {
    clearScreen();
    cout << "\n--------------------------------------------" << endl;
    cout << "          Train Occupancy Report            " << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < totalTrains; i++) {
        int active = 0;
        for (int j = 0; j < totalBookings; j++)
            if (bookedTrainArray[j]==trainArray[i] && bookingStatusArray[j]=="active") active++;
        int total = seatsArray[i] + active;
        int pct   = (total > 0) ? (active * 100) / total : 0;
        cout << "\nTrain  : " << trainArray[i] << endl;
        cout << "Booked : " << active << " / " << total
             << "  (" << pct << "% full)  Available : " << seatsArray[i] << endl;
        int filled = pct / 5;
        cout << "[";
        for (int b = 0; b < 20; b++) cout << (b < filled ? '#' : '-');
        cout << "]" << endl;
    }
    cout << "--------------------------------------------" << endl;
    pressEnterToContinue();
}

bool adminLogin() {
    string username; int password;
    for (int i = 3; i > 0; i--) {
        cout << "                                                   attempts left : " << i << endl;
        cout << "ENTER username : "; cin >> username;
        cout << "ENTER password : "; cin >> password;
        if (username == "admin" && password == 123) return true;
        cout << (i == 1 ? "invalid username & password" : "invalid, try again") << endl << endl;
    }
    return false;
}

void passengerViewAllTrains() {
    printTrainTableHeader();
    for (int i = 0; i < totalTrains; i++) printTrainRow(i);
    pressEnterToContinue();
}

void passengerBookTicket() {
    string psngrName, psngrPswrd, cnfrmPswrd, bookTicketName, cnfrmBooking;
    int age;
    while (true) {
        cout << "-------------\n----login----\n";
        cout << "ENTER your name  : "; 
        cin.ignore(); getline(cin, psngrName);
        cout << "Create password  : ";
        cin >> psngrPswrd;
        cout << "Confirm password : ";
        cin >> cnfrmPswrd;
        if (psngrPswrd != cnfrmPswrd) {
            cout << "passwords do not match, try again" << endl;
            continue; }
        cout << "ENTER your age   : ";
        cin >> age;

        cout << "\navailable trains :" << endl;
        printTrainTableHeader();
        for (int i = 0; i < totalTrains; i++) printTrainRow(i);

        cout << "ENTER train name for booking : ";
        cin.ignore(); getline(cin, bookTicketName);
        int idx = findTrainIndex(bookTicketName);
        if (idx == -1) { cout << "train not found" << endl;
        pressEnterToContinue(); 
        break; }

        if (seatsArray[idx] <= 0) {
            cout << "sorry, no seats available" << endl;
        } else {
            cout << "\nBooking summary :\n";
            cout << "Train : " << trainArray[idx]     << endl;
            cout << "From  : " << fromCityArray[idx]  << "   to : " << toCityArray[idx] << endl;
            cout << "Time  : " << departureArray[idx] << endl;
            cout << "Fare  : " << fareArray[idx]      << endl;
            cout << "\nConfirm booking (1=yes / 0=no) : ";
            cin >> cnfrmBooking;

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

                regNameArray[totalRegPassengers] = psngrName;
                regPassArray[totalRegPassengers] = psngrPswrd;
                totalRegPassengers++;

                saveAllData();
                cout << "booking confirmed! your booking number is : " << totalBookings << endl;
            } else {
                cout << "booking cancelled" << endl;
            }
        }
        break;
    }
    pressEnterToContinue();
}

void passengerViewTicket() {
    string searchName, searchPass;
    cout << "--------------------------------------------\n";
    cout << "            View my ticket                  \n";
    cout << "--------------------------------------------\n";
    cout << "ENTER your name : "; 
    cin.ignore();
    getline(cin, searchName);
    cout << "ENTER your password : ";
    cin >> searchPass;
    if (!verifyPassenger(searchName, searchPass)) {
        cout << "wrong name or password  access denied" << endl;
        cout << "--------------------------------------------\n";
        pressEnterToContinue();
        return;
    }
    bool found = false;
    for (int i = 0; i < totalBookings; i++) {
        if (bookedByArray[i] == searchName) {
            cout << "--------------------------------------------\n";
            cout << "Booking No. : " << (i+1)               << endl;
            cout << "Passenger   : " << bookedByArray[i]    << endl;
            cout << "Train       : " << bookedTrainArray[i] << endl;
            cout << "Fare        : " << bookedFareArray[i]  << endl;
            cout << "Status      : " << bookingStatusArray[i] << endl;
            found = true;
        }
    }
    if (!found) cout << "no booking found against your name" << endl;
    cout << "--------------------------------------------\n";
    pressEnterToContinue();
}

void passengerCancelTicket() {
    string searchName, searchPass;
    cout << "--------------------------------------------\n";
    cout << "            Cancel my ticket                \n";
    cout << "--------------------------------------------\n";
    cout << "ENTER your name : ";
    cin.ignore(); 
    getline(cin, searchName);
    cout << "ENTER your password : ";
    cin >> searchPass;
    if (!verifyPassenger(searchName, searchPass)) {
        cout << "wrong name or password  access denied" << endl;
        cout << "--------------------------------------------\n";
        pressEnterToContinue();
        return;
    }
    bool found = false;
    for (int i = 0; i < totalBookings; i++) {
        if (bookedByArray[i]==searchName && bookingStatusArray[i]=="active") {
            cout << "Booking No. : " << (i+1)
                 << "  Train : " << bookedTrainArray[i]
                 << "  Fare : "  << bookedFareArray[i]
                 << "  Status : "<< bookingStatusArray[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "no active booking found" << endl;
    } else {
        int num;
        cout << "ENTER booking number to cancel (0 to go back) : ";
        cin >> num;
        if      (num == 0) {}
        else if (num < 1 || num > totalBookings) cout << "invalid number" << endl;
        else {
            int idx = num - 1;
            if (bookedByArray[idx] != searchName) cout << "this booking does not belong to you" << endl;
            else cancelBookingByIndex(idx);
        }
    }
    cout << "--------------------------------------------\n";
    pressEnterToContinue();
}

void adminMenu() {
    string opt;
    while (true) {
        clearScreen();
        cout << "\nwelcome to admin menu\n------------------------------------\n";
        cout << "1. View all trains\n2. Search train\n3. Add new train\n4. Check total revenue\n";
        cout << "5. View all bookings\n6. Cancel a booking\n7. Train occupancy report\n8. Logout\n";
        cout << "choose an option : ";
        cin >> opt;
        if      (opt=="1") passengerViewAllTrains();
        else if (opt=="2") adminSearchTrain();
        else if (opt=="3") adminAddTrain();
        else if (opt=="4") adminTotalRevenue();
        else if (opt=="5") adminViewAllBookings();
        else if (opt=="6") adminCancelBooking();
        else if (opt=="7") adminOccupancyReport();
        else if (opt=="8") { cout << "admin logged out" << endl;
        break;
        }else{
        cout << "invalid option" << endl;
        pressEnterToContinue();
        }
    }
}

void adminPortal() {
    clearScreen();
    cout << "\n--------------------\n----Admin Portal----\n--------------------\n\n";
    if (adminLogin()) adminMenu();
    pressEnterToContinue();
}

void passengerPortal() {
    string opt;
    while (true) {
        clearScreen();
        cout << "\n------------------------\n----Passenger Menu------\n------------------------\n\n";
        cout << "1. View all trains\n2. Book ticket\n3. View my ticket\n4. Cancel my ticket\n5. Exit\n";
        cout << "Choose an option : "; cin >> opt;
        if      (opt=="1") passengerViewAllTrains();
        else if (opt=="2") passengerBookTicket();
        else if (opt=="3") passengerViewTicket();
        else if (opt=="4") passengerCancelTicket();
        else if (opt=="5") break;
        else { cout << "invalid option" << endl; 
        pressEnterToContinue();
        }
    }
}

int main() {
    loadAllData();
    string opt;
    while (true) {
        clearScreen();
        cout << "\n!!-=-=-=-=-=-=--=-=-=-=-=-=-=-=--=-=-=-=-=-=!!"    << endl;
        cout <<   "     welcome to train reservation system     " << endl;
        cout <<   "!!-=-=-=-=-=-=--=-=-=-=-=-=-=-=--=-=-=-=-=-=!!\n\n";
        cout << "1. Admin\n2. Passenger\n3. Exit\n";
        cout << "choose your option : "; 
        cin >> opt;
        if      (opt=="1") adminPortal();
        else if (opt=="2") passengerPortal();
        else if (opt=="3") {
        cout << "exited successfully" << endl; 
        break;
        }
        else{
        cout << "wrong option" << endl;
        pressEnterToContinue();
        }
    }
    return 0;
}