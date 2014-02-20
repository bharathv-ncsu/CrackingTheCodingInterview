//Author: Bharath Venkatesh
//Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?
//My Approach: Put each character of the input string into a Set. Set can take only uniques. So ON CONFLICT IT DROPS ALL NON UNIQUE CHARACTERS.
// Then just compare the length of the set with length of String
//NOTE:Time Complexity is O(n)

#include<iostream>
#include "set"

using namespace std;
using std::set;

int main()
{
  string input;
  int i=0;
  set<char> input_set;
  cin>>input;
  while(i<input.length())
  {
    input_set.insert(input[i]);
    i++;
  }
    if(input_set.size()<input.length()) 
    {
      cout<<"String has non unique characters\n";
    }
    else
      cout<<"String has ALL unique characters\n";
    return(0);
}

//Book Approach:
//Check with the interviewer if the string is all ascii or unicode
//NOTE: This is a great thing to point out to your interviewer!
//For simplicity, assume char set is ASCII (if not, we need to increase the storage size. The rest of the logic would be the same). 
//Time complexity is O(n), where n is the length of the string, and space complexity is O(n)
// public static boolean isUniqueChars2(String str) {
// 	
// boolean[] char_set = new boolean[256];
// 	
// for (int i = 0; i < str.length(); i++) {
// 		
// int val = str.charAt(i);
// 		
// if (char_set[val]) return false;
// 		
// char_set[val] = true;
// 	
// }
// 	
// return true;
// }



