/* Write a menu driven program to do the following task:
 * - Press 1 for insert at the beginning of the array.
 * - Press 2 for insert at the specific position.
 * - Press 3 for insert at the end.
 * - Press 4 for displaying the array.
 *
 * Repeating till the user says to end the program.
 */
#include<iostream>

using namespace std;

void take_initial_array(int *numArray,int num_array_count);
void display_initial_array(int *numArray,int num_array_count);
void insert_array_beginning(int *numArray, int num_array_count, int elem_to_insert);
void insert_array_positions(int *numArray, int num_array_count, int elem_to_insert,int position);
void insert_array_end(int *numArray, int num_array_count, int elem_to_insert);

int main(){
    int elem_to_insert,menu,position,num_array_count=0,numArray[100],user_choice;
    char choice;
    cout<<"Enter the number of elements in the array: ";
    cin>>num_array_count;
    take_initial_array(numArray,num_array_count);
    display_initial_array(numArray,num_array_count);

    do{
        cout<<"\nMenu driven program for:\n"
            "1. Entry at the beginning of the array\n"
            "2. Entry at the specific position in array\n"
            "3. Entry at the end of the array \n"
            "4. Display the array\n"
            "5. Initialize new array\n"
            "6. Delete from the beginning of the array\n"
            "7. Delete from the specific position in array\n"
            "8. Delete from the end of the array\n";
        cout<<"\nEnter choice: ";
        cin>>user_choice;
        switch(user_choice){
            case 1: 
                cout<<"\nThis is menu for inserting at new beginning of array \n";

                cout<<"\nEnter number to insert: ";
                cin>>elem_to_insert;
                insert_array_beginning(numArray,num_array_count,elem_to_insert);
                num_array_count++;
                break;
            case 2:
                int position;
                cout<<"\nThis is menu for inserting at certain position in array \n";
                cout<<"\nEnter number to insert: ";
                cin>>elem_to_insert;
                cout<<"\nEnter position to insert: ";
                cin>>position;
                insert_array_positions(numArray,num_array_count,elem_to_insert,position);
                num_array_count++;
                break;
            case 3:
                cout<<"\nthis is meny for inserting at end of the array: \n";
                cout<<"\nEnter number to insert: ";
                cin>>elem_to_insert;
                insert_array_end(numArray,num_array_count,elem_to_insert);
                num_array_count++;
                break;
            case 4:
                if(num_array_count == 0){
                    cout<<"Array is empty enter array first\n";
                    break;
                }
                cout<<"\nThis is for displaying the array: \n";
                for(int i=0; i<num_array_count;i++){
                    cout<<numArray[i]<<"\t";
                }
                break;
            case 5:
                cout<<"Enter the number of elements in the array: ";
                cin>>num_array_count;
                take_initial_array(numArray,num_array_count);
                display_initial_array(numArray,num_array_count);

            case 6:
                cout<<"\nThis is menu for deleting from the beginning of array \n";
                remove_array_beginning(numArray,num_array_count);
                num_array_count--;
                break;


            case 7:
                int position;
                cout<<"\nThis is menu for deleting from certain position in array \n";
                cout<<"\nEnter position to delete: ";
                cin>>position;
                remove_array_positions(numArray,num_array_count,position);
                num_array_count--;
                break;

            case 8:
                cout<<"\nthis is meny for deleting from end of the array: \n";
                remove_array_end(numArray,num_array_count);
                num_array_count--;
                break;

            default:    
                cout<<"\nEnter valid number(1,2,3,4): \n";
        }
    cout<<"\nEnter choice(y:to continue/n:exit program):\n";
    cin>>choice;
    }while(choice=='y');
    return 0;
}


void take_initial_array(int *numArray,int num_array_count){
    cout<<"Enter elements of the array: ";
    for(int i = 0; i < num_array_count; i++){
        cin>> numArray[i];
    }
}
void display_initial_array(int *numArray,int num_array_count){
    cout<<"The entered array is: \n";
    for(int i = 0; i < num_array_count; i++){
        cout<< numArray[i]<<"\t";
    }
}
void insert_array_beginning(int *numArray, int num_array_count, int elem_to_insert){
    for (int i = num_array_count; i > 0; i--) {
		numArray[i] = numArray[i - 1];
	}
	numArray[0] = elem_to_insert;
}

void insert_array_positions(int *numArray, int num_array_count, int elem_to_insert,int position){
    for(int i=num_array_count-1; i>=position-1; i--){
        numArray[i+1]=numArray[i];
    }
    numArray[position-1]=elem_to_insert;
}

void insert_array_end(int *numArray, int num_array_count, int elem_to_insert){
    numArray[num_array_count]=elem_to_insert;
}

void remove_array_beginning(int *numArray, int num_array_count){
    for(int i=0; i<num_array_count; i++){
        numArray[i]=numArray[i+1];
    }
}

void remove_array_positions(int *numArray, int num_array_count,int position){
    for(int i=position-1; i<num_array_count; i++){
        numArray[i]=numArray[i+1];
    }
}

void remove_array_end(int *numArray, int num_array_count){
    numArray[num_array_count-1]=0;
}

