#include<iostream>
using namespace std;
int main()
{
    int choice;
    string book;
    
    while(true){
    cout<<"--- Library System ---"<<endl;
    cout<<"1. Add Book"<<endl;
    cout<<"2. View Book"<<endl;
     cout<<"3. Borrow Book"<<endl;
     cout<<"4. Issue Book "<<endl;
     cout<<"5. Exit"<<endl;
     cout<<"enter your choice(1-5)"<<endl;
    cin>>choice;
    
    if(choice==1){
         cout<<"enter book name"<<endl;
         cin>>book;
          cout<<"you added a book : "<<book<<endl;
    }
   else if(choice==2){
         cout<<"enter book name"<<endl;
         cin>>book;
          cout<<"you View a book : "<<book<<endl;
    }
    else if(choice==3){
         cout<<"enter book name"<<endl;
         cin>>book;
          cout<<"you Borrow a book : "<<book<<endl;
    }
  else  if(choice==4){
         cout<<"enter book name"<<endl;
         cin>>book;
          cout<<"you Issue a book : "<<book<<endl;
    } 
    else {
        cout<<"existing Library System goodbye!"<<endl;
        break; }
        
    }
    
    return 0;
}
