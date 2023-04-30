#pragma once

#include <iostream>

class CameraInstance {
	public:
		static CameraInstance& getInstance();
		~CameraInstance();

		void operateContext(int action);

	private:
		CameraInstance();
		static CameraInstance instance = nullptr;
}
