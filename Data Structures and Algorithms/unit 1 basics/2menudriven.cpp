// wap 1. entry at the beginning of the array 2. entry at the specifiec position 3. entry at the end of the array 4. display the result
#include<iostream>

using namespace std;

int main(){
    int elem,menu,position,num=0,numArray[100];
    char choice;
    do{
        cout<<"\nMenu driven program for:\n"
            "1. Entry at the beginning of the array\n"
            "2. Entry at the specific position in array\n"
            "3. Entry at the end of the array \n"
            "4. Display the result\n";
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice=='4'){
            goto skip;
        }
        else{
            //taking the number of entries in the array 
            cout<<"Enter the number of elements in the array: ";
            cin>>num;
            //taking the initial array
            cout<<"Enter the elements of the array: ";
            for(int i=0; i<num; i++){
                cin>> numArray[i];
            }
            //displaying initial array
            cout<<"The array is:"<<endl;
            for(int i=0; i<num; i++){
                cout<<numArray[i]<<"\t";
            }
        }
        skip:switch(choice){
            case '1': 
                cout<<"\nThis is menu for inserting at new beginning of array \n";
                cout<<"Enter number to insert: ";
                cin>>elem;
                for(int i=num; i>0; i--){
                    numArray[i] = numArray[i-1];
                }
                numArray[0] = elem;
                break;
            case '2':
                int position;
                cout<<"\nThis is menu for inserting at certain position in array \n";
                cout<<"\nEnter number to insert: ";
                cin>>elem;
                cout<<"\nEnter position to insert: ";
                cin>>position;
                for(int i=num-1; i>=position-1; i--){
                    numArray[i+1]=numArray[i];
                }
                numArray[position-1]=elem;
                break;
            case '3':
                cout<<"\nthis is meny for inserting at end of the array: \n";
                cout<<"Enter number to insert: ";
                cin>>elem;
                for(int i=num; i>=0;i--){
                    numArray[i]=numArray[i-1];
                }
                numArray[num]=elem;
                break;
            case '4':
                if(num==0){
                    cout<<"Empty array. Enter array first\n";
                    break;
                }
                cout<<"\nThis is for displaying the previous calculations: \n";
                for(int i=0; i<num+1; i++){
                    cout<<numArray[i]<<"\t";
                }
                break;
            
            default:    
                cout<<"\nEnter valid number(1,2,3,4): ";
        }
    cout<<"\nEnter choice(y:to continue/n:exit program):\n";
    cin>>choice;
    }while(choice=='y');
}