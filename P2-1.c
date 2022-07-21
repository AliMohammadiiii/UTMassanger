#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

#define PHONE_NUMBER_DIGIT 11
#define MIN_PASSWORD_NUMBER_DIGIT 6
#define ACTIVE 1
#define CORRECT 1
#define UNACTIVE 0
#define WRONG 0
#define EMPTY 0


#define Phonenumber 0
#define Username 1
#define pass 2
#define repass 3
#define checker 3


#define SPACE 32

#define NUMBEROFUSER 4
#define LENGTHOFUSERNAMEANDPASS 21
#define LENGTHOFMASSAGES 31
#define NUMBEROFMASSAGE 10

#define MASSAGETEXT 0
#define SOURCEUSERNAME 1
#define DESTINATIONUSERNAME 2

int system(const char* command);
/*this function will clear buffer of scanf*/
void clearbuffer();
int spaceChecker(char text[LENGTHOFUSERNAMEANDPASS]);
/*sign Up method
input: user data
output: When it is finished, it calls function log in and returns 0 if it is incorrect
Note that this affects variable userdata
*/
int signUp(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS]);
/*add User method
input: user data, temp data given by sign up method
output: 1 for correct and 0 for faild
Note that this affects variable userdata
*/
int addUser(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char Data[4][LENGTHOFUSERNAMEANDPASS]);
/*
input: phone number
output: 1 for correct and 0 for faild
*/
/*
This function examines three things: The number of digits is equal to PHONE_NUMBER_DIGIT. The first is zero. Only number entered.
Note : 48 is 0 and 57 is 9
*/
int checkPhoneFormat(char Data[LENGTHOFUSERNAMEANDPASS]);
/*
input: suggest password
output: 1 for correct and 0 for faild
*/
/*
This function examines three things: The number of digits is bigger than 6
*/
int checkPassFormat(char Data[LENGTHOFUSERNAMEANDPASS]);
/*This function checks if a mobile number is available?*/
/*
input: mobile number and user data
output: correct Or Wrong
*/
int phoneNumberExist(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char Data[LENGTHOFUSERNAMEANDPASS]);
int equalString(char userData[LENGTHOFUSERNAMEANDPASS], char Data[LENGTHOFUSERNAMEANDPASS], int lenghtOfcheck);
/*This function checks if a mobile number is available?*/
/*
input: username and user data
output: correct Or Wrong
*/
int UsernameExist(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char Data[LENGTHOFUSERNAMEANDPASS]);
/*This function checks that the input contains only a number*/
/*
Note: This function affects and uses two global variables, numberOfScanInScanf and LastCharacterInInput!
Output: the input is correct or not
*/
int checkInputType(int numberOfScanInScanf, char LastCharacterInInput);
int nullchecker(char data[LENGTHOFUSERNAMEANDPASS]);
/*log in method
input: user data, temp data , massage
output: 1 for correct and 0 for faild
Note that this affects variable massage
*/
int logIn(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char Data[4][LENGTHOFUSERNAMEANDPASS], char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES]);
/*
Is the password correct?
input user data , username , password
output correct or wrong
*/
int checkPassword(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char username[LENGTHOFUSERNAMEANDPASS], char password[LENGTHOFUSERNAMEANDPASS]);
/*
send massage method
input user data massage hostusername
Note that this affects variable massage
*/
int sendMassage(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFMASSAGES]);
/*
check capicity of massage method
input user data massage hostusername destination username
output correct or Wrong
*/
int checkcapicity(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFUSERNAMEANDPASS], char destinationusername[LENGTHOFUSERNAMEANDPASS]);
/* show massage */
int viewMassage(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFUSERNAMEANDPASS]);
/* show massage from  recieved massages*/
int viewreceivedmassage(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFUSERNAMEANDPASS]);
/* show massage from  sent massages*/
int viewsentmassage(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFMASSAGES]);
void initialzeArrayuserdata(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS]);
void initialzeArrayMassage(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES]);


int main() {
	char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS];
	initialzeArrayuserdata(userData);
	char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES];
	initialzeArrayMassage(massage);
	char tempData[4][LENGTHOFUSERNAMEANDPASS] = { EMPTY };
	int flag = ACTIVE, command = EMPTY, numberOfScanInScanf=EMPTY, Capacity = EMPTY;
	char LastCharacterInInput='e';
	printf("Welcome to UTMessenger.\n");
	while (flag)
	{
		printf("Please choose one of the following option:\n1 to SignUp\n2 to logIn\n3 to Quit:\n");
		numberOfScanInScanf = scanf("%d%c", &command, &LastCharacterInInput);
		if (!checkInputType(numberOfScanInScanf, LastCharacterInInput)) {
			continue;
		}
		switch (command)
		{
		case 1:
			  system("cls");
			if (Capacity < NUMBEROFUSER) {
				signUp(userData);
				Capacity++;
				break;
			}
			else
			{
				printf("No room to join our community :(\n");
				break;
			}

		case 2:
			  system("cls");
			logIn(userData, tempData, massage);
			break;
		case 3:
			  system("cls");
			printf("I hope to see you again. Bye!\n");
			flag = UNACTIVE;
			break;
		default:
			  system("cls");
			printf("Your input is incorrect. Try again!\n");
			break;
		}
	}
}
void clearbuffer() {
	char buffer = 'b';
	int garbage=EMPTY;
	while (buffer != '\n')
	{
		garbage = scanf("%c", &buffer);
	}
}
int spaceChecker(char text[LENGTHOFUSERNAMEANDPASS]) {
	int spacechecker = EMPTY;
	for (unsigned int z = 0; z < strlen(text); z++) {
		if ((int)text[z] == SPACE) {
			  system("cls");
			printf("wrong input format you cant use space\n");
			spacechecker = CORRECT;
		}
	}
	if (spacechecker) {
		return CORRECT;
	}
	else {
		return WRONG;
	}
}
int signUp(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS]) {
	char Data[4][LENGTHOFUSERNAMEANDPASS] = { EMPTY };
	int flag = ACTIVE, scanChecker = EMPTY;
	printf("Hi, welcome.\n");
	while (flag) {
		printf("Please enter your mobile number:  ");
		scanChecker = scanf_s("%[^\n]", Data[Phonenumber], LENGTHOFUSERNAMEANDPASS);
		clearbuffer();
		if (!scanChecker) {
			system("cls");
			printf("Wrong phone number format. Try again\n");
			scanChecker = 1;
			continue;
		}
		if (!checkPhoneFormat(Data[Phonenumber])) {
			system("cls");

			printf("Wrong phone number format. Try again\n");
			continue;
		}
		if (!phoneNumberExist(userData, Data[Phonenumber])) {
			  system("cls");
			printf("This phone number exist. Try again\n");
			continue;
		}
		flag = UNACTIVE;

	}
	flag = ACTIVE;
	while (flag) {
		char LastCharacterInInput = 'b', spacechecker = EMPTY;
		printf("Please enter your Username(Your username should be just a maximum of 20 digits):  ");

		scanChecker = scanf_s("%[^\n]", Data[Username], LENGTHOFUSERNAMEANDPASS);
		clearbuffer();
		if (spaceChecker(Data[Username])) {
			continue;
		}
		if (!scanChecker) {
			  system("cls");
			printf("Wrong username format. Try again\n");
			scanChecker = 1;
			continue;
		}
		if (!UsernameExist(userData, Data[Username])) {
			printf("This Username exist. Try again\n");
			continue;
		}
		flag = UNACTIVE;
	}
	flag = ACTIVE;
	while (flag) {
		printf("Now Enter your Password(Your password should be just a minimum of 6 digits and maximum of 20 digits):    ");
		scanChecker = scanf_s("%[^\n]", Data[pass], LENGTHOFUSERNAMEANDPASS);
		clearbuffer();
		if (spaceChecker(Data[pass])) {
			continue;
		}
		if (!scanChecker) {
			printf("Wrong password format. Try again\n");
			scanChecker = 1;
			continue;
		}
		if (!checkPassFormat(Data[pass])) {
			printf("Wrong password format. Try again\n");
			continue;
		}
		printf("Now Renter your Password:  ");
		scanChecker = scanf_s("%[^\n]", Data[repass], LENGTHOFUSERNAMEANDPASS);
		clearbuffer();
		if (spaceChecker(Data[repass])) {
			continue;
		}
		if (!scanChecker) {
			system("cls");
			printf("Wrong password format. Try again\n");
			scanChecker = 1;
			continue;
		}
		if (strlen(Data[pass]) != strlen(Data[repass]) || !equalString(Data[pass], Data[repass], strlen(Data[pass]))) {
			system("cls");
			printf("The Password didn't Match\n");
			continue;
		}
		flag = UNACTIVE;
	}
	addUser(userData, Data);
	  system("cls");
	printf("Your account was created successfully!\n");
	return CORRECT;
}
int addUser(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char Data[4][LENGTHOFUSERNAMEANDPASS]) {
	for (int i = 0; i < NUMBEROFUSER; i++)
	{
		if (userData[i][checker][0] == 'e')
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < LENGTHOFUSERNAMEANDPASS; k++)
				{
					userData[i][j][k] = Data[j][k];
				}
			}
			userData[i][checker][0] = 'f';
			return CORRECT;
		}

	}
	return WRONG;
}
int checkPhoneFormat(char Data[LENGTHOFUSERNAMEANDPASS]) {
	if (strlen(Data) != PHONE_NUMBER_DIGIT || (int)Data[0] != 48) {
		return WRONG;
	}
	for (int i = 1; i < PHONE_NUMBER_DIGIT; i++)
	{
		if ((int)Data[i] < 48 || (int)Data[i] > 57) {
			return WRONG;
		}
	}
	return CORRECT;
}
int checkPassFormat(char Data[LENGTHOFUSERNAMEANDPASS]) {
	if (strlen(Data) < MIN_PASSWORD_NUMBER_DIGIT) {
		return WRONG;
	}
	return CORRECT;
}
int phoneNumberExist(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char Data[LENGTHOFUSERNAMEANDPASS]) {
	for (int i = 0; i < NUMBEROFUSER; i++)
	{
		if (equalString(userData[i][Phonenumber], Data, PHONE_NUMBER_DIGIT)) {
			return WRONG;
		}
	}
	return CORRECT;
}
int UsernameExist(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char Data[LENGTHOFUSERNAMEANDPASS]) {
	for (int i = 0; i < NUMBEROFUSER; i++)
	{
		if (equalString(userData[i][Username], Data, LENGTHOFUSERNAMEANDPASS)) {
			return WRONG;
		}
	}
	return CORRECT;
}
int equalString(char userData[LENGTHOFUSERNAMEANDPASS], char Data[LENGTHOFUSERNAMEANDPASS], int lenghtOfcheck) {
	for (int i = 0; i < lenghtOfcheck; i++)
	{
		if (userData[i] != Data[i]) {
			return WRONG;
		}
	}
	return CORRECT;

}
int checkInputType(int numberOfScanInScanf, char LastCharacterInInput) {
	if (numberOfScanInScanf == EMPTY || LastCharacterInInput != '\n')
	{
		  system("cls");
		printf("Wrong input format. Try again.\n");
		char buffer = 'b';
		while (buffer != '\n')
		{
			numberOfScanInScanf = scanf("%c", &buffer);
		}
		numberOfScanInScanf = CORRECT;
		LastCharacterInInput = '\n';
		return WRONG;
	}
	return CORRECT;
}
int nullchecker(char data[LENGTHOFUSERNAMEANDPASS]) {
	for (int i = 0; i < LENGTHOFUSERNAMEANDPASS; i++)
	{
		if (data[i] != EMPTY) {
			return CORRECT;
		}
	}
	return EMPTY;
}
int logIn(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char Data[4][LENGTHOFUSERNAMEANDPASS], char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES]) {
	char LastCharacterInInput = 'e';
	int flag = ACTIVE, Password = EMPTY, command = EMPTY, scanChecker = EMPTY;
	char inputData[4][LENGTHOFUSERNAMEANDPASS] = { EMPTY };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < LENGTHOFUSERNAMEANDPASS; j++)
		{
			inputData[i][j] = Data[i][j];

		}
	}
	while (flag)
	{
		if (!nullchecker(inputData[Username])) {
			printf("Please, Enter your Username:  ");
			scanChecker = scanf_s("%[^\n]", inputData[Username], LENGTHOFUSERNAMEANDPASS);
			clearbuffer();
			if (spaceChecker(inputData[Username])) {
				for (int i = 0; i < LENGTHOFUSERNAMEANDPASS; i++)
				{
					inputData[Username][i] = EMPTY;
				}
				continue;
			}
			if (!scanChecker) {
				system("cls");
				printf("Wrong username format. Try again\n");
				for (int i = 0; i < LENGTHOFUSERNAMEANDPASS; i++)
				{
					inputData[pass][i] = EMPTY;
				}
				scanChecker = CORRECT;
				continue;
			}

		}
		if (UsernameExist(userData, inputData[Username])) {
			system("cls");
			printf("Your Username doesn't exist\n");
			for (int i = 0; i < LENGTHOFUSERNAMEANDPASS; i++)
			{
				inputData[Username][i] = EMPTY;
			}
			continue;
		}
		if (!nullchecker(inputData[pass])) {
			printf("Please, Enter Password:  ");
			scanChecker = scanf_s("%[^\n]", inputData[pass], LENGTHOFUSERNAMEANDPASS);
			clearbuffer();
			if (spaceChecker(Data[pass])) {
				for (int i = 0; i < LENGTHOFUSERNAMEANDPASS; i++)
				{
					inputData[pass][i] = EMPTY;
				}
				scanChecker = CORRECT;
				continue;
			}
			if (!scanChecker) {
				system("cls");
				printf("Wrong password format. Try again\n");
				for (int i = 0; i < LENGTHOFUSERNAMEANDPASS; i++)
				{
					inputData[pass][i] = EMPTY;
				}
				scanChecker = CORRECT;
				continue;
			}
		}
		if (!checkPassword(userData, inputData[Username], inputData[pass]))
		{
			printf("Wrong password . Try again\n");

			for (int i = 0; i < LENGTHOFUSERNAMEANDPASS; i++)
			{
				inputData[pass][i] = EMPTY;
			}

			continue;
		}
		flag = UNACTIVE;
	}
	flag = ACTIVE;
	  system("cls");
	printf("Hi %s, What do you want to do?\n", inputData[Username]);
	while (flag)
	{
		printf("1.Send message\n2.Show messages\n3.Create channel\n4.Create group\n5.Log Out\n");
		scanChecker = scanf("%d%c", &command, &LastCharacterInInput);
		if (!checkInputType(scanChecker, LastCharacterInInput)) {
			clearbuffer();
			  system("cls");
			printf("wrong input\n");
			continue;
		}
		switch (command)
		{
		case 1:
			  system("cls");
			sendMassage(userData, massage, inputData[Username]);
			break;
		case 2:
			  system("cls");
			viewMassage(massage, inputData[Username]);
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
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < LENGTHOFUSERNAMEANDPASS; j++)
				{
					inputData[i][j] = EMPTY;
				}
			}
			flag = UNACTIVE;
			printf("You have successfully logged out!\n\n");
			break;
		default:
			  system("cls");
			printf("Your input is incorrect. Try again\n");
			break;
		}
	}
	return CORRECT;
}
int checkPassword(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char username[LENGTHOFUSERNAMEANDPASS], char password[LENGTHOFUSERNAMEANDPASS]) {
	for (int i = 0; i < NUMBEROFUSER; i++)
	{
		if (equalString(userData[i][Username], username, strlen(username)) && strlen(username) == strlen(userData[i][Username])) {
			if (equalString(password, userData[i][pass], strlen(password)) && strlen(password) == strlen(userData[i][pass])) {
				return CORRECT;
			}
		}
	}
	return WRONG;
}
int sendMassage(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS], char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFMASSAGES]) {
	char tempMassage[3][LENGTHOFMASSAGES] = { EMPTY };
	int scanChecker = EMPTY;
	system("cls");
	printf("Here are your messages:\n");
	while (CORRECT) {
		printf("Here are your Destination username:\n");
		scanf_s("%[^\n]", tempMassage[DESTINATIONUSERNAME], LENGTHOFMASSAGES);
		clearbuffer();
		if (spaceChecker(tempMassage[DESTINATIONUSERNAME])) {
			continue;
		}
		break;
	}


	if (!checkcapicity(massage, hostusername, tempMassage[2])) {
		system("cls");
		printf("The message capacity for this user is full\n");
		return WRONG;
	}
	if (UsernameExist(userData, tempMassage[2])) {
		 system("cls");
		printf("The username not exist!\n");
		return WRONG;
	}
	for (int i = 0; i < LENGTHOFMASSAGES; i++)
	{
		tempMassage[SOURCEUSERNAME][i] = hostusername[i];
	}
	printf("Wtite your massage:\n");
	scanChecker = scanf_s("%[^\n]", tempMassage[0], LENGTHOFUSERNAMEANDPASS);
	clearbuffer();
	if (!scanChecker) {
		system("cls");
		printf("Wrong phone number format. Try again\n");
		scanChecker = 1;
		return WRONG;
	}
	for (int i = 0; i < (NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE); i++)
	{
		if (massage[i][3][0] == 'e')
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < LENGTHOFUSERNAMEANDPASS; k++)
				{
					massage[i][j][k] = tempMassage[j][k];
				}
			}
			system("cls");
			printf("your massage has been sent\n");
			massage[i][3][0] = 'p';
			return CORRECT;
		}
	}

	return CORRECT;
}
int checkcapicity(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFUSERNAMEANDPASS], char destinationusername[LENGTHOFUSERNAMEANDPASS]) {
	int counter = EMPTY;
	for (int i = 0; i < NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE; i++)
	{
		if (equalString(massage[i][1], hostusername, strlen(massage[i][SOURCEUSERNAME])) && equalString(massage[i][2], destinationusername, strlen(massage[i][DESTINATIONUSERNAME]))) {
			counter++;
		}
	}
	if (counter >= NUMBEROFMASSAGE)
	{
		return WRONG;
	}
	return CORRECT;
}
int viewMassage(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFUSERNAMEANDPASS]) {
	int command = EMPTY, scanChecker = EMPTY, flag = CORRECT;
	char LastCharacterInInput = 'i';
	  system("cls");
	printf("Here are your messages:\n");
	while (flag) {
		printf("Enter 1 to see received messages and 2 to see sent messages: ");
		scanChecker = scanf_s("%d%c", &command, &LastCharacterInInput, LENGTHOFUSERNAMEANDPASS);
		if (!checkInputType(scanChecker, LastCharacterInInput)) {
			printf("wrong input\n");
			continue;
		}
		break;
	}
	switch (command)
	{
	case 1:
		viewreceivedmassage(massage, hostusername);
		break;
	case 2:
		viewsentmassage(massage, hostusername);
		break;
	default:
		  system("cls");
		printf("Wrong input please choose 1 or 2 \n");
		break;
	}

	return CORRECT;
}
int viewreceivedmassage(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFUSERNAMEANDPASS]) {
	int numberOfScanInScanf = EMPTY, show = EMPTY;
	char tempData[LENGTHOFUSERNAMEANDPASS] = "a", userName[LENGTHOFUSERNAMEANDPASS] = "a";
	  system("cls");
	while (CORRECT)
	{
		printf("Enter the source username:  ");
		scanf_s("%[^\n]", userName, LENGTHOFUSERNAMEANDPASS);
		clearbuffer();
		if (spaceChecker(userName)) {
			continue;
		}
		break;
	}

	for (int i = 0; i < (NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE); i++)
	{
		if (equalString(massage[i][DESTINATIONUSERNAME], hostusername, strlen(massage[i][DESTINATIONUSERNAME])) && equalString(massage[i][SOURCEUSERNAME], userName, strlen(massage[i][SOURCEUSERNAME]))) {
			printf("%s", massage[i][MASSAGETEXT]);
			show = CORRECT;
			printf("\n");

		}
	}
	if (!show) {
		printf("There is nothing to show\n");
	}
	return CORRECT;

}
int viewsentmassage(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES], char hostusername[LENGTHOFMASSAGES]) {
	int numberOfScanInScanf = EMPTY, show = EMPTY;
	char tempData[LENGTHOFUSERNAMEANDPASS] = "a", userName[LENGTHOFUSERNAMEANDPASS] = "a";
	  system("cls");
	while (CORRECT)
	{
		printf("Enter the destination username:  ");
		scanf_s("%[^\n]", userName, LENGTHOFUSERNAMEANDPASS);
		clearbuffer();
		if (spaceChecker(userName)) {
			continue;
		}
		break;
	}
	for (int i = 0; i < (NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE); i++)
	{
		if (equalString(massage[i][SOURCEUSERNAME], hostusername, strlen(massage[i][SOURCEUSERNAME])) && equalString(massage[i][DESTINATIONUSERNAME], userName, strlen(massage[i][DESTINATIONUSERNAME]))) {
			printf("%s", massage[i][MASSAGETEXT]);
			show = CORRECT;
			printf("\n");

		}
	}
	if (!show) {
		printf("There is nothing to show\n");
	}
	return CORRECT;

}
void initialzeArrayuserdata(char userData[NUMBEROFUSER][4][LENGTHOFUSERNAMEANDPASS]) {
	for (int i = 0; i < NUMBEROFUSER; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < LENGTHOFUSERNAMEANDPASS; j++)
			{
				userData[i][k][j] = 'a';
			}
		}
	}
	for (int i = 0; i < NUMBEROFUSER; i++)
	{
		userData[i][checker][0] = 'e';
	}
}
void initialzeArrayMassage(char massage[NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE][4][LENGTHOFMASSAGES]) {
	for (int i = 0; i < NUMBEROFUSER * NUMBEROFUSER * NUMBEROFMASSAGE; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int j = 0; j < LENGTHOFMASSAGES; j++)
			{
				massage[i][k][j] = 'a';
			}
		}
	}
	for (int i = 0; i < NUMBEROFUSER; i++)
	{
		massage[i][checker][0] = 'e';
	}
}

