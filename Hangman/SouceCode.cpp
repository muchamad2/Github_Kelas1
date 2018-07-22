#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <string.h>
using namespace std;
/*Anggota Kelompok
Nama : Listia Eka/ 4210161024
Nama :Muchamad Irsad Maulana/4210161005
*/
//declarasi fungsi fillLetter
int fillLetter(char,string,string &);
void play(char letter);
int start();
void highscore();
void getPoint();
bool category(int options);
const int MAX_Life = 10;
char letter, option;
int options;

struct jmldata {
	int data;
} dta;
struct HighScore {
	string name;
	int data;
} score;
struct Category {
	string catego;
} ctg[100];

int main(int argc, char** argv)
{
	category(1);
	system("cls");
//	string *words;
	do {
		system("cls");
		cout<<"Silahkan pilih kondisi\n";
		cout<<"1. Help\n";
		cout<<"2. Play\n";
		cout<<"3. Highscore\n";
		cout<<"4. Categori Pertanyaan\n";
		cout<<"5. Tekan 5 untuk keluar\n";
		cin>>options;
		switch(options) {
			case 1 :
				start();
				break;
			case 2 :
				cout<<"Masukkan namamu :";
				cin>>score.name;
				score.data = 0;
				play(letter);
				break;
			case 4 :
				category(options);
				break;
			case 3 :
				highscore();
				break;
			default :
				break;
		}

	} while(options < 5);
	return 0;
}
int start()
{
	int back;
	system("cls");
	cout<<"How to play Hangnam\n";
	cout<<"1. Pemain dipersilahkan menentukan tema yang telah disediakan\n";
	cout<<"2. Pemain harus menggunakan huruf kecil sebagai inputan\n";
	cout<<"3. Setiap masukan berisi 1 huruf. ex. 'A' \n";
	cout<<"4. Batas maksimal kesempatan berjumlah 10 kali\n";
	cout<<"5. Skor akan disimpan didalam menu high score\n";
	cout<<"6. Skor akan bertambah 10 jika kesempatan masih lebih dari 8 hingga 10\n";
	cout<<"7. Skor akan bertambah 6 jika kesempatan masih lebih dari 6 hingga 8\n";
	cout<<"8. Skor akan bertambah 1 jika kesempatan kurang dari 6\n";
	cout<<"9. Skor tidak akan bertambah jika huruf yang dimasukkan sudah muncul\n";
	cout<<"10.Setiap kali membuat kesalahan atau memasukkan huruf yang sama maka kesempatan akan berkurang\n";
	cout<<"Tekan '1' untuk kembali\n";
	cin>>back;

	return back;
}
bool category(int options)
{
	srand(time(NULL));
	int txt = 0;
	int i = 0;

	string negara[100];
	string buah[100];
	string kota[100];
	cout<<"Masukkan pilihan kategori\n";
	cout<<"1. Nama - nama Negara\n";
	cout<<"2. Nama - nama Buah Buahan\n";
	cout<<"3. Nama - nama Ibukota\n";
	cin>>options;
	ifstream file;
	switch(options) {
		case 1 :
			file.open("Country.txt");
			if(!file.fail()) {
				while(file.good()) {
					getline(file,negara[i]);
					ctg[i].catego = negara[i];
					i++;
				}
				dta.data = i;
				//txt = rand() % i;
				//cout<<negara[txt];
				//ctg.catego = negara[txt];
				file.close();
			} else {
				cout<<"Fail to open \n";
				return false;
			}
			break;
		case 2 :
			file.open("Fruit.txt");
			if(!file.fail()) {
				while(file.good()) {
					getline(file,buah[i]);
					ctg[i].catego = buah[i];
					i++;
				}
				dta.data = i;
				//txt = rand() % i;
				//ctg.catego = buah[txt];
				file.close();
			} else {
				cout<<"Fail to open \n";
				return false;
			}
			break;
		case 3 :
			file.open("City.txt");
			if(!file.fail()) {
				while(file.good()) {
					getline(file,kota[i]);
					ctg[i].catego = kota[i];
					i++;
				}
				dta.data = i;
				//txt = rand() % i;
				//ctg.catego = buah[txt];
				file.close();
			} else {
				cout<<"Fail to open \n";
				return false;
			}
			break;
	}
	return true;
}
void play(char letter/*, string &words*/)
{
	string word;
	system("cls");
	int life = 0;
	//menampilkan soal random
	int n=rand()%dta.data;
	word = ctg[n].catego;
	//ubah word yang tertera menjadi '*'
	string unknow(word.length(),'*');
	cout<<"Selamat Datang Di Game Hangnam\n\n============================\n";
	cout<<"Silahkan menjawab dengan memasukkan kata kunci\nAnda batas pengisian sebanyak "<<MAX_Life<<endl;
	cout<<"=================================\n\n";
	//loop hingga max life digunakan semua
	while(life < MAX_Life) {
		cout<<unknow<<endl;
		cout<<"Masukkan kata kunci : ";
		cin>>letter;
		//mengisi tanda * dengan kata kunci jika benar tanda * akan berubah
		//sebaliknya max life akan semakain berkurang
		if(fillLetter(letter,word,unknow)==0) {
			cout<<"Letter not found\n";

			life++;
		} else {
			cout<<"Kamu menemukan kata kunci\n";
		}
		cout<<"Sisa pengisian anda "<<MAX_Life-life<<endl;
		if(word == unknow) {
			cout<<"\n\nSelamat kamu menyelesaikan pertanyaan\n";
			cout<<"Jawabannya "<<unknow<<endl;
			break;
		}
	}

	if(life == MAX_Life) {
		cout<<"\n\nKamu gagal menyelesaikan permainan\n";
		cout<<"Jawabannya "<<word<<endl;
	}
	ofstream scorefile;
	scorefile.open("score.txt",ios::in |ios::app);
	scorefile << score.name<<'\n';
	scorefile << score.data<<'\n';
	scorefile.close();
	cout<<"Masukkan 1 untuk back to main menu";
	cin>>options;
}
int fillLetter(char word, string secretword, string &guestword)
{
	int i;
	int len = secretword.length();
	int match = 0;
	for(i=0; i<len; i++) {

		// jika word sama dengan word sebelumnya maka akan return 0
		if(guestword[i]==word) {
			return 0;
		}
		//apakah word sesuai dengan screat word jika ya maka '*' diganti word
		if(word == secretword[i]) {
			guestword[i]=word;
			getPoint();
			match++;
		}
	}
	return match;
}
void getPoint()
{
	if(MAX_Life <= 10 && MAX_Life > 8)
		score.data += 10;
	else if(MAX_Life <= 8 && MAX_Life > 6 )
		score.data += 6;
	else if(MAX_Life < 8)
		score.data += 1;
}
void highscore()
{
	char text;
	ifstream scorefile;
	cout<<"1. Reset Score\n";
	cout<<"2. Show Score\n";
	cin>>options;
	switch(options) {
		case 1 :
			scorefile.open("score.txt",ios::trunc);
			scorefile.close();
			break;
		case 2 :
			system("cls");
			cout<<"Highscore anda adalah \n";
			scorefile.open("score.txt",ios::out);
			if(!scorefile.fail()) {
				while(!scorefile.eof()) {
					scorefile.get(text);
					cout<<text;
				}
				scorefile.close();
			} else {
				cout<<"File tidak ditemukan";
			}
			break;
	}
	cout<<"\ntekan 1 untuk back to main menu\n";
	cin>>options;
}
