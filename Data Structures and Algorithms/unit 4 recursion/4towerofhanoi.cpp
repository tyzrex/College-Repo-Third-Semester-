// tower of hanoi using recursion with count of steps

#include <iostream>

using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int &count)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
        count++;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, count);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    count++;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, count);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    int count = 0;
    towerOfHanoi(n, 'A', 'C', 'B', count);
    cout << "Total number of steps: " << count << endl;
    return 0;
}
