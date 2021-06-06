#pragma once
#include "VEHICLE.h"

class CTRUCK : public CVEHICLE
{
public:
	static bool TrafficLight;
	void Draw();
	void DrawSpace();
};

