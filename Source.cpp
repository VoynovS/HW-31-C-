#include <iostream>
#include <string>


using namespace std;
//Task 1
int division(int num1, int num2);
//Task 2
bool len(string& str);

int main() {
	
	srand(time(NULL));
	string str;
	int N, M, res;
	//Task 1
	cout << "Task 1. Enter 2 number: \n";
	cin >> N >> M;
	cin.ignore();
	try {
		res = division(N, M);
		cout << "Random number from " << N << " to " << M << " = " << res << endl;
	}
	catch (const invalid_argument& ex) {
		cout << "Invalid argument: " << ex.what() << endl;
	}

	//Task 2
	cout << "Task 2. Enter the word and the length of the word:";
	getline(cin, str);
	try {
		len(str) == true ? cout << "True: the quantity matches.\n" : cout << "False: the quantity does not match\n";
	}
	catch (const runtime_error& ex) {
		cout << "Runtime error: " << ex.what() << endl;
	}
	
	

	return 0;
}
//Task 2
bool len(string& str) {
	int zero = 0;
	string word;
	string number;
	for (int i = 0; i < str.length(); i++) {
		if (str[0] == ' ') {
			throw runtime_error("Incorrect input of a word and its length.");
			break;
		}
		if (str[i] == ' ')
			zero++;			
	}
	if (zero == 0 || zero > 1) {
		throw runtime_error("Incorrect input of a word and its length.");
	}
	
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			for (int j = i + 1; j < str.length(); j++) {
				if (str[j] > 47 && str[j] < 58)
				number += str[j];
				else
					throw runtime_error("Incorrect input of a word and its length.");
			}
			break;
		}
		else
			word += str[i];
	}
	cout << "Your word: " << word << endl;
	cout << "Number of characters in a word = " << word.length() << endl;;
	int num = word.length();
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			word += str[i];
		}					
	}
	int res = stoi(number);
	cout << "Your number = " << res << endl;
	
	if (res == num)
		return true;
	return false;
}


//Task 1
int division(int num1, int num2) {
	if (num1 < num2 && num1 != num2) {
		int num3 = rand() % (num2 - (num1)+1) + num1;
		return num3;
	}
	else{
		throw invalid_argument("Incorrect range of numbers.");

	}	
}

