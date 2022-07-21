#include "Define.h"
group* findGroupByName(group* headgroup, char* groupname) {
	group* groupneed = (group*)malloc(sizeof(group));
	group* temp = headgroup->Next;
	while (temp != NULL)
	{
		if (!strcmp(temp->groupName, groupname)) {
			return temp;
		}
		temp = temp->Next;
	}
	printf("\t\tGroup Not Found!\n");
	return NULL;
}
int createGroup(group* headgroup, char* creator, user* headuser) {
	user* creatorgroup = userExistByPhoneNumber(headuser, creator);
	char* groupname = GetWord();
	int numberofgroupcreatorjoinedin = creatorgroup->numberOfgroupjoined;
	group* newgroup = (group*)malloc(sizeof(group));
	group* temp = headgroup;

	while (newgroup == NULL)
		newgroup = (group*)malloc(sizeof(group));
	if (creatorgroup->group)
		while (!(creatorgroup->group = (char**)realloc(creatorgroup->group, (creatorgroup->numberOfgroupjoined + 1) * sizeof(char*))));
	else
		while (!(creatorgroup->group = (char**)malloc((creatorgroup->numberOfgroupjoined + 1) * sizeof(char*))));
	while (CORRECT) {
		creatorgroup->group[numberofgroupcreatorjoinedin] = (char*)malloc(sizeof(groupname));
		if (creatorgroup->group[numberofgroupcreatorjoinedin]) strcpy(creatorgroup->group[numberofgroupcreatorjoinedin], groupname);
		else continue;
		break;
	}
	creatorgroup->numberOfgroupjoined++;
	newgroup->adminUsername = (char*)malloc(sizeof(creator));
	while (newgroup->adminUsername == NULL)
		newgroup->adminUsername = (char*)malloc(sizeof(creator));
	strcpy(newgroup->adminUsername, creator);
	newgroup->groupName = (char*)malloc(sizeof(groupname));
	while (newgroup->groupName == NULL)
		newgroup->groupName = (char*)malloc(sizeof(groupname));
	strcpy(newgroup->groupName, groupname);
	newgroup->Next = NULL;
	while (temp->Next != NULL)
		temp = temp->Next;
	temp->Next = newgroup;
	printf("\t\tNew Group created!\n");
	return CORRECT;
}
int add_to(group* headgroup, char* loginphonenumber, user* headuser) {
	char* groupname = GetWord();
	char* username = GetWord();
	group* groupneed = findGroupByName(headgroup, groupname);
	if (groupneed == NULL)
		return WRONG;
	user* wanttoadd = userExistByUsername(headuser, username);
	if (strcmp(groupneed->adminUsername, loginphonenumber))
	{
		printf("\t\tYou haven't access!\n");
		return WRONG;
	}
	for (int i = 0; i < (wanttoadd->numberOfgroupjoined); i++)
	{
		if (!strcmp(wanttoadd->group[i], groupname))
		{
			printf("\t\tuser has been joint now!\n");
			return WRONG;
		}
	}

	if (wanttoadd->group)
		while (!(wanttoadd->group = (char**)realloc(wanttoadd->group, (wanttoadd->numberOfgroupjoined + 1) * sizeof(char*))));
	else
		while (!(wanttoadd->group = (char**)malloc((wanttoadd->numberOfgroupjoined + 1) * sizeof(char*))));
	wanttoadd->group[wanttoadd->numberOfgroupjoined] = groupname;
	wanttoadd->numberOfgroupjoined++;
	printf("\t\tnew member added to group!\n");
	return CORRECT;
}
