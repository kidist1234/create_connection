#include<iostream>
#include <string>
int main(){
  /* int myAge;
    std::string fullName;
    std::string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::cout << "The length of the txt string is: " << txt.length()<<"\n";
    std::cout << "The length of the txt string is: " << txt.size()<<"\n";
    std::cout<<"Hello World1\n";
    std::cout << "I am learning C++\n";
   // std::cin>>myAge;
  //  int myAge=myAge//;
   // std::cout << "I am " << myAge << " years old.";
    std::cout<<"enter you fullname\n";
    //std::cin>>fullName;
    //std::getline(cin, fullname);
   // getline (cin, fullName);
    std::getline (std::cin, fullName);
    std::cout<<fullName;
    */
   int num;
   std::cout<<"enter a number";
   std::cin>>num;
   for(int i = 1; i<=10;i++)
   {
    std::cout<<num <<"*" <<i<<"= "<<num*i<<"\n";
   }
    return 0;
}