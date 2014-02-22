//Author: Bharath Venkatesh
//Write a method to decide if two strings are anagrams or not.
//First Approach: Sort the two strings

// boolean anagram(String s, String t) 
// { 
//   return sort(s) == sort(t);
// }
// Complexity: Sort -> nlogn. Compare : n -> nlogn

//Better Approach: Use Hashes. 
//Hash the first Array : Complexity : O(n)
//For each element in the second array check if it exists in Hash2 : Complexity : O(n)
//Complexity : O(n)


#include<iostream>
#include<map>

using namespace std;
using std::map;

int main()
{
  string s1,s2;
  cout<<"Enter s1\n";
  cin>>s1;
  cout<<"Enter s2\n";
  cin>>s2;
  map<char,int> mymap;		// Map Initialization
  int i=0;
  if(s1.length()!=s2.length())		// Length Difference No Anagram
  {
    cout<<"Not Anagram\n";
    return -1;
  }
  else
  {
  while(i<s1.length())			// Hashin first array taking into care of the duplicate characters
  {
    if(mymap.count(s1[i])>0)
    {
      mymap[s1[i]]+=1;
    }
    else
      mymap[s1[i]]=1;
    i++;
  }
  i=0;
  while(i<s2.length())
  {
     map<char,int>::iterator it;
     it=mymap.find(s2[i]);		// Find character in hash
     if(it!=mymap.end())
     {
	mymap[s2[i]]-=1;
	if(mymap[s2[i]]==0)		// Delete its entry when all of its occurence removed
	  mymap.erase(s2[i]);
     }
     else
     {
	cout<<"Not Anagram\n";
	return -1;
     }
     i++;
  }
  if(!mymap.empty())			// Any character remains in map-> Not anagram
  {
	cout<<"Not Anagram\n";
	return -1;
  }
  else
  {
      cout<<"Anagram";
      return 0;
  }
  }
  return 0;
}