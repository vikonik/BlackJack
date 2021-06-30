#ifndef GAMEFUNCTION
#define GAMEFUNCTION
#include <vector>
#include <iostream>
#include <string>

typedef enum{
    TWO,
    TRE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
}rank;

typedef enum{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
}suit;



class Card{

public:
    Card();
    ~Card();
    int GetValue();//Возвращает значение карты
    void Flip();

private:
    rank m_Rank;//Значение карты (туз, двойка, тройка и так долее). rank — это перечисление, куда входят все 13 значений
    suit m_Suit;//Масть карты (трефы, бубны, червы и пики). suit — это перечисление, содержащее четыре возможные масти
    bool m_IsFaceUp;//Указывает, как расположена карта — вверх лицом или рубашкой. Влияет на то, отображается она или нет

};


class Hand{
public:
    Hand();
    ~Hand();

    void Add(Card* pCard);
    void Clear();
    int GetTotal();

private:
    std::vector <Card*> m_Cards;

};

class GenericPlayer{
    std::string m_Name;
    virtual bool IsHitting()const = 0;
            bool IsBoosted() const;
            void Bust() const;
};

class Player{
    virtual bool IsHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;
};

class House{
    virtual bool IsHitting() const;
    void FlipFirstCard();
};

class Deck{
    void Populate();
    void Shuffle();
    void Deal (Hand& aHand);
    void AddltionalCards(GenericPlayer &aGenerlcPlayer);
};

class Game{
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
    void Play();
};
#endif // GAMEFUNCTION

