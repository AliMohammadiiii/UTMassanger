#include"Define.h"
int signup(user* headuser, char** inputtemp) {
	int garbage = EMPTY;
	char** input = (char**)malloc(NUMBEROFINPUTINSIGNUP * sizeof(char*));
	for (int i = 0; i < NUMBEROFINPUTINSIGNUP; i++)
	{
		input[i] = GetWord();
	}
	if (!checkPhonenumberformat(input[PHONENUMBER])) {
		printf("\t\tWrong input (maybe Wrong phone number format!)\n");
		return WRONG;
	}
	if (userExistByPhoneNumber(headuser, input[PHONENUMBER])) {
		printf("\t\tPhone number exist!\n");
		return WRONG;
	}
	if (!checkPasswordformat(input[PASSWORD])) {
		printf("\t\tWrong input (maybe Wrong password format!)\n");
		return WRONG;
	}
	if (userExistByUsername(headuser, input[USERNAME])) {
		printf("\t\tUsername exist!\n");
		return WRONG;
	}


	if (inputtemp[USERNAME] == NULL)
		while (!(inputtemp[USERNAME] = (char*)malloc(sizeof(input[USERNAME]))));
	else
		while (!(inputtemp[USERNAME] = (char*)realloc(inputtemp[USERNAME], sizeof(input[USERNAME]))));
	strcpy(inputtemp[USERNAME], input[USERNAME]);
	free(input[USERNAME]);


	if (inputtemp[PASSWORD] == NULL)
		while (!(inputtemp[PASSWORD] = (char*)malloc(sizeof(input[PASSWORD]))));
	else
		while (!(inputtemp[PASSWORD] = (char*)realloc(inputtemp[PASSWORD], sizeof(input[PASSWORD]))));
	strcpy(inputtemp[PASSWORD], input[PASSWORD]);
	free(input[PASSWORD]);

	if (inputtemp[PHONENUMBER] == NULL)
		while (!(inputtemp[PHONENUMBER] = (char*)malloc(sizeof(input[PHONENUMBER]))));
	else
		while (!(inputtemp[PHONENUMBER] = (char*)realloc(inputtemp[PHONENUMBER], sizeof(input[PHONENUMBER]))));
	strcpy(inputtemp[PHONENUMBER], input[PHONENUMBER]);
	free(input[PHONENUMBER]);

	garbage = adduser(headuser, inputtemp);
	printf("\t\tsuccessfully registered\n");
	return CORRECT;
}
int adduser(user* headuser, char** data) {
	user* temp = headuser, * newUser = (user*)malloc(sizeof(user));
	while (newUser == NULL) newUser = (user*)malloc(sizeof(user));
	userInitialize(newUser);
	time_t rawtime;
	time(&rawtime);
	newUser->signInDate = localtime(&rawtime);
	while (CORRECT) {
		newUser->username = (char*)realloc(newUser->username, sizeof(data[USERNAME]));
		if (newUser->username) strcpy(newUser->username, data[USERNAME]);
		else continue;
		break;
	}
	while (CORRECT) {
		newUser->password = (char*)realloc(newUser->password, sizeof(data[PASSWORD]));
		if (newUser->password) strcpy(newUser->password, data[PASSWORD]);
		else continue;
		break;
	}
	while (CORRECT) {
		newUser->phonenumber = (char*)realloc(newUser->phonenumber, sizeof(data[PHONENUMBER]));
		if (newUser->phonenumber) strcpy(newUser->phonenumber, data[PHONENUMBER]);
		else continue;
		break;
	}
	newUser->numberOfgroupjoined = EMPTY;
	newUser->group = (char**)realloc(newUser->group, sizeof(char*));
	while (temp->Next != NULL) temp = temp->Next;
	temp->Next = newUser;
	return CORRECT;
}