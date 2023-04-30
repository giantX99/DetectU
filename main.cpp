#include "singleton.hpp"
#include "context.hpp"
#include "CameraStrategies.hpp"

int main()
{
	int operation = 0;
	while(operation != 4)
	{
		std::cout << "Type '1' to enable camera functionalites, '2' to start camera, '3' to stop camera, and '4' to end program" << std::endl;
		std::cin >> operation;

		switch(operation)
		{
			case 1:
				CameraInstance &camera = CameraInstance::getInstance();
				break;
			case 2:
			case 3:
				camera.operateContext(operation);
				break;
			case 4:
				return(EXIT_SUCCESS);

			default:
				std::cout << "Invalid input, try again" << std::endl;
		}
	}
}
