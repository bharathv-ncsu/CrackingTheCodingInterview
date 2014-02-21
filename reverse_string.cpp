//Author: Bharath Venkatesh
//Write code to reverse a C-Style String. (C-String means that “abcd” is represented as five characters, including the null characters
//Normal Approach: Traverse to the end -> One loop. Traverse from reverse to start and copy it to another array.
//Better Approach: Do it "IN PLACE".
//NOTE:Time Complexity is O(n)

#include<iostream>

using namespace std;

int main()
{
    char *str = new char[20];
    cin>>str;

    char *end = str;
    char *op = str;		//Since we move both str and end pointers keep track of start
    char tmp;
    if (str) {			//check if string is null
        while (*end) {		// Move to the end of the string
            ++end;
        }
        --end;			// One back to reach last character
        cout<<end<<"\n"<<str<<"\n";
        while (str < end) {	// Keep one Pointer at Start. Other at end. Move both copying one to another with a temp character.
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
    cout<<op<<"\n";
    return 0;
}