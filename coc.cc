#include "coc.h"

ChamberOfCommerce::ChamberOfCommerce():
    manhunt{false} {}

void ChamberOfCommerce::warning() { manhunt = true; } // A merchant was attacked, become hostile

bool ChamberOfCommerce::wanted() { return manhunt; }

