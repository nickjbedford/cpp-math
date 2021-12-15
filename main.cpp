#include <iostream>

#include "src/include.h"

int main()
{
	auto incident = math::vector3f(2, -1, 1).unit();
	auto normal = math::vector3f(0, 1, 0).unit();
	auto reflected = incident.reflect(normal);
	std::cout << incident.to_string(3) << std::endl;
	std::cout << normal.to_string(3) << std::endl;
	std::cout << reflected.to_string(3) << std::endl;
	return 0;
}
