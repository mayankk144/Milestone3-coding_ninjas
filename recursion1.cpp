//Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
// Do this recursively.

int power(int x, int n) {
    if(n==0){
        return 1;
    }
    if(x==1){
        return 1;
    }
    return x*power(x,n-1);
}

//Given the number 'n', write a code to print numbers from 1 to n in increasing order recursively.

void print(int n){
    if(n == 0){
        return;
    }
    print(n-1);
    cout << n << " ";
}

//Given the number 'n', find out and return the number of digits present in a number .

int count(int n){
    if(n==0){
        return 0;
    }
    int ans = count(n/10);
    return 1 + ans;
}

//Given an array of length N, you need to find and return the sum of all elements of the array.
// Do this recursively.

int sum(int input[], int n) {
  
    if(n==0){
        return 0;
    }
    int val = input[0];
    return val + sum(input+1,n-1);

}

//Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false. 
// Do this recursively.

bool checkNumber(int input[], int size, int x) {
  
    if(size==0){
        return false;
    }
    bool find = checkNumber(input+1,size-1,x);
    if(input[0]==x){
        find = true;
    }
    return find;
}

//Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
// First index means, the index of first occurrence of x in the input array.
// Do this recursively. Indexing in the array starts from 0.

int firstIndex(int input[], int size, int x) {
  
    if(size==0){
        return -1;
    }
    
    if(input[0]==x){
        return 0;
    }
    
    int ans = firstIndex(input+1,size-1,x);
    if(ans==-1){
        return -1;
    }
    else{
        return ans+1;
    }
    

}


//Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
// Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
// You should start traversing your array from 0, not from (N - 1).
// Do this recursively. Indexing in the array starts from 0.

int lastIndex(int input[], int size, int x) {
  
    if(size==0){
        return -1;
    }
    
    int val = lastIndex(input+1,size-1,x);
    
    if(val==-1){
        if(input[0]==x){
            return 0;
        }
        else{
            return -1;
        }
    }
    else{
        return val+1;
    }

}

//Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
//Do this recursively. Indexing in the array starts from 0.

int allIndexes(int input[], int size, int x, int output[]) {
  
    if(size==0){
        return 0;
    }
    
    int ans = allIndexes(input,size-1,x,output);
    
    if(input[size-1]==x){
        output[ans] = size-1;
        return ans+1;
    }
    else{
        return ans;
    }

}

//Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.

int multiplyNumbers(int m, int n) {
    
    if(n==0){
        return 0;
    }
    
    int val = multiplyNumbers(m,n-1);
    return m+val;

}


//Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

int countZeros(int n) {
    if(n==0){
        return 1;
    }
    if(n<10){
        return 0;
    }
    if(n%10==0){
        return 1+countZeros(n/10);
    }
    else
        return countZeros(n/10);
}


//Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.

double geometricSum(int k) {
    if(k<0){
        return 0;
    }
    double result = geometricSum(k-1);
    return result + 1/pow(2,k);

}

//Check whether a given String S is a palindrome using recursion. Return true or false.

#include <bits/stdc++.h>
bool isPalRec(char str[],
              int s, int e)
{
     
    // If there is only one character
    if (s == e)
    return true;
 
    // If first and last
    // characters do not match
    if (str[s] != str[e])
    return false;
 
    // If there are more than
    // two characters, check if
    // middle substring is also
    // palindrome or not.
    if (s < e + 1)
    return isPalRec(str, s + 1, e - 1);
 
    return true;
}
 
bool checkPalindrome(char str[])
{
    int n = strlen(str);
     
    // An empty string is
    // considered as palindrome
    if (n == 0)
        return true;
     
    return isPalRec(str, 0, n - 1);
}

//Write a recursive function that returns the sum of the digits of a given integer.

int sumOfDigits(int n) {
    if(n==0){
        return 0;
    }
    int val = sumOfDigits(n/10);
    return val + n%10;
}

//Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

#include <bits/stdc++.h>
using namespace std;

void replacePi(char input[]) {
	
	if(input[0]=='\0'){
		return;
	}
        replacePi(input + 1);
        if(input[0]=='p' && input[1]=='i'){
          for (int i = strlen(input); i >= 2; i--) {
            input[i + 2] = input[i];
          }
        input[0] = '3';
		input[1] = '.';
		input[2] = '1';
		input[3] = '4';
	}

}

//Given a string, compute recursively a new string where all 'x' chars have been removed.

void removeX(char input[]) {
    if(input[0]=='\0'){
        return;
    }
    removeX(input+1);
    if(input[0]=='x'){
        int i=0;
        for(;input[i]!='\0';i++){
            input[i] = input[i+1];
        }
    }

}


//Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

#include <bits/stdc++.h>
using namespace std;

int stringToNumber(char input[], int last){
	//Base Case
	if(last == 0){
		return input[last] - '0';
	}
	//Recursive Call
	int smallAns = stringToNumber(input,last-1);       
	int a = input[last] - '0';
	return smallAns * 10 + a;
}

//Recursive Function
int stringToNumber(char input[]){
	int len = strlen(input);
	return stringToNumber(input,len-1);
}

//Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

#include <bits/stdc++.h>
using namespace std;

void pairStar1(char arr[],int start){
	//Base Case: Reached End Of String
	if(arr[start]=='\0'){
		return;
	}   
	//Recursive Call 
	pairStar1(arr,start+1);
	if(arr[start] == arr[start+1]){
		int l = strlen(arr);
		//Extending the string
		arr[l+1] = '\0';
		int i;
		//To shift the letters by 1
		for(i = l-1;i>=start +1;i--){
			arr[i+1] = arr [i];
		}
		//Entering * in between
		arr[start+1] = '*';
	}
}

void pairStar(char input[]) {
    pairStar1(input,0);

}

//Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move all disks from source rod to destination rod using third rod (say auxiliary). The rules are :
// 1) Only one disk can be moved at a time.
// 2) A disk can be moved only if it is on the top of a rod.
// 3) No disk can be placed on the top of a smaller disk.
// Print the steps required to move n disks from source rod to destination rod.
// Source Rod is named as 'a', auxiliary rod as 'b' and destination rod as 'c'.

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if(n==0){
        return;   //base case
    }
    towerOfHanoi(n-1,source, destination, auxiliary);   //recursion call to shift (n-1) disks from source to auxiliary
    cout<<source<<" "<<destination<<endl;   
    towerOfHanoi(n-1, auxiliary, source, destination); 

}