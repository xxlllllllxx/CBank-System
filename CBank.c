//Project in Computer Programming
//Bank Management

//Lewis Masallo - 12341234
//Johnlenard Bajao - 1234
//Bles Ann Horario - 1111111111
//Joana Sabas - 2222222222
//Richlan Solares - 0987654321

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define X 10
#define STR 11
//X for How many Accounts the database can handle
//STR for How many letters are ther in username and password

//--------------------------D1----------------------------,
//D1 Handles Variables and Structures
typedef struct{
	int num;
	char username[STR];
	char password[STR];
	float balance;
}acc;
acc temp, hold, clean = {};

//Database: Accounts
acc buffer[X];

//Database: Logs
float current_date;
float logs[X][5];

//File: Receipt: 
float withdrawn = 0;
float deposited = 0;
float sent = 0;
float loaned = 0;
float payed = 0;
float invested = 0;
float gained = 0;

//Others:
int counter;
float bank_Balance = 1000000;
int dtb = 1;

void database(int x);
char *encrypt(char *x);
char  *decrypt(char *x);
char *fill(char *x);
void hidden();
//--------------------------D1----------------------------'


//--------------------------A1----------------------------,
//A1 Handles Input and Output
void firstpage();
void display(int x);
int take(int x);
void secondpage();
//--------------------------A1----------------------------'


//--------------------------B1----------------------------,
//B1 Handles Logical Switches and Scanning Database
int logic(char x);
int check(int x);
int logic2(char x);
//--------------------------B1----------------------------'


//--------------------------C1----------------------------,
//C1 Handles Functions
void login();
void create();
void noAcc();
void profile();
void withdraw();
void deposit();
void send();
void loan();
void invest();
void receipt();
//--------------------------C1----------------------------'


//------------------------MAIN-------------------------
//Main loops first page and second page
int main(int x){
	int a = 0;
	if(dtb == 1) database(1);
	dtb++;
	if(x == 0 || x == 1){
		do{
			if(a == 1) display(1);
			firstpage();
			a = take(1);
			if(a == 2) return 0;
		}
		while(a == 1);
	}	
	a = 0;
	if(x == 0 || x == 1|| x == 2){
		do{
				if(a == 1) display(1);
				secondpage();
				a = take(5);
				if(a == 2) {
					hold = clean;
					counter = 0;
					system("cls");
					main(1);
				}
		}
		while(a == 1);
	}
	return 0;
}
//------------------------MAIN-------------------------'


//--------------------------D1----------------------------,
//For Saving and Scanning The file for Database
void database(int x){
	FILE *fptr;
	switch(x){
		case 1: 
					fptr = fopen("DATABASE.txt", "r");
					fscanf(fptr, " %f\n", &current_date);
					for(int i = 0; i < X; i++){
						fscanf(fptr, " %d", &buffer[i].num);
						if(buffer[i].num != 0){
							fscanf(fptr, " %s %s %f", buffer[i].username, buffer[i].password, &buffer[i].balance);
							fscanf(fptr, " %f %f %f %f %f", &logs[i][0], &logs[i][1], &logs[i][2], &logs[i][3], &logs[i][4]);
						}
						else{
							buffer[i] = clean;
						}
					}
					fclose(fptr);
					break;
		case 2: 
					fptr = fopen("DATABASE.txt", "w");
					fprintf(fptr, " %.0f\n", current_date);
					for(int i = 0; i < X; i++){
						if(buffer[i].num == 0 || buffer[i].num == NULL){
							fprintf(fptr, "0\n");
						}
						else{
							fprintf(fptr, "%d %s %s %.2f %.0f %.0f %.2f %.0f %.2f\n", buffer[i].num, buffer[i].username, buffer[i].password, buffer[i].balance, logs[i][0], logs[i][1], logs[i][2], logs[i][3], logs[i][4]);
						}
					}
					fclose(fptr);
					break;
	}
}

//Encrypts the letters of the x by first letter b :: a
char *encrypt(char *x){
	for(int i = 0; i < STR-1; i++){
		x[i] -= i+1;
	}
	return x;
}

//Decrypts x a :: b
char  *decrypt(char *x){
	for(int i = 0; i < STR-1; i++){
		x[i] += i+1;
	}
	return x;
}

//Make the string x have _ instead of space
char *fill(char *x){
	for(int i = 0; i < STR-1; i++){
   	if(x[i] == '\0') x[i] = '_';
   }
   return x;
}

//HIDDEN SETTINGS: for Logs and setting date
void hidden(){
	printf("HIDDEN SETTINGS: ");
	display(2);
	float temp_date;
	printf("\n\n\tSet Year: ");
	scanf(" %f", &temp_date);
	if(temp_date >= current_date) current_date = temp_date;
	printf("\n\n\tLog: ");
	for(int i = 0; i < X; i++){
		printf("\n\n\tuser[ #%5.0d ]  [ logged in: %2.0f ]",buffer[i].num, logs[i][0]);
		printf("\n\t\t\t[ Loan:       P%5.0f.00  Date: %4.0f ]\n\t\t\t[ Investment: P%5.0f.00  Date: %4.0f ]\n\t", logs[i][2], logs[i][1], logs[i][4], logs[i][3]);
	}
	char ch;
	scanf(" %c", &ch);
}
//------------------------D1------------------------------'


//--------------------------A1----------------------------,
//First page of the Bank: Main Menu
void firstpage(){
	display(2);
	printf("\n\n\t1. Login\n");
	printf("\n\t2. Create Account\n");
	printf("\n\t3. Enter Anonymously\n");
	printf("\n\t0. EXIT\n");
}

//Handles the switch for repeated printfs
void display(int x){
	switch(x){
		case 1: printf("Invalid Key!\n"); break;
		case 2: printf("\n\t\t\t\t\t\t\tdate: %.0f", current_date);
		             printf("\n\n\t\t\tWELCOME TO CBANK!\n"); break;
		case 3: printf("\n\tUsername and Password do not match!"); break;
		case 4: printf("Username already in use!"); break;
		case 5: printf("\n\tDatabase is full!"); display(6); break;
		case 6: printf("\n\n\n\n\n\n\n\n\tPress any key to continue: "); break;
		case 7: printf("Logged in as: [ #%5.0d ] [ %s ]", hold.num, hold.username);
					 printf("\nBalance: P%.2f",hold.balance); break;
		case 8: printf("\n\n\t   LOG IN TO CBANK ACCOUNT"); break;
		case 9: printf("\n\n\t   CREATE NEW CBANK ACCOUNT"); break;
		case 10: printf("\n\n\t   MAIN MENU"); break;
		case 11: printf("\n\n\n\n\n\n\n\n\tPress any key to continue [0 to Exit]: ");
	}
}

//Handles switch for repeated printfs & scanfs pair
int take(int x){
	char ch;
	switch(x){
		case 1: printf("\n\n\t  :: "); scanf(" %c", &ch); return logic(ch); break;
		case 2: printf("\n\n\tEnter Username: "); 
					 scanf(" %s", temp.username);
					 fill(temp.username); break; 
		case 3: printf("\n\tEnter Password: "); scanf(" %s", temp.password);							 encrypt(fill(temp.password)); break;
		case 4: scanf(" %c", &ch);  if(ch == '0') return 1; else return 0; break;
		case 5: printf("\n\n\t  :: "); scanf(" %c", &ch); return logic2(ch); break;
		case 6: scanf(" %s", temp.password); encrypt(fill(temp.password)); 						 return 0; break;
		default: return 1;
	}
	return 1;
}

//Second page of the Bank: 2nd Menu
void secondpage(){
	display(7);
	display(2);
	display(10);
	printf("\n\n\t1. Profile");
	printf("\n\n\t2. Withdraw");
	printf("\n\n\t3. Deposit");
	printf("\n\n\t4. Send Money");
	printf("\n\n\t5. Apply Loan");
	printf("\n\n\t6. Invest");
	printf("\n\n\t0. LOGOUT\n");
}
//--------------------------A1----------------------------'


//--------------------------B1----------------------------,
//Handles the firstpage switch
int logic(char x){
	switch(x){
		case '1': system("cls"); login(); return 0; break;
		case '2': system("cls"); create(); return 0; break;
		case '3': system("cls"); noAcc(); return 0; break;
		case 'H': system("cls"); hidden(); system("cls"); return 1; break;
		case '0': database(2); return 2; break;
		default: system("cls"); return 1;
	}
	return 1;
}

//Handles the seconpage switch
int logic2(char x){
	switch(x){
		case '1': system("cls"); profile(); return 0; break;
		case '2': system("cls"); withdraw(); return 0; break;
		case '3': system("cls"); deposit(); return 0; break;
		case '4': system("cls"); send(); return 0; break;
		case '5': system("cls"); loan(); return 0; break;
		case '6': system("cls"); invest(); return 0; break;
		case '0': receipt(); display(6); take(4); system("cls"); return 2; break;
		default: system("cls"); return 1;
	}
	return 1;
}

//Main Logic gate: For scanning fron database structures and logs
int check(int x){
	int i;
	switch(x){
		case 1: 
					for(i = 0; i < X; i++){
						if(strcmp(buffer[i].username, temp.username) == 0){
							return 1;
							break;
						}
					}
					return 0;
					break;
		case 2:
					for(i = 0; i < X; i++){
						if(buffer[i].username[0] == '\0'){
							temp.balance = 10;
							counter = i;
							logs[counter][0] += 1;
							temp.num = 10000+i+1;
							buffer[i] = temp;
							return 0;
							break;
						}
					}
					display(5);
					take(4);
					hold = clean;
					counter = 0;
					system("cls");
					main(1);
					break;
		case 3:
					for(i = 0; i < X; i++){
						if(strcmp(buffer[i].username, temp.username) == 0 && 										strcmp(buffer[i].password, temp.password) == 0){
							counter = i;
							logs[counter][0] += 1;
							temp = buffer[i];
							return 0; 
							break;
						}
					}
					return 1; break;
		default: return 1;
	}
	return 1;
}
//--------------------------B1----------------------------'


//--------------------------C1----------------------------,
//Handles Login Account
void login(){
	display(2);
	display(8);
	temp = clean;
	take(2);
	take(3);
	if (check(3) == 0) {
		display(6);
		take(4);
		system("cls");
		hold = temp;
		temp = clean;
	}
	else {
		display(3);
		display(11);
		if (take(4) == 1) {
			hold = clean;
			counter = 0;
			system("cls");
			main(1);
			exit(1);
		}
		else {
			system("cls");
			login();
		}
	}
}

//Hangles Create new Account
void create(){
	display(2);
	display(9);
	take(2);
	if(check(1) == 0) {
		take(3);
		if(check(2) == 0){ 
			display(6);
			take(4);
			system("cls");
			hold = temp;
			temp = clean;
			printf("Free P10.00 for new Users!\n");
		}
	}
	else{
		system("cls");
		display(4);
		temp = clean;
		create();
	}
}

//Handles Anonymous Login
void noAcc(){
	strcpy(temp.username, "Anonymous1");
	strcpy(temp.password, "Anonymous1");
	temp.balance = 0;
	counter = 10;
	temp.num = 10000;
	hold = temp;
	temp = clean;
}

//Handles Secondpage user profile
void profile(){
	char ch = '0';
	display(2);
	printf("\n\t\tPROFILE\n");
	printf("\n\n\tuser [ #%5.0d ]", hold.num);
	printf("\n\n\tUsername: %s", hold.username);
	printf("\n\n\tPassword: %s", hold.password);
	printf("\n\n\tBalance: P%.2f", hold.balance);
	if(hold.num == 10000){
		display(6);
		take(4);
		system("cls");
		main(2);
		exit(1);
	}
	else{
	printf("\n\n\tLoan: P%.2f", logs[counter][2]);
	printf("\n\n\tInvestment: P%.2f", logs[counter][2]);
		printf("\n\n\t\t1. Change Password");
		printf("\n\n\t\t2. Remove Account");
		printf("\n\n\t\t0. BACK");
		printf("\n\n\t\t  :: ");
		scanf(" %c", &ch);
		if(ch == '1') {
			printf("\n\n\tEnter Old Password: ");
			take(6);
			if(strcmp(temp.password, hold.password) == 0){
				temp = clean;
				printf("\n\n\tEnter New Password: ");
				take(6);
				strcpy(hold.password, temp.password);
				strcpy(buffer[counter].password, temp.password);
				temp = clean;
				system("cls");
				printf("Password Changed!");
				profile();
				exit(1);
			}
			system("cls");
			printf("Password Incorrect!");
			temp = clean;
			profile();
			exit(1);
		}
		else if(ch == '2'){
			printf("\n\n\tAre you sure you want to remove your account?");
			if(hold.balance != 0) {
			printf("\n\n\tBalance: [ %.2f ] will be lost!", hold.balance);
			}
			printf("\n\n\tEnter Password to continue: ");
			take(6);
			if(strcmp(temp.password, hold.password) == 0){
				display(6);
				take(4);
				temp = clean;
				receipt();
				hold = clean;
				buffer[counter] = clean;
				for (int i = 0; i < 5; i++) logs[counter][i] = 0;
				system("cls");
				main(1);
				exit(1);
			}
			else{
				system("cls");
				printf("Deletion Failed!");
				profile();
				exit(1);
			}
		}
		else if(ch == '0'){
			system("cls");
			main(2);
			exit(1);
		}
		else {
			system("cls");
			display(1);
			profile();
			exit(1);
		}
	}
}

//Handles Withdraw for secondpage
void withdraw(){
	display(7);
	display(2);
	printf("\n\n\t   CBANK WITHDRAW MONEY");
	
}

//Handles deposit
void deposit(){
	display(7);
	display(2);
	printf("\n\n\t   CBANK DEPOSIT MONEY");
}

//Handles send money to other user
void send(){
	display(7);
	display(2);
	char ch;
	printf("\n\n\t   CBANK SEND MONEY");
	printf("\n\n\t1. Send Money\n\n\t0. Exit\n\n\t  :: ");
	scanf(" %c", &ch);
	if(ch == '1'){
    printf("\n\tInput details of receiving account (Receiving)");
	take(2);
	for(int i = 0; i < X; i++){
		if(strcmp(buffer[i].username, temp.username) == 0){
			printf("\n\n\tEnter the amount which you want to transfer: ");
			scanf(" %f", &temp.balance);
			if(temp.balance > hold.balance){
				temp = clean;
				system("cls");
				printf("Amount Exceed your own Balance!\n");
				send();
				exit(1);
			}
			else{
				buffer[i].balance += temp.balance;
				hold.balance -= temp.balance;
				sent += temp.balance;
				temp = clean;
				system("cls");
				main(2);
				exit(1);
			}
		}
	}
	system("cls");
	printf("No Username Found!\n");
	send();
	exit(1);
	}
	else if(ch == '0'){
		system("cls");
		main(2);
		exit(0);
	}
	else{
		system("cls");
		display(1);
		send();
		exit(0);
	};
}

//Handles loan from bank: 2.5% interest rate annually
void loan(){
	if(hold.num == 10000){
		system("cls");
		printf("Cancelled!\n");
		main(2);
		exit(0);
	}
	display(7);
	display(2);
	printf("\n\n\t   CBANK LOAN");
	float total = (logs[counter][2]*(0.025*(current_date - logs[counter][1])))+logs[counter][2];
	printf("\n\n\tCurrent Loan: P%.2f", total);
	printf("\n\n\tPlease select which amount you want to loan\n");
	printf("\n\n\t1. P500, 000\n");
	printf("\n\t2. P400, 000\n");
	printf("\n\t3. P300, 000\n");
	printf("\n\t4. P200, 000\n");
	printf("\n\t5. P100, 000\n");
	printf("\n\t6. Pay Loan\n");
	printf("\n\t0. Exit\n");
	printf("\n\t:: ");
	char select;
	float tmp_loan;
	scanf(" %c", &select);
	switch(select){
		case '1': 
						tmp_loan = 500000;
						break;
		case '2': 
						tmp_loan = 400000;
						break;
		case '3': 
						tmp_loan = 300000;
						break;
		case '4': 
						tmp_loan = 200000;
						break;
		case '5': 
						tmp_loan = 100000;
						break;
		case '6': 
						if(logs[counter][1] == 0){
							system("cls");
							printf("No Current Loan!\n");
							loan(1);
							exit(0);
						}
						printf("\n\n\tEnter Amount: ");
						scanf(" %f", &tmp_loan);
						display(11);
						if (take(4) == 1){
							tmp_loan = 0;
							system("cls");
							printf("Paying Loan Voided!\n");
							loan();
							exit(1);
						}
						else {
							if(hold.balance >= tmp_loan){
								if(tmp_loan > total){
									system("cls");
									printf("Amount Exceed Current Loan!\n");
									loan();
									exit(1);
								}
								hold.balance -= tmp_loan;
								payed += tmp_loan;
								logs[counter][2] = total;
								logs[counter][1] = current_date;
								logs[counter][2] -= tmp_loan;
								if(logs[counter][2] == 0){
									logs[counter][1] = 0;
								}
								system("cls");
								printf("Payment Granted!\n");
								loan();
								exit(1);
							}
							else {
								tmp_loan = 0;
								system("cls");
								printf("Amount Exceed Account Balance!\n");
								loan();
								exit(1);
							}
						}
						exit(1);
						break;
		case '0':
						system("cls");
						main(2);
						exit(1);
						break;
		default:
						system("cls");
						display(1);
						loan();
						exit(1);
						break;
	}
	printf("\n\n\tAmount Loaned P%.2f", tmp_loan);
	printf("\n\n\tThank you for choosing CBank!");
	display(11);
	if(take(4) == 1){
		tmp_loan = 0;
		system("cls");
		printf("Loan Voided!\n");
		loan();
		exit(1);
	} 
	else {
		loaned += tmp_loan;
		logs[counter][1] = current_date;
		logs[counter][2] += tmp_loan;
		loaned += tmp_loan;
		hold.balance += tmp_loan;
		system("cls");
		printf("Loan Availed!\n");
		loan();
		exit(1);	
	}
}

//Handles investment from bank: 2.5% interest rate annually
void invest(){
	if(hold.num == 10000){
		system("cls");
		printf("Cancelled!\n");
		main(2);
		exit(0);
	}
	display(7);
	display(2);
	printf("\n\n\t   CBANK INVEST");
	float total = (logs[counter][4] * (0.025 * (current_date - logs[counter][3])))+logs[counter][4];
	printf("\n\n\tCurrent Investment: P%.2f", total);
	printf("\n\n\t1. Invest in CBank\n\t\t5 Percent Annual return on Investment");
	printf("\n\n\t2. Take Investment");
	printf("\n\n\t0. BACK\n\n\t  :: ");
	char ch;
	scanf(" %c", &ch);
	if(ch == '1'){
		if(logs[counter][4] == 0){
			printf("\n\n\tEnter Amount: ");
			scanf(" %f", &temp.balance);
			if(hold.balance < temp.balance){
				system("cls");
				printf("Input Exceed Account Balance!\n");
				invest();
				exit(1);
			}
			else{
				hold.balance -= temp.balance;
				invested = temp.balance;
				logs[counter][3] = current_date;
				logs[counter][4] = temp.balance;
				temp = clean;
				printf("\n\n\tInvestment Saved\n\n\t  :: ");
				take(4);
				system("cls");
				main(2);
				exit(1);
			}
		}
		else{
			system("cls");
			printf("You Already have Investment!\n");
			invest();
			exit(1);
		}
	}
	else if(ch == '2'){
		if(logs[counter][4] != 0){
			printf("\n\n\tInvestment: P%.2f Date: %.0f", logs[counter][4], logs[counter][3]);
			printf("\n\n\tTotal Return: P%.2f", total);
			printf("\n\tAre you sure you want to continue?");
			display(11);
			if(take(4) == 1){
				system("cls");
				invest();
				exit(1);
			}
			else{
				hold.balance += total;
				gained = total;
				logs[counter][4] = 0;
				logs[counter][3] = 0;
				system("cls");
				main(2);
				exit(1);
			}
		}
		else{
			system("cls");
			printf("No Investment!\n");
			invest();
			exit(1);
		}
	}
	else if(ch == '0'){
		system("cls");
		main(2);
		exit(1);
	}
	else{
		system("cls");
		display(1);
		invest();
		exit(1);
	}
}

//For Outputing Receipt file
void receipt(){
	printf("\n\n\n\n\tPRINTING RECEIPT... \n\n\n");
	buffer[counter] = hold;
	database(2);
	dtb = 1;
	FILE *fptr = fopen("Receipt.txt", "a");
	fprintf(fptr, "\n ____________________________________________");
	fprintf(fptr, "\n|                                                                               |");
	fprintf(fptr, "\n|       ccc     cccc         c         c       c     c    c         |");
	fprintf(fptr, "\n|     c           c     c      c  c       c c    c     c  c           |");
	fprintf(fptr, "\n|     c           ccc        c    c      c   c  c     cc             |");
	fprintf(fptr, "\n|     c           c      c   ccccc     c    c c     c   c          |");
	fprintf(fptr, "\n|       ccc     cccc    c        c    c       c     c      c       |");
	fprintf(fptr, "\n|                                                                               |");
	fprintf(fptr, "\n|                                                                               |");
	fprintf(fptr, "\n|                           __RECEIPT__                              |");
	fprintf(fptr, "\n\n   Date: %.0f\n", current_date);
	fprintf(fptr, "\n\n        Account Number: [ #%d ]", hold.num);
	fprintf(fptr, "\n\n        Username: [ %s ]", hold.username);
	fprintf(fptr, "\n\n        Balance: [ P%.2f ]\n", hold.balance);
	fprintf(fptr, "\n\n                        -Withdraw----- P%.2f", withdrawn);
	fprintf(fptr, "\n\n                        -Deposit---- P%.2f", deposited);
	fprintf(fptr, "\n\n                        -Sent---------- P%.2f", sent);
	if(hold.num != 10000){
		fprintf(fptr, "\n\n                        -Loan--------- P%.2f", loaned);
		fprintf(fptr, "\n\n                        -Invest------- P%.2f\n\n", invested);
	}
	if(logs[counter][2] != 0){
		fprintf(fptr, "\n\n   Loan from CBank: ( %.0f ) P%.2f", logs[counter][1], logs[counter][2]);
	}
	if(logs[counter][4] != 0){
		fprintf(fptr, "\n\n   Invested to CBank: ( %.0f ) P%.2f", logs[counter][3], logs[counter][4]);
	}
	if(gained != 0){
		fprintf(fptr, "\n\n   Investment Claimed: ( %.0f ) P%.2f ", current_date, gained);
	}
	if(payed != 0){
		fprintf(fptr, "\n\n   Loan Payed: ( %.0f ) P%.2f", current_date, payed);
	}
	fprintf(fptr, "\n\n   Total Account Balance: P%.2f", hold.balance+((logs[counter][4] * (0.025 * (current_date - logs[counter][3])))+logs[counter][4]));
	fprintf(fptr, "\n|                                                                               |");
	fprintf(fptr, "\n|                                                                               |");
	fprintf(fptr, "\n|            Thank you for using our CBank!              |");
	fprintf(fptr, "\n|                                                                               |");
	fprintf(fptr, "\n|                                                                               |");
	fprintf(fptr, "\n ____________________________________________");
	fprintf(fptr, "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");
	withdrawn = 0;
	deposited = 0;
	sent = 0;
	loaned = 0;
	invested = 0;
	hold = clean;
	counter = 0;
	fclose(fptr);
	printf("\n\n\tRECEIPT PRINTED! ");
}

//--------------------------C1----------------------------'

