#include "Define.h"
int checkPhonenumberformat(char* phonenumber) {
	if (strlen(phonenumber) != PHONE_NUMBER_DIGIT || (int)phonenumber[0] != ASCIIZERO) {
		return WRONG;
	}
	for (int i = 1; i < PHONE_NUMBER_DIGIT; i++)
	{
		if ((int)phonenumber[i] < ASCIIZERO || (int)phonenumber[i] > ASCIININE) {
			return WRONG;
		}
	}
	return CORRECT;
}
int checkPasswordformat(char* password) {
	if (strlen(password) < MIN_PASSWORD_NUMBER_DIGIT) {
		return WRONG;
	}
	return CORRECT;
}
user* userExistByPhoneNumber(user* headuser, char* phonenumber) {
	user* temp = headuser->Next;
	while (temp != NULL)
	{
		if (!strcmp(temp->phonenumber, phonenumber))
			return temp;
		temp = temp->Next;
	}
	return WRONG;
}
user* userExistByUsername(user* headuser, char* username) {
	user* temp = headuser->Next;
	while (temp != NULL)
	{
		if (!strcmp(temp->username, username))
			return temp;
		temp = temp->Next;
	}
	return WRONG;
}
char* GetWord() {
	char character = getchar();
	char* newword = (char*)malloc(sizeof(char));
	int counter = EMPTY;
	while (character != '\n' && character != ' ')
	{
		newword[counter] = character;
		counter++;
		if (newword == NULL)
			while (!(newword = (char*)malloc((counter + 1) * sizeof(char))));
		else
			while (!(newword = (char*)realloc(newword, (counter + 1) * sizeof(char))));
		character = getchar();
	}
	newword[counter] = '\0';
	return newword;
}
void userInitialize(user* headuser) {
	headuser->group = (char**)malloc(sizeof(char*));
	headuser->password = (char*)malloc(sizeof(char));
	headuser->phonenumber = (char*)malloc(sizeof(char));
	headuser->username = (char*)malloc(sizeof(char));
	headuser->signInDate = (struct tm*)malloc(sizeof(struct tm));
	headuser->Next = NULL;
}
void massageInitialize(massage* newmassage) {
	newmassage->destination = (char*)malloc(sizeof(char));
	newmassage->massagetxt = (char*)malloc(sizeof(char));
	newmassage->Source = (char*)malloc(sizeof(char));
	newmassage->postDate = (struct tm*)malloc(sizeof(struct tm));
	newmassage->Next = NULL;
	newmassage->uniqID = 0;
}
void clearbuffer() {
	char trash = getchar();
	while (trash != '\n')
	{
		trash = getchar();
	}
}
void freeUser(user* headuser) {
	user* tempDelete;
	while (headuser != NULL)
	{
		tempDelete = headuser;
		headuser = headuser->Next;
		free(tempDelete);
	}
}
void freemassage(massage* headmassage) {
	massage* tempDelete;
	while (headmassage != NULL)
	{
		tempDelete = headmassage;
		headmassage = headmassage->Next;
		free(tempDelete);
	}
}
void freeGroup(group* headgroup) {
	group* tempDelete;
	while (headgroup != NULL)
	{
		tempDelete = headgroup;
		headgroup = headgroup->Next;
		free(tempDelete);
	}
}
void freeMemmory(user* headuser, massage* headmassage, group* headgroup) {
	freeUser(headuser);
	freemassage(headmassage);
	freeGroup(headgroup);
}