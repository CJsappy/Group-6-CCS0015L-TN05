/******************************************************************************
    Exercise 1: Array Operations Program Development
        OOP {Classes & Objects}
        
*******************************************************************************/

#include <iostream>
#include <cstdlib> 

using namespace std;

const int max_Size = 20;

void CLS() {
#ifdef _WIN64 // If the user uses Windows Operating System
    system("cls");
#else         // if  the user uses Macintosh OS or Linux
    system("clear");
#endif

}

class fixed_sized_Array {
private:
    int arr[max_Size];
    int count;

public:
    fixed_sized_Array() {
        count = 0;
    }
        void insert(int value, int index) {
        if (count >= max_Size) {
            cout << "\tArray is full. Cannot insert more elements." << endl;
            return;
        }
        if (index < 0 || index > count) {
            cout << "\tInvalid index." << endl;
            return;
        }
        for (int i = count; i > index; --i) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        count++;
    }

    void remove(int index) {
        if (index < 0 || index >= count) {
            cout << "\tInvalid index." << endl;
            return;
        }
        for (int i = index; i < count - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        count--;
    }

    void display() {
        if (count == 0) {
            CLS();
            cout << "\tArray is empty." << endl;
            return;
        }
        CLS();
        cout << "\tArray Content: ";
        for (int i = 0; i < count; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert_Element() {
        int value, index;
        while (true) {
            cout << "\t_______________________________" << endl;
            cout << "\tEnter value to insert: ";
            if (!(cin >> value)) {
                cout << "\t_______________________________" << endl;
                cout << "\tInvalid input! Please enter a number." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue; 
            }
            break; 
        }
        while (true) {
            cout << "\t_______________________________" << endl;
            cout << "\tEnter index to insert: ";
            if (!(cin >> index)) {
                cout << "\t_______________________________" << endl;
                cout << "\tInvalid input! Please enter a number." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue; 
            }
            CLS();
            cout << "\t_______________________________" << endl;
            cout << "\tArray inserted succesfully." << endl;
            break; 
        }
        insert(value, index);
    }

    void delete_Element() {
        int index;
        while (true) {
            cout << "\t_______________________________" << endl;
            cout << "\tEnter index to delete: ";
            if (!(cin >> index)) {
                cout << "\t_______________________________" << endl;
                cout << "\tInvalid input! Please enter a number." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue; 
            }
            CLS();
            cout << "\t_______________________________" << endl;
            cout << "\tElement deleted succesfully." << endl;
            break; 
        }
        remove(index);
    }

    void swap_Element() {
        int index1, index2;
        while (true) {
            cout << "\t_______________________________" << endl;
            cout << "\tEnter first index to swap: ";
            if (!(cin >> index1)) {
                cout << "\t_______________________________" << endl;
                cout << "\tInvalid input! Please enter a number." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue; 
            }
            break; 
        }
        while (true) {
            cout << "\t_______________________________" << endl;
            cout << "\tEnter second index to swap: ";
            if (!(cin >> index2)) {
                cout << "\t_______________________________" << endl;
                cout << "\tInvalid input! Please enter a number." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue; 
            }
            CLS();
            cout << "\t_______________________________" << endl;
            cout << "\tElements swapped succesfully." << endl;
            break; 
        }
        swap(index1, index2);
    }

    void reverse_Element() {
        reverse();
        CLS();
        cout << "\t_______________________________" << endl;
        cout << "\tArray reversed successfully." << endl;
    }

    void find_Element() {
        int value;
        while (true) {
            cout << "\t_______________________________" << endl;
            cout << "\tEnter value to find: ";
            if (!(cin >> value)) {
                cout << "\t_______________________________" << endl;
                cout << "\tInvalid input! Please enter a number." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue; 
            }
            break; 
        }
        find(value);
    }

    void swap(int index1, int index2) {
        if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count) {
            cout << "\t_______________________________" << endl;
            cout << "\tInvalid indices." << endl;
            return;
        }
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
        CLS();
        cout << "\t_______________________________" << endl;
        cout << "\tElements swapped successfully." << endl;
    }

    void reverse() {
        for (int i = 0; i < count / 2; ++i) {
            int temp = arr[i];
            arr[i] = arr[count - 1 - i];
            arr[count - 1 - i] = temp;
        }
    }

int find(int value) {
    bool found = false;
    
    for (int i = 0; i < count; ++i) {
        if (arr[i] == value) {
            CLS();
            cout << "\t_______________________________" << endl;
            cout << "\tValue " << value << " found at index " << i << "." << endl;
            found = true;
            
            return i; // Return the index if value is found
        }
    }
    if (!found) {
        CLS();
        cout << "\t_______________________________" << endl;
        cout << "\tValue " << value << " not found in the array." << endl;
        
    }
    return -1; // Return -1 if value is not found
}
};

int main() {
    fixed_sized_Array array;
    int N = 100;
    // Prepopulate values
    for (int i = 0; i < 10; ++i) {
        array.insert(rand() % N, i);
    }

    int input; // Change input to int type

    while (true) {
        cout << "\t_______________________________" << endl;
        cout << "\n\t*   ARRAY MANIPULATION MENU   *" << endl;        
        cout << "\t_______________________________" << endl;
        cout << "\n\t[1] Display array content" << endl;
        cout << "\t[2] Insert element" << endl;
        cout << "\t[3] Delete element" << endl;
        cout << "\t[4] Swap elements" << endl;
        cout << "\t[5] Reverse elements" << endl;
        cout << "\t[6] Find element" << endl;
        cout << "\t[7] Quit" << endl;
        cout << "\t_______________________________" << endl;
        cout << "\n\tEnter your choice: ";

        // Read integer input
        cin >> input;

        // Check if input is within the valid range
        if (input < 1 || input > 7 || cin.fail()) {
            cout << "Invalid input! Please enter a number from 1 to 7." << endl;

            // Clear input stream
            cin.clear();

            // Ignore rest of the line
            while (cin.get() != '\n')
                continue;

            // Prompt the user again
            continue;
        }

        char choice; // declare choice here

        // Process user input
        switch (input) {
            case 1:
                array.display();
                break;
            case 2:
                do {
                    array.insert_Element();
                    cout << "\tDo you want to continue inserting elements? (Enter y to continue and enter any to go back menu): ";
                    cin >> choice;
                    CLS();
                } while (choice == 'y' || choice == 'Y');
                break;
            case 3:
                do {
                    array.delete_Element();
                    cout << "\tDo you want to continue deleting elements? (Enter y to continue and enter any to go back menu): ";
                    cin >> choice;
                    CLS();
                } while (choice == 'y' || choice == 'Y');
                break;
            case 4:
                do {
                    array.swap_Element();
                    cout << "\tDo you want to continue swapping elements? (Enter y to continue and enter any to go back menu): ";
                    cin >> choice;
                    CLS();
                } while (choice == 'y' || choice == 'Y');
                break;
            case 5:
                array.reverse_Element();
                break;
            case 6:
                do {
                    array.find_Element();
                    cout << "\tDo you want to continue finding elements? (Enter y to continue and enter any to go back menu): ";
                    cin >> choice;
                    CLS();
                } while (choice == 'y' || choice == 'Y');
                break;
            case 7:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}