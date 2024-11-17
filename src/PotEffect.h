#ifndef POTEFFECT_H
#define POTEFFECT_H

class PotEffect {
public:
  virtual int changeAtk() = 0;
  virtual int changeDef() = 0;
  virtual ~PotEffect() = 0;
};
#endif
