#pragma once
#include"Struct.h"
/*General Function*/
//Deletes information if there is information left in the buffer
void clearbuffer();
//take one word from console.
//output: one string(pointer).
char* GetWord();
//The new node of the massage list link prepares the information to be recorded.
//input: head of massage LinkedList.
void massageInitialize(massage* newmassage);
//The new node of the user list link prepares the information to be recorded.
//input: head of user LinkedList.
void userInitialize(user* headuser);
//This function checks if the mobile number format is correct?
//input: Phonenumber
//output: CORRECT Or WRONG
int checkPhonenumberformat(char* phonenumber);
//This function checks if the password format is correct?
//input: Password
//output: CORRECT or WRONG
int checkPasswordformat(char* password);
//This function checks if a mobile number is available? if exist return address of this house.
//input: Phonenumber and head of user linked list
//output: Address of Userdata or WRONG
user* userExistByPhoneNumber(user* headuser, char* phonenumber);
//This function checks if a Username is available? if exist return address of this house.
//input: Username and head of user linked list
//output: Address of Userdata or WRONG
user* userExistByUsername(user* headuser, char* username);
//Free Nodes in Linked List
//Note: This function affects group LinkedList (delete it)
//input: head of group linked list
void freeGroup(group* headgroup);
//Free Nodes in Linked List
//Note: This function affects massage LinkedList (delete it)
//input: head of massage linked list
void freemassage(massage* headmassage);
//Free Nodes in Linked List
//Note: This function affects group LinkedList (delete it)
//input: head of user linked list
void freeUser(user* headuser);
//Free Nodes in All Linked List. Call freeUser(), freemassage(), freeGroup().
//Note: This function affects group LinkedList (delete it)
//input: head of group linked list
void freeMemmory(user* headuser, massage* headmassage, group* headgroup);
/*signup*/
//input = new input data and head of user linkedList.
//Note: This function affects one LinkedList, UserData!
//Output = Returns CORRECT if the program is executed correctly.
int adduser(user* headuser, char** data);
//Receives the mobile phone numberand passwordand registers it if it is correct and not duplicate
//input = head of User LinkedList , input temp.
//Note: This function affects one LinkedList, UserData!
//Output = CORRECT and WRONG
int signup(user* headuser, char** inputtemp);
/*........................................*/
//Show username of All user registred.
//Accsess in any step!
//input: head of user LinkedList.
void getinfo(user* headuser);
//Show Username, PhoneNumber, signup date
//accsess If you have logged in.
//input: head of user LinkedList.
void aboutsomeone(user* headuser);
//show all new massage user have never seen
//input: head of user LinkedList, head of massage LinkedList, username loggedin user.
void showunseenMassage(massage* headmassage, char* source, user* headuser);
//check user password with input
//input: head of user LinkedList, username, password.
//output: CORRECT or WRONG
int checkuserpassword(user* headuser, char* password, char* username);
//send massage. Call function savemassage.
//input: head of user LinkedList, head of massage LinkedList, head of group LinkedList, Phonenumber loggedin user.
//Note: This function affects one LinkedList, MassageData!
//output: CORRECT or WRONG
int sendMassage(user* headuser, group* headgroup, massage* headmassage, char* sourcephonenumber);
//input: head of massage LinkedList, Phonenumber destination, Phonenumber source user, index, type of massage (private or Group).
//Note: This function affects one LinkedList, MassageData!
//output: CORRECT or WRONG
int savemassage(massage* headmassage, char* destination, char* sourceUsername, char* index, int typeMassage);
//Check that the group name is in the list of groups of people.
//input: head of user LinkedList, Phonenumber user has been loggedin, group destination.
//output: CORRECT or WRONG
int existUserGrouped(user* headuser, char* sourcephonenumber, char* destination);
//show all massage you sent in group 
//input: head of user LinkedList, head of massage LinkedList, Phonenumber user has been loggedin, group destination.
//output: CORRECT or WRONG
int showgroupedsentmassage(user* headuser, massage* headmassage, char* sourcephonenumber, char* destination);
//show all massage you sent to other user
//input: head of user LinkedList, head of massage LinkedList, Phonenumber user has been loggedin, destination.
//output: CORRECT or WRONG
int showprivatesentmassage(user* headuser, massage* headmassage, char* sourcephonenumber, char* destination);
//show all massage you sent. Call showgroupedsentmassage() or showprivatesentmassage()
//input: head of user LinkedList, head of massage LinkedList, Phonenumber user has been loggedin, destination.
//output: CORRECT or WRONG
int showSentMassage(user* headuser, massage* headmassage, group* headgroup, char* sourcephonenumber);
//show all massage you recived from other user
//input: head of user LinkedList, head of massage LinkedList, Phonenumber user has been loggedin, destination.
//output: CORRECT or 
int showprivateRecivedmassage(user* headuser, massage* headmassage, char* source, char* destination);
//show all massage you recived from group that you have been joint in
//input: head of user LinkedList, head of massage LinkedList, Phonenumber user has been loggedin, group destination.
//output: CORRECT or WRONG
int showgroupedRecivedmassage(user* headuser, massage* headmassage, char* source, char* destination);
//show all massage you have been Recived. Call showprivateRecivedmassage() or showgroupedRecivedmassage()
//input: head of user LinkedList, head of massage LinkedList, Phonenumber user has been loggedin, destination.
//output: CORRECT or WRONG
int showRecivedMassage(user* headuser, group* headgroup, massage* headmassage, char* destinationphonenumber);
//change username to new
//input: head of user LinkedList, phonenumber user has been loggedin
//output: CORRECT or WRONG
int edit_username(user* headuser, char* phonenumber);
//change password to new
//input: head of user LinkedList, phonenumber user has been loggedin
//output: CORRECT or WRONG
int edit_pass(user* headuser, char* phonenumber);
//First, it takes the usernameand password, and if it is correct, it enters the user's user panel
//input: temp UserName and password
//Note: This function affects three LinkedList, UserData, MassageData, GroupData!
//output: Correct , Wrong , CLOSEAPP
int login(user* headuser, massage* headmassage, char** data, group* headgroup);
/*SaveAndLoad*/
//save user data to Userdata.txt.
//input: head of user LinkedList
//output: CORRECT or WRONG
int saveUserData(user* headuser);
//save massage data to Massagedata.txt.
//input: head of massage LinkedList
//output: CORRECT or WRONG
int saveMassageData(massage* headmassage);
//save group data to Groupdata.txt.
//input: head of group LinkedList
//output: CORRECT or WRONG
int saveGroupData(group* headgroup);
//save All data. call saveMassageData(), saveUserData(), saveGroupData() 
//input: head of group LinkedList, head of massage LinkedList, head of user LinkedList
void SaveData(user* headuser, massage* headmassage, group* headgroup);
//take one word from file.
//input: FILE pointer
//output: one string(pointer).
char* GetWordFromFile(FILE* data);
//read user data from Userdata.txt. Call addUserFromLoad()
//Note: This function affects UserData LinkedList, UserData, MassageData, GroupData!
//input: head of user LinkedList
//output: CORRECT or WRONG
int loadUserData(user* headuser);
//read massage data from Massagedata.txt. Call addMassageFromLoad()
//Note: This function affects MassageData LinkedList
//input: head of massage LinkedList
//output: CORRECT or WRONG
int loadMassageData(massage* headmassage);
//read group data from GroupData.txt. Call addGroupDataFromLoad()
//Note: This function affects GroupData LinkedList
//input: head of group LinkedList
//output: CORRECT or WRONG
int loadGroupData(group* headgroup);
//Load All data. call loadUserData(), loadMassageData(), loadGroupData() 
//input: head of group LinkedList, head of massage LinkedList, head of user LinkedList
void LoadData(user* headuser, massage* headmassage, group* headgroup);
//add new user to user linked list
//Note: This function affects user LinkedList
//input: head of user LinkedList
//output: CORRECT or WRONG
int addUserFromLoad(user* headuser, user* newuserdata);
//add new massage to massage linked list
//Note: This function affects massage LinkedList
//input: head of massage LinkedList
//output: CORRECT or WRONG
int addMassageFromLoad(massage* headmassage, massage* newmassagedata);
//add new group to group linked list
//Note: This function affects group LinkedList
//input: head of group LinkedList
//output: CORRECT or WRONG
int addGroupDataFromLoad(group* headgroup, group* newgroupdata);
/*Group*/
//This function checks if a group is available? if exist return address of this house of group.
//input: groupname and head of group linked list
//output: Address of house group or WRONG
group* findGroupByName(group* headgroup, char* groupname);
//Create new group
//Note: This function affects group LinkedList
//input: phone number creator and head of group linked list and head of user linked list
//output: CORRECT or WRONG
int createGroup(group* headgroup, char* creator, user* headuser);
//add someone to group
//Note: This function affects group LinkedList
//input: phone number user Who we want added in and head of group linked list and head of user linked list
//output: CORRECT or WRONG
//Note: you must be admin
int add_to(group* headgroup, char* loginphonenumber, user* headuser);