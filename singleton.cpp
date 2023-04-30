#include "singleton.hpp"
#include "context.hpp"

CameraInstance& CameraInstance::getInstance()
{
	if(instance == nullptr)
	{
		instance = new CameraInstance();
	}
	return instance;
}

CameraInstance::~CameraInstance(){}

CameraInstance::CameraInstance(){}

void CameraInstance::operateContext(int action)
{
	Context context;

	//basic idea, actual names of context functions may require this to change
	if(action == 2)
	{
		context.setStrategy(std::make_unique<Start>());
		context.strategy();
	}
	if(action == 3)
	{
		context.setStrategy(std::make_unique<Stop>());
		context.strategy();
	}
	else
	{
		std::cout << "Operation not found, try input again" << std::endl;
	}
}

