/*
Nama		: Delanika Olympiani T. C.
NPM			: 140810180026
Deskripsi	: Program ini menampilkan menu-menu doubly linked list
Tahun       : 2019
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Element{
    char huruf;
    Element* next;
    Element* prev;
};

void inputData(Element* &newData);
void insertFirst(Element* &First, Element* newData);
void insertLast(Element* &First, Element* newData);
void deleteFirst(Element* &First, Element* &pHapus);
void deleteLast(Element* &First, Element* &pHapus);
void traversal(Element* First);

int main()
{
    Element *List=NULL, *p;
	int pilihan;

	 while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Tambah data di awal"<<endl;
        cout<<"2. Tambah data di akhir"<<endl;
        cout<<"3. Hapus data paling awal"<<endl;
        cout<<"4. Hapus data paling akhir"<<endl;
        cout<<"5. Tampilkan data"<<endl;
        cout<<"6. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilihan;
        switch(pilihan){
        case 1:
            inputData(p);
            insertFirst(List, p);
        break;

        case 2:
            inputData(p);
            insertLast(List, p);
        break;

        case 3:
            deleteFirst(List, p);
        break;

        case 4:
            deleteLast(List, p);
        break;

        case 5:
            traversal(List);
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}

void inputData(Element* &newData){
    newData = new Element;
    cout<<"Masukkan satu huruf: "; cin>>newData->huruf;
    newData->next=NULL;
    newData->prev=NULL;
}

void insertFirst(Element* &First, Element* newData){
    if(First==NULL){
        First=newData;
    }
    else{
        newData->next=First;
        First->prev=newData;
        First=newData;
    }
}

void insertLast(Element* &First, Element* newData){
    Element* Last;

    if(First==NULL){
        First=newData;
    }
    else{
        Last=First;
        while(Last->next!=NULL){
                Last=Last->next;
        }
        Last->next=newData;
        newData->prev=Last;
    }
}

void deleteFirst(Element* &First, Element* &pHapus){
    pHapus=First;

	if(First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus."<<endl;
	}
	else{
		First=First->next;
		pHapus->next=NULL;
		pHapus=NULL;
    }
}

void deleteLast(Element* &First, Element* &pHapus){
    pHapus=First;
    Element *prevLast;

	if(First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus."<<endl;
	}
	else{
	    while(pHapus->next!=NULL){
	        prevLast=pHapus;
			pHapus=pHapus->next;
		}
		prevLast->next=NULL;
		pHapus->prev=NULL;
		pHapus=NULL;
    }
}

void traversal(Element* First){
    Element *trav=First;

    if(First!=NULL){
        while(trav!=NULL){
            cout<<"'"<<trav->huruf<<"'";
			if(trav->next!=NULL){
				cout<<"<-->";
			}
			trav=trav->next;
		}
	}
	else{
		cout<<"List tidak ditemukan."<<endl;
	}
}
