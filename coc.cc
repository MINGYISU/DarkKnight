#include "coc.h"

ChamberOfCommerce::ChamberOfCommerce(bool hunt = false):
    manhunt{hunt} {}

void ChamberOfCommerce::warning() { manhunt = true; } // A merchant was attacked, become hostile

bool ChamberOfCommerce::wanted() { return manhunt; }

