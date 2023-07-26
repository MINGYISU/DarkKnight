#ifndef HALFLING_H
#define HALFLING_H

class Halfling: public Enemy {
    public:
        Halfling();
        char charAt() override;
        bool hurt(int dmg) override;
};

#endif
