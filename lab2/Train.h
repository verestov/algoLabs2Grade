#ifndef LABSALGO_TRAIN_H
#define LABSALGO_TRAIN_H


#include <string>

class Train {
private:
    std::string NAZN;
    int NUMR;
    std::string TIME;

public:
    Train();

    Train(const std::string& nazn, int numr, const std::string& time);

    Train(const Train& other);

    ~Train();

    std::string getNAZN() const;
    int getNUMR() const;
    std::string getTIME() const;

    void setNAZN(const std::string& nazn);
    void setNUMR(int numr);
    void setTIME(const std::string& time);

    void print() const;
};

#endif
