#include "user.h"

/**
 * 存放链表的表头
 */
static User* userLinkedHead = NULL;
/**
 * 存放当前记录的结构体地址
 */
static User* userCurrent = NULL;
/**
 * 存放前一条记录的结构体的地址
 */
static User* userPre = NULL;

void userDemo(void){
	/**
	 * 获取用户链表
	 */
	User* userLinked = getUserLinked("select * from user;");
	/**
	 * 打印用户链表
	 */
	printUserLinked(userLinked);
	/**
	 * 释放用户链表
	 */
	freeUserLinked(userLinked);
}

static int select_callback(void* data, int col_count, char** col_values, char** col_name){

	int i;
	userCurrent = calloc(1, sizeof(User));
	for (i = 0; i < col_count; i++) {
		if(strcmp(col_name[i], "id") == 0){
			strcpy(userCurrent->id, col_values[i]);
		}
		if(strcmp(col_name[i], "name") == 0){
			strcpy(userCurrent->name, col_values[i]);
		}
		if(strcmp(col_name[i], "password") == 0){
			strcpy(userCurrent->password, col_values[i]);
		}
		if(strcmp(col_name[i], "startTime") == 0){
			strcpy(userCurrent->startTime, col_values[i]);
		}
	}  
	userCurrent->next = NULL;

	if(userLinkedHead == NULL){
		userLinkedHead = userCurrent;
		userPre = userCurrent;
	}else{
		userPre->next = userCurrent;
		userPre = userCurrent;
	}
	userCurrent = NULL;

	return 0;  
}

void printUserLinked(User* userLinked){
	User* userCurrent = userLinked;
	while(userCurrent){
		printf("id = %s\n", userCurrent->id);
		printf("name = %s\n", userCurrent->name);
		printf("password = %s\n", userCurrent->password);
		printf("startTime = %s\n", userCurrent->startTime);
		userCurrent = userCurrent->next;
	}
}

void freeUserLinked(User* userLinked){
	User* freeCurrent = userLinked;
	User* freePre = userLinked;
	while(freeCurrent){
		freeCurrent = freePre->next;
		free(freePre);
		freePre = freeCurrent;
	}
	userLinkedHead = NULL;
}

User* getUserLinked(char* sql){

	sqlite3 *db;  
	sqlite3_open("./user.db", &db);

	sqlite3_exec(db, sql, select_callback, 0, NULL);  

	sqlite3_close(db);
	db = 0;

	return userLinkedHead;  
}

int updateUserDB(char* sql){

	sqlite3 *db;  
	sqlite3_open("./user.db", &db);

	sqlite3_exec(db, sql, NULL, NULL, NULL);  

	sqlite3_close(db);
	db = 0;

	return 0;  
}
