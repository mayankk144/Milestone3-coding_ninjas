// Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
// Do this recursively.

void replaceCharacter(char input[], char c1, char c2) {
    
    if(input[0]=='\0'){
        return;
    }
    
    if(input[0]!=c1){
        return replaceCharacter(input+1,c1,c2);
    }
    else{
        input[0] = c2;
        return replaceCharacter(input+1,c1,c2);
    }
    
}

//Given a string S, remove consecutive duplicates from it recursively.

void removeConsecutiveDuplicates(char *input) {
	
	if(input[0]=='\0'){
		return;
	}

	if(input[0]==input[1]){
		 int i=1;
		 for(;input[i]!='\0';i++){
			 input[i-1]=input[i];
		 }
		 input[i-1]='\0';
		 return removeConsecutiveDuplicates(input);
	}
	else{
		return removeConsecutiveDuplicates(input+1);
	}


}

//Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.

void merge(int *part1, int size1, int *part2, int size2, int *output, int n) {
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < size1 && j < size2) {
    if (part1[i] < part2[j]) {
      output[k++] = part1[i++];
    } else {
      output[k++] = part2[j++];
    }
  }
  while (j < size2) {
    output[k++] = part2[j++];
  }
  while (i < size1) {
    output[k++] = part1[i++];
  }
}
void mergeSort(int arr[], int size) {
  if (size == 1) {
    return;
  }
  int *part1 = new int[size / 2];
  int size1 = size / 2;
  int *part2 = new int[size - size / 2];
  int size2 = size - size / 2;
  for (int i = 0; i < size1; i++) {
    part1[i] = arr[i];
  }
  int k = 0;
  for (int i = size1; i < size; i++) {
    part2[k++] = arr[i];
  }
  mergeSort(part1, size1);
  mergeSort(part2, size2);
  merge(part1, size1, part2, size2, arr, size);
}

// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.

int Partition(int a[], int l, int u) {
  int pivot = a[u];
  int pIndex = l;

  for (int i = l; i < u; i++) {

    if (pivot > a[i]) {
      int temp = a[pIndex];
      a[pIndex] = a[i];
      a[i] = temp;
      pIndex++;
    }
  }
  int temp = a[pIndex];
  a[pIndex] = a[u];
  a[u] = temp;
  return pIndex;
}

void qS(int a[], int l, int u) {
  if (l < u) {
    int pIndex = Partition(a, l, u);
    qS(a, l, pIndex - 1);
    qS(a, pIndex + 1, u);
  }
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
  qS(input, 0, size - 1);
}


// Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
// Return empty string for numbers 0 and 1.
// Note : 1. The order of strings are not important.
// 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.


#include <string>
using namespace std;

int keypad(int num, string output[]){

    string input;
    
    if(num==0){
        output[0] = "";
        return 1;
    }

    int n = num%10;
    num = num/10;
    int current_size = keypad(num, output);

    switch(n){
    case 2:
      input = "abc";
      break;
    case 3:
      input = "def";
      break;
    case 4:
      input = "ghi";
      break;
    case 5:
      input = "jkl";
      break;
    case 6:
      input = "mno";
      break;
    case 7:
      input = "pqrs";
      break;
    case 8:
      input = "tuv";
      break;
    case 9:
      input = "wxyz";
      break;
    }
    int net_size = current_size*(input.size());
    string temp[net_size];
    int k=0;
    for(int i=0;i<current_size;i++){
        for(int j=0;j<input.size();j++){
            temp[k++] = output[i] + input[j];
        }
    }
    for(int i=0;i<net_size;i++){
        output[i] = temp[i];
    }
    return net_size;

}

//Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string dial(int key){
    unordered_map<int,string>m;
    m[0]="";
    m[1]="";
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    return m[key];
}

void kp(int num, string output){
    if(num==0){
        cout << output<<endl;
        return;
    }

    string pd=dial(num%10);
    for(int i=0;i<pd.size();i++){
        kp(num/10,pd[i]+output);
    }
}


void printKeypad(int num){
    kp(num,"");
}


// Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
// a. The string begins with an 'a'
// b. Each 'a' is followed by nothing or an 'a' or "bb"
// c. Each "bb" is followed by nothing or an 'a'
// If all the rules are followed by the given string, return true otherwise return false.

#include<cstring>
using namespace std;

bool check(char input[]){
	if(strlen(input) == 1 || strlen(input) == 0){
		return true;
	}
	bool b = true;
	if(input[0]=='a'){
		if(input[1]=='a'){
			b = check(input+1);
		}
		else if(input[1]=='b' && input[2] == 'b'){
			b = check(input+2);
		}
		else{
			return false;
		}
	}
	else if(input[0] == 'b'){
		if(input[1]=='a'){
			b = check(input+1);
		}
		else{
			return false;
		}
	}
}

bool checkAB(char input[]) {

  bool b = true;
  if (input[0] != 'a') {
    return false;
  } else {
    b = check(input);
  }
  return b;
}

// A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.

int staircase(int n){
    
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}

//Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
// Return -1 if x is not present in the given array.
// Note : If given array size is even, take first mid.
// Input format :

// Line 1 : Array size

// Line 2 : Array elements (separated by space)

// Line 3 : x (element to be searched)

int binary(int input[],int lb, int hb, int element){
    int mid = (lb+hb)/2;
    if(input[mid]==element){
        return mid;
    }
    if(lb==hb){
        return -1;
    }
    if(element<input[mid]){
        hb=mid-1;
        binary(input, lb, hb, element);
    }
    else{
        lb = mid+1;
        binary(input,lb,hb,element);
    }
}


int binarySearch(int input[], int size, int element) {
    
    int n = binary(input,0,size,element);
    return n;

}

// Given an integer array (of length n), find and return all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

// Note : The order of subsets are not important.

// Input format :

// Line 1 : Size of array

// Line 2 : Array elements (separated by space)

int subset(int input[], int n, int output[][20]) {
if(n==0)
{
    output[0][0]=0;
    return 1;
}
int smalloutput=subset(input+1,n-1,output);
for(int i=0;i<smalloutput;i++)
{
    output[i+smalloutput][0]=output[i][0]+1;
    output[i+smalloutput][1]=input[0];
    for(int j=0;j<output[i][0];j++)
    {
        output[i+smalloutput][j+2]=output[i][j+1];
    }
}
return 2*smalloutput;
}

// Given an integer array (of length n), find and print all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print the subsets in different lines.

void printSubsetsOfArray(int input[],int size, int output[],int outputSize){
    if(size == 0){
        for(int i=0;i<outputSize;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    printSubsetsOfArray(input+1,size-1,output,outputSize);
    //assuming current elemnet is included in array
    int newoutput[20] = {};
    for(int i=0;i<outputSize;i++){
        newoutput[i] = output[i];
    }
    newoutput[outputSize] = input[0];
    printSubsetsOfArray(input+1,size-1,newoutput,outputSize+1);
}

void printSubsetsOfArray(int input[], int size) {
    int ans[20] = {};
    printSubsetsOfArray(input,size,ans,0);
}

//Given an array A and an integer K, print all subsets of A which sum to K.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print them in different lines.
// Input format :

#include <bits/stdc++.h>
using namespace std;

/*void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
}*/
void psubset(int input[], int size, int k, int output[], int m) {
  if (size == 0) {
    if (k == 0) {
      for (int i = 0; i < m; i++) {
        cout << output[i] << " ";
      }
      cout << endl;
      return;
    } else
      return;
  }

  int o1[m + 1];
  int i;
  for (i = 0; i < m; i++) {
    o1[i] = output[i];
  }
  o1[i] = input[0];
  psubset(input + 1, size - 1, k - input[0], o1, m + 1);
  psubset(input + 1, size - 1, k, output, m);
}

void printSubsetSumToK(int input[], int size, int k) {
  // Write your code here
  int m = 0;
  int output[m];
  psubset(input, size, k, output, m);
}

// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. And input string does not contain 0s.

#include <string.h>
#include <bits/stdc++.h>
using namespace std;

void help(string input, string out, vector<string> &str) {
  if (input.size() == 0) {
    str.push_back(out);
    return;
  }
  char c1 = (input[0] - 48) + 96;

  // Ignore the output coming from zero in a string
  if (input[0] == '0')
    return;

  help(input.substr(1), out + c1, str);

  if (input.size() > 1) {
    int d = (input[0] - 48) * 10 + (input[1] - 48);
    if (d > 26)
      return;
    char c2 = 96 + d;
    help(input.substr(2), out + c2, str);
  }
}

int getCodes(string input, string output[10000]) {
  /*
  You are given the input text and output string array. Find all possible codes
  and store in the output string array. Don’t print the codes. Also, return the
  number of codes return to the output string. You do not need to print
  anything.
  */
  vector<string> str;
  string out = "";
  help(input, out, str);

  for (int i = 0; i < str.size(); i++)
    output[i] = str[i];

  int x = str.size();

  return x;
}

//Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.

#include <string.h>
using namespace std;

void printAllPossibleCodesHelper(string input, string output){ 
    if(input[0] == '\0'){
        cout << output << endl;
        return; 
        
    } 
    
    int num = input[0] - 48; 
    char ch = num - 1 + 'a';
    printAllPossibleCodesHelper(input.substr(1), output + ch);
    if(input[1] != '\0'){ 
        num = num * 10 + input[1] - 48;
        ch = num - 1 + 'a';
        if(num >= 10 && num <= 26){
            printAllPossibleCodesHelper(input.substr(2), output + ch);
        }
    }
}
            
void printAllPossibleCodes(string input) {
    printAllPossibleCodesHelper(input, "");
}


//Given a string S, find and return all the possible permutations of the input string.

#include <string>
using namespace std;

int returnPermutations(string input, string output[]) {
  if (input.length() == 0) {
    output[0] = "";
    return 1;
  }

  string smallOutput[10000];
  int smallSize = returnPermutations(input.substr(1), smallOutput);
  int k = 0;
  for (int i = 0; i < smallSize; i++) {
    for (int j = 0; j <= smallOutput[i].length(); j++) {
      output[k++] =
          smallOutput[i].substr(0, j) + input[0] + smallOutput[i].substr(j);
    }
  }

  return k;
}

// Given an input string (STR), print all possible permutations of the input string.

#include <iostream>
#include <string>
using namespace std;

void permute(string &a, int l, int r) {
  // Base case
  if (l == r)
    cout << a << endl;
  else {
    // Permutations made
    for (int i = l; i <= r; i++) {

      // Swapping done
      swap(a[l], a[i]);

      // Recursion called
      permute(a, l + 1, r);

      // backtrack
      swap(a[l], a[i]);
    }
  }
}

void printPermutations(string input){

    	int n = input.length();
      permute(input, 0, n-1);
}