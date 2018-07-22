#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;
char option;
int pilih;
int Uscore,Escore;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*Anggota Kelompok
Nama : Listia Eka/ 4210161024
Nama :Muchamad Irsad Maulana/4210161005
*/
int help()
{
	system("cls");
	cout<<"Help and About\n";
	cout<<"Game ini adalah game batu gunting kertas\n";
	cout<<"1. Masukkan kata untuk bermain ex. ""batu""\n";
	cout<<"2. Score akan diberikan berdasarkan menang, kalah dan draw\n";
	cout<<"3. Untuk melihat score bisa dilihat di pilihan highscore";
	cout<<"\nTekan 1 untuk kembali\n";
	cin>>pilih;
	return pilih;
}
void play()
{
	do {
		srand(time(NULL));
		system("CLS");
		cout<<"\nSelamat Datang Di Permainan Batu Gunting Kertas\n===========================\nBatu\nGunting\nKertas\n";
		string enemy[]= {"batu","gunting","kertas"};
		int n = rand()%3;
		string your;
		cout<<"Silahkan memilih dengan mengetikkannya \n";
		cin>>your;
		cout<<"\nYour is "<<your;
		cout<<"\nEnemy is "<<enemy[n]<<endl;
		if(your==enemy[n]) {
			cout<<"draw";
		} else {
			if(your=="batu") {
				if(enemy[n]=="kertas") {
					cout<<"You Lose";
					Escore+=1;
				} else if(enemy[n]=="gunting") {
					cout<<"You Win";
					Uscore+=1;
				}
			} else if(your=="gunting") {
				if(enemy[n]=="kertas") {
					cout<<"You Win";
					Uscore+=1;
				} else if(enemy[n]=="batu") {
					cout<<"You Lose";
					Escore+=1;
				}
			} else if(your=="kertas") {
				if(enemy[n]=="batu") {
					cout<<"You Win";
					Uscore+=1;
				} else if(enemy[n]=="gunting") {
					cout<<"You Lose";
					Escore+=1;
				}
			}
		}
		cout<<"\nTekan y untuk bermain lagi\n";
		cout<<"\nTekan n untuk kembali ke menu\n";
		cin>>option;
	} while(option == 'y'||option == 'Y');
}
void score()
{
	system("cls");
	cout<<"\nGame Has been Ended \n";
	cout<<"Your Score is "<<Uscore;
	cout<<"Enemy Score is "<<Escore;
	if(Uscore > Escore) {
		cout<<"\nThe winner is you";
	} else if(Uscore == Escore) {
		cout<<"\nNo Winner";
	} else {
		cout<<"\nThe Winner is Enemy";
	}
	cout<<"\nTekan 1 untuk kembali ke menu\n";
	cin>>pilih;
}

int main(int argc, char** argv)
{
	do {
		system("cls");
		cout<<"Main Menu\n";
		cout<<"1. Help\n";
		cout<<"2. Play\n";
		cout<<"3. Highscore\n";
		cout<<"Tekan 5 untuk keluar\n";
		cin>>pilih;
		switch(pilih) {
			case 1 :
				help();
				break;
			case 2 :
				play();
				break;
			case 3 :
				score();
				break;
		}
	} while(pilih!=5);
	return 0;
}
