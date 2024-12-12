#include "trem.h"
#include <QtCore>


QMutex mutexRegiao1, mutexRegiao2, mutexRegiao3, mutexRegiao4, mutexRegiao5, mutexRegiao6;
QWaitCondition condRegiao1, condRegiao2, condRegiao3, condRegiao4, condRegiao5, condRegiao6;

// Declarando os mutexes estáticos
QMutex Trem::mutexRegiao1;
QMutex Trem::mutexRegiao2;
QMutex Trem::mutexRegiao3;
QMutex Trem::mutexRegiao4;
QMutex Trem::mutexRegiao5;
QMutex Trem::mutexRegiao6;
QMutex Trem::mutexRegiao7;

// Variáveis de controle para as regiões críticas
int Trem::regiao1 = 0;
int Trem::regiao2 = 0;
int Trem::regiao3 = 0;
int Trem::regiao4 = 0;
int Trem::regiao5 = 0;
int Trem::regiao6 = 0;
int Trem::regiao7 = 0;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}


void Trem::setVelocidade(int novaVelocidade) {
    velocidade = 200 - novaVelocidade;
}


//Função a ser executada após executar trem->START
void Trem::run() {
    while (true) {
        switch (ID) {

        case 1: // Trem 1
            if (y == 30 && x < 330) { // Indo para a direita
                if (x == 320) { // Antes de entrar na Região 1
                    QMutexLocker locker(&mutexRegiao1);
                    while (regiao1 != 0) {
                        condRegiao1.wait(&mutexRegiao1); // Espera a região ser liberada
                    }
                    regiao1 = 1; // Marca a região como ocupada pelo Trem 1
                }
                x += 10;
            } else if (x == 330 && y < 150) { // Indo para baixo
                if (y == 140) {
                    QMutexLocker locker(&mutexRegiao2);
                    while (regiao2 != 0) {
                        condRegiao2.wait(&mutexRegiao2); // Espera a região ser liberada
                    }
                    regiao2 = 1; // Marca a região como ocupada pelo Trem 1
                }
                y += 10;
            } else if (x > 130 && y == 150) { // Indo para a esquerda
                if (x == 330) {
                    QMutexLocker locker(&mutexRegiao2); // Libera a Região 2
                    regiao2 = 0;
                    condRegiao2.wakeOne(); // Notifica outros trens esperando
                }
                if (x == 140) {
                    QMutexLocker locker(&mutexRegiao1); // Libera a Região 1
                    regiao1 = 0;
                    condRegiao1.wakeOne(); // Notifica outros trens esperando
                }
                x -= 10;
            } else { // Indo para cima
                y -= 10;
            }
            break;

        case 2: // Trem 2
            if (y == 30 && x < 520) { // Indo para a direita
                if (x == 510) { // Antes de entrar na Região 3
                    QMutexLocker locker(&mutexRegiao3);
                    while (regiao3 != 0) {
                        condRegiao3.wait(&mutexRegiao3); // Espera a região ser liberada
                    }
                    regiao3 = 2; // Marca a região como ocupada pelo Trem 2
                }
                x += 10;
            } else if (x == 520 && y < 150) { // Indo para baixo
                if (y == 140) {
                    QMutexLocker locker(&mutexRegiao4);
                    while (regiao4 != 0) {
                        condRegiao4.wait(&mutexRegiao4); // Espera a região ser liberada
                    }
                    regiao4 = 2; // Marca a região como ocupada pelo Trem 2
                }
                y += 10;
            } else if (x > 330 && y == 150) { // Indo para a esquerda
                if (x == 510) {
                    QMutexLocker locker(&mutexRegiao4); // Libera a Região 4
                    regiao4 = 0;
                    condRegiao4.wakeOne(); // Notifica outros trens esperando
                }
                if (x == 340) {
                    QMutexLocker locker(&mutexRegiao3); // Libera a Região 3
                    regiao3 = 0;
                    condRegiao3.wakeOne(); // Notifica outros trens esperando
                }
                x -= 10;
            } else { // Indo para cima
                y -= 10;
            }
            break;

        case 3: // Trem 3
            if (y == 150 && x < 240) { // Indo para a direita
                if (x == 230) { // Antes de entrar na Região 5
                    QMutexLocker locker(&mutexRegiao5);
                    while (regiao5 != 0) {
                        condRegiao5.wait(&mutexRegiao5); // Espera a região ser liberada
                    }
                    regiao5 = 3; // Marca a região como ocupada pelo Trem 3
                }
                x += 10;
            } else if (x == 240 && y < 270) { // Indo para baixo
                if (y == 260) {
                    QMutexLocker locker(&mutexRegiao6);
                    while (regiao6 != 0) {
                        condRegiao6.wait(&mutexRegiao6); // Espera a região ser liberada
                    }
                    regiao6 = 3; // Marca a região como ocupada pelo Trem 3
                }
                y += 10;
            } else if (x > 60 && y == 270) { // Indo para a esquerda
                if (x == 230) {
                    QMutexLocker locker(&mutexRegiao6); // Libera a Região 6
                    regiao6 = 0;
                    condRegiao6.wakeOne(); // Notifica outros trens esperando
                }
                if (x == 70) {
                    QMutexLocker locker(&mutexRegiao5); // Libera a Região 5
                    regiao5 = 0;
                    condRegiao5.wakeOne(); // Notifica outros trens esperando
                }
                x -= 10;
            } else { // Indo para cima
                y -= 10;
            }
            break;

        case 4: // Trem 4
            if (y == 150 && x < 420) { // Indo para a direita
                if (x == 410) { // Antes de entrar na Região 2
                    QMutexLocker locker(&mutexRegiao2);
                    while (regiao2 != 0) {
                        condRegiao2.wait(&mutexRegiao2); // Espera a região ser liberada
                    }
                    regiao2 = 4; // Marca a região como ocupada pelo Trem 4
                }
                if (x == 240) {
                    QMutexLocker locker(&mutexRegiao5);
                    while (regiao5 != 0) {
                        condRegiao5.wait(&mutexRegiao5); // Espera a região ser liberada
                    }
                    regiao5 = 4; // Marca a região como ocupada pelo Trem 4
                }
                x += 10;
            } else if (x == 420 && y < 270) { // Indo para baixo
                if (y == 260) {
                    QMutexLocker locker(&mutexRegiao6);
                    while (regiao6 != 0) {
                        condRegiao6.wait(&mutexRegiao6); // Espera a região ser liberada
                    }
                    regiao6 = 4; // Marca a região como ocupada pelo Trem 4
                }
                y += 10;
            } else if (x > 240 && y == 270) { // Indo para a esquerda
                if (x == 410) {
                    QMutexLocker locker(&mutexRegiao6); // Libera a Região 6
                    regiao6 = 0;
                    condRegiao6.wakeOne(); // Notifica outros trens esperando
                }
                if (x == 250) {
                    QMutexLocker locker(&mutexRegiao5); // Libera a Região 5
                    regiao5 = 0;
                    condRegiao5.wakeOne(); // Notifica outros trens esperando
                }
                x -= 10;
            } else if (x == 240 && y > 150) { // Indo para cima
                if (y == 160) {
                    QMutexLocker locker(&mutexRegiao2); // Libera a Região 2
                    regiao2 = 0;
                    condRegiao2.wakeOne(); // Notifica outros trens esperando
                }
                y -= 10;
            }
            break;

        case 5: // Trem 5
            if (y == 150 && x < 600) { // Indo para a direita
                if (x == 590) {
                    QMutexLocker locker(&mutexRegiao3);
                    while (regiao3 != 0) {
                        condRegiao3.wait(&mutexRegiao3); // Espera a região ser liberada
                    }
                    regiao3 = 5; // Marca a região como ocupada pelo Trem 5
                }
                x += 10;
            } else if (x == 600 && y < 270) { // Indo para baixo
                if (y == 260) {
                    QMutexLocker locker(&mutexRegiao4);
                    while (regiao4 != 0) {
                        condRegiao4.wait(&mutexRegiao4); // Espera a região ser liberada
                    }
                    regiao4 = 5; // Marca a região como ocupada pelo Trem 5
                }
                y += 10;
            } else if (x > 410 && y == 270) { // Indo para a esquerda
                if (x == 590) {
                    QMutexLocker locker(&mutexRegiao4); // Libera a Região 4
                    regiao4 = 0;
                    condRegiao4.wakeOne(); // Notifica outros trens esperando
                }
                if (x == 420) {
                    QMutexLocker locker(&mutexRegiao3); // Libera a Região 3
                    regiao3 = 0;
                    condRegiao3.wakeOne(); // Notifica outros trens esperando
                }
                x -= 10;
            } else if (x == 420 && y > 150) { // Indo para cima
                y -= 10;
            }
            break;


        default:
            break;
        }

        emit updateGUI(ID, x, y); // Atualiza a interface gráfica
        msleep(velocidade); // Controla a velocidade
    }
}




