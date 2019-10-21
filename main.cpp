#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{

    //vector<string> item{"Windtalker, stat = +40 attack speed", "Athena Shield, stat = +58 Magical Defence"};
    //vector<string>::iterator penunjuk;
    vector<vector<string>>item { {"Blade of despair", "+100 physical attack"}, {"Athena Shield", "+58 magical defence"}, {"Scarlet Phantom", "+40 attack speed"}, {"Blade Armor", "+90 physical defence"} };
    vector<vector<string>>inventory;
    vector<vector<string>>::iterator penunjuk;
    vector<string>::iterator penun;

    int maks_invent=0,pilihan=0,item_hapus=0;
    string item_invent;
    int item_dipilih=0;
    int jumlah_invent=0;
    char jawaban='y';
    int maks_item;

    maks_item = item.size();
    cout << "Jumlah Item yang tersedia : "<<maks_item<<endl;
    cout << "Masukkan Jumlah max Inventory : ";cin >>maks_invent;
    awal:
    while(jawaban=='y'||jawaban=='Y'){
        cout << "Pilihan Inventory : "<< endl;
        cout << "1. Tampilkan Inventory" <<endl;
        cout << "2. Hapus Inventory" <<endl;
        cout << "3. Tambahkan Inventory"<<endl;
        cout << "Masukkan pilihan : ";cin >> pilihan;

    if(pilihan==1){
        if(inventory.empty()){
            cout << "Maaf, anda belum memiliki inventory"<<endl;
        }
        else {
            for(penunjuk = inventory.begin();penunjuk != inventory.end();penunjuk++){
                for(penun = penunjuk->begin();penun != penunjuk->end();penun++){
                    cout << *penun << " ";
                }
                cout <<endl;
            }
        }
    }
    if(pilihan==2){
        if(jumlah_invent <=0){
            cout << "Maaf, anda tidak punya item "<<endl;
        }
        else {
            tengah:
            cout << "Item yang akan dihapus item ke :";cin >>item_hapus;
            if(item_hapus>jumlah_invent){
                cout << "Maaf Item tidak ada"<<endl;
                goto tengah;
            }
            else {
                inventory.erase(inventory.begin() + (item_hapus-1));
                jumlah_invent--;
                cout << "Jumlah Inventory sekarang : " <<jumlah_invent<<endl;
            }
        }
    }
    if(pilihan==3){
        if(jumlah_invent>=maks_invent){
            cout << "Maaf anda tidak bisa menambah item lagi"<<endl;
        }
        else {
            srand(unsigned(time(0)));
            item_dipilih = (rand()%maks_item);
            cout<< "Item berhasil ditambahkan"<<endl;
            cout<< "Item yang didapat :" <<item[item_dipilih][0]<< "\tStat :"<<item[item_dipilih][1]<<endl;
            inventory.push_back(vector<string>({item[item_dipilih][0]}));
            inventory[jumlah_invent].push_back(item[item_dipilih][1]);
            jumlah_invent++;
            cout<< "Jumlah Inventory anda: "<<jumlah_invent<<endl;
        }
    }
    cout << "Ingin Menggunakan inventory lagi ?(y/n)";cin >>jawaban;
}
    return 0;
}
