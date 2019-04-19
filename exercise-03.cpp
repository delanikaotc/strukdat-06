/*
Nama		: Delanika Olympiani T. C.
NPM			: 140810180026
Deskripsi	: Program ini menampilkan menu-menu circular doubly linked list
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
		First->next=First;
		First->prev=First;
	}
	else{
		newData->next=First;
		newData->prev=First->prev;
		First->prev->next=newData;
		First->prev=newData;
		First=newData;
	}
}

void insertLast(Element* &First, Element* newData){
    Element *Last=First;

    if(First==NULL){
		First=newData;
		newData->next=newData;
		newData->prev=newData;
	}
	else{
	    while(Last->next!=First){
                Last=Last->next;
		}
		Last->next=newData;
		newData->prev=Last;
		newData->next=First;
		First->prev=newData;
    }
}

void deleteFirst(Element* &First, Element* &pHapus){
    pHapus=First;

	if(First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus."<<endl;
	}
	else if(First->next==First){
		First->next=NULL;
		First->prev=NULL;
		First=NULL;
	}
	else{
		First->next->prev=First->prev;
		First->prev->next=First->next;
		First=First->next;
		pHapus->next=NULL;
		pHapus->prev=NULL;
		pHapus=NULL;
    }

}
void deleteLast(Element* &First, Element* &pHapus){
    pHapus=First;
    Element *prevLast;

	if(pHapus==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus."<<endl;
	}
	else if(First->next==First){
		First->next=NULL;
		First->prev=NULL;
		First=NULL;
	}
	else{
		while(pHapus->next!=First){
			prevLast=pHapus;
			pHapus=pHapus->next;
		}
		prevLast->next=First;
		pHapus->prev=NULL;
		pHapus->next=NULL;
		pHapus=NULL;
		}
}

void traversal(Element* First){
    Element *trav=First;

    if(First!=NULL){
        cout<<"...<-->";
		do{
			cout<<"'"<<trav->huruf<<"'";
			if(trav->next!=First){
				cout<<"<-->";
			}
			trav=trav->next;
		}
		while(trav!=First);
		cout<<"<-->...";
	}
}
