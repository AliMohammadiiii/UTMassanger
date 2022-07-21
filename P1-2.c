#include <stdio.h>
#include <time.h> 
#define PHONE_NUMBER_DIGIT 10
#define MAX_PASSWORD_NUMBER_DIGIT 6
#define ACTIVE 1
#define CORRECT 1
#define UNACTIVE 0
#define WRONG 0
#define EMPTY 0

/*These variables to check Input type is int or not*/
int numberOfScanInScanf;
char LastCharacterInInput;


/*User Data*/
long long int user1 = EMPTY, user2 = EMPTY, user3 = EMPTY;
int pas1 = EMPTY, pas2 = EMPTY, pas3 = EMPTY;

/*This function counts the digits of the numbers to check the correctness of the input*/
/*
input: The number to be checked
output: lenght of number
*/
int countDigit(long long int number)
{
	int count = EMPTY;
	while (number != EMPTY)
	{
		number /= 10;
		++count;
	}
	return count;
}
/*First, it takes the username and password, and if it is correct, it enters the user's user panel*/
/*
input: temp userName and password
output: Notifies if the user enters the wrong password three times
*/
logIn(long long int userName,int pass) {
	int flag= ACTIVE,Password=EMPTY,command= EMPTY,passincorrectCounter = EMPTY;
	long long int usernamePhoneNumber= EMPTY;
	usernamePhoneNumber = userName;
	Password = pass;
	while (flag)
	{
		if (usernamePhoneNumber == EMPTY) {
			printf("Please, Enter your phone number:  ");
			numberOfScanInScanf = scanf_s("%lld%c", &usernamePhoneNumber, &LastCharacterInInput);
			if (!checkInputType()) {
				return WRONG;
			}
		}
		if (!phoneNumberExist(usernamePhoneNumber)) {
			printf("Your Phone number doesn't exist\n");
			return WRONG;
		}
		if (Password == EMPTY) {
			printf("Please, Enter your Password:  ");
			numberOfScanInScanf = scanf_s("%d%c", &Password, &LastCharacterInInput);
			if (!checkInputType()) {
				return WRONG;
			}
		}
		if (checkUserPassword(usernamePhoneNumber, Password)) {
			flag = UNACTIVE;
		}
		else
		{
			passincorrectCounter++;
			Password = EMPTY;
			printf("Your password is incorrect\n");
		}
		if (passincorrectCounter == 3) {
			system("cls");
			printf("Too many attempts Log in is locked for 30 second\n");
			return 2;
		}
	}
	flag = ACTIVE;
	system("cls");
		printf("Hi %lld, What do you want to do?\n", usernamePhoneNumber);
	while (flag)
	{
		printf("1.Send message\n2.Show messages\n3.Create channel\n4.Create group\n5.Log Out\n");
		numberOfScanInScanf = scanf_s("%d%c", &command, &LastCharacterInInput);
		if (!checkInputType()) {
			return WRONG;
		}
		switch (command)
		{
		case 1:
			system("cls");
			printf("You can now send your own messages\n\n\n\n\n\n\n\n");
			break;
		case 2:
			system("cls");
			printf("Here are your messages:\n\n\n\n\n\n\n\n");
			break;
		case 3:
			system("cls");
			printf("You can Create a channel:\n\n\n\n\n\n\n\n");
			break;
		case 4:
			system("cls");
			printf("You can Create a group:\n\n\n\n\n\n\n\n");
			break;
		case 5:
			system("cls");
			Password = EMPTY;
			usernamePhoneNumber = EMPTY;
			flag = UNACTIVE;
			printf("You have successfully logged out!\n\n");
			break;
		default:
			system("cls");
			printf("Your input is incorrect. Try again\n");
			break;
		}
	}
}
/*
Receives the mobile phone number and password and registers it if it is correct and not duplicate
*/
/*
input = none.
Note: This function affects two global variables, username and password!
Output = none.
*/
signUp() {
	long long int mobilePhoneNumber;
	int  passNumber, rePassNumber, flag = ACTIVE;
	printf("Hi, welcome.");
	while (flag)/*Phone Number Check*/
	{
		printf("Please enter your mobile number:  ");
		numberOfScanInScanf = scanf_s("%lld%c", &mobilePhoneNumber, &LastCharacterInInput);
		if (!checkInputType()) {
			return WRONG;
		}
		if (phoneNumberExist(mobilePhoneNumber)) {
			printf("This phone number exist. Try again\n");
			return WRONG;
		}
		else {
			if (checkPhoneFormat(mobilePhoneNumber)) {/*number format check*/
				flag = UNACTIVE;
			}
			else {
				printf("Wrong phone number format. Try again\n");
			}
		}
		

	}
	flag = ACTIVE;
	while (flag)/*PassWord check*/
	{
		printf("Now Enter your Password(Your password should be just a number and a maximum of 6 digits):    ");
		numberOfScanInScanf = scanf_s("%d%c", &passNumber, &LastCharacterInInput);
		if (!checkInputType()) {
			return WRONG;
		}
		if (countDigit(passNumber) > MAX_PASSWORD_NUMBER_DIGIT) {
			printf("Your password is incorrect. Your password is more than 6 digits. Try Again\n");
			continue;
		}
		printf("Now Renter your Password:  ");
		numberOfScanInScanf = scanf_s("%d%c", &rePassNumber, &LastCharacterInInput);
		if (!checkInputType()) {
			return WRONG;
		}
		if (passNumber == rePassNumber) {
			flag = UNACTIVE;
		}
		else {
			printf("The Password didn't Match");
		}
	}
	addUser(mobilePhoneNumber, passNumber);
	system("cls");
	printf("Your account was created successfully!\n");
	logIn(mobilePhoneNumber, passNumber);
}
/*This function checks that the input contains only a number*/
/*
Note: This function affects and uses two global variables, numberOfScanInScanf and LastCharacterInInput!
Output: the input is correct or not
*/
int checkInputType() {
	if (numberOfScanInScanf == EMPTY || LastCharacterInInput != '\n')
	{
		system("cls");
		printf("Wrong input format. Try again.\n");
		char buffer = 'b';
		while (buffer != '\n')
		{
			numberOfScanInScanf = scanf_s("%c", &buffer);
		}
		numberOfScanInScanf = CORRECT;
		LastCharacterInInput == '\n';
		return WRONG;
	}
	return CORRECT;
}
/*This function checks if the mobile number format is correct?*/
/*
input: mobile number
output: correct Or Wrong
*/
checkPhoneFormat(long long guessNumber) {
	if (countDigit(guessNumber) == PHONE_NUMBER_DIGIT) {
		return CORRECT;
	}
	else
	{
		return WRONG;
	}
}
/*This function checks if a mobile number is available?*/
/*
input: mobile number
output: correct Or Wrong
*/
phoneNumberExist(long long int Username) {
	if (user1 == Username || user2 == Username || user3 == Username){
		return CORRECT;
	}
	else {
		return WRONG;
	}
}
/*This function checks if the password format is correct?*/
/*
input: mobile number
output: correct Or Wrong
*/
checkUserPassword(long long int Username, int pass) {
	if (user1 == Username) {
		if (pas1 == pass)
		{
			return CORRECT;
		}
		else
		{
			return WRONG;
		}
	}
	else if (user2 == Username) {
		if (pas2 == pass)
		{
			return CORRECT;
		}
		else
		{
			return WRONG;
		}
	}
	else if (user3 == Username) {
		if (pas3 == pass)
		{
			return CORRECT;
		}
		else
		{
			return WRONG;
		}
	}

}
/*
input = userName and Password.
Note: This function affects two global variables, username and password!
Output = none.
*/
addUser(long long UserName,int password) {
	if (user1 == EMPTY) {
		user1 = UserName;
		pas1 = password;
	}
	else if (user2 == EMPTY) {
		user2 = UserName;
		pas2 = password;
	}
	else if (user3 == EMPTY) {
		user3 = UserName;
		pas3 = password;
	}
}
/*This function checks if a room exists?*/
/*
input: none
output: Exist Or unavailable
*/
checkCapacity() {
	if (user1 == EMPTY || user2 == EMPTY || user3 == EMPTY) {
		return CORRECT;
	}
	else
	{
		return WRONG;
	}
}

main() {
	int flag = ACTIVE,command = EMPTY,check = EMPTY,timer = EMPTY ,timercheck= EMPTY;
	time_t start, end;
	start = time(NULL);
	end = time(NULL);
	printf("Welcome to UTMessenger.\n");
	while (flag)
	{
		printf("Please choose one of the following option:\n1 to SignUp\n2 to logIn\n3 to Quit:\n");
		numberOfScanInScanf = scanf_s("%d%c", &command, &LastCharacterInInput);
		if (!checkInputType()) {
			continue;
		}
		switch (command)
		{
		case 1:
			system("cls");
			if (checkCapacity()) {
				signUp();
				break;
			}
			else
			{
				printf("No room to join our community :(\n");
				break;
			}
			
		case 2:
			/*If you enter the wrong password 3 times, it checks the timer and locks for 30 seconds*/
			system("cls");
			if (timercheck) {
				end = time(NULL);
				timer = difftime(end, start);
				if (timer < 30.0 && timer > 0) {
					printf("LogIn is Locked please Try again after %.2f seconds", 30.0-difftime(end, start));
				}
				else
				{
					timercheck = EMPTY;
					check = logIn(EMPTY, EMPTY);
					if (check == 2) {
						start = time(NULL);
						timercheck = ACTIVE;
					}
				}
			}
			else {
				check = logIn(EMPTY, EMPTY);
				if (check == 2) {
					start = time(NULL);
					timercheck = ACTIVE;
				}
			}
			break;
		case 3:
			system("cls");
			printf("I hope to see you again. Bye!");
			flag = UNACTIVE;
			break;
		default:
			system("cls");
			printf("Your input is incorrect. Try again!");
			break;
		}
	}
}