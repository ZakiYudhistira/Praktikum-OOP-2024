#include <iostream>
#include "RekeningTabungan.h"
using namespace std;

RekeningTabungan :: RekeningTabungan(double saldo, double biaya) : Rekening(saldo), biayaTransaksi(biaya){}

void RekeningTabungan :: setBiayaTransaksi(double biaya) {
    biayaTransaksi = biaya;
}

double RekeningTabungan :: getBiayaTransaksi() const{
    return biayaTransaksi;
}

void RekeningTabungan :: simpanUang(double saldo){
    Rekening :: simpanUang(saldo);
    setSaldo(getSaldo() - biayaTransaksi);
}

bool RekeningTabungan :: tarikUang(double tarik){
    if(Rekening :: tarikUang(tarik)){
        setSaldo(getSaldo() - biayaTransaksi);
        return true;
    } else {
        return false;
    }
}