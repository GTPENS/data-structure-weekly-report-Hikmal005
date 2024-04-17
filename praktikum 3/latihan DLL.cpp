#include <iostream>
using namespace std;

// M. Hikmal Muzaffir
// 5233600005

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