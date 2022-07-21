#include"Define.h"
void getinfo(user* headuser) {
	user* tempdata = headuser;
	while (tempdata->Next != NULL) {
		printf("\t\tUser name:   %s\n\t\tPhone Number:    %s\n\t\tsignup Date:  %s\n\t\t................\n"
			, tempdata->Next->username, tempdata->Next->phonenumber, asctime(tempdata->Next->signInDate));
		tempdata = tempdata->Next;
	}
}
void showunseenMassage(massage* headmassage, char* source, user* headuser) {
	massage* temp = headmassage->Next;
	user* sourceuser, * loginuser = userExistByPhoneNumber(headuser, source);
	while (temp != NULL)
	{
		if (temp->seen == 0)
		{
			if (!strcmp(temp->destination, source)) {
				printf("\t\tUnread Massage:\n");
				break;
			}
		}
		temp = temp->Next;
	}
	while (temp != NULL)
	{
		if (temp->seen == 0)
		{
			sourceuser = userExistByPhoneNumber(headuser, temp->Source);
			if (!strcmp(temp->destination, source))
				printf("\t\tmassage from: %s\n\t\tmassage Date: %s\n", sourceuser->username, asctime(temp->postDate));
		}
		temp = temp->Next;
	}
	for (int i = 0; i < loginuser->numberOfgroupjoined; i++)
	{
		temp = headmassage->Next;
		while (temp != NULL)
		{
			if (temp->seen == 0)
			{
				sourceuser = userExistByPhoneNumber(headuser, temp->Source);
				if (!strcmp(temp->destination, loginuser->group[i]))
					printf("\t\tmassage group: %s\n\t\tfrom: %s\n\t\tmassage Date: %s\n", temp->destination, sourceuser->username, asctime(temp->postDate));
			}
			temp = temp->Next;
		}
	}
}
void aboutsomeone(user* headuser) {
	char* username = GetWord();
	user* temp = userExistByUsername(headuser, username);
	printf("\t\tUser name:   %s\n\t\tPhone Number:    %s\n\t\tSignup Date:  %s\n\t\t................\n", temp->username, temp->phonenumber, asctime(temp->signInDate));
}
int checkuserpassword(user* headuser, char* password, char* username) {
	user* temp = userExistByUsername(headuser, username);
	if (!strcmp(temp->password, password))
		return CORRECT;
	else
		return WRONG;
}
int sendMassage(user* headuser, group* headgroup, massage* headmassage, char* sourcephonenumber) {
	char* destination = GetWord();
	char* index = GetWord();
	int garbage = EMPTY;
	if (!userExistByUsername(headuser, destination) && !existUserGrouped(headuser, sourcephonenumber, destination)) {
		printf("\t\tyour destination not exist\n");
		return WRONG;
	}
	else if (userExistByUsername(headuser, destination)) {
		user* destinationdata = userExistByUsername(headuser, destination);
		if (destination == NULL || index == NULL)
			return WRONG;
		garbage = savemassage(headmassage, destinationdata->phonenumber, sourcephonenumber, index, TYPEPRIVATE);
	}
	else if (existUserGrouped(headuser, sourcephonenumber, destination))
		garbage = savemassage(headmassage, destination, sourcephonenumber, index, TYPEGROUP);
	return CORRECT;
}
int savemassage(massage* headmassage, char* destination, char* sourceUsername, char* index, int typeMassage) {
	massage* newmassage;
	while (!(newmassage = (massage*)malloc(sizeof(massage))));
	massageInitialize(newmassage);
	newmassage->destination = destination;
	newmassage->Source = sourceUsername;
	newmassage->massagetxt = index;
	newmassage->type = typeMassage;
	newmassage->seen = WRONG;
	time_t rawtime;
	time(&rawtime);
	newmassage->postDate = localtime(&rawtime);
	massage* temp = headmassage;
	while (temp->Next != NULL)
		temp = temp->Next;
	newmassage->uniqID = (temp->uniqID + 1);
	temp->Next = newmassage;
	printf("\t\tmassage successfully sent!\n");
	return CORRECT;
}
int showSentMassage(user* headuser, massage* headmassage, group* headgroup, char* sourcephonenumber) {
	char* destination = GetWord();
	int garbage = EMPTY;
	if (!userExistByUsername(headuser, destination) && !existUserGrouped(headuser, sourcephonenumber, destination)) {
		printf("\t\tyour destination not exist\n");
		return WRONG;
	}
	else if (userExistByUsername(headuser, destination))
		garbage = showprivatesentmassage(headuser, headmassage, sourcephonenumber, destination);
	else if (existUserGrouped(headuser, sourcephonenumber, destination))
		garbage = showgroupedsentmassage(headuser, headmassage, sourcephonenumber, destination);
	return CORRECT;
}
int existUserGrouped(user* headuser, char* sourcephonenumber, char* destination) {
	user* tempuser = userExistByPhoneNumber(headuser, sourcephonenumber);
	for (int i = 0; i < (tempuser->numberOfgroupjoined); i++)
	{
		if (!strcmp(destination, tempuser->group[i]))
			return CORRECT;
	}
	return WRONG;
}
int showgroupedsentmassage(user* headuser, massage* headmassage, char* sourcephonenumber, char* destination) {
	int show = WRONG;
	massage* temp = headmassage;
	user* sourceuser;
	while (temp != NULL)
	{
		sourceuser = userExistByPhoneNumber(headuser, sourcephonenumber);
		if (!strcmp(temp->destination, destination) && !strcmp(temp->Source, sourcephonenumber)) {
			if (temp->seen)
				printf("\t\tmassage to: %s\n\t\t%s\n\t\tin: %s\n\t\t..................\n", destination, temp->massagetxt, asctime(temp->postDate));
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRN);
				printf("\t\tmassage to: %s\n\t\t%s\n\t\tin: %s\n\t\t..................\n", destination, temp->massagetxt, asctime(temp->postDate));
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RESET);
			}
			show = CORRECT;
		}
		temp = temp->Next;
	}
	if (!show)
		printf("\t\tnothing for show\n");
	return CORRECT;

}
int showprivatesentmassage(user* headuser, massage* headmassage, char* sourcephonenumber, char* destination) {
	int show = WRONG;
	user* destinationdata = userExistByUsername(headuser, destination);
	massage* temp = headmassage;
	while (temp != NULL)
	{
		if (!strcmp(temp->destination, destinationdata->phonenumber) && !strcmp(temp->Source, sourcephonenumber)) {
			if (temp->seen)
				printf("\t\tto: %s\n\t\t%s\n\t\tin: %s\n\t\t..................\n", destination, temp->massagetxt, asctime(temp->postDate));
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRN);
				printf("\t\tto: %s\n\t\t%s\n\t\tin: %s\n\t\t..................\n", destination, temp->massagetxt, asctime(temp->postDate));
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RESET);
			}
			show = CORRECT;
		}
		temp = temp->Next;
	}
	if (!show)
		printf("\t\tnothing for show\n");
	return CORRECT;
}
int showRecivedMassage(user* headuser, group* headgroup, massage* headmassage, char* destinationphonenumber) {
	int show = WRONG, garbage = EMPTY;
	char* source = GetWord();
	if (!userExistByUsername(headuser, source) && !existUserGrouped(headuser, destinationphonenumber, source)) {
		printf("\t\tyour destination not exist\n");
		return WRONG;
	}
	else if (userExistByUsername(headuser, source))
		garbage = showprivateRecivedmassage(headuser, headmassage, source, destinationphonenumber);
	else if (existUserGrouped(headuser, destinationphonenumber, source))
		garbage = showgroupedRecivedmassage(headuser, headmassage, destinationphonenumber, source);
	return CORRECT;
}
int showprivateRecivedmassage(user* headuser, massage* headmassage, char* source, char* destination) {
	int show = WRONG;
	massage* temp = headmassage;
	user* sourcedata = userExistByUsername(headuser, source);
	while (temp != NULL)
	{
		if (!strcmp(temp->destination, destination) && !strcmp(temp->Source, sourcedata->phonenumber)) {
			printf("\t\tfrom: %s\n\t\t%s\n\t\tin: %s\n\t\t..................\n", source, temp->massagetxt, asctime(temp->postDate));
			temp->seen = CORRECT;
			show = CORRECT;
		}
		temp = temp->Next;
	}
	if (!show)
		printf("\t\tnothing for show\n");
	return CORRECT;

}
int showgroupedRecivedmassage(user* headuser, massage* headmassage, char* source, char* destination) {
	int show = WRONG;
	massage* temp = headmassage;
	user* sourceuser;
	while (temp != NULL)
	{
		if (!strcmp(temp->destination, destination)) {
			sourceuser = userExistByPhoneNumber(headuser, temp->Source);
			printf("\t\t%s\n\t\tmassage group: %s\n\t\tfrom: %s\n\t\tmassage Date: %s\t\t..................\n", temp->massagetxt, temp->destination, sourceuser->username, asctime(temp->postDate));
			temp->seen = CORRECT;
			show = CORRECT;
		}
		temp = temp->Next;
	}
	if (!show)
		printf("\t\tnothing for show\n");
	return CORRECT;
}
int edit_username(user* headuser, char* phonenumber) {
	char* newusername = GetWord();
	if (userExistByUsername(headuser, newusername)) {
		printf("\t\tUsername exist!\n");
		return WRONG;
	}
	user* temp = userExistByPhoneNumber(headuser, phonenumber);
	temp->username = newusername;
	printf("\t\tsuccsesfully changed!\n");
	return CORRECT;
}
int edit_pass(user* headuser, char* phonenumber) {
	char* newpass = GetWord();
	if (!checkPasswordformat(newpass)) {
		printf("\t\tWrong password format!\n");
		return WRONG;
	}
	user* temp = userExistByPhoneNumber(headuser, phonenumber);
	temp->password = newpass;
	printf("\t\tsuccsesfully changed!\n");
	return CORRECT;
}
int login(user* headuser, massage* headmassage, char** data, group* headgroup) {
	int flag = CORRECT, garbage = EMPTY;
	char* command, * USERname, * PASSword;
	if (data[USERNAME][0] == '\0' || data[PASSWORD][0] == '\0') {
		USERname = GetWord();
		PASSword = GetWord();
	}
	else
	{
		USERname = (char*)malloc(sizeof(data[USERNAME]));
		while (USERname == NULL)
			USERname = (char*)malloc(sizeof(data[USERNAME]));
		strcpy(USERname, data[USERNAME]);
		PASSword = (char*)malloc(sizeof(data[PASSWORD]));
		while (PASSword == NULL)
			PASSword = (char*)malloc(sizeof(data[PASSWORD]));
		strcpy(PASSword, data[PASSWORD]);
	}
	user* temp = (user*)malloc(sizeof(user));
	if (temp == NULL)
		temp = (user*)malloc(sizeof(user));
	if (!userExistByUsername(headuser, USERname)) {
		printf("\t\tthis username not exist!\n");
		return WRONG;
	}
	if (!checkuserpassword(headuser, PASSword, USERname))
	{
		printf("\t\tYour password is incorect!\n");
		return WRONG;
	}
	temp = userExistByUsername(headuser, USERname);
	printf("\t\thi %s;\n", temp->username);
	showunseenMassage(headmassage, temp->phonenumber, headuser);
	while (flag)
	{
		printf(">> ");
		command = GetWord();
		if (!strcmp(command, "send"))
			garbage = sendMassage(headuser, headgroup, headmassage, temp->phonenumber);
		else if (!strcmp(command, "show_sent"))
			garbage = showSentMassage(headuser, headmassage, headgroup, temp->phonenumber);
		else if (!strcmp(command, "show_recived"))
			garbage = showRecivedMassage(headuser, headgroup, headmassage, temp->phonenumber);
		else if (!strcmp(command, "about"))
			aboutsomeone(headuser);
		else if (!strcmp(command, "info"))
			getinfo(headuser);
		else if (!strcmp(command, "create_group"))
			garbage = createGroup(headgroup, temp->phonenumber, headuser);
		else if (!strcmp(command, "add_to"))
			garbage = add_to(headgroup, temp->phonenumber, headuser);
		else if (!strcmp(command, "edit_username"))
			garbage = edit_username(headuser, temp->phonenumber);
		else if (!strcmp(command, "edit_pass"))
			garbage = edit_pass(headuser, temp->phonenumber);

		else if (!strcmp(command, "logout")) {
			free(data[USERNAME]); data[USERNAME] = (char*)malloc(sizeof(char)); data[USERNAME][0] = '\0';
			free(data[PASSWORD]); data[PASSWORD] = (char*)malloc(sizeof(char)); data[PASSWORD][0] = '\0';
			printf("\t\tGood Bye,\n\t\tsuccessfully logged out\n");
			flag = WRONG;
		}
		else if (!strcmp(command, "close"))
			return 3;
		else
		{
			printf("\t\tyour input is incorrect!\n");
			clearbuffer();
		}
	}
	return CORRECT;
}