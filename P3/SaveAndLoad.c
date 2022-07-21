#include"Define.h"
int saveUserData(user* headuser) {
	FILE* checkexist = fopen(ADDRESSFILEUSERDATA, "r");
	if (checkexist != NULL)
	{
		fclose(checkexist);
		remove(ADDRESSFILEUSERDATA);
	}
	FILE* data = fopen(ADDRESSFILEUSERDATA, "w+");
	user* tempdata = headuser->Next;
	while (tempdata != NULL)
	{
		fprintf(data, "%s %s %s %d %d %d %d %d %d %d %d %d %d ",
			tempdata->username, tempdata->phonenumber, tempdata->password, tempdata->numberOfgroupjoined,
			tempdata->signInDate->tm_sec, tempdata->signInDate->tm_min, tempdata->signInDate->tm_hour, tempdata->signInDate->tm_mday, tempdata->signInDate->tm_mon, tempdata->signInDate->tm_year, tempdata->signInDate->tm_wday, tempdata->signInDate->tm_yday, tempdata->signInDate->tm_isdst);
		for (int i = 0; i < tempdata->numberOfgroupjoined; i++)
		{
			fprintf(data, "%s ", tempdata->group[i]);
		}
		tempdata = tempdata->Next;
	}
	fprintf(data, ENDOFFILEUSERDATA);
	fprintf(data, " ");
	fclose(data);
	return CORRECT;
}
int saveMassageData(massage* headmassage) {
	FILE* checkexist = fopen(ADDRESSFILEMASSAGEDATA, "r");
	if (checkexist != NULL)
	{
		fclose(checkexist);
		remove(ADDRESSFILEMASSAGEDATA);
	}
	FILE* massagedata = fopen(ADDRESSFILEMASSAGEDATA, "w+");
	massage* tempdata = headmassage->Next;
	while (tempdata != NULL)
	{
		fprintf(massagedata, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d ",
			tempdata->massagetxt, tempdata->Source, tempdata->destination, tempdata->type, tempdata->uniqID, tempdata->seen,
			tempdata->postDate->tm_sec, tempdata->postDate->tm_min, tempdata->postDate->tm_hour, tempdata->postDate->tm_mday, tempdata->postDate->tm_mon, tempdata->postDate->tm_year, tempdata->postDate->tm_wday, tempdata->postDate->tm_yday, tempdata->postDate->tm_isdst);
		tempdata = tempdata->Next;
	}
	fprintf(massagedata, ENDOFFILEMASSAGEDATA);
	fprintf(massagedata, " ");
	fclose(massagedata);
	return CORRECT;
}
int saveGroupData(group* headgroup) {
	FILE* checkexist = fopen(ADDRESSFILEGROUPDATA, "r");
	if (checkexist != NULL)
	{
		fclose(checkexist);
		remove(ADDRESSFILEGROUPDATA);
	}
	FILE* groupdata = fopen(ADDRESSFILEGROUPDATA, "w+");
	group* tempdata = headgroup->Next;
	while (tempdata != NULL)
	{
		fprintf(groupdata, "%s %s ", tempdata->adminUsername, tempdata->groupName);
		tempdata = tempdata->Next;
	}
	fprintf(groupdata, ENDOFFILEGROUPDATA);
	fprintf(groupdata, " ");
	fclose(groupdata);
	return CORRECT;
}
char* GetWordFromFile(FILE* data) {
	int counter = EMPTY;
	char character = fgetc(data);
	char* newwordforfile = realloc(NULL, (counter + 1) * sizeof(char));
	while (newwordforfile == NULL)
		newwordforfile = realloc(NULL, (counter + 1) * sizeof(char));
	while (character != '\n' && character != ' ')
	{
		newwordforfile[counter] = character;
		counter++;
		if (newwordforfile == NULL)
			while (!(newwordforfile = (char*)malloc((counter + 1) * sizeof(char))));
		else
			while (!(newwordforfile = (char*)realloc(newwordforfile, (counter + 1) * sizeof(char))));
		character = fgetc(data);
	}
	newwordforfile[counter] = '\0';
	return newwordforfile;
}
int loadUserData(user* headuser) {
	int garbage = EMPTY;
	FILE* data = fopen(ADDRESSFILEUSERDATA, "r");
	if (data == NULL)
		return WRONG;
	user* userdata = (user*)malloc(sizeof(user));
	userInitialize(userdata);
	int i = EMPTY;
	while (!(userdata->signInDate = (struct tm*)malloc(sizeof(struct tm))));
	while (userdata->signInDate == NULL)
		userdata->signInDate = (struct tm*)malloc(sizeof(struct tm));
	userdata->username = GetWordFromFile(data);
	while (strcmp(userdata->username, ENDOFFILEUSERDATA))
	{
		userdata->phonenumber = GetWordFromFile(data);
		userdata->password = GetWordFromFile(data);
		userdata->numberOfgroupjoined = atoi(GetWordFromFile(data));
		while (!(userdata->group = (char**)malloc(userdata->numberOfgroupjoined * sizeof(char*))));
		userdata->signInDate->tm_sec = atoi(GetWordFromFile(data));
		userdata->signInDate->tm_min = atoi(GetWordFromFile(data));
		userdata->signInDate->tm_hour = atoi(GetWordFromFile(data));
		userdata->signInDate->tm_mday = atoi(GetWordFromFile(data));
		userdata->signInDate->tm_mon = atoi(GetWordFromFile(data));
		userdata->signInDate->tm_year = atoi(GetWordFromFile(data));
		userdata->signInDate->tm_wday = atoi(GetWordFromFile(data));
		userdata->signInDate->tm_yday = atoi(GetWordFromFile(data));
		userdata->signInDate->tm_isdst = atoi(GetWordFromFile(data));
		for (int i = 0; i < userdata->numberOfgroupjoined; i++)
		{
			userdata->group[i] = GetWordFromFile(data);
		}
		garbage = addUserFromLoad(headuser, userdata);
		userdata->username = GetWordFromFile(data);
	}
	fclose(data);
	return CORRECT;
}
int loadMassageData(massage* headmassage) {
	int garbage = EMPTY;
	FILE* data = fopen(ADDRESSFILEMASSAGEDATA, "r");
	if (data == NULL)
		return WRONG;
	massage* massagedata = (massage*)malloc(sizeof(massage));
	massageInitialize(massagedata);
	int i = EMPTY;
	while (!(massagedata->postDate = (struct tm*)malloc(sizeof(struct tm))));
	massagedata->massagetxt = GetWordFromFile(data);
	while (strcmp(massagedata->massagetxt, ENDOFFILEMASSAGEDATA))
	{
		massagedata->Source = GetWordFromFile(data);
		massagedata->destination = GetWordFromFile(data);
		massagedata->type = atoi(GetWordFromFile(data));
		massagedata->uniqID = atoi(GetWordFromFile(data));
		massagedata->seen = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_sec = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_min = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_hour = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_mday = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_mon = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_year = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_wday = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_yday = atoi(GetWordFromFile(data));
		massagedata->postDate->tm_isdst = atoi(GetWordFromFile(data));
		garbage = addMassageFromLoad(headmassage, massagedata);
		massagedata->massagetxt = GetWordFromFile(data);
	}
	fclose(data);
	return CORRECT;
}
int loadGroupData(group* headgroup) {
	int garbage = EMPTY;
	FILE* data = fopen(ADDRESSFILEGROUPDATA, "r");
	if (data == NULL)
		return WRONG;
	group* groupdata;
	int i = EMPTY;
	while (!(groupdata = (group*)malloc(sizeof(group))));
	groupdata->adminUsername = GetWordFromFile(data);
	while (strcmp(groupdata->adminUsername, ENDOFFILEGROUPDATA))
	{
		groupdata->groupName = GetWordFromFile(data);
		garbage = addGroupDataFromLoad(headgroup, groupdata);
		groupdata->adminUsername = GetWordFromFile(data);
	}
	fclose(data);
	return CORRECT;
}
int addUserFromLoad(user* headuser, user* newuserdata) {
	user* temp = headuser;
	user* newUser = (user*)malloc(sizeof(user));
	while (newUser == NULL)
		newUser = (user*)malloc(sizeof(user));
	userInitialize(newUser);
	while (!(newUser->username = (char*)malloc(sizeof(newuserdata->username))));
	strcpy(newUser->username, newuserdata->username);
	while (!(newUser->password = (char*)malloc(sizeof(newuserdata->password))));
	strcpy(newUser->password, newuserdata->password);
	while (!(newUser->phonenumber = (char*)malloc(sizeof(newuserdata->phonenumber))));
	strcpy(newUser->phonenumber, newuserdata->phonenumber);
	newUser->numberOfgroupjoined = newuserdata->numberOfgroupjoined;
	while (!(newUser->group = (char**)malloc(newUser->numberOfgroupjoined * sizeof(char*))));
	for (int i = 0; i < newuserdata->numberOfgroupjoined; i++)
	{
		newUser->group[i] = newuserdata->group[i];
	}
	while (!(newUser->signInDate = (struct tm*)malloc(sizeof(struct tm))));
	newUser->signInDate->tm_sec = newuserdata->signInDate->tm_sec;
	newUser->signInDate->tm_min = newuserdata->signInDate->tm_min;
	newUser->signInDate->tm_hour = newuserdata->signInDate->tm_hour;
	newUser->signInDate->tm_mday = newuserdata->signInDate->tm_mday;
	newUser->signInDate->tm_mon = newuserdata->signInDate->tm_mon;
	newUser->signInDate->tm_year = newuserdata->signInDate->tm_year;
	newUser->signInDate->tm_wday = newuserdata->signInDate->tm_wday;
	newUser->signInDate->tm_yday = newuserdata->signInDate->tm_yday;
	newUser->signInDate->tm_isdst = newuserdata->signInDate->tm_isdst;
	while (temp->Next != NULL)
		temp = temp->Next;
	temp->Next = newUser;
	return CORRECT;
}
int addMassageFromLoad(massage* headmassage, massage* newmassagedata) {
	massage* temp = headmassage, * newUser = (massage*)malloc(sizeof(massage));
	while (newUser == NULL)
		newUser = (massage*)malloc(sizeof(massage));
	massageInitialize(newUser);
	while (CORRECT) {
		newUser->massagetxt = (char*)malloc(sizeof(newmassagedata->massagetxt));
		if (newUser->massagetxt) strcpy(newUser->massagetxt, newmassagedata->massagetxt);
		else continue;
		break;
	}
	while (CORRECT) {
		newUser->Source = (char*)malloc(sizeof(newmassagedata->Source));
		if (newUser->Source) strcpy(newUser->Source, newmassagedata->Source);
		else continue;
		break;
	}
	while (CORRECT) {
		newUser->destination = (char*)malloc(sizeof(newmassagedata->destination));
		if (newUser->destination) strcpy(newUser->destination, newmassagedata->destination);
		else continue;
		break;
	}
	newUser->type = newmassagedata->type;
	newUser->uniqID = newmassagedata->uniqID;
	newUser->seen = newmassagedata->seen;
	while (!(newUser->postDate = (struct tm*)malloc(sizeof(struct tm))));
	newUser->postDate->tm_sec = newmassagedata->postDate->tm_sec;
	newUser->postDate->tm_min = newmassagedata->postDate->tm_min;
	newUser->postDate->tm_hour = newmassagedata->postDate->tm_hour;
	newUser->postDate->tm_mday = newmassagedata->postDate->tm_mday;
	newUser->postDate->tm_mon = newmassagedata->postDate->tm_mon;
	newUser->postDate->tm_year = newmassagedata->postDate->tm_year;
	newUser->postDate->tm_wday = newmassagedata->postDate->tm_wday;
	newUser->postDate->tm_yday = newmassagedata->postDate->tm_yday;
	newUser->postDate->tm_isdst = newmassagedata->postDate->tm_isdst;
	while (temp->Next != NULL)
		temp = temp->Next;
	temp->Next = newUser;
	return CORRECT;
}
int addGroupDataFromLoad(group* headgroup, group* newgroupdata) {
	group* temp = headgroup;
	group* newUser = (group*)malloc(sizeof(group));
	while (newUser == NULL)
		newUser = (group*)malloc(sizeof(group));
	while (CORRECT) {
		newUser->adminUsername = (char*)malloc(sizeof(newgroupdata->adminUsername));
		if (newUser->adminUsername) strcpy(newUser->adminUsername, newgroupdata->adminUsername);
		else continue;
		break;
	}
	while (CORRECT) {
		newUser->groupName = (char*)malloc(sizeof(newgroupdata->groupName));
		if (newUser->groupName) strcpy(newUser->groupName, newgroupdata->groupName);
		else continue;
		break;
	}
	newUser->Next = NULL;
	while (temp->Next != NULL)
		temp = temp->Next;
	temp->Next = newUser;
	return CORRECT;
}
void LoadData(user* headuser, massage* headmassage, group* headgroup) {
	loadUserData(headuser);
	loadMassageData(headmassage);
	loadGroupData(headgroup);
}
void SaveData(user* headuser, massage* headmassage, group* headgroup) {
	saveUserData(headuser);
	saveMassageData(headmassage);
	saveGroupData(headgroup);
}