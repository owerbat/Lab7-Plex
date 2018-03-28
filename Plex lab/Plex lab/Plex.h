#pragma once

using namespace System::Drawing;

class TRoot{
protected:
	bool visible;
	bool active;
public:
	TRoot(bool _visible = true, bool _active = false) {
		visible = _visible;
		active = _active;
	}

	virtual void Show(Graphics ^gr) = 0;
	virtual void Hide(Graphics ^gr) = 0;
	virtual void Move(Graphics ^gr, int dx, int dy) = 0;
};



class TPoint : TRoot {
protected:
	int x;
	int y;
public:
	TPoint(int _x = 0, int _y = 0) : TRoot() {
		x = _x;
		y = _y;
	}

	virtual void Show(Graphics ^gr);
	virtual void Hide(Graphics ^gr);
	virtual void Move(Graphics ^gr, int dx, int dy);
};