#include<iostream>

using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination){
    if(n == 0){
        return;
    }
    towerOfHanoi(n-1,source,auxiliary,destination);
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<destination<<endl;
    towerOfHanoi(n-1,auxiliary,destination,source);
}

int main(){
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    towerOfHanoi(n, 'a', 'b', 'c');
    return 0;
}
