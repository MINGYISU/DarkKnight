#ifndef HALFLING_H
#define HALFLING_H

class Halfling: public Enemy {
    public:
        Halfling();
        void attack() override;
        void hurt(int dmg, std::string enemy) override;
};

#endif
