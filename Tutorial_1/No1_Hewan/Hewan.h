#include <iostream>

using namespace std;

class Hewan {
	public:
		Hewan(string nama){
            this->nama = nama;
        };
        ~Hewan(){
            cout << "Hewan mati " << this->nama << '\n';
        }
        virtual void print(){
            cout << "Hewan ini namanya " << nama << '\n';
        }
	protected:
		string nama;
};

class Anjing : public Hewan {
    public:
        Anjing(string nama) : Hewan(nama){}
        ~Anjing(){
            cout << "Anjing mati " << nama << endl;
        }
        void print(){
            cout << "Anjing ini namanya " << nama << '\n';
        }
};

class Kucing : public Hewan {
    public:
        Kucing(string nama) : Hewan(nama){}
        virtual ~Kucing(){
            cout << "Kucing mati " << nama << endl;
        }
};

class KucingAnggora : public Kucing {
    protected:
        string pemilik;
    public:
        KucingAnggora(string nama, string nama_pemilik) : Kucing(nama), pemilik(nama_pemilik){}
        ~KucingAnggora(){
            cout << "Kucing anggora mati " << nama << endl;
        }
        void print(){
            cout << "Kucing anggora ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl;
        }
};

class AnjingBulldog : public Anjing {
    protected:
        string pemilik;
    public:
        AnjingBulldog(string nama, string nama_pemilik) : Anjing(nama), pemilik(nama_pemilik){}
        ~AnjingBulldog(){
            cout << "Anjing bulldog mati " << nama << endl;
        }
        void print(){
            cout << "Anjing bulldog ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl;
        }
};