/*
Nama		: Delanika Olympiani T. C.
NPM			: 140810180026
Deskripsi	: Program ini mmenampilkan menu phone book
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct Contact{
    char name[10];
    char phone[12];
    Contact* next;
};

struct Index{
    char indeks[2];
    Contact* nextContact;
    Index* next;
};

typedef Index* pointerIndeks;
typedef Contact* pointerContact;
typedef pointerIndeks ListIndeks;

void createListIndeks(ListIndeks& First);
void createElementIndeks(pointerIndeks& pBaru);
void createElementContact(pointerContact& pBaru);
void traversalIndeks(ListIndeks First);
void linearSearch(ListIndeks First, char key[10], int& status, pointerIndeks& pCari);
void insertFirstIndeks(ListIndeks& First, pointerIndeks pBaru);
void deleteFirstIndeks(ListIndeks& First, pointerIndeks& pHapus);
void insertFirstContact(ListIndeks& First, char key[10], pointerContact pBaru);
void deleteFirstContact(ListIndeks& First, char key[10], pointerContact& pHapus);
void traversal(ListIndeks First);

int main()
{
    pointerIndeks pIndeks, pHapusIndeks;
	ListIndeks First;
	pointerContact pContact, pHapusContact;
	char key[10];
	int n, pilihan;

	while(1){
    system("cls");
	cout << "Menu" << endl;
	cout << "1. Insert Index" << endl;
	cout << "2. Insert Contact" << endl;
	cout << "3. Delete Index" << endl;
	cout << "4. Delete Contact" << endl;
	cout << "5. Traversal" << endl;
	cout << "6. Exit" << endl;
	cout << "Masukan Pilihan	: "; cin >> pilihan;
	switch (pilihan){
		case 1 :
			createElementIndeks(pIndeks);
			insertFirstIndeks (First, pIndeks);
			break;
		case 2 :
		    cout << "Gunakan huruf kapital untuk Indeks!" <<endl;
			cout << "Indeks : "; cin >> key;
			createElementContact(pContact);
			insertFirstContact(First, key, pContact);
			break;
		case 3 :
			deleteFirstIndeks(First, pHapusIndeks);
			break;
		case 4 :
			cout << "Gunakan huruf kapital untuk Indeks!" <<endl;
			cout << "Indeks	: "; cin >> key;
			deleteFirstContact(First, key, pHapusContact);
			break;
		case 5 :
			traversal(First);
		case 6 :
			return 0;
        }
	}
}

void createListIndeks (ListIndeks& First){
	First=NULL;
}

void createElementIndeks (pointerIndeks& pBaru){
	pBaru=new Index;

	cout << "Indeks Huruf : "; cin >> pBaru->indeks;
	pBaru->next=NULL;
	pBaru->nextContact=NULL;
}

void createElementContact (pointerContact& pBaru){
	pBaru=new Contact;

	cout << "Nama	    : "; cin.ignore(); cin.getline(pBaru->name, 10);
	cout << "Nomor HP	: "; cin >> pBaru->phone;
	pBaru->next=NULL;
}

void traversalIndeks(ListIndeks First){
	pointerIndeks pBantu;
    pBantu=First;

    cout<<"Index :"<<endl;
    while(pBantu!=NULL){
        cout<<"|- "<<pBantu->indeks<<endl;
        pBantu=pBantu->next;
        }
}

void insertFirstIndeks(ListIndeks& First, pointerIndeks& pBaru){
	if (First==NULL){
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}

void deleteFirstIndeks(ListIndeks& First, pointerIndeks& pHapus){
	if(First==NULL){
		pHapus=NULL;
		cout <<"List kosong, tidak ada yang dihapus."<< endl;
	}
	else if (First->next=NULL){
		pHapus=First;
		First=NULL;
	}
	else {
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
	}
}


void insertFirstContact (ListIndeks& First, char key[10], pointerContact pBaru){
	pointerIndeks pIndeks;
 	pIndeks=First;
	int status=0;

	while(pIndeks!=NULL&&status==0){
		if(strcmp(pIndeks->indeks, key)==0){
			status=1;
		}
		else {
			pIndeks=pIndeks->next;
		}
	}
	if (status){
		cout << "Berhasil Ditemukan" << endl;
		if (pIndeks->nextContact==NULL){
			pIndeks->nextContact=pBaru;
		}
		else{
			pBaru->next=pIndeks->nextContact;
			pIndeks->nextContact=pBaru;
		}
	}
	else
	cout << "Tidak ditemukan" << endl;
}

void deleteFirstContact (ListIndeks& First, char key[10], pointerContact& pHapus){
	pointerIndeks pIndeks;
	int status=0;
	pIndeks=First;

	while (pIndeks!=NULL&&status==0){
		if (strcmp(pIndeks->indeks,key)==0){
			status=1;
		}
		else {
			pIndeks=pIndeks->next;
		}
	}
	if(status){
		cout << "Ditemukan" << endl;
		if(pIndeks->nextContact==NULL){
			pHapus=NULL;
			cout << "List Kosong" << endl;
		}
		else if (pIndeks->nextContact->next==NULL){
			pHapus=pIndeks->nextContact;
			pIndeks->nextContact=NULL;
		}
		else{
			pHapus=pIndeks->nextContact;
			pIndeks->nextContact=pIndeks->nextContact->next;
			pHapus->next=NULL;
		}
	}
	else{
		cout << "Tidak Ditemukan" << endl;
	}
}

void traversal(ListIndeks First){
    pointerIndeks pBantuIndeks;
    pointerContact pBantuContact;
    cout<<"Index Contact"<<endl;
    pBantuIndeks=First;

    while (pBantuIndeks!=NULL){
        cout<<"|- "<<pBantuIndeks->indeks<<endl;
        pBantuContact=pBantuIndeks->nextContact;
        while (pBantuContact!=NULL) {
        	cout<<"\t|- "<<pBantuContact->name<< " / "<<pBantuContact->phone<<endl;
        	pBantuContact=pBantuContact->next;
        }
        pBantuIndeks=pBantuIndeks->next;
    }
}
