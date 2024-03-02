#include <iostream>
#include "Rekening.h"
using namespace std;

Rekening :: Rekening(double saldo) {
    if (saldo < 0) {
        this->saldo = 0.0;
    } else {
        this->saldo = saldo;
    }
}

void Rekening :: setSaldo(double saldo){
    this->saldo = saldo;
}

double Rekening :: getSaldo() const {
    return this->saldo;
}

void Rekening :: simpanUang(double saldo_tambah){
    this->saldo += saldo_tambah;
}

bool Rekening :: tarikUang(double saldo_tarik){
    if (saldo_tarik > this->saldo){
        return false;
    } else {
        saldo -= saldo_tarik;
        return true;
    }
}