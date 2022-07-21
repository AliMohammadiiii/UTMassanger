#include "Define.h"
main() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RESET);
	int flag = CORRECT, loginfeedback = WRONG;
	char* command;
	char** inputtemp = (char**)malloc(2 * sizeof(char*));//Create 2d arrey to save temp on
	while (!(inputtemp[USERNAME] = (char*)malloc(sizeof(char)))); inputtemp[USERNAME][0] = NULL;//Initialize Username in 2d arrey inputtemp
	while (!(inputtemp[PASSWORD] = (char*)malloc(sizeof(char)))); inputtemp[PASSWORD][0] = NULL;//Initialize Password in 2d arrey inputtemp
	while (!(inputtemp[PHONENUMBER] = (char*)malloc(sizeof(char)))); inputtemp[PHONENUMBER][0] = NULL;//Initialize Password in 2d arrey inputtemp
	user* headuser = (user*)malloc(sizeof(user));	userInitialize(headuser);//Create head of User LinkedList And initialize it.
	massage* headmassage = (massage*)malloc(sizeof(massage)); massageInitialize(headmassage); //Create head of Massage LinkedList And initialize it.
	group* headgroup = (group*)malloc(sizeof(group)); headgroup->Next = NULL; //Create head of Group LinkedList And initialize it. 
	LoadData(headuser, headmassage, headgroup);//Load All Data from File. this Function Call LoadUserdata() , loadMassageData() And loadGroupData(). And saves the data in linkedList
	printf("Welcome to UT Massenger\nPlease Ente your command\n.............................................\n");
	while (flag)
	{
		printf(">> ");
		command = GetWord();//Get First Word from Console. It then checks which command it is.
		if (!strcmp(command, "signup")) {
			signup(headuser, inputtemp) ? (loginfeedback = login(headuser, headmassage, inputtemp, headgroup), printf("\t\tDone!\n")) : printf("\t\tFailed!\n");
			if (loginfeedback == CLOSEAPP)//If the user writes to close the program return CLOASEAPP and The program ends.
				flag = WRONG;
		}
		else if (!strcmp(command, "login")) {
			loginfeedback = login(headuser, headmassage, inputtemp, headgroup);
			if (loginfeedback == CLOSEAPP)//If the user writes to close the program return CLOASEAPP and The program ends.
				flag = WRONG;
			else if (loginfeedback == WRONG)
				printf("\t\tFailed!\n");

		}
		else if (!strcmp(command, "close")) {
			printf("\t\tclosing...\n");
			flag = WRONG;
		}
		else if (!strcmp(command, "info"))
			getinfo(headuser);
		else
		{
			printf("\t\tyour input is incorrect!\n");
			clearbuffer();
		}

	}
	SaveData(headuser, headmassage, headgroup);//Save All Data from LinkedList. this Function Call saveUserData() , saveMassageData() And saveGroupData(). And read the data from linkedList
	freeMemmory(headuser, headmassage, headgroup);//Free All LinkedList
	return 0;
}