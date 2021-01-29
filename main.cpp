#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

struct Mahasiswa {
    string NIM;
    string NAMA;
    string KELAS;
    int NILAI;
    Mahasiswa *next;
};
// prototype function
bool ifEmpty(Mahasiswa *first);
void addData(Mahasiswa *&first, Mahasiswa *&last , string NIM, string NAMA, string KELAS, int NILAI);
void saveData(Mahasiswa *&first, Mahasiswa *&last , string NIM, string NAMA, string KELAS, int NILAI);
void viewList(Mahasiswa *now);
void delData(Mahasiswa *first, Mahasiswa *last);
int menu();
string getGrade(int nilai);

// function 
bool ifEmpty(Mahasiswa *first){ // cel data
   return (first == NULL) ?  true :  false;
}
// function untuk handel grade
string getGrade(int nilai){
    if (nilai >= 85 && nilai <= 100){
       return "A";
    }else if(nilai >= 70 && nilai <= 85){
       return "B";
    }else if(nilai >= 60 && nilai <= 69){
       return "C";
    }else if(nilai >= 50 && nilai <= 59){
       return "D";
    }else if(nilai >= 40 && nilai <= 49){
       return "E";
    }else if(nilai < 40){
       return "F";
    }else{
        return "Error";
    }
}

int menu(){
    int pilih;
    cout << "====================================\n" ;
    cout << "=  Menu Utama                      =\n" ;
    cout << "====================================\n" ;
    cout << "= [1] Tambah Data Mahasiswa        =\n" ;
    cout << "= [2] Hapus Data Mahasiswa         =\n" ;
    cout << "= [3] Tampilkan Data Mahasiswa     =\n" ;
    cout << "= [0] Keluar                       =\n" ;
    cout << "====================================\n" ;
    cout << "Pilih 0-3 : ";
    cin >> pilih;
    return pilih;
}

void saveData(Mahasiswa *&first, Mahasiswa *&last , string NIM, string NAMA, string KELAS, int NILAI){
    Mahasiswa *tmp = new Mahasiswa;
    tmp->NIM = NIM;
    tmp->NAMA = NAMA;
    tmp->KELAS = KELAS;
    tmp->NILAI = NILAI;
    tmp->next = NULL;
    first = tmp; 
    last = tmp;
}

void addData(Mahasiswa *&first, Mahasiswa *&last , string NIM, string NAMA, string KELAS, int NILAI){
    if (ifEmpty(first)){
        saveData(first,last,NIM,NAMA,KELAS,NILAI);
    }else{
        Mahasiswa *tmp = new Mahasiswa;
        tmp->NIM = NIM;
        tmp->NAMA = NAMA;
        tmp->KELAS = KELAS;
        tmp->NILAI = NILAI;
        tmp->next = NULL;
        last->next = tmp;
        last = tmp;
    }
}

void delData(Mahasiswa *first, Mahasiswa *last){
    Mahasiswa *tmp;
    Mahasiswa *prev;
    if (ifEmpty(first)){
       cout << "Data Kosong \n";
    }
    if (first->next == NULL){
       tmp = first;
       first = NULL;
       free(tmp);
    }else{
        tmp = first;
           while (tmp->next != NULL){
             prev = tmp;
             tmp = tmp->next;
           }
        prev->next = NULL;
        free(tmp);
    }    
}

void viewList(Mahasiswa *now){
    if (ifEmpty(now)){
        cout << "List Kosong \n";
    }else{
         cout << "Data Siswa \n";
         while(now != NULL){
             cout << "====================================\n" ;
             cout << "  Nim        : " << now->NIM <<endl;
             cout << "  Nama       : " << now->NAMA <<endl;
             cout << "  Kelas      : " << now->KELAS <<endl;
             cout << "  Nilai      : " << now->NILAI <<endl;
             cout << "  Grade      : " << getGrade(now->NILAI)<<endl; // execute function getGrade() , return grade  
             cout << "====================================\n" ;
             now = now->next;
         }
    }
}

int main(){
    
     Mahasiswa *first = NULL;
     Mahasiswa *last = NULL;

     int pilih, NILAI;
     string NIM, NAMA, KELAS;

     do{
         system("cls");
         pilih = menu();
         switch (pilih){
         case 1: 
          // input Data
              cin.ignore();
              cout << "====================================\n" ;
              cout << " Masukan Data Mahasiswa\n";
              cout << "====================================\n" ;
              cout << " Nim     : ";
              getline(cin,NIM);
              cout << " Nama    : ";
              getline(cin,NAMA);
              cout << " Kelas   : ";
              getline(cin,KELAS);
              cout << " Nilai   : ";
              cin>>NILAI;
              addData(first,last,NIM,NAMA,KELAS,NILAI);           
              system("pause");
             break;
         case 2:
          // delete data
              delData(first,last);
              cout << "Data Terakhir Terhapus\n";
              system("pause");
             break;
         case 3:
          // lihat list
              system("cls");
              viewList(first);
              system("pause");
             break;
         case 0 :
            // exit
              break;
         default:
             break;
         }
     } while (pilih != 0);
     return 0; 

}
