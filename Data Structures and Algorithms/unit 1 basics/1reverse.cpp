#include<iostream>

using namespace std;

int main(){
    int num,revNum=0,lastDigit;
    cout<<"Enter a number to reverse: ";
    cin>>num;
    while(num!=0){
        lastDigit = num %10;
        revNum = revNum*10 + lastDigit;
        num = num/10;
    }
    cout<<"The reverse is: "<<revNum<<endl;
    return 0;
}