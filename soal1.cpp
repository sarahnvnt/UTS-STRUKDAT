/*
Nama Program	: Soal No 1 
Nama			: Sarah Navianti
NPM 			: 140810180021
Kelas 			: A
Tahun			: 2019
*/
#include <iostream>

using namespace std;

struct ElementList{
 int nodaf;
 char tim[100];
 char daerah[20];
 int gol;
 ElementList* next;
};
typedef ElementList* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
}

void createElemt(pointer& pBaru){
    pBaru=new ElementList;
    cout << "No. Daftar :";cin >>pBaru->nodaf;
    cout << "Nama Tim   :";cin >>pBaru->tim;
    cout << "Asal Daerah:";cin >>pBaru->daerah;
 pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
    if(First==NULL)
    First=pBaru;
    else{
    pBaru->next=First;
    First=pBaru;
  }
}

void traversal(List First){
	
    pointer pBantu;
 	pBantu=First;
 	cout << "No. Pendaftaran\t"<< "Nama Tim\t"<< "Asal Daerah\t"<<"Gol\t"<<endl;
 	while(pBantu != NULL){
 		
	 	cout <<pBantu->nodaf<<"\t"<<pBantu->tim<<"\t"<<pBantu->daerah<<"\t"<<endl;
	pBantu=pBantu->next;
	 }
}

void deleteFirst(List& First, pointer& pHapus){
    if (First==NULL){
        pHapus=NULL;
        cout << "List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void insertLast(List& First, pointer pBaru){

    pointer last;
    if(First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
    }
    last->next=pBaru;
    }
}

void deleteLast(List& First, pointer& pHapus){
    pointer last,precLast;
    cout << "Delete last"<<endl;
    if (First==NULL){
        pHapus=NULL;
        cout << "List Kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        last=First;
        precLast=NULL;
        while(last->next !=NULL){
            precLast=last;
            last=last->next;
        }
        pHapus=last;
        precLast->next=NULL;
    }
}


void insertAfter(List& First,pointer pCari,pointer pBaru){
    if (pCari->next==NULL)
        pCari->next=pBaru;
    else {
        pBaru->next=pCari->next;
        pCari->next=pBaru;
    }
}


void linearSearch(List First,int key, int& found, pointer& pCari){
    found=0;
    pCari=First;
    while (found==0 && pCari!=NULL) {
        if (pCari->nodaf==key)
            found=1;
        else
        pCari=pCari->next;
        }

}

void update(List& First, int key) {
  pointer pToUpdate = NULL;
  cout << "nama: "; cin >> pToUpdate->gol;
  cout << endl;
}

void sortin(List& First){
  int count = 0, i;
  pointer start,curr,trail,temp;
  start=First;
  curr=NULL;
  trail=NULL;
  temp=NULL;

  while(start != NULL) { //grab count
    count++;
    start = start->next;
  }

  for(i = 0; i<count; ++i) { //for every element in the list

    curr = trail = First; //set curr and trail at the start node

    while (curr->next != NULL) { //for the rest of the elements in the list
      if (curr->nodaf > curr->next->nodaf) { //compare curr and curr->next

        temp = curr->next; //swap pointers for curr and curr->next
        curr->next = curr->next->next;
        temp->next = curr;

        //now we need to setup pointers for trail and possibly head
        if(curr == First) //this is the case of the first element swapping to preserve the head pointer
          First = trail = temp;
        else //setup trail correctly
          trail->next = temp;
        curr = temp; //update curr to be temp since the positions changed
      }
      //advance pointers
      trail = curr;
      curr = curr->next;
    }
  }
}

int main()
{
    pointer p,pCari;
    List m;
    int ketemu;
    int kunci;
    int pilih;

    createList(m);
    while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Masukan Jumlah Gol"<<endl;
        cout<<"3. Tampilkan"<<endl;
        cout<<"4. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilih;
        switch(pilih){
        case 1:
            createElemt(p);
            insertFirst(m, p);
            sortin(m);
        break;

        case 2:
            cout<<"\nMasukkan No Pendaftaran : "; cin>>kunci;
            linearSearch(m,kunci,ketemu,pCari);
            if (ketemu){
                cout<<"Ditemukan yang dicari "<<endl;
                update(m,kunci);
            }
            else {
                cout<<" Tidak Ditemukan yang dicari "<<endl;
            }
        break;

        case 3:
            traversal(m);
        break;

        case 4:
            return 0;
            break;
        }
        system("pause");
    }

    return 0;
}
