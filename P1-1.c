#include <stdio.h>
#define PHONE_NUMBER_DIGIT 10
#define MAX_PASSWORD_NUMBER_DIGIT 6
#define ACTIVE 1
#define CORRECT 1
#define UNACTIVE 0
#define WRONG 0
#define EMPTY 0

#define UPPER_LIMIT_OF_MOBILE_PHONE_NUMBER 10000000000
#define LOWER_LIMIT_OF_MOBILE_PHONE_NUMBER 999999999

main() {
	/*These variables to check Input*/
	int numberOfScanInScanf;
	char LastCharacterInInput;


	/*User Data*/
	long long int user1 = EMPTY, user2 = EMPTY, user3 = EMPTY;
	int pas1=EMPTY, pas2=EMPTY, pas3=EMPTY;


	/*While Checker*/
	int flagmain = ACTIVE;


	printf("Welcome to UTMessenger.\n");


	while (flagmain)	{
		int  command, Capacity = EMPTY, phoneNumberExist = EMPTY;

		/*User temp*/
		long long int mobilePhoneLogin = EMPTY;
		int passwordLogin = EMPTY;

		printf("Please choose one of the following option:\n1 to SignUp\n2 to logIn\n3 to Quit:\n");

		/*Check the accuracy of the input*/
		numberOfScanInScanf = numberOfScanInScanf = scanf_s("%d%c", &command, &LastCharacterInInput);
		if (numberOfScanInScanf == 0 || LastCharacterInInput != '\n')
		{
			system("cls");
			printf("Wrong input format. Try again.\n");
			char buffer = 'b';
			while (buffer != '\n')
			{
				numberOfScanInScanf = scanf_s("%c", &buffer);
			}
		}


		switch (command)
		{
			/*SignUp*/
		case 1:
			system("cls");

			/*Check Capacity of USerNum*/
			if (user1 == EMPTY || user2 == EMPTY || user3 == EMPTY) {
				Capacity = CORRECT;
			}
			else
			{
				Capacity = WRONG;
			}

			if (Capacity) {
				/*Variable initialize*/
				long long int mobilePhoneNumber, checkPhoneFormat = EMPTY, correctPass=ACTIVE;
				int  passNumber=EMPTY, rePassNumber, flag = ACTIVE,flag2=UNACTIVE;

				printf("Hi, welcome.\n");

				/*Phone Number Check*/
				while (flag)
				{

					//get phone num
					printf("Please enter your mobile number:  ");
					/*Check the accuracy of the input*/
					numberOfScanInScanf = numberOfScanInScanf = scanf_s("%lld%c", &mobilePhoneNumber, &LastCharacterInInput);
					if (numberOfScanInScanf == 0 || LastCharacterInInput != '\n')
					{
						printf("Wrong input format. Try again.\n");
						char buffer = 'b';
						while (buffer != '\n')
						{
							numberOfScanInScanf = scanf_s("%c", &buffer);
						}
					}

					//check validity
					if (mobilePhoneNumber < LOWER_LIMIT_OF_MOBILE_PHONE_NUMBER || mobilePhoneNumber >= UPPER_LIMIT_OF_MOBILE_PHONE_NUMBER)
					{
						system("cls");
						printf("The entered phone number is not valid.\n");
						continue;
					}
					else
					{
						flag2 = 1;
						flag = 0;
					}
					/*Check Phone number exist*/
					
					
					
				}

				/*Check User Exist*/
				if (user1 == mobilePhoneNumber || user2 == mobilePhoneNumber || user3 == mobilePhoneNumber) {
					system("cls");
					printf("This phone number exist. Try again\n");
					mobilePhoneNumber = 0;
					break;
				}
				
				/*PassWord check*/
				while (flag2)
				{
					correctPass = ACTIVE;
					printf("Now Enter your Password(Your password should be just a number and a maximum of 6 digits):    ");
					/*Check the accuracy of the input*/
					numberOfScanInScanf = numberOfScanInScanf = scanf_s("%d%c", &passNumber, &LastCharacterInInput);
					if (numberOfScanInScanf == 0 || LastCharacterInInput != '\n')
					{
						system("cls");
						printf("Wrong input format. Try again.\n");
						correctPass = UNACTIVE;
						char buffer = 'b';
						while (buffer != '\n')
						{
							numberOfScanInScanf = scanf_s("%c", &buffer);
						}
					}
					/*variable initialize*/
					int countDigit = EMPTY,temp = passNumber;

					/*count number of password*/
					while (temp != 0)
					{
						temp /= 10;
						++countDigit;
					}

					/*Chck count of number of password is corroct or not*/
					if (countDigit > MAX_PASSWORD_NUMBER_DIGIT) {
						system("cls");
						printf("Your password is incorrect. Your password is more than 6 digits. Try Again\n");
						correctPass = UNACTIVE;
						continue;
					}
					if (correctPass) {
						printf("Now Renter your Password:  ");
					/*Check the accuracy of the input*/
					numberOfScanInScanf = numberOfScanInScanf = scanf_s("%d%c", &rePassNumber, &LastCharacterInInput);
					if (numberOfScanInScanf == 0 || LastCharacterInInput != '\n')
					{
						printf("Wrong input format. Try again.\n");
						char buffer = 'b';
						while (buffer != '\n')
						{
							numberOfScanInScanf = scanf_s("%c", &buffer);
						}
					}
					/*check password is match or not*/
					if (passNumber == rePassNumber) {
						flag2 = UNACTIVE;
					}
					else {
						system("cls");
						printf("The Password didn't Match\n");
					}
				}
				
					}
				/*Add User*/
				if (user1 == EMPTY) {
					user1 = mobilePhoneNumber;
					pas1 = passNumber;
				}
				else if (user2 == EMPTY) {
					user2 = mobilePhoneNumber;
					pas2 = passNumber;
				}
				else if (user3 == EMPTY) {
					user3 = mobilePhoneNumber;
					pas3 = passNumber;
				}
				system("cls");
				printf("Your account was created successfully!\n");

				/*initialize variable for Login*/
				mobilePhoneLogin = mobilePhoneNumber;
				passwordLogin = passNumber;
			}
			else
			{
				printf("No room to join our community :(\n");
				break;
			}

		case 2:
			system("cls");
			/*variable initialize*/
			int flag = ACTIVE,flag2 =UNACTIVE, Password=EMPTY, command;
			long long int usernamePhoneNumber = EMPTY;
			usernamePhoneNumber = mobilePhoneLogin;
			Password = passwordLogin;

			/*Login Step*/
			while (flag)
			{
				/*Enter Username*/
				if (usernamePhoneNumber == EMPTY) {
					printf("Please, Enter your phone number:  ");
					/*Check the accuracy of the input*/
					numberOfScanInScanf = numberOfScanInScanf = scanf_s("%lld%c", &usernamePhoneNumber, &LastCharacterInInput);
					if (numberOfScanInScanf == 0 || LastCharacterInInput != '\n')
					{
						printf("Wrong input format. Try again.\n");
						char buffer = 'b';
						while (buffer != '\n')
						{
							numberOfScanInScanf = scanf_s("%c", &buffer);
						}
					}
				}
				break;
			}
				/*Check Phone number Exist*/
				if (user1 == usernamePhoneNumber || user2 == usernamePhoneNumber || user3 == usernamePhoneNumber) {
					phoneNumberExist = CORRECT;
				}
				else {
					system("cls");
					printf("Your Phone number doesn't exist\n");
					break;
				}

				while (flag)
				{				
				if (Password == EMPTY) {
					printf("Please, Enter your Password:  ");
					/*Check the accuracy of the input*/
					numberOfScanInScanf = numberOfScanInScanf = scanf_s("%d%c", &Password, &LastCharacterInInput);
					if (numberOfScanInScanf == 0 || LastCharacterInInput != '\n')
					{
						printf("Wrong input format. Try again.\n");
						char buffer = 'b';
						while (buffer != '\n')
						{
							numberOfScanInScanf = scanf_s("%c", &buffer);
						}
					}
				}
				/*Check User Password*/
				if (user1 == usernamePhoneNumber) {
					if (pas1 == Password)
					{
						flag = UNACTIVE;
						flag2 = CORRECT;
					}
					else
					{
						Password = EMPTY;
						system("cls");
						printf("Your password is incorrect\n");
					}
				}
				else if (user2 == usernamePhoneNumber) {
					if (pas2 == Password)
					{
						flag = UNACTIVE;
						flag2 = CORRECT;
					}
					else
					{
						Password = EMPTY;
						system("cls");
						printf("Your password is incorrect\n");
					}
				}
				else if (user3 == usernamePhoneNumber) {
					if (pas3 == Password)
					{
						flag = UNACTIVE;
						flag2 = CORRECT;
					}
					else
					{
						Password = EMPTY;
						system("cls");
						printf("Your password is incorrect\n");
					}
				}
			}
				/*Welcome*/
			if (flag2) {
				system("cls");
				printf("Hi %lld, What do you want to do?\n", usernamePhoneNumber);
			}

			/*Command Step*/
			while (flag2)
			{
				printf("1.Send message\n2.Show messages\n3.Create channel\n4.Create group\n5.Log Out\n");
				/*Check the accuracy of the input*/
				numberOfScanInScanf = numberOfScanInScanf = scanf_s("%d%c", &command, &LastCharacterInInput);
				if (numberOfScanInScanf == 0 || LastCharacterInInput != '\n')
				{
					printf("Wrong input format. Try again.\n");
					char buffer = 'b';
					while (buffer != '\n')
					{
						numberOfScanInScanf = scanf_s("%c", &buffer);
					}
				}

				/*Command Work*/
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
					mobilePhoneLogin = EMPTY;
					passwordLogin = EMPTY;
					flag2 = UNACTIVE;
					printf("You have successfully logged out!\n\n");
					break;
				default:
					system("cls");
					printf("Your input is incorrect. Try again\n");
					break;
				}
			}
			break;
		case 3:
			system("cls");
			printf("I hope to see you again. Bye!");
			flagmain = UNACTIVE;
			break;
		default:
			system("cls");
			printf("Your input is incorrect. Try again!\n");
			break;
		}
	}
}