#include <iostream>
#include <vector>
#include <algorithm>

// https://cplusplus.com/

using namespace std;

class Competition {
    vector<int> _scores;

    void setScore(size_t id, int vote)
    {
        _scores[id] += vote;
    }
public:
    Competition(size_t partCount)
    {
        _scores.assign(partCount, 0);
    }
    void setLike(size_t id)
    {
        setScore(id, 1);
    }
    void setDislike(size_t id)
    {
        setScore(id, -1);
    }
    vector<size_t> getWinners(size_t n)
    {
        // Вектор пар значений score-id
        vector<pair<int, size_t>> score_id;
        for (size_t i = 0; i < _scores.size(); i++)
            score_id.push_back({ _scores[i], i });
        // Сортировка вектора результатов score-id
        sort(score_id.rbegin(), score_id.rend());
        // Получить лучший результат
        vector<size_t> bestid;
        for (size_t i = 0; i < min(score_id.size(), n); i++)
            bestid.push_back(score_id[i].second);
        return bestid;
    }
};

int main()
{
    Competition *cmp = new Competition(5);
    cmp->setLike(0);
    cmp->setDislike(0);
    cmp->setDislike(0);

    cmp->setLike(1);
    cmp->setLike(1);
    cmp->setLike(1);

    cmp->setLike(2);
    cmp->setLike(2);
    cmp->setLike(2);
    cmp->setLike(2);
    cmp->setLike(2);
    cmp->setLike(2);

    cmp->setLike(3);
    cmp->setDislike(3);
    cmp->setDislike(3);
    cmp->setDislike(3);

    cmp->setLike(4);
    cmp->setDislike(4);
    cmp->setDislike(4);
    cmp->setDislike(4);

    vector<size_t> betsID = cmp->getWinners(2);

    delete cmp;
}
