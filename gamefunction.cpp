#include "gamefunction.h"
using namespace std;
/***********************Card**********************/
Card::Card(rank r, suit s, bool ifu)
    : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{

}


Card::~Card(){}

int Card::GetValue(){
    //если карта перевернута лицом вниз, ее значение равно О
    int value = 0;
    if (m_IsFaceUp)
    {
        // значение - это число, указанное на карте
        value = m_Rank;
        // значение равно 10 для JACK, QUEEN и KING
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::Flip(){
    m_IsFaceUp = !(m_IsFaceUp);
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
