#include "gamefunction.h"
using namespace std;
/***********************Card**********************/
Card::Card(){

}

Card::~Card(){}

int Card::GetValue(){
    return m_Rank;
}

void Card::Flip(){
    m_IsFaceUp = ~m_IsFaceUp;
}
/***********************Hand*********************/
Hand::Hand(){


}

Hand::~Hand(){}

/* метод Add, который добавляет в коллекцию карт новую карту, соответственно он
принимает в качестве параметра указатель на новую карту*/
void Hand::Add(Card* pCard){
    m_Cards.push_back(pCard);
}

/* метод Clear, который очищает руку от карт*/
void Hand::Clear(){
    m_Cards.erase(m_Cards.begin(),m_Cards.end());
}

/* метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть
возможность того, что туз может быть равен 11)*/
int Hand::GetTotal(){
    int numOfCards = m_Cards.size();//Получили количество карт у игрока
    int summ = 0;
    for(int i = 0; i < numOfCards; i++){
        Card *card = m_Cards[i];//Создаю указатель экземпляр класса и копирую в него из вектора
        if(card->GetValue() == ACE){
            if(summ <= 10) summ += 11;
            else summ += 1;
        }
        else{
            summ += card->GetValue();//Суммируем полученные карты
        }
    }
    return summ;
}
