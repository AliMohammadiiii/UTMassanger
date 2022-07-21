#pragma once
struct UserData
{
	char* username;
	char* phonenumber;
	char* password;
	char** group;
	int numberOfgroupjoined;
	struct tm* signInDate;
	struct UserData* Next;
};
struct MassageData
{
	char* massagetxt;
	char* Source;
	char* destination;
	struct tm* postDate;
	unsigned int uniqID;
	unsigned int seen;/*1 for seen 0 for unseen*/
	int type;/*1 for Group and 2 for Private*/
	struct MassageData* Next;
};
struct GroupData
{
	char* groupName;
	char* adminUsername;
	struct GroupData* Next;
};
typedef struct UserData user;
typedef struct MassageData massage;
typedef struct GroupData group;
typedef struct tm timeStruct;