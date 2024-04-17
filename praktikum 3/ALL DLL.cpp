## Nama    : M. Hikmal Muzaffir
## NRP     : 5223600005
## Kelas   : 1 GT-A


# Praktikum 03 : Double Linked List

## Modul Praktikum

### D. PERCOBAAN
1. Implementasikan operasi dasar Double linked list : Menyisipkan sebagai simpul ujung(awal) dari linked list.
2. Implementasikan operasi dasar Double linked list : Membaca atau menampilkan
3. Implementasikan operasi dasar Double linked list : Mencari sebuah simpul tertentu. Tambahkan kondisi jika yang dicari adalah data yang paling depan.
4. Implementasikan operasi dasar Double linked list : Menghapus simpul tertentu. Tambahkan kondisi jika yang dihapus adalah data yang paling depan atau data yang paling terakhir.
5. Gabungkan semua operasi di atas dalam sebuah Menu Pilihan.

versi full code cpp :
```cpp
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
};
// 1. Menyisipkan sebagai simpul ujung(awal) dari linked list.
void insertNode(Node*& head, Node*& tail, int data){
    Node* n=new Node();
    n->data=data;

    if(head==nullptr){
        n->next=nullptr;
        n->prev=nullptr;
        head=n;
        tail=n;
    }else{
        n->next=head;
        head->prev=n;
        head=n;
    }
}
// 2. Membaca atau menampilkan
void tampil(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout<<"head pada "<<head->data<<" next-nya "<<head->next->data<<endl;
}
// 3. Mencari sebuah simpul tertentu. Menambahkan kondisi jika yang dicari adalah data yang paling depan.
void cari(Node* head, int data){
    Node* temp=head;
    int n=1;
    if(head==nullptr){
        cout<<"List belum dibuat"<<endl;
    }else{
        while(temp->data!=data){
            if(temp->next==nullptr){
                cout<<"data "<<data<<" tidak ditemukan"<<endl;
                break;
            }else{
                temp=temp->next;
            }
            n++;
        }
    }
    if(temp->data==data) cout<<"data "<<data<<" ditemukan di node ke-"<<n<<endl;
}
//   4. Menghapus simpul tertentu. Tambahkan kondisi jika yang dihapus adalah data yang paling depan atau data
//      yang paling terakhir.
void hapusNode(Node*& head, Node*& tail, int data){
    Node* temp=new Node();
    temp=head;
    while(temp->data!=data){
        temp=temp->next;
    }
    if(temp==head){
        head=head->next;
    }else if(temp==tail){
        tail=tail->prev;
    }else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    delete temp;
}
// menghapus keseluruhan node
void hapus(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;

    int pilihan, data;

    do {
        cout << "\nMenu Pilihan:\n";
        cout << "1. Sisipkan Node di Awal\n";
        cout << "2. Tampilkan Node\n";
        cout << "3. Cari Node\n";
        cout << "4. Hapus Node (by data)\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data yang akan disisipkan: ";
                cin >> data;
                insertNode(head, tail, data);
                break;
            case 2:
                cout << "Linked List: ";
                tampil(head);
                break;
            case 3:
                cout << "Masukkan data yang akan dicari: ";
                cin >> data;
                cari(head, data);
                break;
            case 4:
                cout << "Masukkan data yang akan dihapus: ";
                cin >> data;
                hapusNode(head, tail, data);
                break;
            case 5:
                cout << "Keluar dari program\n";
                break;
            default:
                cout << "Pilihan tidak valid! Silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    hapus(head);

    return 0;

}
```

### Pembahasan 
#### 1. Menyisipkan sebagai simpul ujung(awal) dari linked list.
```cpp

//...
// 1. Menyisipkan sebagai simpul ujung(awal) dari linked list.
void insertNode(Node*& head, Node*& tail, int data){
    Node* n=new Node();
    n->data=data;

    if(head==nullptr){
        n->next=nullptr;
        n->prev=nullptr;
        head=n;
        tail=n;
    }else{
        n->next=head;
        head->prev=n;
        head=n;
    }
}

//...

```
#### 2. Membaca atau menampilkan
```cpp

//...
// 2. Membaca atau menampilkan
void tampil(Node* head){
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout<<"head pada "<<head->data<<" next-nya "<<head->next->data<<endl;
}

//...

```

#### 3. Mencari sebuah simpul tertentu.
```cpp 

//...
// 3. Mencari sebuah simpul tertentu. Menambahkan kondisi jika yang dicari adalah data yang paling depan.
void cari(Node* head, int data){
    Node* temp=head;
    int n=1;
    if(head==nullptr){
        cout<<"List belum dibuat"<<endl;
    }else{
        while(temp->data!=data){
            if(temp->next==nullptr){
                cout<<"data "<<data<<" tidak ditemukan"<<endl;
                break;
            }else{
                temp=temp->next;
            }
            n++;
        }
    }
    if(temp->data==data) cout<<"data "<<data<<" ditemukan di node ke-"<<n<<endl;
}

//...

```

#### 4. Mengahapus simpul tertentu
Fungsi berikut saya buat untuk mengahpus node tertentu berdasarkan data yang dimiliki oleh suatu node.
```cpp

//...
//   4. Menghapus simpul tertentu. Tambahkan kondisi jika yang dihapus adalah data yang paling depan atau data
//      yang paling terakhir.
void hapusNode(Node*& head, Node*& tail, int data){
    Node* temp=new Node();
    temp=head;
    while(temp->data!=data){
        temp=temp->next;
    }
    if(temp==head){
        head=head->next;
    }else if(temp==tail){
        tail=tail->prev;
    }else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    delete temp;
}

//...
```
adapun fungsi yang saya buat untuk menghapus keseluruhan node
```cpp
// menghapus keseluruhan node
void hapus(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

//...

```


### Latihan
E. Latihan
1. Bangunlah double linked list di atas adalah double linked list dengan prinsip
LIFO.
2. Bangunlah sebuah single linked list dentan prinsip FIFO(First In First Out)

Code full versi cpp :
```cpp
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* prev;
    Node* next;
};
// 1. Menyisipkan sebagai simpul ujung(awal) dari linked list.
void insertNode(Node*& head, Node*& tail, int data){
    Node* n=new Node();
    n->data=data;

    if(head==nullptr){
        n->next=nullptr;
        n->prev=nullptr;
        head=n;
        tail=n;
    }else{
        n->next=head;
        head->prev=n;
        head=n;
    }
}
// 2. Membaca atau menampilkan
// Menampilkan LIFO
void tampil(Node* head){
    Node* temp = head; 
    cout<<"Tampilan LIFO  : ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
// Menampilkan FIFO
void tampilFIFO(Node* tail){
    Node* temp = tail;
    cout<<"Tampilan FIFO  : ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout<<endl;
}
// 3. Mencari sebuah simpul tertentu. Menambahkan kondisi jika yang dicari adalah data yang paling depan.
void cari(Node* head, int data){
    Node* temp=head;
    int n=1;
    if(head==nullptr){
        cout<<"List belum dibuat"<<endl;
    }else{
        while(temp->data!=data){
            if(temp->next==nullptr){
                cout<<"data "<<data<<" tidak ditemukan"<<endl;
                break;
            }else{
                temp=temp->next;
            }
            n++;
        }
    }
    if(temp->data==data) cout<<"data "<<data<<" ditemukan di node ke-"<<n<<endl;
}
//   4. Menghapus simpul tertentu. Tambahkan kondisi jika yang dihapus adalah data yang paling depan atau data
//      yang paling terakhir.
void hapusNode(Node*& head, Node*& tail, int data){
    Node* temp=new Node();
    temp=head;
    while(temp->data!=data){
        temp=temp->next;
    }
    if(temp==head){
        head=head->next;
    }else if(temp==tail){
        tail=tail->prev;
    }else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    delete temp;
}
// menghapus keseluruhan node
void hapus(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;

    insertNode(head,tail, 10);
    insertNode(head,tail, 20);
    insertNode(head,tail, 30);
    insertNode(head,tail, 40);
    insertNode(head,tail, 50);
    insertNode(head,tail, 60);
    
    tampil(head);
    tampilFIFO(tail);
    hapus(head);

    return 0;

}
```
