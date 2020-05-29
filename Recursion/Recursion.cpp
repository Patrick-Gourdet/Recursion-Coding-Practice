#include <iostream>
#include <ostream>
#include <string>


// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here
string cypher(string str,char a)
{	
	if(str.size() == 1) return str;
	str.erase(str.begin( ) + (str.size()-1)/2);
	cypher(str,str.at((str.size()-1)/2));
	return str = (a + str);
	
}

string findEncryptedWord(string s) {
  // Write your code here

	string str1;
	string str2;
	string result;
	if(s.size() % 2 == 0)
	{
		result = s.substr(0,s.size() / 2 - 1);
		str1 = s.substr(0,s.size() / 2 - 1);
		str2 = s.substr(s.size()/ 2 ,s.size());
	}
	else
	{
		result = s.substr(s.size()/ 2 ,1);
		str1 = s.substr(0,s.size() / 2);
		str2 = s.substr(s.size()/ 2 + 1,s.size());
	}
	result += cypher(str1,str1.at((str1.size()-1)/2)) + cypher(str2,str2.at((str2.size()-1)/2));

	return str1;
}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom, but they are otherwise not editable!

void printString(string& str) {
  cout << "[\"" << str << "\"]";
}

int test_case_number = 1;

void check(string& expected, string& output) {
  bool result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printString(expected); 
    cout << " Your output: ";
    printString(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  string s_1 = "abcxhke";
  string expected_1 = "bac";
  string output_1 = findEncryptedWord(s_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string expected_2 = "bacd";
  string output_2 = findEncryptedWord(s_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}