
#include <IInputDevice.h>

class InputDeviceDownStub :
	public IInputDevice
{
public:
	InputDeviceDownStub(){};
	~InputDeviceDownStub(){};
	virtual bool left(){ return false; };
	virtual bool right(){ return false; };
	virtual bool up(){ return false; };
	virtual bool down(){ return true; };
	virtual bool turnLeft(){ return false; };
	virtual bool turnRight(){ return false; };
	virtual bool fire(){ return false; };
	virtual bool left2(){ return false; };
	virtual bool right2(){ return false; };
	virtual bool up2(){ return false; };
	virtual bool down2(){ return false; };

	virtual bool select(){ return false; };
	virtual bool next(){ return false; };
	virtual bool previously(){ return false; };

	virtual bool pause(){ return false; };
	virtual bool displayInfo(){ return false; };
	virtual bool exit(){ return false; };
};
