//Author: Bharath Venkatesh
//Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.
//NOTE: One or two additional variables are fine. An extra copy of the array is not.

//Book Approach:
//For each character, check if it is a duplicate of already found characters.
//Skip duplicate characters and update the non duplicate characters.
// NOTE: CODE DOESNT WORK FOR MULTI VARIBALE REPEATS.




// #include<iostream>
//
// using namespace std;
//
// int main()
// {
//     if (str.empty()) return 0;
//     int len = str.length;
//     if (len < 2)
//     {
//      cout<<str<<"\n";
//      return 0;
//     }
//     int tail = 1;
//     for (int i = 1; i < len; ++i) {
//         int j;
//         for (j = 0; j < tail; ++j) {
//             if (str[i] == str[j]) break;
//         }
//         if (j == tail) {
//             str[tail] = str[i];
//             ++tail;
//         }
//     }
//     str[tail] = 0;
//     cout<<str<<"\n";
//     return(0);
// }


//My Approach: Brute Force: Check for each characters repeat in the entire string
//If found copy all characters next to the one found from the found place
//NOTE:Time Complexity is O(n3)
//Analysis: Works fine but should work on trying to bringing down complexity.

#include<iostream>

using namespace std;

// int main()
// {
//     string str;
//     cin>>str;
//     int i,j,k=0;
//     if (str.empty()) return 0;
//     int len = str.length();
//     if (len < 2)
//     {
//         cout<<str<<"\n";
//         return 0;
//     }
//     else
//     {
//         for(i=0; i<len; i++) {
//             for(j=i+1; j<len; j++) {
//                 if(str[i]==str[j])
//                 {
//                     int temp=j;
//                     for(k=j+1; k<len; k++,temp++)
//                     {
//                         str[temp]=str[k];
//                     }
//                     str[--k]='\0';
//                     len--;
//                     j--; 	// NOTE: Bug Fix for consecutive characters not being removed!!
//                 }
//             }
//         }
//     }
//     cout<<str<<"\n";
//     return 0;
// }

//Another Approach: Given that another buffer can be used
//Book Approach
//NOTE: Doesnt work for consecutive characters

// int main()
// {
//     string str;
//     cin>>str;
//     int i,j,k=0;
//     if (str.empty()) return 0;
//     int len = str.length();
//     if (len < 2)
//     {
//         cout<<str<<"\n";
//         return 0;
//     }
//     else
//     {
//         bool hit[256];
//         for (int i = 0; i < 256; ++i) {
//             hit[i] = false;
//         }
//         hit[str[0]] = true;
//         int tail = 1;
//         for (int i = 1; i < len; ++i) {
//             if (!hit[str[i]]) {
//                 str[tail] = str[i];
//                 ++tail;
//                 hit[str[i]] = true;
//             }
//         }
//         str[tail] = 0;
//     }
//     cout<<str<<"\n";
//     return(0);
// }

//MODIFIED TO WORK
//Logic: For each character that is unique set a boolean at its ascii place to be true in a boolean array
//Check the array at its ascii location before each insert and follow the same logic of copying rest.
//NOTE: Complexity: O(n2)

int main()
{
    string str;
    cin>>str;
    int i,j,k=0;
    if (str.empty()) return 0;
    int len = str.length();
    if (len < 2)
    {
        cout<<str<<"\n";
        return 0;
    }
    else
    {
        bool hit[256];
        for (int i = 0; i < 256; ++i) {
            hit[i] = false;
        }
        hit[str[0]] = true;
        //int tail = 1;
        for (int i = 1; i < len; ++i) {
            if (hit[str[i]]) {
                     int temp=i;
		     for(k=i+1; k<len; k++,temp++)
                     {
                        str[temp]=str[k];
                     }
                    str[--k]='\0';
                    len--;
                    i--;
	      
	    }
	    else
	      hit[str[i]] = true;
        }
       // str[tail] = 0;
    }
    cout<<str<<"\n";
    return(0);
}

