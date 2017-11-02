
#include <IInputDevice.h>

class InputDeviceTrueStub :
	public IInputDevice
{
public:
	InputDeviceTrueStub(){};
	~InputDeviceTrueStub(){};
	virtual bool left(){return true;};
	virtual bool right(){return true;};
	virtual bool up(){return true;};
	virtual bool down(){return true;};
	virtual bool turnLeft(){return true;};
	virtual bool turnRight(){return true;};
	virtual bool fire(){return true;};
	virtual bool left2(){return true;};
	virtual bool right2(){return true;};
	virtual bool up2(){return true;};
	virtual bool down2(){return true;};

	virtual bool select(){return true;};
	virtual bool next(){return true;};
	virtual bool previously(){return true;};

	virtual bool pause(){return true;};
	virtual bool displayInfo(){return true;};
	virtual bool exit(){return true;};
};
