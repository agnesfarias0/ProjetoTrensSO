#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int);  //construtor
    void run();         //função a ser executada pela thread
    void setVelocidade(int novaVelocidade);

    // Variáveis de controle para as regiões críticas (declaradas como estáticas)
    static int regiao1;
    static int regiao2;
    static int regiao3;
    static int regiao4;
    static int regiao5;
    static int regiao6;
    static int regiao7;

//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem

   // Mutexes para as regiões críticas
   static QMutex mutexRegiao1;
   static QMutex mutexRegiao2;
   static QMutex mutexRegiao3;
   static QMutex mutexRegiao4;
   static QMutex mutexRegiao5;
   static QMutex mutexRegiao6;
   static QMutex mutexRegiao7;
};

#endif // TREM_H
